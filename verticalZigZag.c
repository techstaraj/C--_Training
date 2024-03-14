#include <stdio.h>

int main(){
    int i,n;
    scanf("%d",&n);

    for(i = 1;i <= n;i++){
        if(i%2 == 0) printf("  * \n");
        else if(i%4 == 1) printf("*  \n");
        else printf("    * \n");
    }

    return 0;
}