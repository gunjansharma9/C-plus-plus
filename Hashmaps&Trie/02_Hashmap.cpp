// we are using array for the implementation of hashmap

// Hash function ek aisi layer hai jha input mein aap kuch dete ho or vo btata hai isko array k konse index se map krna hai

// hash function 2 cheejo se milkr bna hota hai ek hota hai Hash code or ek hota hai compression function

// hash code ek aise function hai jo tumhari key ko numeric part m convert krne ka kaam krta h -> hash code is basically responsible for conversion

// hash code jo numeric digit generate krta hai ho skta hai vo array ki range mein na ho toh usko range m laane ka kaam compression function krta hai

// Collision Handling
// 1 -> Open Hashing -> in this we attached linked list
// 2 -> Closed Addresing -> in this we find next free index -> it can be linear probing , quadratic probing

// no of element denoted by n
// no of free boxes denoted by b
// if ratio n/b is less than 0.7 then it is a good hash function and this ratio is called Load Factor

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// bool checkCircular(Node* head){
//     unordered_map<Node*,bool>vis;
//     Node* temp = head;

//     while(temp != NULL){
//         if(vis.find(temp) != vis.end()){
//             vis[temp] = true;
//         }
//         else{
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

int main(){
    string str = "thiruvananthapuram";
    unordered_map<char,int>freq;

    for(int i=0;i<str.length();i++){
        char ch = str[i];
        freq[ch]++;
    }

    for(auto i:freq){
        cout<<i.first<<" "<<i.second<<endl;
    }
}


// Array Subset of another array -> gfg
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>map;
    string ans = "Yes";
    
    // map hashing using a1
    for(int i=0;i<n;i++){
        map[a1[i]]++;
    }
    
    // check whether all elements of a2 present in a1
    for(int i=0;i<m;++i){
        if(map.find(a2[i]) == map.end()){
            ans = "No";
            break;
        }
        else{
            // present
            if(map[a2[i]] > 0){
                map[a2[i]]--;
            }
            else{
                ans = "No";
                break;
            }
        }
    }
    return ans;
}


// Union of Two Linked Lists -> gfg
// isme hm occurence isliye store kr rhe hai taki sbki occurence k basis pr hi hm match kre naaki only present k basis pr

// struct Node* makeUnion(struct Node* head1, struct Node* head2)
// {
// //element ko ushi k node k saath map kraya taki sidha ll return kr ske
//     map<int,Node*>map;
//     Node* curr = head1;
    
// //   L1 hashed
//     while(curr){
//         map[curr->data] = curr;
//         curr = curr->next;
//     }
//     curr = head2;
    
// //   L2 hashed
//     while(curr){
//         map[curr->data] = curr;
//         curr = curr->next;
//     }
    
//     Node* UL = NULL;
//     curr = 0;
// //   iterate map & make final UL
//     for(auto it=map.begin();it != map.end();it++){
//         if(!UL){
//             UL = it->second;
//             curr = UL;
//         }
//         else{
//             curr->next = it->second;
//             curr = curr->next;
//         }
//     }
//     // last node
//     curr -> next = 0;
//     return UL;
// }


// Intersection of Two LL
// list1 mein jis order mein hai elements ushi order ko maintain krna hai
// map mein phela int kya store krega value ko dusra int store krega occurence ko

// Node* findIntersection(Node* head1, Node* head2)
// {
//     unordered_map<int,int>map;
//     Node* curr = head2;
//     // hash L2 items
//     while(curr){
//         map[curr->data]++;
//         curr = curr -> next;
//     }

//     Node* IL = NULL;
//     Node* it = 0;
//     curr = head1;

//     while(curr){
//         if(map.find(curr->data) != map.end()){
//             // node val found in L2
//             if(!IL){
//                 IL = curr;
//                 it = IL;
//             }
//             else{
//                 if(map[curr->data] > 0){
//                     it->next = curr;
//                     it = it->next;
//                     map[curr->data]--;
//                 }
//             }
//         }
//         curr = curr->next;
//     }
//     it->next = NULL;
//     return IL;
// }



// Sum equals to Sum -> gfg

int findPairs(long long a[], long long n)
{
    unordered_map<int,bool>map;
    // pairs
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i]+a[j];
            // sum nikalo agr vo phele se map se store hai toh pairs exists kr rhe hai toh true return kr jao 
            if(map.find(sum) != map.end()){
                return true;
            }
            else{
                map[sum] = true;
            }
        }
    }
    
    return false;
}


// Largest subarray with 0 sum
int maxLen(vector<int>&A, int n)
{   
    unordered_map<int,int>map;
    int csum = 0;
    int ans = 0; //max length of subarray with 0 sum
    for(int i=0;i<n;i++){
        csum += A[i];
        if(csum == 0){
            // agr hmne zero index se start kra or sum zero ho gya
            ans = max(ans,i+1);
        }
        else if(map.find(csum) == map.end()){
            // agr sum exist nhi kr rha toh index store krlo
            map[csum] = i;
        }
        else{
            // agr vo vala sum phele se exist kr rha hai toh
            // map has csum already
            ans = max(ans,i-map[csum]);
        }
    }
    return ans;
}


// Largest Subarray of 0's and 1's
int maxLen(int A[], int n)
{
    unordered_map<int,int>map;
    int csum = 0;
    int ans = 0; //max length of subarray with 0 sum
    for(int i=0;i<n;++i){
        // saare 0's ko 1 se replace krdo phir phele vale ques ki trh logic
        int val = A[i] == 0 ? -1 : 1;
        csum += val;
        if(csum == 0){
            ans = max(ans,i+1);
        }
        else if(map.find(csum) == map.end()){
            map[csum] = i;
        }
        else{
            // map has csum already
            ans = max(ans,i-map[csum]);
        }
    }
    return ans;
}