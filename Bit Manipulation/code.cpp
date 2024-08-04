#include "bits/stdc++.h"
using namespace std;

// // EVEN AND ODD
// // if n & 1 == 1 means odd hai
// int main(){ 
//     int n;
//     cout<<"Enter number : ";
//     cin>>n;

//     if(n & 1) cout<<"Number is ODD";
//     else cout<<"Number is EVEN";
//     return 0;
// }


// Find ith bit of a number
// #doubt
int getithBit(int n,int i){
    int mask = 1 << i;
    int ans = n & mask;
    if(ans == 0) return 0;
    else return 1;
    // agr ans non zero aaya mtlb bit 1 thi
}

void setithBit(int n,int i){
    // make zero to one
    int mask = 1 << i;
    int ans = n | mask;
    cout<<"After setting "<<i<<"th bit : "<<ans<<endl;
}

void resetithBit(int& n,int i){
    int mask = ~(1<<i);
    n = n & mask;
    cout<<"After resetting "<<i<<"th bit : "<<n<<endl;
}

void updateIthBit(int &n,int i,int target){
    resetithBit(n,i);
    int mask = target << i;
    n = n | mask;
    cout<<"After updating "<<n<<endl;
}

void clearLastNBits(int n,int i){
    // last ki i bits ko zero krdo
    int mask = (-1 << i);
    n = n & mask;
    cout<<"After clearing last ith bits : "<<n<<endl;
}

bool checkPowerOf2(int n){
    if((n & (n-1)) == 0)
        return true;
    else{
        return false;
    }
}

int countSetBits(int n){
    int count = 0;
    while(n != 0){
        int lastBit = n & 1;
        if(lastBit){
            count++;
        }
        n = n >> 1;
    }
    return count;
    // last bit nikaal ko dekho agr one hai toh increment krdo count then right shift krdo next bit check krne k liye
}

// Minimum no. of steps to reach destination where you can take steps in power of 2
int countSetBitsFast(int n){
    int count = 0;
    while(n != 0){
        n = (n & (n-1));
        count++;
    }
    return count;
}

void clearBitsInRange(int n,int i,int j){
    int a = (-1 << (i+1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
    cout<<"After clearing bits from "<<i<<" to "<<j<<" is : "<<n<<endl;
}

void getSubsequences(string str){
    vector<string>ans;
    int n = str.length();

    for(int num = 0;num < (1<<n);num++){
        // 1<<n is 2 to the power n
        string temp = "";
        // we will create subsequence string in this temp string
        for(int i=0;i<n;i++){
            char ch = str[i];
            if(num & (1 << i)){
                temp.push_back(ch);
            }
        }
        if(temp.length() >= 0){
            ans.push_back(temp);
        }
    }
    cout<<"Count of subsequences "<<ans.size()<<endl;
    cout<<"Printing the subsequences"<<endl;
    sort(ans.begin(),ans.end());
    for(auto i: ans){
        cout<<i<<endl;
    }
    
}

int main(){
    int ans = getithBit(10,3);
    cout<<"ith bit is : "<<ans<<endl;
    // oth bit from right to left

    setithBit(10,2);

    int a = 10;
    resetithBit(a,1);
    // // #remember :- zero based indexing from right to left
    int n = 10;
    updateIthBit(n,1,0);
    // 1 index bit ko zero bna do

    int b = 7;
    clearLastNBits(b,2);

    bool check = checkPowerOf2(16);
    cout << (check ? "It is power of 2" : "It is not power of 2")<<endl;

    int ans2 = countSetBits(15);
    cout<<"No of set bits : "<<ans2<<endl;

    int ansfast = countSetBitsFast(15);
    cout<<"No of set bits : "<<ansfast<<endl;

    clearBitsInRange(15,2,0);

    string str = "abc";
    getSubsequences(str);
    return 0;
}



// 136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // xor operation perform krne se jo double occurences vale no. hai vo cancel ho jayenge
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
