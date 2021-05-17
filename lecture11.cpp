#include <iostream>
#include <vector>
using namespace std;
vector<string> ratInMazeWithReturnType(int sr,int sc,int er,int ec){
  if(sr==er&&sc==ec){
    vector<string>base;
    base.push_back("");
    return base;
  }
  vector<string>ans;
  if(sc+1<=ec){
    vector<string> east= ratInMazeWithReturnType(sr,sc+1,er,ec);
    for(string element: east){
      ans.push_back("H"+element);
    }
  }
  if(sr+1<=er){
    vector<string> south= ratInMazeWithReturnType(sr+1,sc,er,ec);
    for(string element: south){
      ans.push_back("V"+element);
    }
  }
  return ans;
}

void ratInMazeWithReturnType(){
  vector<string>ans= ratInMazeWithReturnType(0,0,2,2);
  for(string element: ans){
    cout<<element<<"\n";
  }
  cout<<"\n";
}
void nokiaKeyPad(vector<string>& arr,string st,string ans,int id){
  if(id==st.length()){
    cout<<ans<<"\n";
    return;
  }
  char ch= st[id];
  for(int i=0;i<arr[ch-'0'].length();i++){
    nokiaKeyPad(arr,st,ans+arr[ch-'0'][i],id+1);
  }
}

void nokiaKeyPad(){
  vector<string> arr= {"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz","/*+"};
  string st="123";
  nokiaKeyPad(arr, st, "",0);
}

bool isSafeForQueen(vector<vector<int>>&board, int row,int col){
  // row decrease ho rha h aur column increase ho rha h
  for(int i=row,j=col;i>=0&&j<board[0].size();i--,j++){
    if(board[i][j]==1){
      return false;
    }
  }
  // row decrease ho rha h aur column bhi decrease ho rha h
  for(int i=row,j=col;i>=0&&j>=0;i--,j--){
    if(board[i][j]==1){
      return false;
    }
  }
  // row decrease ho rha h
  for(int i=row;i>=0;i--){
    if(board[i][col]==1){
      return false;
    }
  }
  return true;
}
void display(vector<vector<int>>&board){
  for(int i=0;i<board.size();i++){
    for(int j=0;j<board[0].size();j++){
      cout<<board[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void nqueen(vector<vector<int>>&board, int row){
  if(row==board.size()){
    display(board);
    cout<<"\n";
    return ;
  }
  
  for(int col=0;col<board[0].size();col++){
    if(isSafeForQueen(board,row,col)){
      board[row][col]=1;
      nqueen(board,row+1);
      board[row][col]=0;
    }
  }
}
void nqueen(){
  vector<vector<int>>board(4,vector<int>(4,0));
  nqueen(board,0);
}
bool isSafeForSudoku(vector<vector<int>>&board,int row,int col,int val){
  // entire row
  for(int i=0;i<board.size();i++){
    if(board[i][col]==val){
      return false;
    }
  }
  // entire column
  for(int i=0;i<board[0].size();i++){
    if(board[row][i]==val){
      return false;
    }
  }
  // entire box
  row=(row/3)*3;
  col=(col/3)*3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i+row][j+col]==val){
        return false;
      }
    }
  }
  return true;

}
void sudoku(vector<vector<int>>&board,int row,int col){
  if(row==board.size()-1&&col==board[0].size()){
    display(board);
    cout<<"\n";
    return ;
  }
  if(col==board[0].size()){
    row=row+1;
    col=0;
  }
  if(board[row][col]!=0){
    sudoku(board,row,col+1);
  }
  else{
    for(int val=1;val<=9;val++){
      if(isSafeForSudoku(board,row,col,val)){
        board[row][col]=val;
        sudoku(board,row,col+1);
        board[row][col]=0;
      }
    }
  }
}
void sudoku(){
  vector<vector<int>>board={{5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},
  {8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},
  {0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9}};
  sudoku(board,0,0);
}
int main() {
  // ratInMazeWithReturnType();
  // nokiaKeyPad();
  // nqueen();
  sudoku();
}