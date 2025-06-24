#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
    sim, eh possivel fazer subtracoes. Eh so converter o numero negativo para binario com complemento de 2 e realizar a soma;
*/

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

int adderOne(int* vet1){
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

    // recebe o numero 1 e ja calcula em binario
    int i1, i2;
    scanf("%d", &n1);
    if(n1<0){
        i1=binary(n1*(-1), pN1);
        twosComplement(pN1);
        adderOne(pN1);
        i1++;
    }else{
        i1=binary(n1, pN1);
    }

    // recebe o numero 2 e ja calcula em binario
    scanf("%d", &n2);
    if(n2<0){
        i2=binary(n2*(-1), pN2);
        twosComplement(pN2);
        adderOne(pN2);
        i2++;
    }else{
        i2=binary(n2, pN2);
    }

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
    printf("Sum/Minus: ");
    for(int j=iSum;j>=0;j--){
        printf("%d", vetSum[j]);
    }
    printf("\n");
}