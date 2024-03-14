#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[20];
    int rollNo;
    char gender;
    float marks[5];
    float avg;
} std;

void setAvgMarks(std *s){
    float sum = 0;
    for(int i = 0;i < 5;i++) sum += s->marks[i];
    s->avg = sum/5;
}

std inputDetails(){
    std s;
    //printf("Enter Name : ");
    scanf("%s",s.name);
    //printf("Enter Roll No. : ");
    scanf("%d",&s.rollNo);
    //printf("Enter Gender(M/F) : ");
    scanf("%c",&s.gender);
    //printf("Enter marks for Maths, CTSD-1, GCf, DT, ACTW respectively (out of 100) :- \n");
    for(int i=0;i<5;i++){
        scanf("%f",&s.marks[i]);
    }
    setAvgMarks(&s);
    return s;
}

void sort(std *arr,int n){
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-i-1;j++){
            if(arr[j].avg < arr[j+1].avg){
                std temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    int n,i;
    std array[50];

    //printf("Enter No. Of Students(<50) : ");
    scanf("%d",&n);

    for(i = 0;i < n;i++){
        //printf("Enter Details for student no. %d \n",i+1);
        array[i] = inputDetails();
    }

    // Sorting array according to percentage
    sort(array,n);

    // Printing Student List as there percentage
    printf("Rank \t Roll-No  Name \t Percentage \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t %d \t %s \t  %.2f \n",i+1,array[i].rollNo,array[i].name,array[i].avg);
    }
    


    return 0;
}