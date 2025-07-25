#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
        child = nullptr;
    }
};

// Flatten Function
Node* flatten(Node* head) {
    if (!head) return nullptr;

    stack<Node*> st;
    Node* current = head;

    while (current) {
        if (current->child) {
            if (current->next) {
                st.push(current->next);
            }

            current->next = current->child;
            current->next->prev = current;
            current->child = nullptr;
        }

        if (!current->next && !st.empty()) {
            current->next = st.top();
            st.top()->prev = current;
            st.pop();
        }

        current = current->next;
    }

    return head;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;

    
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    node7->next = node8;
    node8->prev = node7;

    node3->child = node7;

  
    Node* flatHead = flatten(head);

    cout << "Flattened List: ";
    printList(flatHead);

    return 0;
}
