/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      C:/ti/grace_3_10_00_82/packages/ti/mcu/msp430/csl2/adc/ADC10_B_init.xdt
 */
#include <driverlib/MSP430FR57xx/inc/hw_memmap.h>
#include <driverlib/MSP430FR57xx/adc10_b.h>
#include "_Grace.h"

/* USER CODE START (section: ADC10_B_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: ADC10_B_init_c_prologue) */

/*
 *  ======== ADC10_B_graceInit ========
 *  Initialize Config for the MSP430 10-bit Analog to Digital Converter (ADC)
 */
void ADC10_B_graceInit(void)
{

    /* USER CODE START (section: ADC10_B_graceInit_prologue) */
    /* User initialization code */
    /* USER CODE END (section: ADC10_B_graceInit_prologue) */

    /* Initializes ADC10_B */
    ADC10_B_init(ADC10_B_BASE, ADC10_B_SAMPLEHOLDSOURCE_SC, ADC10_B_CLOCKSOURCE_ADC10OSC, ADC10_B_CLOCKDIVIDER_1);

    /* Disables ADC10_B */
    ADC10_B_disable(ADC10_B_BASE);

    /* USER CODE START (section: ADC10_B_graceInit_epilogue) */
    /* User code */
    /* USER CODE END (section: ADC10_B_graceInit_epilogue) */

}
