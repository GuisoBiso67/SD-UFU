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

        if (sum == 0) {
            vetSum[i] = 0;
            carry = 0;
        } else if (sum == 1) {
            vetSum[i] = 1;
            carry = 0;
        } else if (sum == 2) {
            vetSum[i] = 0;
            carry = 1;
        } else {
            vetSum[i] = 1;
            carry = 1;
        }
    }
}

int addZeroOnLeft(int* vet){ // sei la essa merda;
    int copy[16]={0};
    for(int i=0;i<16;i++){
        copy[i]=vet[i];
    }
    vet[0]=0;
    for(int i=1;i<=16;i++){

    }
}

int multiply(int* vet1, int* vet2, int* vetRes){
    int *p;
    p = vetRes;
    int vetTemp1[16]={0}, vetTemp2[16]={0};
    int *pVetTemp1, *pVetTemp2; // ponteiros para as strings temporarias
    pVetTemp1 = vetTemp1;
    pVetTemp2 = vetTemp2;

    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(i%2==0){
                vetTemp1[j]=vet1[i]*vet2[j]; // preenche o vetor 1 com o resultado da primeira multiplicacao;
            }else{
                vetTemp2[j]=vet1[i]*vet2[j]; // preenche o vetor 2 com o resultado da segunda multiplicacao;
            }
        }
        if(i!=0 && i%2==0){
            adder(pVetTemp1, pVetTemp2, vetRes);
        }
    }
}

int main(){
    int n1, n2;
    int vetN1[16]={0}, vetN2[16]={0}, vetSum[32]={0};

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
    int iSum=31;
    while(iSum<0 && pNSum[iSum]==0){
        iSum--;
    }
    printf("Sum: ");
    for(int j=iSum;j>=0;j--){
        printf("%d", vetSum[j]);
    }
    printf("\n");
}