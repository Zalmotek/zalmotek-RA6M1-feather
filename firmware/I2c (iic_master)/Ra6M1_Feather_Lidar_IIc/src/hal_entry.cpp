#include "hal_data.h"
#include "Wire.h"  // Include the Wire (I2C) library

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

uint8_t deviceAddress = 0x10;  // TF-Luna device I2C address

void hal_entry(void)
{
    fsp_err_t err;

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

    /* Initialize I2C communication with the TF-Luna sensor */
    err = beginTransmission(deviceAddress);
    if (err != FSP_SUCCESS) {
        APP_PRINT("** I2C Initialization Failed **\r\n");
        return;
    }

    APP_PRINT("TF-Luna communication started.\r\n");

    while (1)
    {
        // Start communication with the TF-Luna
        beginTransmission(deviceAddress);
        write(0x00);  // Send the command to request data
        endTransmission(false);  // Complete the transmission

        // Request 7 bytes from the sensor
        err = requestFrom(deviceAddress, 7);
        if (err == FSP_SUCCESS && available()) {
            uint8_t data[7];
            for (int i = 0; i < 7; i++) {
                data[i] = read();  // Read the data from the buffer
            }

            // Process distance and signal strength
            unsigned int distance = (data[1] << 8) | data[0];  // Distance value
            unsigned int signalStrength = (data[3] << 8) | data[2];  // Signal strength

            APP_PRINT("Distance: %u cm\r\n", distance);
            APP_PRINT("Signal Strength: %u\r\n", signalStrength);
        } else {
            APP_PRINT("** Data request failed **\r\n");
        }

        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);  // Delay to control loop timing
    }
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&IOPORT_CFG_CTRL, &IOPORT_CFG_NAME);

#if BSP_CFG_SDRAM_ENABLED

        /* Setup SDRAM and initialize it. Must configure pins first. */
        R_BSP_SdramInit(true);
#endif
    }
}

#if BSP_TZ_SECURE_BUILD

FSP_CPP_HEADER
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
FSP_CPP_FOOTER

#endif
