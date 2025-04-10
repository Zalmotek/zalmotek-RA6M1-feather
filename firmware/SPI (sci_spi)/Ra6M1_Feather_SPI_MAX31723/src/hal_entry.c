#include "common_utils.h"
#include "spi_max31723.h"
#include "usb_uart.h"

uint64_t cnt = 0;

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    max31723_init();
    usb_init();
    while (true) {
        cnt++;
        if (configured && cnt % 1000000 == 0) {

            float temp = get_temperature();

            print_to_console((char*)computationinfo);
            print_to_console((char*)okstatus);
            print_to_console((char*)closingbracket);
            print_to_console((char*)spacerinfo);

            print_to_console((char*)spiinfo);
            if (spiok) {
                print_to_console((char*)okstatus);
            }
            else {
                print_to_console((char*)nokstatus);
            }
            print_to_console((char*)closingbracket);
            print_to_console((char*)spacerinfo);

            print_to_console((char*)temperatureinfo);
            if (spiok) {
                print_val(temp);
                print_to_console((char*)degreec);
            }
            print_to_console((char*)closingbracket);
            print_to_console((char*)spacerinfo);

            print_to_console((char*)endline);

            APP_PRINT("Measured temperature: %d.", (int)temp);
            APP_PRINT("%d\n", (int)(temp * 100) % 100);

            cnt = 0;
        }
        handle_usb_event();
    }

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
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
