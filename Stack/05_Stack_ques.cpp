#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// // Remove all adjacent duplicates from a string

// string removeDuplicates(string s) {
//     stack<char>st;
//     for(auto ch:s){
//         if(!st.empty() && st.top()==ch){
//             st.pop();
//         }else{
//             st.push(ch);
//         }
//     }

//     string ans;
//     while(!st.empty()){
//         ans += st.top();
//         st.pop();
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }

// int main(){
//     string s = "aabcdderf";
//     cout<<"Ans is : "<<removeDuplicates(s);

//     return 0;
// }



// // count the no of reversals required to make valid parenthesis

// int countRev (string s)
// {
//     // if odd sized string then impossible to make pairs
//     if(s.size() & 1) return -1;
    
//     int ans = 0;
//     stack<int>st;
//     for(char ch:s){
//         if(ch == '{'){
//             st.push(ch);
//         }
//         else{
//             if(!st.empty() && st.top() == '{'){
//                 st.pop();
//             }else{
//                 st.push(ch);
//             }
//         }
//     }
    
//     // if stack is still not empty,let's count reversals
//     while(!st.empty()){
//         char a = st.top();st.pop();
//         char b = st.top();st.pop();
        
//         if(a == b)
//             ans+=1;
            
//         else
//             ans+=2;
//     }
//     return ans;
// }

// int main(){
//     string s = "{{}}}}}{}}";
//     cout<<"The total no of reversals required are : "<<countRev(s);

//     return 0;
// }




// // Next greater node in linked list  leetcode

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

// vector<int> nextLargerNodes(ListNode* head) {
//         vector<int>ll;
//         while(head){
//             ll.push_back(head -> val);
//             head = head->next;
//         }

//         stack<int>st;
//         vector<int>ans(ll.size());

//         for(int i=0;i<ll.size();++i){
//             while(!st.empty() && ll[i]>ll[st.top()]){
//                 int kids = st.top();
//                 st.pop();
//                 ans[kids] = ll[i];
//             }
//             // index push krna h remember
//             st.push(i);
//         }
//         return ans;
// }



// // The Celebrity problem --> gfg


// int celebrity(vector<vector<int> >& M, int n) 
// {
//     stack<int>st;
    
//     // step1:push all persons into stack
//     for(int i=0;i<n;++i){
//         st.push(i);
//     }
    
//     // step2:run discard method,to get a mightBeCelebrity
//     while(st.size() != 1){
//         int a = st.top();st.pop();
//         int b = st.top();st.pop();
        
//         // if a knows b?
//         if(M[a][b]){
//             // a is not celebrity,b might be
//             st.push(b);
//         }else{
//             // b is not celebrity,a might be
//             st.push(a);
//         }
//     }
    
//     // step3:Check that a single person is actually celebrity?
//     int mightBeCelebrity = st.top();st.pop();
    
//     // Cel. should not know anyone
//     for(int i=0;i<n;i++){
//         if(M[mightBeCelebrity][i] != 0){
//             return -1;
//         }
//     }
    
//     // everyone should know Cel.
//     for(int i=0;i<n;i++){
//             // here second condition for diagonal elements
//         if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){
//             return -1;
//         }
//     }
    
//     // mightBeCelebrity is the cel.
//     return mightBeCelebrity;
// }




// // N Stack in an array

// class NStack{
//     int *a,*top,*next;
//     int n;      //no. of stacks
//     int size;   //size of main array
//     int freeSpot;   //tells free space in main memory

//     public:
//         NStack(int _n,int _s):
//         n(_n),size(_s){
//             freeSpot = 0;
//             a = new int[size];
//             top = new int[n];
//             next = new int[size];

//             for(int i = 0;i<n;i++){
//                 top[i] = -1;
//             }

//             for(int i = 0;i<size;i++){
//                 next[i] = i+1;
//             }
//             next[size - 1] = -1;
//         }

//         bool push(int X,int m){
//             if(freeSpot == -1){
//                 return false;  //stack overflow
//             }

//             // 1.find index
//             int index = freeSpot;

//             // 2.update freespot
//             freeSpot = next[index];

//             // 3.insert
//             a[index] = X;

//             // 4.update next
//             next[index] = top[m-1];

//             // 5.update top
//             top[m-1] = index;

//             return true;
//         }

//         int pop(int m){
//             if(top[m-1] == -1){
//                 return -1;
//             }

//             int index = top[m-1];
//             top[m-1] = next[index];
//             int poppedElement = a[index];
//             next[index] = freeSpot;
//             freeSpot = index;
//             return poppedElement;
//         }

