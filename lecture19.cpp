#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapSack(vector<int> &wt, vector<int> &value, int pos, int cap)
{
  if (cap == 0 || pos == 0)
  {
    return 0;
  }
  int left = 0, right = 0;
  if (cap >= wt[pos - 1])
  {
    left = knapSack(wt, value, pos - 1, cap);
    right = knapSack(wt, value, pos - 1, cap - wt[pos - 1]) + value[pos - 1];
  }
  else
  {
    left = knapSack(wt, value, pos - 1, cap);
  }
  return max(left, right);
}
int knapSackMemoization(vector<int> &wt, vector<int> &value, int pos, int cap, vector<vector<int>> &dp)
{
  if (cap == 0 || pos == 0)
  {
    return dp[pos][cap] = 0;
  }
  if (dp[pos][cap] != -1)
  {
    return dp[pos][cap];
  }
  int left = 0, right = 0;
  if (cap >= wt[pos - 1])
  {
    left = knapSackMemoization(wt, value, pos - 1, cap, dp);
    right = knapSackMemoization(wt, value, pos - 1, cap - wt[pos - 1], dp) + value[pos - 1];
  }
  else
  {
    left = knapSackMemoization(wt, value, pos - 1, cap, dp);
  }
  return dp[pos][cap] = max(left, right);
}
int knapSackTabulation(vector<int> &weight, vector<int> &value, int cap, vector<vector<int>> &dp)
{
  for (int i = 0; i <= weight.size(); i++)
  {
    for (int j = 0; j <= cap; j++)
    {
      if (j == 0 || i == 0)
      {
        dp[i][j] = 0;
        continue;
      }
      int left = 0, right = 0;
      if (j >= weight[i - 1])
      {
        left = dp[i - 1][j];
        right = dp[i - 1][j - weight[i - 1]] + value[i - 1];
      }
      else
      {
        left = dp[i - 1][j];
      }
      dp[i][j] = max(left, right);
    }
  }
  return dp[dp.size() - 1][dp[0].size() - 1];
}
void knapSack()
{
  vector<int> wt = {3, 2, 5, 2};
  vector<int> value = {6, 7, 5, 11};
  int cap = 7;
  // cout<<knapSack(wt,value,wt.size(),cap)<<"\n";
  vector<vector<int>> dp(wt.size() + 1, vector<int>(cap + 1, -1));
  // cout<<knapSackMemoization(wt,value,wt.size(),cap,dp)<<"\n";
  cout << knapSackTabulation(wt, value, cap, dp) << "\n";
  for (int i = 0; i < dp.size(); i++)
  {
    for (int j = 0; j < dp[0].size(); j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}
int LCS_Memoization(string x,string y,int xPos,int yPos,vector<vector<int>>&dp){
  if(xPos==0||yPos==0){
    return dp[xPos][yPos]= 0;
  }
  if(dp[xPos][yPos]!=-1) return dp[xPos][yPos];
  int ans=0;
  if(x[xPos-1]==y[yPos-1]){
    ans= LCS_Memoization(x,y,xPos-1,yPos-1,dp)+1;
  }
  else{
    int a= LCS_Memoization(x,y,xPos-1,yPos,dp);
    int b= LCS_Memoization(x,y,xPos,yPos-1,dp);
    ans=max(a,b);
  }
  return dp[xPos][yPos]= ans;
}
void LCS(){
  string x="saturday";
  string y="sunday";
  vector<vector<int>>dp(x.length()+1,vector<int>(y.length()+1,-1));
  cout<<LCS_Memoization(x,y,x.length(),y.length(),dp)<<"\n";
}
int main()
{
  // knapSack();
  LCS();
}