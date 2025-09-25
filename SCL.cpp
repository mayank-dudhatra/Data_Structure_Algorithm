#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr) , prev(nullptr) {}
};

void insertNodeDL(Node*& Head, int value) {
    Node* newNode = new Node(value);

    if (Head == nullptr) {
        Head = newNode;
    } else {
        Node* ptr = Head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            cout << ptr->data << endl;
        }
        ptr->next = newNode;
        newNode->prev = ptr ; 
    }
}

void insertStartNodeDL(Node*& Head, int value){
  Node* newNode= new Node(value);
  newNode->next = Head;
  
  if(Head != nullptr){
    Head->prev = newNode ;
  }
  
  Head = newNode ;
}




void printListDL(Node* Head) {
    Node* temp = Head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void printListReverseDL(Node* Head) {
    Node* temp = Head;

    if (temp == nullptr) return;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}


int main(){
    Node* Head = nullptr;
    
    insertNodeDL(Head,10);
    insertNodeDL(Head,20);
    insertNodeDL(Head,30);
    insertNodeDL(Head,40);
    
    insertStartNodeDL(Head, 80);
    // insertBtwNode(Head,999,20);
    // deletionLast(Head);
    // deletionBtw(Head,20);
    // deleteFirst(Head);
    printListDL(Head);
    printListReverseDL(Head);
}