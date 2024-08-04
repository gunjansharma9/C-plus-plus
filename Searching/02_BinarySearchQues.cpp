#include "bits/stdc++.h"
using namespace std;

int FirstOccurence(vector<int>v,int target){
    int s = 0;
    int e = v.size()-1;
    int ans = -1;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(v[mid] == target){
            // ans store and then left mein jao
            ans = mid;
            e = mid-1;
        }else if(target > v[mid]){
            s = mid+1;
        }else if(target < v[mid]){
            e = mid-1;
        }
    }
    return ans;
}

int lastOcc(vector<int>arr,int target){
    int s = 0;
    int e = arr.size()-1;
    int ans = -1;
    int mid;
    while(s<=e){
        mid = s + (e-s)/2;
        if(arr[mid] == target){
            ans = mid;
            s = mid+1;
        }else if(target<arr[mid]){
            e = mid-1;
        }else if(target>arr[mid]){
            s = mid+1;
        }
    }
    return ans;
}

int findPivot(vector<int>arr){
    int s = 0;
    int e = arr.size()-1;
    int mid;
    while(s <= e){
        mid = s + (e-s)/2;
        if(mid+1<arr.size() && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid-1>=0 && arr[mid-1] > arr[mid]){
            return mid-1;
        }
        if(arr[s] >= arr[mid]){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1;
}

// 33. Search in Rotated Sorted Array
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int s, int e) {
        int mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
    
    int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
                return mid;
            else if (mid > 0 && nums[mid] < nums[mid - 1])
                return mid - 1;
            else if (nums[s] <= nums[mid])
                s = mid + 1; // Adjusting the update of 's'
            else
                e = mid - 1;
        }
        // when only one element in the array
        return s;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1; // Handle empty vector
        int pivotIndex = findPivot(nums);
        int n = nums.size();
        if (target >= nums[0] && target <= nums[pivotIndex])
            return binarySearch(nums, target, 0, pivotIndex);
        if (pivotIndex < n - 1 && target >= nums[pivotIndex + 1] && target <= nums[n - 1])
            return binarySearch(nums, target, pivotIndex + 1, n - 1);
        return -1;
    }
};

int findSqrtIntPart(int n){
    int target = n;
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(mid*mid == target){
            return mid;
        }
        if(mid*mid > target){
            e = mid-1;
        }else{
            ans = mid;
            s = mid+1;
        }
    }
    return ans;
}

bool binary_search2D(int arr[][4],int rows,int cols,int target){
    int s = 0;
    int e = rows*cols-1;

    while(s<=e){
        int mid = s+(e-s)/2;
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        if(arr[rowIndex][colIndex] == target){
            cout<<"\nFound at "<<rowIndex<<" "<<colIndex<<endl;
            return true;
        }

        if(arr[rowIndex][colIndex] < target){
            s = mid+1;
        }

        else{
            e = mid-1;
        }
    }
    return false;
}

int binarySearchInNearlySortedArray(vector<int>arr,int target){
    int s = 0;
    int e = arr.size()-1;
    int mid;

    while(s<=e){
        mid = s + (e-s)/2;
        if(target == arr[mid]){
            return mid;
        }
        if(mid-1 >=0 && target == arr[mid-1]){
            return mid-1;
        }
        if(mid+1 <=arr.size() && target == arr[mid+1]){
            return mid+1;
        }
        if(target < arr[mid]){
            e = mid-2;
        }else{
            s = mid+2;
        }
    }
    return -1; 
}

// quotient * divisor + remainder = dividend
// quotient * divisor <= dividend 
int solve(int &dividend,int &divisor){
    int s = 0;
    int e = abs(dividend);
    int ans = 0;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(abs(mid * divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        if(abs(mid * divisor) > abs(dividend)){
            e = mid-1;
        }else{
            ans = mid;
            s = mid+1;
        }
    }
    if((divisor<0 && dividend<0) || (dividend >0 && divisor>0)){
        return ans;
    }else{
        return -ans;
    }
}

int findODD(vector<int>v){
    int s = 0;
    int e = v.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(s == e){
            return s;
        }
        if(mid % 2 == 0){
            if(v[mid] == v[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        else{
            if(v[mid] == v[mid-1]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int>v{1,3,4,4,4,6,7};
    int target = 4;
    int indexOfFirstOcc = FirstOccurence(v,target);
    cout<<"First occurance of "<<target<<" is present at index "<<indexOfFirstOcc<<endl;

    int indexofLastOcc = lastOcc(v,target);
    cout<<"Last occurance of "<<target<<" is at index "<<indexofLastOcc<<endl;

    int totalNoOfOcc = indexofLastOcc-indexOfFirstOcc+1;
    cout<<"Total no of Occurances of "<<target <<" are "<<totalNoOfOcc<<endl;

    vector<int>pivot{1,2,3,4,5,6,7,3,4};
    cout<<"The index of Pivot element is : "<<findPivot(pivot)<<endl;

    int n = 10;
    int ans = findSqrtIntPart(n);
    cout<<"The square root of "<<n <<" is "<<endl;
    int ansWithPrecisionValue = 3;
    double step = 0.1;
    double finalAns = ans;
    for(int i=0;i<ansWithPrecisionValue;i++){
        for(double j=finalAns;j*j <=n;j=j+step){
            finalAns = j;
        }
        step = step/10;
    }
    cout<<"Final ans is : "<<finalAns;

    // Find element in 2D array
    int arr2D[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int rows = 5;
    int cols = 4;
    int target2 = 19;
    bool ans2 = binary_search2D(arr2D,rows,cols,target2);
    if(ans2){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    // c*i+j is equivalent to 2D representation in 1D array


    // Search in a nearly sorted array
    // nearly sorted array is one in which element which is present at ith position in sorted array,can present at i-1 or i or i+1 in nearly sorted array
    vector<int>arr3{10,3,40,20,50,80,70};
    int target3 = 80;
    int ans3 = binarySearchInNearlySortedArray(arr3,target3);
    cout<<"Index of "<<target3<<" is "<<ans3<<endl;

    int dividend = 22;
    int divisor = 7;
    int quotient = solve(dividend,divisor);
    cout<<"Quotient is : "<<quotient<<endl;

    vector<int>vector{1,1,2,2,3,3,4,4,3,3,6,600,600,4,4};
    int odd = findODD(vector);
    cout<<"ODD element is : "<<vector[odd]<<endl;

    return 0;
}

// Find the ODD occuring element in an arry
// all element occur even no of times except one
// all repeating occurance of element appear in pairs & pairs are not adjacent 