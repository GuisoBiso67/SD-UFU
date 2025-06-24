#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char binary[34];
    char binary_padded[40];
    char hexa_final[9];
    fgets(binary, sizeof(binary), stdin);
    binary[strcspn(binary, "\n")] = '\0';

    const char hex_digits[] = "0123456789ABCDEF"; // constante hexadecimal;

    int len = strlen(binary);
    int padding = (4 - (len % 4)) % 4; // calcula quantidade de zeros para o binario ser divisivel por 4;
    for (int i = 0; i < padding; i++) { // copia os zeros necessarios para a nova string;
        binary_padded[i] = '0';
    }
    binary_padded[padding] = '\0'; // adiciona \0;
    strcat(binary_padded, binary); // concatena a string binaria original após os zeros;

    int hexa_index=0;
    for (int i = 0; i < strlen(binary_padded); i += 4) {
        // converte 4 bits para um valor decimal;
        int vDecimal = 0;
        if (binary_padded[i]   == '1'){
            vDecimal += 8;
        }
        if (binary_padded[i+1] == '1'){
            vDecimal += 4;
        }
        if (binary_padded[i+2] == '1'){
            vDecimal += 2;
        }
        if (binary_padded[i+3] == '1'){
            vDecimal += 1;
        }
        // usa o valor decimal para encontrar o caractere no 'hex_digits[]';
        hexa_final[hexa_index] = hex_digits[vDecimal];
        hexa_index++;
    }

    printf("Hexadecimal: %s\n", hexa_final);
}