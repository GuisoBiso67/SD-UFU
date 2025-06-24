#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char binary[34];
    fgets(binary, sizeof(binary), stdin);
    binary[strcspn(binary, "\n")] = '\0';
    int len = strlen(binary);

    unsigned int decimal=0;

    for(int i=0;i<len;i++){
        if(binary[i] == '1'){
            int pot = len - 1 - i;
            decimal+=pow(2,pot);
        }
    }

    printf("Decimal: %d\n", decimal);
}
