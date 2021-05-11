#include<iostream>
#include<vector>
using namespace std;
void decreasing(int n){
  if(n==0){
    return ;
  }
  cout<<n<<" ";
  decreasing(n-1);
}
int fibonacci(int n){
  if(n==0||n==1) return n;
  int a= fibonacci(n-1);
  int b= fibonacci(n-2);
  return a+b;
}

void allSubsetWithoutReturnType(vector<int>&arr,string ans, int id){
  if(id==arr.size()){
    cout<<ans<<"\n";
    return;
  }
  allSubsetWithoutReturnType(arr,ans,id+1);
  allSubsetWithoutReturnType(arr,ans+to_string(arr[id])+" ",id+1);
}
void allSubsetWithoutReturnType(){
  vector<int>arr={1,2,3};
  allSubsetWithoutReturnType(arr,"",0);
}
vector<string> allSubsetWithReturnType(vector<int>&arr, int id){
  if(id==arr.size()){
    vector<string>base;
    base.push_back("");
    return base;
  }
  vector<string>ans= allSubsetWithReturnType(arr,id+1);
  vector<string>fans;
  for(int i=0;i<ans.size();i++){
    fans.push_back(ans[i]);
  }
  for(int i=0;i<ans.size();i++){
    fans.push_back(to_string(arr[id])+ans[i]);
  }
  return fans;
}

void allSubsetWithReturnType(){
  vector<int>arr={1,2,3};
  vector<string>ans=  allSubsetWithReturnType(arr,0);
  
  for(string ele: ans){
    cout<<ele<<"\n";
  }
}
void type1(vector<int>&arr,int target,string ans,int sum){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }

  for(int i=0;i<arr.size();i++){
    if(sum+arr[i]<=target){
      type1(arr,target,ans+to_string(arr[i]),sum+arr[i]);
    }
  }
}
void type2(vector<int>&arr,int target,string ans,int sum, int id){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }

  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=target){
      type2(arr,target,ans+to_string(arr[i]),sum+arr[i],i);
    }
  }
}
void type1(){
  vector<int>arr={1,2,3};
  int tar=6;
  type1(arr,tar,"",0);
}
void type2(){
  vector<int>arr={1,2,3};
  int tar=6;
  type2(arr,tar,"",0,0);
}
int main(){
  // decreasing(6);
  // cout<<"\n";
  // cout<<fibonacci(6)<<"\n";
  // allSubsetWithoutReturnType();
  allSubsetWithReturnType();

  // type1();//permutation with repitition
  // type2();// combination with repitition
}