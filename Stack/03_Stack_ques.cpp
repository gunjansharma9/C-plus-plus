#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// void printMiddleElement(stack <int> &s,int totalSize){     
//     if(s.size() == 0){
//         cout<<"Stack is empty"<<endl;
//         return;
//     }

//     // base case
//     if(s.size() == totalSize/2 + 1){
//         cout<<"Middle element is : "<<s.top()<<endl;
//         return;
//     }

//     int temp = s.top();
//     s.pop();

//     printMiddleElement(s,totalSize);

//     // backtrack
//     s.push(temp);
// }

// int main(){
//     stack <int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.push(6);
//     s.push(7);

//     int totalSize = s.size();
//     printMiddleElement(s, totalSize);
//     return 0;
// }


// Insert topmost element at the bottom of the stack

// void insertAtBottom(stack<int>&s,int target){

//     if(s.empty()){
//         s.push(target);
//         return;
//     }

//     int temp = s.top();
//     s.pop();

//     insertAtBottom(s,target);
    
//     s.push(temp);
// }

// int main(){
//     stack<int> s;
//     s.push(10);
//     s.push(14);
//     s.push(13);
//     s.push(50);
//     s.push(60);
//     s.push(67);
//     s.push(19);

//     if(s.empty()){
//         cout<<"Stack is empty"<<endl;    
//     }

//     int target = s.top();
//     s.pop();
//     insertAtBottom(s,target);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }

//     return 0;
// }


// // Reverse a stack
// void insertAtBottom(stack<int>&s,int target){

//     if(s.empty()){
//         s.push(target);
//         return;
//     }

//     int temp = s.top();
//     s.pop();

//     insertAtBottom(s,target);
    
//     s.push(temp);
// }

// void reverseStack(stack<int>&s){
//     if(s.empty()){
//         return;
//     }

//     int target = s.top();
//     s.pop();

//     reverseStack(s);

//     insertAtBottom(s,target);
// }

// int main(){
//     stack<int>s;

//     s.push(4);
//     s.push(56);
//     s.push(12);

//     reverseStack(s);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     return 0;
// }


// valid parenthesis or not

// bool isValid(string s) {
//     stack<char>st;

//     for(int i=0;i<s.length();i++){
//         char ch = s[i];

//         // opening bracket
//         if(ch=='{' || ch=='(' || ch=='['){
//             st.push(ch);
//         }else{
//             if(!st.empty()){
//                 char topCh = st.top();
//                 if(ch == ')' && topCh == '('){
//                     st.pop();
//                 }else if(ch==']' && topCh=='['){
//                     st.pop();
//                 }else if(ch=='}' && topCh=='{'){
//                     st.pop();
//                 }else{
//                     return false;
//                 }
//             }else{
//                 return false;
//             }
//         }
//     }
//     if(st.empty()){
//         return true;
//     }else{
//         return false;
//     }
// }



// // sort element of a stack

// void insertSorted(stack<int>&s,int target){
//     if(s.empty()){
//         s.push(target);
//         return;
//     }
//     // base case
//     if(s.top() >= target){
//         s.push(target);
//         return;
//     }

//     int topElement = s.top();
//     s.pop();
//     insertSorted(s,target);

//     s.push(topElement);
// }

// void sortStack(stack<int>&s){
//     // base case
//     if(s.empty()){
//         return;
//     }
//     int topElement = s.top();
//     s.pop();

//     sortStack(s);

//     insertSorted(s,topElement);
// }

// int main(){
//     stack<int>s;
//     s.push(4);
//     s.push(5);
//     s.push(57);
//     s.push(25);
//     s.push(51);
//     s.push(56);
//     s.push(59);

//     sortStack(s);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     return 0;
// }


// // is redundant brackets or not

// bool isRedundant(string &str){
//     stack<char>s;
//     for (int i=0;i<str.length();i++){
//         char ch = str[i];

//         if(ch == '(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
//             s.push(ch);
//         }else{
//             // ch ya toh ')' hai or lowercase letter
//             if(ch == ')'){  
//                 bool isRedundant = true;
//                 while(s.top() != '('){
//                     char top = s.top();
//                     if(top == '+' || top=='-' || top=='*' || top=='/'){
//                         isRedundant = false;
//                     }
//                     s.pop();
//                 }

//                 if(isRedundant == true){
//                     return true;
//                 }
//                 s.pop();
//             }
//         }
//     }
//     return false;
// }





