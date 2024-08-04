#include "bits/stdc++.h"
using namespace std;

// Get Node value -> hackerRank

// void fun(SinglyLinkedListNode* head,int &positionFromTail,int &ans){
//     if(head == 0) return;
//     fun(head->next,positionFromTail,ans);
   
//     if(positionFromTail == 0){
//         ans = head->data;
//     }
//     positionFromTail--;
// }
// int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
//     int ans = -1;
//     fun(llist,positionFromTail,ans);
//     return ans;
// }



// // 160. Intersection of Two Linked Lists(at which value ll are getting intersection)
// // phele find kro konsi linked list bdi hai or kitni bdi hai,find krne k baad bigger linked list ko aage se start kro jitni vo bdi hai utni aage se
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* a = headA;
//         ListNode* b = headB;

//         while(a->next && b->next){
//             if(a == b){
//                 return a;
//             }
//             a = a->next;
//             b = b->next;
//         }

//         if(a->next == 0 && b->next == 0 && a != b) return 0;
       
//         if(a->next == 0){
//             // B LL is bigger
//             // we need to find out how much bigger it is
//             int blen = 0;
//             while(b->next){
//                 blen++;
//                 b = b->next;
//             }
//             while(blen--){
//                 headB = headB->next;
//             }
//         }
//         else{
//             // A LL is larger
//             int alen = 0;
//             while(a->next){
//                 alen++;
//                 a = a->next;
//             }
//             while(alen--){
//                 headA = headA->next;
//             }
//         }
//         while(headA != headB){
//             headA = headA -> next;
//             headB = headB -> next;
//         }
//         return headA;
//     }
// };


// 21. Merge Two Sorted Lists
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
//         if(left == 0) return right;
//         if(right == 0) return left;
//         ListNode* ans = new ListNode(-1);
//         ListNode* mptr = ans;

//         while(left && right){
//             if(left->val <= right->val){
//                 mptr->next = left;
//                 mptr = left;
//                 left = left->next;
//             }
//             else{
//                 mptr->next = right;
//                 mptr = right;
//                 right = right -> next;
//             }
//         }
//         if(left){
//             mptr->next = left;
//         }
//         if(right){
//             mptr->next = right;
//         }
//         return ans->next;
//         // bcoz first value -1 hai na isliye
//     }
// };



// // 148. Sort List

// class Solution {
// public:
//     ListNode* findMid(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* merge(ListNode* left, ListNode* right) {
//         if(left == 0) return right;
//         if(right == 0) return left;

//         ListNode* ans = new ListNode(-1);
//         ListNode* mptr = ans;

//         while(left && right){
//             if(left->val <= right->val){
//                 mptr->next = left;
//                 mptr = left;
//                 left = left->next;
//             }
//             else{
//                 mptr->next = right;
//                 mptr = right;
//                 right = right -> next;
//             }
//         }
//         if(left){
//             mptr->next = left;
//         }
//         if(right){
//             mptr->next = right;
//         }
//         return ans->next;
//     }

//     ListNode* sortList(ListNode* head) {
//         if(head == 0 || head->next == 0){
//             return head;
//         }

//         // Break LL into two halves using mid node
//         ListNode* mid = findMid(head);
//         ListNode* left = head;
//         ListNode* right = mid->next;
//         mid->next = 0;

//         // sort RE
//         left = sortList(left);
//         right = sortList(right);

//         // merge both left and right
//         ListNode* mergedLL = merge(left,right);
//         return mergedLL;
//     }
// };



// // Flattening a Linked List -> gfg
// Node* merge(Node*a,Node*b){
//     if(!a) return b;
//     if(!b) return a;
   
//     Node* ans = 0;
//     if(a->data < b->data){
//         ans = a;
//         a->bottom = merge(a->bottom,b);
//     }else{
//         ans = b;
//         b->bottom = merge(a,b->bottom);
//     }
//     return ans;
// }
// Node *flatten(Node *root)
// {
//     if(!root) return 0;
//     Node* mergedLL = merge(root,flatten(root->next));
// //piche se merge kr rhe hai taki links save na krne pde
//     return mergedLL;
// }

// // 138. Copy List with Random Pointer
// class Solution {
// public:
//     Node* helper(Node* head,unordered_map<Node*,Node*>&mp){
//         if(head == 0) return 0;

//         Node* newHead = new Node(head->val);
//         mp[head] = newHead;
//         newHead->next = helper(head->next,mp);
//         if(head->random){
//             newHead->random = mp[head->random];
//         }
//         return newHead;
//     }
//     Node* copyRandomList(Node* head) {
//         // // solution 1 with space complexity-O(n)
//         // unordered_map<Node*,Node*>mp;
//         // // old node --> new node ki mapping
//         // return helper(head,mp);

