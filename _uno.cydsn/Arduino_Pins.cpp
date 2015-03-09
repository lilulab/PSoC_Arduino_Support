/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

extern "C" {
#include <Project.h>
}


#include <Arduino_Pins.h>

void (*pinWriteFuncs[20])(uint8_t level);
uint8_t (*pinReadFuncs[20])();
void (*pinModeFuncs[20])(uint8_t driveMode);
void (*pinBypassFuncs[20])();

void pinFuncInit()
{
    pinWriteFuncs[0] = D0_Write;
    pinWriteFuncs[1] = D1_Write;
    pinWriteFuncs[2] = D2_Write;
    pinWriteFuncs[3] = D3_Write;
    pinWriteFuncs[4] = D4_Write;
    pinWriteFuncs[5] = D5_Write;
    pinWriteFuncs[6] = D6_Write;
    pinWriteFuncs[7] = D7_Write;
    pinWriteFuncs[8] = D8_Write;
    pinWriteFuncs[9] = D9_Write;
    pinWriteFuncs[10] = D10_Write;
    pinWriteFuncs[11] = D11_Write;
    pinWriteFuncs[12] = D12_Write;
    pinWriteFuncs[13] = D13_Write;
    pinWriteFuncs[14] = A0_Write;
    pinWriteFuncs[15] = A1_Write;
    pinWriteFuncs[16] = A2_Write;
    pinWriteFuncs[17] = A3_Write;
    pinWriteFuncs[18] = A4_Write;
    pinWriteFuncs[19] = A5_Write;
    
    
    pinReadFuncs[0] = D0_Read;
    pinReadFuncs[1] = D1_Read;
    pinReadFuncs[2] = D2_Read;
    pinReadFuncs[3] = D3_Read;
    pinReadFuncs[4] = D4_Read;
    pinReadFuncs[5] = D5_Read;
    pinReadFuncs[6] = D6_Read;
    pinReadFuncs[7] = D7_Read;
    pinReadFuncs[8] = D8_Read;
    pinReadFuncs[9] = D9_Read;
    pinReadFuncs[10] = D10_Read;
    pinReadFuncs[11] = D11_Read;
    pinReadFuncs[12] = D12_Read;
    pinReadFuncs[13] = D13_Read;
    pinReadFuncs[14] = A0_Read;
    pinReadFuncs[15] = A1_Read;
    pinReadFuncs[16] = A2_Read;
    pinReadFuncs[17] = A3_Read;
    pinReadFuncs[18] = A4_Read;
    pinReadFuncs[19] = A5_Read;
    
    pinModeFuncs[0] = D0_SetDriveMode;
    pinModeFuncs[1] = D1_SetDriveMode;
    pinModeFuncs[2] = D2_SetDriveMode;
    pinModeFuncs[3] = D3_SetDriveMode;
    pinModeFuncs[4] = D4_SetDriveMode;
    pinModeFuncs[5] = D5_SetDriveMode;
    pinModeFuncs[6] = D6_SetDriveMode;
    pinModeFuncs[7] = D7_SetDriveMode;
    pinModeFuncs[8] = D8_SetDriveMode;
    pinModeFuncs[9] = D9_SetDriveMode;
    pinModeFuncs[10] = D10_SetDriveMode;
    pinModeFuncs[11] = D11_SetDriveMode;
    pinModeFuncs[12] = D12_SetDriveMode;
    pinModeFuncs[13] = D13_SetDriveMode;
    pinModeFuncs[14] = A0_SetDriveMode;
    pinModeFuncs[15] = A1_SetDriveMode;
    pinModeFuncs[16] = A2_SetDriveMode;
    pinModeFuncs[17] = A3_SetDriveMode;
    pinModeFuncs[18] = A4_SetDriveMode;
    pinModeFuncs[19] = A5_SetDriveMode;

    pinBypassFuncs[0] = D0_Bypass;
    pinBypassFuncs[1] = D1_Bypass;
    pinBypassFuncs[2] = D2_Bypass;
    pinBypassFuncs[3] = D3_Bypass;
    pinBypassFuncs[4] = D4_Bypass;
    pinBypassFuncs[5] = D5_Bypass;
    pinBypassFuncs[6] = D6_Bypass;
    pinBypassFuncs[7] = D7_Bypass;
    pinBypassFuncs[8] = D8_Bypass;
    pinBypassFuncs[9] = D9_Bypass;
    pinBypassFuncs[10] = D10_Bypass;
    pinBypassFuncs[11] = D11_Bypass;
    pinBypassFuncs[12] = D12_Bypass;
    pinBypassFuncs[13] = D13_Bypass;
    pinBypassFuncs[14] = A0_Bypass;
    pinBypassFuncs[15] = A1_Bypass;
    pinBypassFuncs[16] = A2_Bypass;
    pinBypassFuncs[17] = A3_Bypass;
    pinBypassFuncs[18] = A4_Bypass;
    pinBypassFuncs[19] = A5_Bypass;
    
    uint8_t i = 0;
    for (i = 0; i<20; i++)
    {
        pinMode(i, INPUT);
        digitalWrite(i, LOW);
    }
}
    
void digitalWrite(uint8_t pin, uint8_t level)
{
    pinWriteFuncs[pin](level);
}
    
uint8_t digitalRead(uint8_t pin)
{
    return pinReadFuncs[pin]();
}

void pinMode(uint8_t pin, enum PIN_MODE mode)
{
    pinBypassFuncs[pin]();
    switch(mode)
    {
        case OUTPUT:
        pinModeFuncs[pin](PIN_DM_STRONG);
        break;
        case INPUT_PULLUP:
        pinModeFuncs[pin](PIN_DM_RES_UP);
        pinWriteFuncs[pin](1);
        break;
        case INPUT:
        default:
        pinModeFuncs[pin](PIN_DM_DIG_HIZ);
    }
}

void D0_Bypass()
{
    D0_BYP &= ~D0_MASK;
}

void D1_Bypass()
{
    D1_BYP &= ~D1_MASK;
}

void D2_Bypass()
{
    D2_BYP &= ~D2_MASK;
}

void D3_Bypass()
{
    D3_BYP &= ~D3_MASK;
}

void D4_Bypass()
{
    D4_BYP &= ~D4_MASK;
}

void D5_Bypass()
{
    D5_BYP &= ~D5_MASK;
}

void D6_Bypass()
{
    D6_BYP &= ~D6_MASK;
}

void D7_Bypass()
{
    D7_BYP &= ~D7_MASK;
}

void D8_Bypass()
{
    D8_BYP &= ~D8_MASK;
}

void D9_Bypass()
{
    D9_BYP &= ~D9_MASK;
}

void D10_Bypass()
{
    D10_BYP &= ~D10_MASK;
}

void D11_Bypass()
{
    D11_BYP &= ~D11_MASK;
}

void D12_Bypass()
{
    D12_BYP &= ~D12_MASK;
}

void D13_Bypass()
{
    D13_BYP &= ~D13_MASK;
}

void A0_Bypass()
{
    A0_BYP &= ~A0_MASK;
}

void A1_Bypass()
{
    A1_BYP &= ~A1_MASK;
}

void A2_Bypass()
{
    A2_BYP &= ~A2_MASK;
}

void A3_Bypass()
{
    A3_BYP &= ~A3_MASK;
}

void A4_Bypass()
{
    A4_BYP &= ~A4_MASK;
}

void A5_Bypass()
{
    A5_BYP &= ~A5_MASK;
}

/* [] END OF FILE */
