#include "include/initBoard.h"
#include "include/public.h"

// CONFIG2
#pragma config POSCMOD = NONE    // Primary Oscillator Select->Primary oscillator disabled
#pragma config OSCIOFNC = OFF    // Primary Oscillator Output Function->OSC2/CLKO/RC15 functions as CLKO (FOSC/2)
#pragma config FCKSM = CSDCMD    // Clock Switching and Monitor->Clock switching and Fail-Safe Clock Monitor are disabled
#pragma config FNOSC = FRCPLL    // Oscillator Select->Fast RC Oscillator with PLL module (FRCPLL)
#pragma config IESO = ON    // Internal External Switch Over Mode->IESO mode (Two-Speed Start-up) enabled

// CONFIG1
#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler->1:32,768
#pragma config FWPSA = PR128    // WDT Prescaler->Prescaler ratio of 1:128
#pragma config WINDIS = ON    // Watchdog Timer Window->Standard Watchdog Timer enabled,(Windowed-mode is disabled)
#pragma config FWDTEN = ON    // Watchdog Timer Enable->Watchdog Timer is enabled
#pragma config ICS = PGx2    // Comm Channel Select->Emulator/debugger uses EMUC2/EMUD2
#pragma config COE = OFF    // Set Clip On Emulation Mode->Reset Into Operational Mode
#pragma config BKBUG = OFF    // Background Debug->Device resets into Operational mode
#pragma config GWRP = OFF    // General Code Segment Write Protect->Writes to program memory are allowed
#pragma config GCP = OFF    // General Code Segment Code Protect->Code protection is disabled
#pragma config JTAGEN = OFF    // JTAG Port Enable->JTAG port is enabled

/* fcy = 16MHz */
void OSCILLATOR_Initialize(void)
{
    // NOSC FRCPLL; SOSCEN disabled; OSWEN Switch is Complete; 
    __builtin_write_OSCCONL((uint8_t) (0x0100 & 0x00FF));
    // RCDIV FRC/1; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3000;
    // TUN Center frequency; 
    OSCTUN = 0x0000;
}

 

void initIO(void)
{

    //TRISDbits.TRISD0 = 0;
    
    /* PBs */
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD7 = 1;
    TRISDbits.TRISD13 = 1;
  //  TRISAbits.TRISA7 = 1;
    
    /* LEDs */
    TRISAbits.TRISA0 = 0; // LED D3
    TRISAbits.TRISA1 = 0; // LED D4
    
    
}