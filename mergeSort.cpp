#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1],b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l+i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+i+1];
    }

    int i = 0,j = 0,k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++; i++;
        }else{
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i < n1){
        arr[k] = a[i];
        k++; i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++; j++;
    }
    
}

void mergeSort(int arr[],int l,int r){
    if(l < r){
        int  mid = (r+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){

    int arr[] = {8,7,2,9,4,6,1,0,3};

    mergeSort(arr,0,8);

    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl; 

    return 0;
}