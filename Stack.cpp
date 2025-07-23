#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
   

    Node(int value) : data(value), next(nullptr) {}
};

void push (Node*& Top, int value, int& size) {
  Node* newNode = new Node(value);
  newNode -> next = Top;
  Top = newNode;

  cout << value << " Top is Added Successfully" << endl;
  
  size++;
  
}

void pop(Node*& Top, int& size) {
    if (Top == nullptr) {
        cout << "Stack Underflow!\n";
        return;
    }
    Node* temp = Top;
    Top = Top->next;
    cout << temp->data << " popped from stack.\n";
    delete temp;
    size--;
}


bool isEmpty(Node* Top){
  return Top == nullptr;
}

void print(Node* Top) {
    if (Top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    Node* temp = Top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void size(Node* Top) {
    if (Top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    Node* temp = Top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}





int main(){
    Node* Top = nullptr;
    int size = 0;
    
    push(Top, 10 , size);
    push(Top, 20, size);
    push(Top, 30, size);
    
    pop(Top, size);
    
    
    print(Top);
    
        if (isEmpty(Top)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }
    
    cout << "Current Stack Size: " << size << endl;
    
}