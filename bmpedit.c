#include <stdio.h>
#include <stdlib.h>

int invoerbuffer;

unsigned char data[] = {0x42, 0x4D,                 //BMP ding
                        0x00, 0x00, 0x00, 0x00,     //totaal grootte bestand
                        0x00, 0x00, 0x00, 0x00,     //editor onzin
                        0x36, 0x00, 0x00, 0x00,     //header grootte
                        0x28, 0x00, 0x00, 0x00,     //overblijvende voor DIB
                        0x00, 0x00, 0x00, 0x00,     //grootte horizontaal
                        0x00, 0x00, 0x00, 0x00,     //grootte verticaal
                        0x01, 0x00, 0x18, 0x00,     //iets met kleurplaat en bpp
                        0x00, 0x00, 0x00, 0x00,     //compressiemethode (die's ernie)
                        0x00, 0x00, 0x00, 0x00,     //hoogte * breedte * 3
                        0x00, 0x00, 0x00, 0x00,     //onnodige ruimteverspilling 4
                        0x00, 0x00, 0x00, 0x00,     //onnodige ruimteverspilling 8
                        0x00, 0x00, 0x00, 0x00,     //onnodige ruimteverspilling 12
                        0x00, 0x00, 0x00, 0x00,     //onnodige ruimteverspilling 16
                        0x00, 0xff, 0x00};          //pixeldata

int main() {
    FILE * fp;  //bereidt het bestand voor
    fp = fopen("foto.bmp", "w+");

    printf("Bitmap breedte?\n");
    scanf("%d", &invoerbuffer);
    data[18] = invoerbuffer;

    printf("Bitmap hoogte?\n");
    scanf("%d", &invoerbuffer);
    data[22] = invoerbuffer;

    data[34] = data[18] * data[22] * 3;

    data[2] = data[34] + 54;

    int groottedata = sizeof(data) / sizeof(data[0]); //schrijft de invoer
    for(int i = 0; i <= groottedata; i++) {
        fprintf(fp, "%c", data[i]);
    }

    fclose(fp);
    return 0;
}
