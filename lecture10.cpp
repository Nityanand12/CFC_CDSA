#include<iostream>
#include<vector>
using namespace std;
void combinationWithoutRepitition(vector<int>&arr,int sum,int id,string ans,int tar){
  if(sum==tar){
    cout<<ans<<"\n";
    return;
  }
  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=tar)
    combinationWithoutRepitition(arr,sum+arr[i],i+1,ans+to_string(arr[i])+" ",tar);
  }
}
void combinationWithoutRepitition(){
  vector<int>arr={1,2,3};
  combinationWithoutRepitition(arr,0,0,"",3);
}
void permutationWithoutRepitition(vector<int>&arr,int sum,string ans,int tar,vector<int>&vis){
  if(sum==tar){
    cout<<ans<<"\n";
    return;
  }
  for(int i=0;i<arr.size();i++){
    if(sum+arr[i]<=tar&&vis[i]==0){
      vis[i]=1;
      permutationWithoutRepitition(arr,sum+arr[i],ans+to_string(arr[i]),tar,vis);
      vis[i]=0;
    }
  }
}

void permutationWithoutRepitition(){
  vector<int>arr={1,2,3};
  vector<int>vis(arr.size(),0);
  permutationWithoutRepitition(arr,0,"",3,vis);
}
void ratInMazeWithoutReturnType(int sr,int sc,int er,int ec,string ans){
  if(sr==er&&sc==ec){
    cout<<ans<<"\n";
    return;
  }
  if(sr+1<=er)
  ratInMazeWithoutReturnType(sr+1,sc,er,ec,ans+"H");
  if(sc+1<=ec)
  ratInMazeWithoutReturnType(sr,sc+1,er,ec,ans+"V");
}
void ratInMazeWithoutReturnType(){
  ratInMazeWithoutReturnType(0,0,2,2,"");
}
int main(){
  // combinationWithoutRepitition();
  // permutationWithoutRepitition();
  ratInMazeWithoutReturnType();
  return 0;
}