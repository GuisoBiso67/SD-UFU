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

int adder(int* vet1, int* vet2, int* vetSum){
    int carry=0;
    
    for(int i=0;i<16;i++){
        int sum = vet1[i] + vet2[i] + carry;

        // Agora, determinamos o bit do resultado e o próximo "vai-um"
        if (sum == 0) {         // 0 + 0 + 0
            vetSum[i] = 0;
            carry = 0;
        } else if (sum == 1) {  // 1 + 0 + 0
            vetSum[i] = 1;
            carry = 0;
        } else if (sum == 2) {  // 1 + 1 + 0
            vetSum[i] = 0;
            carry = 1;
        } else { // sum == 3   // 1 + 1 + 1
            vetSum[i] = 1;
            carry = 1;
        }
    }
}

int main(){
    int n1, n2;
    int vetN1[16]={0}, vetN2[16]={0}, vetSum[16]={0};

    int *pN1, *pN2, *pNSum;
    pN1 = vetN1;
    pN2 = vetN2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    
    int i1=binary(n1,pN1);
    int i2=binary(n2,pN2);

    pNSum = vetSum;

    printf("Num1: ");
    for(int j=i1-1;j>=0;j--){
        printf("%d", vetN1[j]);
    }
    printf("\n");

    printf("Num2: ");
    for(int j=i2-1;j>=0;j--){
        printf("%d", vetN2[j]);
    }
    printf("\n");

    adder(pN1, pN2, pNSum);
    int iSum=15;
    while(iSum<0 && pNSum[iSum]==0){
        iSum--;
    }
    printf("Sum: ");
    for(int j=iSum;j>=0;j--){
        printf("%d", vetSum[j]);
    }
    printf("\n");
}