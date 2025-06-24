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

int twosComplement(int* vet){
    for(int i=0;i<16;i++){
        if(vet[i]==0){
            vet[i]=1;
        }else{
            vet[i]=0;
        }
    }
}

int adder(int* vet1){
    int carry=1;
    
    for(int i=0;i<16;i++){
        int sum = vet1[i] + carry;

        if (sum == 0) {
            vet1[i] = 0;
            carry = 0;
        } else if (sum == 1) {
            vet1[i] = 1;
            carry = 0;
        } else if (sum == 2) {
            vet1[i] = 0;
            carry = 1;
        } else {
            vet1[i] = 1;
            carry = 1;
        }

        if(carry==0){
            return 0;
        }
    }
}

int main(){
    int n1, *p, vet[16]={0};
    scanf("%d",&n1);
    p=vet;

    int i;
    if(n1<0){
        i=binary(n1*(-1), p);
        twosComplement(p);
        adder(p);
        i++;
    }else{
        i=binary(n1, p);
    }

    printf("Num1: ");
    for(int j=i;j>=0;j--){
        printf("%d", vet[j]);
    }
    printf("\n");
}