//         ~NStack(){
//             delete[] a;
//             delete[] top;
//             delete[] next;
//         }
// };

// int main(){
//     NStack s(3,6);
//     cout<<s.push(10,1)<<endl;

//     cout<<"Popped element is "<<s.pop(1)<<endl;

//     return 0;
// }



// Online stock span   leetcode

// class StockSpanner {
// public:
//     stack<pair<int,int>>st;
    
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int span = 1;
//         while(!st.empty() && st.top().first <= price){
//             span += st.top().second;
//             st.pop();
//         }
//         st.push({price,span});
//         return span;
//     }
// };



// Simplify path    leetcode

void buildAns(stack<string>&s,string&ans){
    if(s.empty()){
        return;
    }
    string minPath = s.top();s.pop();
    buildAns(s,ans);
    ans += minPath;
}
string simplifyPath(string path) {
    stack<string>s;
    int i = 0;
    while(i<path.size()){
        int start = i;
        int end = i+1;
        while(end < path.size() && path[end] != '/'){
            ++end;
        }
        string minPath = path.substr(start,end-start);
        // substr contain two arguments from which part and how much length
        i = end;
        if(minPath == "/" || minPath == "/."){
            continue;
        }
        if(minPath != "/.."){
            s.push(minPath);
        }
        else if(!s.empty()){
            s.pop();
        }
    }
    string ans = s.empty() ? "/" : "";
    buildAns(s,ans);
    // this function is just use to reverse the string 
    return ans;
}


// // Decode string --> leetcode

// string decodeString(string s) {
//     stack<string>st;
//     for(auto ch:s){
//         if(ch == ']'){
//             string stringToRepeat = "";
//             while(!st.empty() && st.top() != "["){
//                 string top = st.top();
//                 stringToRepeat += top;
//                 st.pop();
//             }
//             st.pop();
//             string numericTimes = "";
//             while(!st.empty() && isdigit(st.top()[0])){
//                 numericTimes += st.top();
//                 st.pop();
//             }
//             reverse(numericTimes.begin(),numericTimes.end());
//             int n = stoi(numericTimes);

//             // final decoding
//             string currentdecode = "";
//             while(n--){
//                 currentdecode += stringToRepeat;
//             }
//             st.push(currentdecode);
//         }
//         else{
//             string temp(1,ch);
//             st.push(temp);
//         }
//     }
//     string ans;
//     while(!st.empty()){
//         ans += st.top();
//         st.pop();
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }




// Car fleet - leetcode


// class Solution{
//     class Car{
//         public:
//             int pos,speed;
//             Car(int p,int s):pos(p),speed(s){};
//     };
//     static bool myComp(Car&a,Car&b){
//         return a.pos<b.pos;
//     }
    
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         vector<Car>cars;
//         for(int i=0;i<position.size();++i){
//             Car car(position[i],speed[i]);
//             cars.push_back(car);
//         }
//         sort(cars.begin(),cars.end(),myComp);

//         stack<float>st;
//         for(auto car:cars){
//             float time = (target-car.pos)/((float) car.speed);
//             while(!st.empty() && time >= st.top()){
//                 st.pop();
//             }
//             st.push(time);
//         }
//         return st.size();
//     }
// };



// Car fleet 2 -- leetcode

// vector<double> getCollisionTimes(vector<vector<int>>& cars) {
//     vector<double>answer(cars.size(),-1);
//     stack<int>st;
//     for(int i=cars.size()-1;i>=0;--i){
//         // check if car ahead of current car is faster?
//         while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
//             st.pop();
//         }

//         while(!st.empty()){
//             double colTime = (double)(cars[st.top()][0] - cars[i][0])/(cars[i][1] - cars[st.top()][1]);
//             if(answer[st.top()] == -1 || colTime <= answer[st.top()]){
//                 answer[i] = colTime;
//                 break;
//             }
//             st.pop();
//         }
//         st.push(i);
//     }
//     return answer;
// }


// Max rectangle in a Binary matrix
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

int largestRectangleArea(vector<int>& height) {
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

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>>v;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;++i){
        vector<int>t;
        for(int j=0;j<m;++j){
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    int area = largestRectangleArea(v[0]);
    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){
            if(v[i][j]){
                v[i][j] += v[i-1][j];
            }
            else{
                v[i][j] = 0;
            }
        }
        area = max(area,largestRectangleArea(v[i]));
    }
    return area;
}