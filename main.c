#define POLY 0x8408
//die Bibliothek, die man verwendet
#include <string.h>
//Ergebnis, die man mitbekommen muss
int     crc_ok = 0x470F;

//wir schreiben daten, die dividiert mit ein Polynom werden.
unsigned short crc16(unsigned char * data_p, unsigned short length) {

       //daten von Sensor z.B.
       unsigned int data;
       unsigned int crc;
       int i;

       crc = 0xffff;
       //wenn es nicht eingetippt wird die crc zurückgegeben
       if (length == 0)
              return (~crc);
       //Es nimmt die Daten von Sensoren beispielsweise und probieren, ob die crc_ok gleich mit dem division ist.
         do {
            for (i = 0 , data = (unsigned int)0xff & * data_p++;
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
       //sieht wie groß soll die Data oder der Text sein
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
       //deklaration der Text, den wir verschluesseln moechten
       unsigned char a[100];

       unsigned short crc;
       //Durch die Tastatur der Text eingeben
       scanf("%s",&a);
       //wird der Text mitgebracht, und die Polynomdivision gemacht.
       printf("The crc of \"%s\" is 0x%X.\r\n\n",
                    a, crc16 (a, (short)strlen((char *)a)));


       puts("strike RETURN to continue...");
       //bekommen von die Daten(=TEXT)
       getchar();
}

