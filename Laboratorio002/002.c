#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binary(int n, int* vet){
    int i=0;
    if(n==0){
        return 0;
    }
    while(n>0){
        vet[i] = n%2;
        n = n/2;
        i++;
    }
    return i;
}

int binaryAndTwosComplement(int n, int* vet){

}

int main(){

}