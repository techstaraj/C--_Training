#include<iostream>
#include<string>
using namespace std;

int getBit(int n,int pos){
    return ((n & (1 << pos)) != 0);
}

int setBit(int n,int pos){
    return (n | (1<<pos));
}

int powerof2(int n){
    // if((n & (n-1)) || n == 0){
    //     return 0;
    // }else{
    //     return 1;
    // }

    return (n && !(n & (n-1))); 
}

int count1sInBinary(int n){
    if(n == 0) return 0;
    if(!(n & (n-1))) return 1;

    int sum = count1sInBinary(n & (n-1));
    return ++sum;
}

void printAllSubsets(string n){
    int size = n.length();
    for(int i = 0; i < (1<<size); i++){
        string toPrint = "";
        for(int j = 0; j < size; j++){
            if(i & (1 << j)) toPrint += n.substr(j,1) ;
        }
        cout<<toPrint<<endl;
    }
}

int uniqueNumber(int arr[],int n){
    int unique = arr[0];
    for (int i = 1; i < n; i++)
    {
        unique = (unique ^ arr[i]);
    }
    return unique;    
}

void twoUniqueNumbers(int arr[],int n){
    int uniqueXor = 0;
    for (int i = 0; i < n; i++)
    {
        uniqueXor = (uniqueXor ^ arr[i]);
    }
    int tempXor = uniqueXor;

    int setbit = 0;
    int pos = 0;
    while (!setbit)
    {
        setbit = uniqueXor & 1;
        pos++;
        uniqueXor = uniqueXor >> 1;
    }

    int firstNum = 0;
    for (int i = 0; i < n; i++)
    {
        if(getBit(arr[i],(pos-1))) firstNum = (firstNum^arr[i]);
    }

    cout<<firstNum<<","<<(firstNum^tempXor)<<" are two unique numbers."<<endl;
    
}

int uniqueInThriceFreq(int arr[],int n){
    int k = 0;
    int result = 0;
    while(k<64){
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if(getBit(arr[i],k)) count++;
        }

        if((count%3) != 0){
            result = setBit(result,k);
        }
        k++;
    }

    return result; 
}

int main(){

    /* W.A.P to check if a given number is power of 2.*/
    // while (1){
    //     int n;
    //     cin>>n;

    //     if(powerof2(n)) cout<<n<<" is power of 2."<<endl;
    //     else cout<<n<<" is not a power of 2."<<endl;
    // }

    /* W.A.P to count the number of ones in binary representation of a number. */
    // while(1){
    //     int n;
    //     cin>>n;

    //     cout<<count1sInBinary(n)<<" no. of 1's are present in "<<n<<endl;
    // }
    
    /* W.A.P to generate all possible subsets of a given set. */
    // string n;
    // cin>>n;
    // printAllSubsets(n);

    /* W.A.P to find a unique number in an array where all numbers except one , are present twice. */
    // int arr[7] = {2,4,6,3,4,6,2};
    // cout<<uniqueNumber(arr,7)<<" is unique."<<endl;

    /* W.A.P to find two unique number in an array where all numbers except two , are present twice. */
    // int arr[8] = {2,4,6,7,4,5,6,2};
    // twoUniqueNumbers(arr,8);

    /* W.A.P to find a unique number in an array where all numbers except one , are present thrice. */
    int arr[10] = {1,3,2,3,4,2,1,1,3,2};
    cout<<uniqueInThriceFreq(arr,10)<<" is unique."<<endl;




    return 0;
}