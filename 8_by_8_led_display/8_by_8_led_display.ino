#include <LedControl.h>//27
#define INT_BITS 30
 
int DIN = 12;
int CS =  11;
int CLK = 10;

byte e[8]; // SHOWING SINGLE FRAME
// TO PRINT "KEVIN"
byte f[30] =     {0xf8,0x20,0x50,0x88,0x00,0xf8,0xa8,0xa8,0x00,0x38,0x40,0x80,0x40,0x38,0x00,0x88,0xf8,0x88,0x00,0xf8,0x20,0x40,0xf8,0x00,0x20,0x20,0x20,0x00,0x00,0x70};
// TO PRINT "GOVIND"
byte g[30] =     {0x70,0x88,0xa8,0x60,0x00,0x70,0x88,0x88,0x70,0x00,0x38,0x40,0x80,0x40,0x38,0x00,0x88,0xf8,0x88,0x00,0xf8,0x20,0x40,0xf8,0x00,0xf8,0x88,0x88,0x70,0x00};


LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() {
  lc.shutdown(0, false);      //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 3);     // Set the brightness  maximum value is 15
  lc.clearDisplay(0);         // and clear the display

}

void loop() {

    for (int j = 0; j < 23; j++)
  {
delay(100);
      for (int i = 0; i < 8; i++)
  { 
    e[i] = f[i+j];  
  }    
  printlnByte(e);
  }
      for (int j = 0; j < 23; j++)
  {
       delay(100);
      for (int i = 0; i < 8; i++)
  { 
    e[i] = g[i+j];  
  }    
  printlnByte(e);
  }
}


void printlnByte(byte character [])
{/*for showing single frame */
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
  delay(100);
}
int rightRotate(int n, unsigned int d)
{
   /*for  horizontal rotation
   In n>>d, first d bits are 0. To put last 3 bits of at 
     first, do bitwise or of n>>d with n <<(INT_BITS - d) */
   return (n >> d)|(n << (INT_BITS - d));
}
