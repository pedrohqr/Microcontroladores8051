/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "compiler_defs.h"
#include "C8051F040_defs.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

void Timer_Init()
{
    SFRPAGE   = TIMER01_PAGE;
    TMOD      = 0x01;
    CKCON     = 0x08;
}

void Port_IO_Init()
{
    // P0.0  -  Unassigned,  Push-Pull,  Digital
    // P0.1  -  Unassigned,  Push-Pull,  Digital
    // P0.2  -  Unassigned,  Push-Pull,  Digital
    // P0.3  -  Unassigned,  Push-Pull,  Digital
    // P0.4  -  Unassigned,  Push-Pull,  Digital
    // P0.5  -  Unassigned,  Push-Pull,  Digital
    // P0.6  -  Unassigned,  Push-Pull,  Digital
    // P0.7  -  Unassigned,  Push-Pull,  Digital

    // P1.0  -  Unassigned,  Push-Pull,  Digital
    // P1.1  -  Unassigned,  Push-Pull,  Digital
    // P1.2  -  Unassigned,  Push-Pull,  Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Push-Pull,  Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Push-Pull,  Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Push-Pull,  Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

    SFRPAGE   = CONFIG_PAGE;
    P0MDOUT   = 0xFF;
    P1MDOUT   = 0xFF;
    P2MDOUT   = 0xFF;
    P3MDOUT   = 0xFF;
    P4MDOUT   = 0xFF;
    P5MDOUT   = 0xFF;
    P6MDOUT   = 0xFF;
    P7MDOUT   = 0xFF;
    XBR2      = 0x40;
}

void Oscillator_Init()
{
    int i = 0;
    SFRPAGE   = CONFIG_PAGE;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    CLKSEL    = 0x01;
}

void Interrupts_Init()
{
    IE        = 0x03;
    IP        = 0xC2;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    Timer_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}
