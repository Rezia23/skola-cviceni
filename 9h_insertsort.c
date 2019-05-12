#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void){
    srand(time(NULL));
    int pocetprvku;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int tmp = 0;
    scanf("%d",&pocetprvku);

    int pole[pocetprvku];

    for(i = 0; i < pocetprvku;i++){
        pole[i] = rand();
        printf("%d ", pole[i]);
    }

    for(j = 1; j<pocetprvku;j++){
        for(k = 0; k<j;k++){
            if(pole[j]<pole[k]){
                tmp = pole[j];
                pole[j] = pole [k];
                pole[k] = tmp;
            }
        }
    }
    printf("\n");
    for(l = 0; l<pocetprvku;l++){
        printf("%d ", pole[l]);
    }

}
