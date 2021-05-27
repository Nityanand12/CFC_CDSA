#include<iostream>
#include<stack>
using namespace std;
class vehicle{
  public:
  int wheels;
  int mileage;
  vehicle(){

  }
  void move(){
    cout<<"Vehicle can move forward as well as backward"<<"\n";
  }
  virtual void tyre(int n){
    cout<<"Vehicle has "<<n<<" tyre"<<"\n";
  }
  void tyre(int n,int m){
    cout<<"Vehicle has "<<n<<" black tyre and "<<m<<" White tyre"<<"\n";
  }
};
class bus : public vehicle{
  public:
  void busSeat(){
    cout<<" Bus has 10 seat"<<"\n";
  }
  void move(){
    cout<<"Bus can move forward as well as backward"<<"\n";
  }
  void tyre(int n){
    cout<<"Bus has "<<n<<" tyre"<<"\n";
  }
};


// Leetcode 206. Reverse Linked List
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *prev=nullptr,*curr=head,*forw=head;
//         whivle(forw!=nullptr){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
// };




// Leetcode 876. Middle of the Linked List
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if(head==nullptr){
//             return nullptr;
//         }
//         ListNode *slow=head,*fast=head;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
            
//     }
// };


// Leetcode 141. Linked List Cycle
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//          if(head==nullptr) return false;
//         ListNode *slow=head,*fast=head;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast) return true;
//         }
//         return false;
//     }
// };





// Leetcode 160. Intersection of Two Linked Lists
// class Solution {
// public:
//     ListNode *ManageSize(ListNode *head,int cnt){
//         while(cnt>0){
//             cnt--;
//             head=head->next;
//         }
//         return head;
//     }
//     int length(ListNode *head){
//         int cnt=0;
//         while(head!=nullptr){
//             head=head->next;
//             cnt++;
//         }
//         return cnt;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int l1= length(headA);
//         int l2= length(headB);
//         if(l1>l2) headA= ManageSize(headA,l1-l2);
//         if(l2>l1) headB= ManageSize(headB,l2-l1);
//         while(headA!=headB){
//             headA=headA->next;
//             headB=headB->next;
//         }
//         return headA;
//     }
    
// };




class Node {
  public:
  int data;
  Node *next;
  Node(int data){
    this->data=data;
    next=nullptr;
  }
};
class CustomLikedList{
  public:
  int size;
  Node *head;
  Node *tail;
  CustomLikedList(){
    size=0;
    head=nullptr;
    tail=nullptr;
  }
  void addLast(int data){
    Node *newNode= new Node(data);
    if(size==0){
      tail=newNode;
      head=newNode;
    }
    else{
      tail->next=newNode;
      tail=newNode;
    }
    size++;
  }
  void addFirst(int data){
    if(size==0){
      addLast(data);
      return;
    }
    Node *newNode= new Node(data);
    newNode->next=head;
    head=newNode;
    size++;
  }
  int removeLast(){
    if(size==0){
      cout<<"LinkedList is Empty"<<"\n";
      return EXIT_FAILURE;
    }
    size--;
    if(head->next==nullptr){
      int p= head->data;
      head=nullptr;
      tail=nullptr;
      return p;
    }
    Node *k=head;
    while(k->next!=tail){
      k=k->next;
    }
    int p= tail->data;
    k->next=nullptr;
    tail=k;
    return p;
  }
  int removeFirst(){
    if(head==nullptr){
      cout<<"LinkedList is Empty"<<"\n";
      return EXIT_FAILURE;
    }
    if(head->next==nullptr){
      return removeLast();
    }
    int p= head->data;
    head=head->next;
    return p;
  }
  void display(){
    Node *k= head;
    while(k!=nullptr){
      cout<<k->data<<"\n";
      k=k->next;
    }
  }

};
int main(){
  // vehicle *v1= new vehicle();
  // v1->tyre(5);
  // bus *b1= new bus();
  // b1->tyre(5);
  // vehicle *v2= new bus();
  // v2->tyre(5);
  // v2->move();


  CustomLikedList ll;
  ll.addFirst(10);
  ll.addFirst(20);
  ll.addFirst(30);
  ll.addLast(50);
  ll.addLast(70);
  ll.addFirst(100);
  // ll.display();
  ll.removeFirst();
  ll.removeFirst();
  ll.removeLast();
  ll.display();
  
  return 0;
}