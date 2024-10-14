#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int d) {
    // New node creation
    Node* temp = new Node(d);
    temp->next = head; 
    head = temp; 
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // To add a new line after printing the list
}

int main() {
    Node* node1 = new Node(10);
    cout << "Initial node data: " << node1->data << endl;
    cout << "Initial node next: " << node1->next << endl;
    
    Node* head = node1;
    print(head);
    
    InsertAtHead(head, 12);
    print(head);
    
    InsertAtHead(head, 15);
    print(head);
    
    return 0;
}
