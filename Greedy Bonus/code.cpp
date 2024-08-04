#include "bits/stdc++.h"
using namespace std;

// ACTIVITY SELECTION PROBLEM
// bool cmp(pair<int,int>a,pair<int,int>b){
//     return a.second < b.second;
// }

// int solve(int n,int arr[],int dept[]){
//     vector<pair<int,int>>data;
//     for(int i=0;i<n;i++){
//         data.push_back({arr[i],dept[i]});
//     }
//     sort(data.begin(),data.end(),cmp);

//     int count = 1;
//     cout<<data[0].first << "->"<<data[0].second<<endl;
//     int lastDept = data[0].second;
//     // count ko 1 se isliye initialize kia hai qki first train ko include krna hi hai
//     for(int i=1;i<n;i++){
//         if(data[i].first >= lastDept){
//             count++;
//             lastDept = data[i].second;
//             cout<<data[i].first<<"->"<<data[i].second<<endl;
//         }
//     }
//     return count;
// }

// int main(){
//     int n = 4;
//     int arrival[] = {5,8,2,4};
//     int departure[] = {7,11,6,5};
//     int ans = solve(n,arrival,departure);
//     cout<<"Ans is : "<<ans<<endl;

//     return 0;
// }


// SHOP CANDY -> minimum amount to buy all candies
// int main(){
//     int prices[] = {2,8,6,9,4,7};
//     int n = 6;

//     sort(prices,prices+n);
//     int amount = 0;
//     int buy = 0;
//     int free = n-1;
//     while(buy <= free){
//         amount += prices[buy];
//         buy++;
//         free--;
//         free--;
//     }
//     cout<<"Answer is : "<<amount<<endl;

//     return 0;
// }


// // Minimum cost to merge n ropes
// int main(){
//     int arr[] = {4,3,2,6};
//     int n = 4;

//     priority_queue<int,vector<int>,greater<int>>pq;
//     for(int i=0;i<n;i++){
//         pq.push(arr[i]);
//     }

//     int cost = 0;
//     while(pq.size() != 1){
//         int first = pq.top();
//         pq.pop();
//         int second = pq.top();
//         pq.pop();

//         cost += first + second;
//         int newLength = first + second;
//         pq.push(newLength);
//     }

//     cout<<"Cost is "<<cost<<endl;

//     return 0;
// }


// // Fractional Knapsack
// bool cmp(pair<int,int>a,pair<int,int>b){
//     double ratio1 = ((1.0)*a.first)/a.second;
//     double ratio2 = ((1.0)*b.first)/b.second;
//     return ratio1 > ratio2;
// }

// int main(){
//     int val[] = {60,100,120};
//     int wt[] = {10,20,30};
//     int n = 3;
//     int capacity = 50;

//     vector<pair<int,int>>data;
//     for(int i=0;i<n;i++){
//         data.push_back({val[i],wt[i]});
//     }

//     sort(data.begin(),data.end(),cmp);
//     int totalValue = 0;
//     // check each item ka entire item lena hai ya fraction
//     for(int i=0;i<n;i++){
//         pair<int,int>item = data[i];
//         int itemValue = item.first;
//         int itemWeight = item.second;
//         if(itemWeight <= capacity){
//             totalValue += itemValue;
//             capacity = capacity - itemWeight;
//         }
//         else{
//             // fraction include kro
//             int ratio = ((1.0)*itemValue)/itemWeight;
//             int valueToAdd = ratio*capacity;
//             totalValue += valueToAdd;

//             // update capacity
//             capacity = 0;
//         }
//     }

//     cout <<"Answer is: "<<totalValue<<endl;
//     return 0;
// }



// Chocolate distribution problem
int main(){
    int n = 8;
    int m = 5;
    int arr[] = {3,4,1,9,56,7,9,12};
    sort(arr,arr+n);

    int i = 0;
    int j = m-1;
    int diff = INT_MAX;
    while(j<n){
        int newDiff = arr[j] - arr[i];
        diff = min(diff,newDiff);
        j++;
        i++;
    }
    cout<<"Answer is : "<<diff<<endl;
    return 0;
}