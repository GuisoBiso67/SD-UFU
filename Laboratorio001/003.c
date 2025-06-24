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

int main(){
    int number;
    int vet[32];
    int *p;
    p = vet;
    scanf("%d", &number);
    
    int i=binary(number,p);

    for(int j=i-1;j>=0;j--){
        printf("%d", vet[j]);
    }
    printf("\n");
}