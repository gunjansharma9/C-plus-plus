#include "bits/stdc++.h"
using namespace std;

// Sieve of Eratosthenes
// 204. Count Primes
int countPrimes(int n) {
    if(n==0) return 0;
    vector<bool>prime(n,true); //all are prime marked already
    prime[0] = prime[1] = false;
    int ans = 0;
    
    for(int i=2;i<n;i++){
        if(prime[i]){
            ans++;
            // int j=2*i;     //not optimized
            int j = i*i;
            // first unmarked number would be i*i,as others have been marked by 2 to (i-1)
            while(j<n){
                prime[j] = false;
                j+=i;
            }
        }
    }
    return ans;

    // TC -> O(nloglogn)
}

// GCD OF TWO NUMBERS

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while(a>0 && b>0){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    return a==0 ? b : a;
}

int findLCM(int a,int b){
    int LCM = a*b / gcd(a,b);
    return LCM;
}
// lcm * hcf = a*b


int fastExponentiation(int a,int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            // odd
            ans = ans*a;
        }
        a = a*a;
        b>>=1;
    }
    return ans;
}

int main(){
    int a = 56;
    int b = 12;
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<findLCM(a,b)<<endl;
    cout<<"exponentiation is : "<<fastExponentiation(5,12);
    return 0;
}