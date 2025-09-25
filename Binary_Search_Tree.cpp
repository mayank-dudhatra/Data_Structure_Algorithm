#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;  

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


Node* insertion(Node* root, int k) {
    if (root == nullptr) {
        return new Node(k);
    }

    if (k < root->data) {
        root->left = insertion(root->left, k);
    } else if (k > root->data) {
        root->right = insertion(root->right, k);
    }

    return root;
}

Node* searchLeaf(Node* root){
  if(root->right == nullptr) return root;
  
  return searchLeaf(root->right);
}

Node* remainNode(Node* root){
  if(root->left == nullptr) return root->right;
  if(root->right == nullptr) return root->left;
  
  Node* rightNode = root->right;
  Node* leftrightNode = searchLeaf(root->left);
  
  leftrightNode->right = rightNode;
  
  return root->left;
  
}


Node* deleteNode (Node* root, int k){
  if(root == nullptr) return nullptr;
  
  if(root -> data == k) return remainNode(root);
  
  Node* temp = root;
  
  while(temp!=nullptr){
    
    if(temp->data >k){
      
      if(temp->left!=nullptr && temp->left->data == k){
        temp->left = remainNode(temp->left);
        break;
      }
       else{
         temp=temp->left;
       }
       
    }
     else if(temp->data < k) {
       
       if(temp->right!=nullptr && temp->right->data == k){
        temp->right = remainNode(temp->right);
        break;
      }
       else{
         temp=temp->right;
       }
       
     }
  }
  return root;
}





// Inorder traversal
void inorder(Node* root) {
    if (root == nullptr) return;  

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertion(root, 10);
    insertion(root, 5);
     insertion(root, 15);
     insertion(root, 3);
     insertion(root, 7);
     
      deleteNode(root, 15);
      
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "NULL" << endl;
    
    

    return 0;
}
