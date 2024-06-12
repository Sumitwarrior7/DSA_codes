#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        // Constructor
        Node(int data) {
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }

};

/* -----------------------------------------------------------------------Insertion Operations-----------------------------------------------------------------------*/
void insert_at_head(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insert_at_tail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insert_at_position(Node* &head, Node* &tail, int pos, int data) {
    // Insert at start
    if (pos == 1) {
        insert_at_head(head, data);
        return;
    }

    Node* back = NULL;
    Node* curr = head;

    int i = 1;
    while (i < pos) {
        back = curr;
        curr = curr -> next;
        i += 1;
    }

    // Insert at end
    if (curr == tail) {
        insert_at_tail(tail, data);
        return;
    }

    // Insert at any pos
    Node* new_node = new Node(data);
    curr -> prev = new_node;
    new_node -> next = curr;
    back -> next = new_node;
    new_node -> prev = back;

}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


void deleteNode(int position, Node* & head) { 
    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}



int main() {
    Node* node1 = new Node(3);

    Node* head = node1; 
    Node* tail = node1;

    insert_at_head(head, 2);
    insert_at_head(head, 1);

    insert_at_tail(tail, 4);
    insert_at_tail(tail, 5);

    insert_at_position(head, tail, 3, 7);

    print(head);

    return 0;
}
