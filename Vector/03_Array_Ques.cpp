#include "bits/stdc++.h"
using namespace std;


// 75. Sort Colors
// Three pointer approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int h = nums.size()-1;
        while(m<=h){
            if(nums[m] == 0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m] == 1){
                m++;
            }else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};

// Move all negative integer to the left side of the array
// Dutch National Flag Algo or Two pointer approach
void moveAllNegative(int *a,int size){
    int l = 0;
    int h = size-1;
    while(l<h){
        if(a[l]<0){
            l++;
        }else if(a[h]>0){
            h--;
        }else{
            swap(a[l],a[h]);
        }
    }
}

void findMissing(int *a,int n){
    for(int i=0;i<n;i++){
        int index = abs(a[i]);
        if(a[index-1] > 0){
            a[index-1] *= -1;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i] > 0){
            cout<<i+1<<" ";
        }
    }
}

// First Repeating Element - gfg
int firstRepeated(int a[], int n){
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(hash[a[i]] > 1){
                return i+1;
            }
        }
        return -1;
}

void wavePrintMatrix(vector<vector<int>>v){
    int row = v.size();
    int col = v[0].size();

    for(int startCol=0;startCol<col;startCol++){
        // even no of col -> top to bottom
        if((startCol & 1) == 0){
            for(int i=0;i<row;i++){
                cout<<v[i][startCol]<<" ";
            }
        }else{
        // odd no of col -> Bottom to top
            for(int i=row-1;i>=0;i--){
                cout<<v[i][startCol]<<" ";
            }
        }
    }
}

// 54. Spiral Matrix
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int total_elements = rows*cols;

    int startingRow = 0;
    int endingCol = cols-1;
    int endingRow = rows-1;
    int startingCol = 0;

    int count = 0;
    while(count < total_elements){
        for(int i=startingCol;i<=endingCol && count<total_elements;i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i=startingRow;i<=endingRow && count<total_elements;i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i=endingCol;i>=startingCol && count<total_elements;i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i=endingRow;i>=startingRow && count<total_elements;i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

// Add two numbers represented by two arrays - gfg
class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int carry = 0;
        string ans;
        int i=n-1;
        int j=m-1;
        
        while(i>=0 && j>=0){
            int x = a[i]+b[j]+carry;
            int digit = x%10;
            ans.push_back(digit+'0');
            carry = x/10;
            i--;
            j--;
        }
        
        //jb j vali array khatm ho jaaye
        while(i>=0){
            int x = a[i]+0+carry;
            int digit = x%10;
            ans.push_back(digit + '0');
            carry = x/10;
            i--;
        }
        
        // jb i vala array khatm ho jaaye
        while(j>=0){
            int x = 0 + b[j] + carry;
            int digit = x%10;
            ans.push_back(digit + '0');
            carry = x/10;
            j--;
        }
        
        // agr carry bch rha h
        if(carry){
            ans.push_back(carry + '0');
        }
        
        while(ans[ans.size()-1] == '0'){
            // agr hmare pas extra zeroes pde hue hai
            // starting mein toh hmhe unhe htana hai qki hm
            // string mein ans store krre hai toh hm leading zeros ko ignore ni kr skte
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Factorials of large numbers - gfg
class Solution {
public:
    vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
        int carry = 0;
        for(int i=2;i<=N;i++){
            for(int j=0;j<ans.size();j++){
                int x = ans[j]*i+carry;
                ans[j] = x%10;
                carry = x/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry /= 10;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


int main(){
    // int a[] = {1,2,-3,4,-5,6};
    // int n = sizeof(a)/sizeof(int);
    // moveAllNegative(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;


    // Missing Elements from an array with duplicates
    int n2;
    int arr[]={1,3,5,3,4};
    n2 = sizeof(arr)/sizeof(int);
    // findMissing(arr,n2);

    // 2nd method
    // sorting swapping method
    int i=0;
    while(i<n2){
        int index = arr[i]-1;
        if(arr[i] != arr[index]){
            swap(arr[i],arr[index]);
        }else{
            ++i;
        }
    }
    for(int i=0;i<n2;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=0;i<n2;i++){
        if(arr[i] != i+1){
            cout<<i+1<<" ";
        }
    }cout<<endl;
    
    vector<vector<int>>v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    wavePrintMatrix(v);

    return 0;
}


// Common elements
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int>ans;
    set<int>st;
    int i,j,k;
    i=j=k=0;
    while(i<n1 && j<n2 && k<n3){
        if(A[i] == B[j] && B[j]==C[k]){
            st.insert(A[i]);
            i++;
            j++;k++;
        }
        else if(A[i]<B[j]){
            i++;
        }else if(B[j]<C[k]){
            j++;
        }else{
            k++;
        }
    }
    for(auto i:st){
        ans.push_back(i);
    }
    return ans;
}