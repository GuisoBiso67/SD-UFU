#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    unsigned int x;
    scanf("%d", &x);

    int numDigitos = floor(log10(x)) + 1; // calcula o numero de digitos
    int pot[numDigitos];

    for(int i=0;i<numDigitos;i++){
        pot[i] = 0;
    }

    int i=0;
    int n=1;

    while(x%(n*10) != 0 && i<numDigitos){
        pot[i]++;
        x-=n;
        if(x%(n*10) == 0){
            pot[i]=pot[i]*n;
            n=n*10;
            i++;
        }
    }

    for(int i=0;i<numDigitos;i++){
        printf("%d\n",pot[i]);
    }
}