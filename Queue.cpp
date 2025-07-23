#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
   

    Node(int value) : data(value), next(nullptr) {}
};



void enqueue(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued into queue.\n";
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr; 
    }

    cout << temp->data << " dequeued from queue.\n";
    delete temp;
}

void isEmpty(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }
}

void size(Node* front) {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Queue size: " << count << endl;
}




int main(){
    Node* front = nullptr;
    Node* rear = nullptr;
    
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);
    enqueue(front, rear,40);
    dequeue(front, rear);
    dequeue(front, rear);

    
      
}