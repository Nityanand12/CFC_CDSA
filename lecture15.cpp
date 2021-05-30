#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void nextGreaterElementRandom(){
  // vector<int>arr={1,5,50,25,20,29,7};
  // stack<int>st;
  // for(int i=0;i<arr.size();i++){
  //   if(st.size()==0){
  //     st.push(arr[i]);
  //     continue;
  //   }
  //   while(st.size()!=0&&st.top()<arr[i]){
  //     cout<<"next greater element of "<<st.top()<<" is "<<arr[i]<<"\n";
  //     st.pop();
  //   }
  //   st.push(arr[i]);
  // }
  // while(st.size()!=0){
  //   cout<<"next greater element of "<<st.top()<<" is "<<-1<<"\n";
  //   st.pop();
  // }
}
void nextGreaterElement(){
  vector<int>arr={1,5,50,25,20,29,7};
  vector<int>myAns(arr.size(),0);
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      myAns[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    myAns[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<arr.size();i++){
    cout<<"next greater element of "<<arr[i]<<" is "<<myAns[i]<<"\n";
  }
}
void nextSmallerElement(){
  vector<int>arr={1,5,50,25,20,29,7};
  vector<int>myAns(arr.size(),0);
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      myAns[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    myAns[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<arr.size();i++){
    cout<<"next smaller element of "<<arr[i]<<" is "<<myAns[i]<<"\n";
  }
}
void previousGreaterElement(){
  vector<int>arr={1,5,50,25,20,29,7};
  vector<int>myAns(arr.size(),0);
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      myAns[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    myAns[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<arr.size();i++){
    cout<<"previous greater element of "<<arr[i]<<" is "<<myAns[i]<<"\n";
  }
}
void previousSmallerElement(){
  vector<int>arr={1,5,50,25,20,29,7};
  vector<int>myAns(arr.size(),0);
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      myAns[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    myAns[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<arr.size();i++){
    cout<<"previous smaller element of "<<arr[i]<<" is "<<myAns[i]<<"\n";
  }
}

class KhudKaQueue{
  public:
  int defaultSize=10;
  int *arr;
  int frnt ,rear,size;
  KhudKaQueue(){
    arr= new int[defaultSize];
    frnt=0;
    rear=-1;
    size=0;
  }
  bool isfull(){
    if(size==defaultSize) return true;
    return false;
  }
  int *resize(){
    int *newArr= new int[defaultSize*2];
    for(int i=0;i<defaultSize;i++){
      newArr[i]= arr[frnt%defaultSize];
      frnt++;
    }
    defaultSize=defaultSize*2;
    frnt=0;
    rear= size-1;
    return newArr;
  }
  void push(int data){
    if(isfull()){
      // cout<<"Queue is full"<<"\n";
      resize();
      // return;
    }
    size++;
    rear=(rear+1)%defaultSize;
    arr[rear]= data;
  }
  bool isEmpty(){
    if(size==0) return true;
    return false;
  }
  void pop(){
    if(isEmpty()){
      cout<<"Queue is empty"<<"\n";
      return; 
    }
    size--;
    frnt=(frnt+1)%defaultSize;
  }
  int front(){
    if(isEmpty()){
      cout<<"Queue is empty"<<"\n";
      return EXIT_FAILURE; 
    }
    return arr[frnt];
  }
  int back(){
    if(isEmpty()){
      cout<<"Queue is empty"<<"\n";
      return EXIT_FAILURE; 
    }
    return arr[rear];
  }
};








int main() {
  // nextGreaterElementRandom();
  // nextGreaterElement();
  // nextSmallerElement();
  // previousGreaterElement();
  // previousSmallerElement();
  // KhudKaQueue que;
  // que.push(10);
  // que.push(20);
  // que.push(30);
  // que.push(40);
  // que.push(50);
  // que.push(60);
  // que.push(70);
  // que.push(80);
  // que.push(90);
  // que.push(100);
  // que.push(110);
  // que.push(120);
  // cout<<que.front()<<"\n";
  // que.pop();
  // cout<<que.front()<<"\n";
  // cout<<que.back()<<"\n";


  // queue<int>que;
  // que.push(10);
  // que.push(20);
  // que.push(30);
  // que.push(40);
  // que.push(50);
  // que.push(60);
  // que.push(70);
  // que.push(80);
  // que.push(90);
  // que.push(100);
  // que.push(110);
  // que.push(120);
  // cout<<que.front()<<"\n";
  // que.pop();
  // cout<<que.front()<<"\n";
  // cout<<que.back()<<"\n";

  queue<string>q;
  int n=10;
  int cnt=1;
  q.push("1");
  while(cnt<n){
    string k= q.front();
    q.pop();
    cout<<k<<"\n";
    if(cnt+1<=n){
      cnt++;
      q.push(k+"0");
    }
    if(cnt+1<=n){
      cnt++;
      q.push(k+"1");
    }
  }
  while(q.size()!=0){
    cout<<q.front()<<"\n";
    q.pop();
  }
  return 0;
}
