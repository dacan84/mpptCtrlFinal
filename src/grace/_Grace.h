
/*
 *  ======== _Grace.h ========
 *  DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN
 */

#ifdef __cplusplus
extern "C" {
#endif

/* external peripheral initialization functions */
void Timer0_A3_graceInit(void);
void PinMux_graceInit(void);
void CS_graceInit(void);
void EUSCI_B0_graceInit(void);
void ADC10_B_graceInit(void);
void REF_graceInit(void);
void InterruptVectors_graceInit(void);
void System_graceInit(void);
void WDT_A_graceInit(void);
void Grace_init(void);

#ifdef __cplusplus
}
#endif

