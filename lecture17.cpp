#include<iostream>
using namespace std;
// template<typename k>







// Leetcode 543. Diameter of Binary Tree
// class Solution {
// public:
//     int ans=0;
//     int diameter(TreeNode* root){
//         if(root==nullptr) return -1;
//         int left= diameter(root->left);
//         int right= diameter(root->right);
//         ans=max(ans,left+right+2);
//         return max(left,right)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         diameter(root);
//         return ans;
//     }
// };









// Leetcode 450. Delete Node in a BST
// class Solution {
// public:
//     int minimum(TreeNode* root){
//         if(root->left==nullptr) return root->val;
//         return minimum(root->left);
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//        if(root==nullptr) return nullptr;
//         if(root->val==key){
//             if(root->left==nullptr&&root->right==nullptr){
//                 return nullptr;
//             }
//             else if(root->left!=nullptr&&root->right!=nullptr){
//                 int value= minimum(root->right);
//                 root->val=value;
//                 root->right=deleteNode(root->right,value);
//             }
//             else if(root->right!=nullptr){
//                 return root->right;
//             }
//             else{
//                 return root->left;
//             }
//         }
//         if(root->val>key){
//             root->left=deleteNode(root->left,key);
//         }
//         else{
//             root->right=deleteNode(root->right,key);
//         }
//         return root;
//     }
// };








class BinarySearchTree{
    public:
    class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node(int value){
      this->value=value;
      left=nullptr;
      right=nullptr;
    }
  };
    Node *root=nullptr;
    Node *insert(Node *node, int value){
    if(node==nullptr){
      Node *base= new Node(value);
      return base;
    }
    if(node->value<=value){
      node->right=  insert(node->right,value);
    }
    else{
        node->left=  insert(node->left,value);
    }
    return node;
  }
  void insert(int value){
    root=insert(root,value);
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
  bool find(int value,Node *node){
    if(node==nullptr) return false;
    if(node->value==value) return true;
    if(node->value<value){
      return  find(value,node->right);
    }
    else{
       return find(value,node->left);
    }
  }
  bool find(int value){
   return find(value,root);
  }
};
int main(){
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(8);
    bst.insert(16);
    bst.insert(10);
    bst.insert(20);
    bst.insert(6);
    bst.insert(13);
    bst.display();
    cout<<bst.find(20)<<"\n";
    return 0;
}

