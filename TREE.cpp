#include <iostream>
#include <queue>
using namespace std;

int id = -1;  

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

Node* Insertation(int arr[], int n) {
    ++id;

    if (id >= n || arr[id] == -1) {
        return nullptr;
    }

    Node* newNode = new Node(arr[id]);
    cout << "Inserted Node: " << arr[id] << endl;

    newNode->left = Insertation(arr, n);
    newNode->right = Insertation(arr, n);

    return newNode;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << "->";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
  if(root == nullptr) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << "->"; 
}

void levelorder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}



void deleteDeepest(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left == delNode) {
                delete temp->left;
                temp->left = nullptr;
                return;
            } else {
                q.push(temp->left);
            }
        }

        if (temp->right) {
            if (temp->right == delNode) {
                delete temp->right;
                temp->right = nullptr;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

void deleteNode(Node* root, int key) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
            delete root;
            root = nullptr;
        }
        return;
    }

    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* temp;

    while (!q.empty()) {
        temp = q.front(); q.pop();

        if (temp->data == key) {
            keyNode = temp;
        }

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (keyNode) {
        int x = temp->data; 
        deleteDeepest(root, temp);
        keyNode->data = x;
    }
}








int main() {
    int arr[] = {1, 2, -1, -1, 3, 4, -1, -1}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = Insertation(arr, n);

    cout << "Inorder Traversal: ";
    inorder(root); 
    cout << endl;
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    
    cout << "Levelorder Traversal: ";
    levelorder(root);
    cout << endl;
    
     cout << "Deleted" << endl;
    int key = 3;
    deleteNode(root, key);
   
    
    cout << "Levelorder Traversal: ";
    levelorder(root);
    cout << endl;
 


    return 0;
}
