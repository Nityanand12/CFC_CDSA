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