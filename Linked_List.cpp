#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertNode(Node*& Head, int value) {
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
    }
}


void insertStartNode(Node*& Head,int value){
    Node* newNode = new Node(value);
    Node* second = Head;
    Head = newNode;
    
    Head->next = second ;
}

void insertBtwNode(Node*& Head, int value,int after){
    Node* newNode = new Node(value);
    Node* box = Head ;
    Node* last ;
    
    while(box->next != nullptr){
        if(box->data == after){
            last = box->next;
            box->next =newNode;
            newNode->next = last ;
        }
        box = box->next;
    }
}

void deletionBtw(Node*& Head, int value){
    Node* box = Head ;
    while(box->next != nullptr){
        if(box->next->data == value){
            box->next = box->next->next;
        }
        box = box->next;
    }
}

void deletionLast(Node*& Head){
    
    Node* box = Head;
    if(box == nullptr){
        return ;
    }
    
    if(box -> next == nullptr){
        Head = nullptr;
        return;
    }
    while(box->next != nullptr){
        if(box->next->next == nullptr){
            box->next = nullptr;
            break;
        }
        box = box->next;
    }
}

void deleteFirst(Node*& Head){
    Node* Box = Head;
    Box = Head->next->next ;
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){
    Node* Head = nullptr;
    
    insertNode(Head,10);
    insertNode(Head,20);
    insertNode(Head,30);
    insertNode(Head,40);
    
    insertStartNode(Head, 80);
    insertBtwNode(Head,999,20);
    deletionLast(Head);
    deletionBtw(Head,20);
    deleteFirst(Head);
    printList(Head);
}