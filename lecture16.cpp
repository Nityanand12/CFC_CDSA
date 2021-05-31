#include<iostream>
using namespace std;
template <typename k>


// Leetcode 111. Minimum Depth of Binary Tree
// class Solution {
// public:
//     int fun(TreeNode* root){
//         if(root==nullptr) return INT_MAX;
//         if(root->left==nullptr&&root->right==nullptr) return 1;
//         return min(maxDepth(root->left),maxDepth(root->right))+1;
//     }
//     int minDepth(TreeNode* root) {
//         if(root==nullptr) return 0;
//         fun(root);
//     }
// };





// Leetcode 104. Maximum Depth of Binary Tree
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==nullptr) return 0;
//         return max(maxDepth(root->left),maxDepth(root->right))
//     }
// };



// Leetcode 145. Binary Tree Postorder Traversal
// class Solution {
// public:
//     void postorder(TreeNode* root,vector<int>&ans){
//         if(root==nullptr) return;
//         postorder(root->left,ans);
//         postorder(root->right,ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         postorder(root,ans);
//         return ans;
//     }
// };





// Leetcode 94. Binary Tree Inorder Traversal
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&ans){
//         if(root==nullptr) return;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         inorder(root,ans);
//         return ans;
//     }
// };




// Leetcode 144. Binary Tree Preorder Traversal
// class Solution {
// public:
//     void preorder(TreeNode* root,vector<int>&ans){
//         if(root==nullptr) return;
//         ans.push_back(root->val);
//         preorder(root->left,ans);
//         preorder(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         preorder(root,ans);
//         return ans;
//     }
// };



class BinaryTree{
  public:
  class Node{
    public:
    k value;
    Node *left;
    Node *right;
    Node(k value){
      this->value=value;
      left=nullptr;
      right=nullptr;
    }
  };
  Node *root=nullptr;
  Node *insert(Node *node, k value,string dirs,int idx){
    if(node==nullptr){
      Node *base= new Node(value);
      return base;
    }
    if(dirs.length()==idx){
      node->value=value;
      return node;
    }
    if(dirs[idx]=='L'){
      node->left= insert(node->left,value,dirs,idx+1);
    }
    else{
      node->right= insert(node->right,value,dirs,idx+1);
    }
    return node;
  }
  void insert(k value,string dirs){
    this->root=insert(root,value,dirs,0);
  }
  void display(Node *node){
    if(node==nullptr) return;
    if(node->left==nullptr) cout<<" -> ";
    else cout<<node->left->value<<" -> ";
    cout<<node->value;
    if(node->right==nullptr) cout<<" <- ";
    else cout<<" <- "<<node->right->value;
    cout<<"\n";
    display(node->left);
    display(node->right);
  }
  void display(){
    display(root);
  }
  bool find(k value,Node *node){
    if(node==nullptr) return false;
    if(node->value==value) return true;
    return find(value,node->left)||find(value,node->right);
  }
  bool find(k value){
    find(value,root);
  }
};
int main(){
  BinaryTree<string> bt;
  bt.insert("10","");
  bt.insert("14","L");
  bt.insert("18","R");
  bt.insert("19","LR");
  bt.insert("21","LRL");
  bt.insert("31","RL");
  bt.insert("37","LL");
  bt.display();
  cout<<bt.find("101")<<"\n";
}