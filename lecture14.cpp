#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class KhudkaStack{
  public:
  int defaultSize=500000;
  int *arr;
  int peek=-1;
  KhudkaStack(){
    arr= new int[defaultSize];
    peek=-1;
  }
  int *resize(){
    defaultSize=defaultSize*2;
    int *newArr= new int[defaultSize];
    for(int i=0;i<=peek;i++){
      newArr[i]= arr[i];
    }
    return newArr;
  }
  void push(int data){
    if(peek+1==defaultSize){
      arr= resize();
      // cout<<"Stack Overflow"<<"\n";
      return;
    }
    peek=peek+1;
    arr[peek]=data;
  }
  int pop(){
    if(peek==-1){
      cout<<"stack underflow"<<"\n";
      return EXIT_FAILURE;
    }
    int k= arr[peek];
    peek=peek-1;
    return k;
  }
  int top(){
    if(peek==-1){
      cout<<"stack underflow"<<"\n";
      return EXIT_FAILURE;
    }
    return arr[peek];
  }
  int size(){
    return peek+1;
  }

};






void balancedParanthesis(){
  string s="{{}{}[()]}";
  cout<<balancedParanthesis(s)<<"\n";
}
char openBracket(char ch){
  if(ch=='(') return ')';
  if(ch=='{') return '}';
   return ']';
}
bool balancedParanthesis(string s){
  if(s.length()==0) return true;
  stack<int>st;
  for(int i=0;i<s.length();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
      st.push(i);
    }
    else{
      if(s[i]==openBracket(s[st.top()])){
        st.pop();
      }
      else{
        return false;
      }
    }
  }
  return st.size()==0;
}


void nextGreaterElement(){
  vector<int>arr={2,50,60,30,100,16,17,21};
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(i==0){
      st.push(arr[i]);
      continue;
    }
    while(st.size()!=0&&st.top()<arr[i]){
      cout<<"next greater element of "<<st.top()<<" is "<<arr[i]<<"\n";
      st.pop();
    }
    st.push(arr[i]);
  }
  while(st.size()!=0){
    cout<<"next greater element of "<<st.top()<<" is "<<-1<<"\n";
    st.pop();
  }
}

int main(){
  // KhudkaStack st;
  // st.push(10);
  // st.push(20);
  // st.push(30);
  // cout<<st.pop()<<"\n";
  // st.push(40);
  // st.push(50);
  // st.push(60);
  // st.push(70);
  // cout<<st.size()<<"\n";
  // cout<<st.pop()<<"\n";
  // cout<<st.top()<<"\n";
  // cout<<st.size()<<"\n";


  // stack<int>st;
  // st.push(10);
  // st.push(20);
  // st.push(30);
  // st.push(40);
  // st.push(50);
  // st.push(60);
  // cout<<st.top()<<"\n";
  // st.pop();
  // st.pop();
  // st.push(100);
  // cout<<st.size()<<"\n";


  // balancedParanthesis();
  // nextGreaterElement();
}