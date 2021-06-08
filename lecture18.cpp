#include<iostream>
#include<vector>
using namespace std;
int fibonacciMemoization(int n,vector<int>&dp){
  if(n==0||n==1) return n;
  if(dp[n]!=0) return dp[n];
  int left= fibonacciMemoization(n-1,dp);
  int right= fibonacciMemoization(n-2,dp);
  return dp[n]= left+right;
}
int fibonacciTabulation(vector<int>&dp,int n){
  for(int i=0;i<=n;i++){
    if(i<=1){
      dp[i]=i;
    }
    else{
      dp[i]= dp[i-1]+dp[i-2];
    }
  }
  return dp[n];
}
void fibonacci(){
  int n=6;
  vector<int>dp(n+1,0);
  cout<<fibonacciMemoization(n,dp)<<"\n";
  cout<<fibonacciTabulation(dp,n)<<"\n";
}
int climbStairMemoization(int target, vector<int>&dp,int myPos){
  if(myPos>target){
    return 0;
  }
  if(myPos==target){
    return dp[myPos]=1;
  }
  if(dp[myPos]!=0) return dp[myPos];
  int a= climbStairMemoization(target,dp,myPos+1);
  int b= climbStairMemoization(target,dp,myPos+2);
  int c= climbStairMemoization(target,dp,myPos+3);
  // for(int i=1;i<=3;i++){
  //   a=a+climbStairMemoization(target,dp,myPos+i);
  // }
  return dp[myPos]= a+b+c;
}
int climbStairTabulation(int target,vector<int>&dp){
  dp[dp.size()-1]=1;
  for(int i=dp.size()-2;i>=0;i--){
    int sum=0;
    if(i+1<dp.size()) sum+= dp[i+1];
    if(i+2<dp.size()) sum+= dp[i+2];
    if(i+3<dp.size()) sum+= dp[i+3];
    dp[i]= sum;
  }
  return dp[0];
}
void climbStair(){
  int target=7;
  vector<int>dp(target+1,0);
  cout<<climbStairMemoization(target,dp,0)<<"\n";
   cout<<climbStairTabulation(target,dp)<<"\n";
}
void LIS(){
  int ans=1;
  vector<int>arr={3,5,6,10,1,100,14,15,7,9,11};
  vector<int>dp(arr.size()+1,1);
  for(int i=0;i<arr.size();i++){
    for(int j=i-1;j>=0;j--){
      if(arr[i]>arr[j]){
        dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
      }
    }
  }
  cout<<ans<<"\n";
}
int main(){
  // fibonacci();
  // climbStair();
  LIS();
}