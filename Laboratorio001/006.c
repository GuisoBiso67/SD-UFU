#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char hexa[9];
    fgets(hexa, sizeof(hexa), stdin);
    hexa[strcspn(hexa, "\n")] = '\0';
    int len = strlen(hexa);

    char binary[33];
    int j=0;

    // claramente ineficiente, mas funciona '_';
    for(int i=0;i<len;i++){
        switch (hexa[i]){
        case 'F': case 'f':
            binary[j] = '1';
            binary[j+1] = '1';
            binary[j+2] = '1';
            binary[j+3] = '1';
            j+=4;
            break;
        case 'E': case 'e':
            binary[j] = '1';
            binary[j+1] = '1';
            binary[j+2] = '1';
            binary[j+3] = '0';
            j+=4;
            break;
        case 'D': case 'd':
            binary[j] = '1';
            binary[j+1] = '1';
            binary[j+2] = '0';
            binary[j+3] = '1';
            j+=4;
            break;
        case 'C': case 'c':
            binary[j] = '1';
            binary[j+1] = '1';
            binary[j+2] = '0';
            binary[j+3] = '0';
            j+=4;
            break;
        case 'B': case 'b':
            binary[j] = '1';
            binary[j+1] = '0';
            binary[j+2] = '1';
            binary[j+3] = '1';
            j+=4;
            break;
        case 'A': case 'a':
            binary[j] = '1';
            binary[j+1] = '0';
            binary[j+2] = '1';
            binary[j+3] = '0';
            j+=4;
            break;
        case '9':
            binary[j] = '1';
            binary[j+1] = '0';
            binary[j+2] = '0';
            binary[j+3] = '1';
            j+=4;
            break;
        case '8':
            binary[j] = '1';
            binary[j+1] = '0';
            binary[j+2] = '0';
            binary[j+3] = '0';
            j+=4;
            break;
        case '7':
            binary[j] = '0';
            binary[j+1] = '1';
            binary[j+2] = '1';
            binary[j+3] = '1';
            j+=4;
            break;
        case '6':
            binary[j] = '0';
            binary[j+1] = '1';
            binary[j+2] = '1';
            binary[j+3] = '0';
            j+=4;
            break;
        case '5':
            binary[j] = '0';
            binary[j+1] = '1';
            binary[j+2] = '0';
            binary[j+3] = '1';
            j+=4;
            break;
        case '4':
            binary[j] = '0';
            binary[j+1] = '1';
            binary[j+2] = '0';
            binary[j+3] = '0';
            j+=4;
            break;
        case '3':
            binary[j] = '0';
            binary[j+1] = '0';
            binary[j+2] = '1';
            binary[j+3] = '1';
            j+=4;
            break;
        case '2':
            binary[j] = '0';
            binary[j+1] = '0';
            binary[j+2] = '1';
            binary[j+3] = '0';
            j+=4;
            break;
        case '1':
            binary[j] = '0';
            binary[j+1] = '0';
            binary[j+2] = '0';
            binary[j+3] = '1';
            j+=4;
            break;
        case '0':
            binary[j] = '0';
            binary[j+1] = '0';
            binary[j+2] = '0';
            binary[j+3] = '0';
            j+=4;
            break;
        }
    }

    for(int i=0;i<j;i++){
        if(i%4==0 && i != 0){
            printf(" ");
        }
        printf("%c",binary[i]);
    }
}