//         // // Solution 2 without using map
//         if(!head) return 0;
//         // Step 1:Clone A -> A'
//         Node* it = head; //iterate over old head
//         while(it){
//             Node* clonedNode = new Node(it->val);
//             clonedNode->next = it->next;
//             it->next = clonedNode;
//             it = it->next->next;
//         }

//         // Step2 : Assign random links of A' with the helper A
//         it = head;
//         while(it){
//             Node* clonedNode = it->next;
//             clonedNode->random = it->random ? it->random->next : nullptr;
//             it = it->next->next;
//         }

//         // Step3 : Detach A' with A
//         it = head;
//         Node* clonedHead = it->next;
//         while(it){
//             Node* clonedNode = it->next;
//             it->next = it->next->next;

//             if(clonedNode->next){
//                 clonedNode->next = clonedNode->next->next;
//             }
//             it = it->next;
//         }
//         return clonedHead;
//     }

// };


// //                             61. Rotate List
// class Solution {
// public:
//     int getLength(ListNode* head){
//         int len = 0;
//         while(head){
//             len++;
//             head = head->next;
//         }
//         return len;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(!head) return 0;

//         int len = getLength(head);
//         int actualKValue = (k%len);
//         if(actualKValue == 0) return head;
//         int newLastNodePos = len-actualKValue-1;
//         ListNode* newLastNode = head;
//         for(int i=0;i<newLastNodePos;i++){
//             newLastNode = newLastNode->next;
//         }
//         ListNode* newHeadNode = newLastNode->next;
//         newLastNode->next = 0;
//         ListNode* it = newHeadNode;
//         while(it->next){
//             it = it->next;
//         }
//         it -> next = head;
//         return newHeadNode;
//     }
// };


// //Delete N nodes after M nodes of a linked list -> gfg
// class Solution
// {
//     public:
//     void linkdelete(struct Node **head, int M, int N)
//     {
//         if(!head) return;
//         Node* it = head;
//         for(int i=0;i<M-1;i++){
//             // if M nodes are not available
//             if(!it) return ;
//             it = it->next;
//         }
//        
//         // it->would be at Mth node
//         if(!it) return;
//         Node* MthNode = it;
//         it = MthNode -> next;
//         for(int i=0;i<N;i++){
//             if(!it) break;
//             Node* temp = it->next;
//             delete it;
//             it = temp;
//         }
//         MthNode -> next = it;
//         linkdelete(it,M,N);
//     }
// };


// //2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> ans = {-1, -1}; //minDist,maxDist
//         ListNode* prev = head;
//         if(!prev) return ans;
//         ListNode* curr = head->next;
//         if(!curr) return ans;
//         ListNode* nxt = head->next->next;
//         if(!nxt) return ans;
//
//         int firstCP = -1;
//         int lastCP = -1;
//         int minDist = INT_MAX;
//         int i = 1;
//         while(nxt){
//             bool isCP = ((curr->val > prev->val && curr->val > nxt->val) || 
//                         (curr->val < prev->val && curr->val < nxt->val))
//                         ? true : false;
//             if(isCP && firstCP == -1){
//                 firstCP = i;
//                 lastCP = i;
//             }
//             else if(isCP){
//                 minDist = min(minDist,i - lastCP);
//                 lastCP = i;
//             }
//             ++i;
//             prev = prev->next;
//             curr = curr->next;
//             nxt  = nxt->next;
//         }
//         if(lastCP == firstCP){
//             // only 1 CP was found;
//             return ans;
//         }else{
//             ans[0] = minDist;
//             ans[1] = lastCP - firstCP;
//         }
//         return ans;
//     }
// };


// // 2181. Merge Nodes in Between Zeros
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         if(!head) return 0;
//         ListNode* slow = head,*fast = head->next,*newLastNode = 0;
//         int sum = 0;
//         while(fast){
//             if(fast->val != 0){
//                 sum += fast->val;
//             }else{
//                 // fast->val == 0
//                 slow->val = sum;
//                 newLastNode = slow;
//                 slow = slow->next;
//                 sum = 0;
//             }
//             fast = fast->next;
//         }
//         // just formed new list
//         newLastNode->next = 0;
//
//         // Deleting old list
//         while(slow){
//             ListNode* nxt = slow -> next;
//             delete slow;
//             slow = nxt;
//         }
//         return head;
//     }
// };

