#include <stdio.h>

int main(){
    int n,z=0;

    scanf("%d",&n);

    #if n>z
        printf("The Number is Positive.");
    #elif n<z
        printf("The Number is Neagtive.");
    #else
        printf("The Number is Zero.");
    #endif

    printf("\n");

    return 0;
}