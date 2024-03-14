#include<iostream>
using namespace std;

void swap(int arr[],int x,int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partialSort(int arr[],int l,int r){
    int pi = arr[l]; // We are using pivot as first element.
    int i = l,j = l+1;
    while (j<=r)
    {
        if(arr[j] < pi){
            i++;
            swap(arr,i,j);
        }
        j++;
    }
    swap(arr,i,l);
    
    return i;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int piMark = partialSort(arr,l,r);
        quickSort(arr,l,piMark-1);
        quickSort(arr,piMark+1,r);
    }

}

int main(){
    int arr[] = {5,4,8,3,6,2,4,10};
    quickSort(arr,0,7);

    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}