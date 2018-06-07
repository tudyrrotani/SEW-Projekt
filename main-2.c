#define POLY 0x8408

#include <string.h>
//extern  crc_ok;
int     crc_ok = 0x470F;


unsigned short crc16(unsigned char * data_p, unsigned short length) {


       unsigned int data;
       unsigned int crc;

       crc = 0xffff;

       if (length == 0)
              return (~crc);

       do {
              for (int i = 0 , data = (unsigned int)0xff & *data_p++;
                  i < 8;
                  i++, data >>= 1) {
                    if ((crc & 0x0001) ^ (data & 0x0001))
                           crc = (crc >> 1) ^ POLY;
                    else
                           crc >>= 1;
              }
       } while (--length);

       crc = ~crc;

       data = crc;
       crc = (crc << 8) | (data >> 8 & 0xFF);

       return (crc);
}


/**************************************************************************
//
// main() - test driver for crc16 function
//
**************************************************************************/

#include <stdio.h>


main(int argc, char *argv)

{
       unsigned char a[100];
       unsigned short crc;

       scanf("%s",&a);
       printf("The crc of \"%s\" is 0x%X.\r\n\n",
                    a, crc16 (a, (short)strlen((char *)a)));


       puts("strike RETURN to continue...");
       getchar();
}
