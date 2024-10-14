#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        if (tail == NULL) {
            tail = head;
        }
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, d);
    } else {
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    print(head); // Initially, the list is empty

    insertAtTail(tail, 12);
    head = tail; // Since list was empty, head should now point to the new tail
    print(head);

    insertAtHead(head, 15);
    if (tail == NULL) {
        tail = head;
    }
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}
