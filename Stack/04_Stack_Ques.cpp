#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

// Min Stack - perform push ,pop,getminElement,getTop element from stack in constant time

// class MinStack{
//     public:
//     vector <pair<int,int>>st;

//     MinStack(){

//     }

//     void push(int val){
//         if(st.empty()){
//             pair<int,int> p = make_pair(val,val);
//             st.push_back(p);
//         }else{
//             pair<int,int>p;
//             p.first = val;
//             p.second = min(val,st.back().second);
//             st.push_back(p);
//         }
//     }

//     void pop(){
//         st.pop_back();
//     }

//     int top(){
//         return st.back().first;
//     }

//     int getMin(){
//         return st.back().second;
//     }

// };

// int main(){
//     MinStack s;
//     s.push(4);
//     s.push(3);
    
//     cout<<"Minimum element is : "<<s.getMin();

//     return 0;
// }



// // Return maximum length of valid parenthesis

// int longestValidParentheses(string &s) {
//     stack<int>st;

//     st.push(-1);

//     int maxLen = 0;
//     for(int i=0;i<s.length();i++){
//         char ch = s[i];
//         if(ch == '('){
//             st.push(i);
//         }else{
//             st.pop();
//             if(st.empty()){
//                 st.push(i);
//             }else{
//                 int len = i - st.top();
//                 maxLen = max(len,maxLen);
//             }
//         }
//     }
//     return maxLen;
// }

// int main(){
//     string s = ")(())";
//     cout<<"The max length of valid parenthesis is : "<<longestValidParentheses(s);
//     return 0;
// }



// next smaller element for every element of an array

// vector<int> nextSmaller(vector<int>&v){
//     stack<int>s;
//     s.push(-1);
//     vector<int>ans(v.size());
//     for(int i=v.size()-1;i>=0;i--){
//         int curr = v[i];
//         while(s.top() >= curr){
//             s.pop();
//         }
//         ans[i] = s.top();
//         s.push(curr);
//     }   
//     return ans;
// }
// int main(){
//     vector<int>v;
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(4);
//     v.push_back(6);
//     v.push_back(3);
//     vector<int>ans;
//     ans = nextSmaller(v);

//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }

//     return 0;
// }


// // prev smaller element

// vector<int>prevSmaller(vector<int>&v){
//     stack<int>s;
//     s.push(-1);

//     vector<int>ans(v.size());
//     for(int i=0;i<v.size();i++){
//         int curr = v[i];
        
//         while(s.top() >= curr){
//             s.pop();
//         }

//         ans[i] = s.top();

//         s.push(curr);
//     }
//     return ans;
// }

// int main(){
//     vector<int>v;
//     v.push_back(3);
//     v.push_back(1);
//     v.push_back(5);
//     v.push_back(4);
//     v.push_back(7);

//     vector<int>ans;

//     ans = prevSmaller(v);

//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }

//     return 0;
// }


// Largest area in the histogram

vector<int>prevSmallerIndex(vector<int>v){
    stack<int>s;
    s.push(-1);

    vector<int>ans(v.size());
    for(int i=0;i<v.size();i++){
        int curr = v[i];
        
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerIndex(vector<int>v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }   
    return ans;
}

int getRectangularAreaHistogram(vector<int>&height){
    int size = height.size();

    // prev smaller output
    vector<int> prev = prevSmallerIndex(height);

    // next smaller output
    vector<int> next = nextSmallerIndex(height);

    int maxArea = INT_MIN;

    for(int i=0;i<height.size();i++){
        int length = height[i];

        if(next[i] == -1){
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea,area);
    }

    return maxArea;
}

int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout<<"Ans is : "<<getRectangularAreaHistogram(v)<<endl;

    return 0;
}