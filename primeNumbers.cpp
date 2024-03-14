#include<iostream>
using namespace std;

void prime1toN(int n){
    int spf[n+1] = {0};
    
    for (int i = 2; i < n+1; i++)
    {
        if(!spf[i]){
            cout<<i<<" , ";
            int k = i*i;
            while (k < n+1)
            {
                spf[k] = 1;
                k += i;
            }
            
        }
    }

    cout<<endl;
    
}

void primeFactorization(int n){   // Using Sieve of Erathosthenes
    int spf[n+1] = {0}; // spf --> smallest prime factor.
    for (int i = 2; i < n+1; i++)
    {
        spf[i] = i;
    }
    
    
    for (int i = 2; i < n+1; i++)
    {
        if(spf[i] == i){
            int k = i*i;
            while (k < n+1)
            {
                if(spf[k] == k) spf[k] = i;
                k += i;
            }
            
        }
    }
    
    while (n != 1)
    {
        cout<<spf[n]<<",";
        n = n/spf[n];
    }
    

    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    /* Finding primes in Range 1 to n*/
    // prime1toN(n);

    /* Pinting prime factorization of n*/
    primeFactorization(n);

    return 0;
}