#include "mbed.h"

int main()
{
   BufferedSerial serial(PA_9, PA_10, 115200);

   while(true) {}

   // main() is expected to loop forever.
   // If main() actually returns the processor will halt
   //

   serial.readable();
   printf("Ciao!\n");

   return 0;
}

