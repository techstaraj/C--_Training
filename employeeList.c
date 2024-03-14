#include <stdio.h>

struct employee{
    char name[20];
    int Id;
};

int main(){
    struct employee list[5];
    for(int i = 0;i < 5; i++){
        scanf("%s",list[i].name);
        scanf("%d",&list[i].Id);
    }

    printf("Employee List: \n");
    printf("Name \t Id \n");

    for(int i = 0;i < 5; i++){
        printf("%s",list[i].name);
        printf("\t %d",list[i].Id);
        printf("\n");
    }

    return 0;
}