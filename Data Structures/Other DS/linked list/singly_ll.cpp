#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        // Constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        // Destructor
        ~Node() {
            int value = this -> data;
            //memory free
            if(this->next != NULL) {
                delete next;
                this->next = NULL;
            }
            cout << " memory is free for node with data " << value << endl;
        }
};


void print(Node* &head) {
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }

    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

/* -----------------------------------------------------------------------Insertion Operations-----------------------------------------------------------------------*/
void insertAtHead(Node* &head, int data) {
    // new node create
    Node* temp = new Node(data);

    temp -> next = head;
    // Now temp will be our new Head
    head = temp; 
}

void insertAtTail(Node* &tail, int data) {
     // new node create
    Node* temp = new Node(data);

    tail -> next = temp;
    // Now temp will be our new Tail
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {
    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }


    // Storing that node in temp, after which the new node has to be inserted
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    // Inserting at position except last position
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void deleteNode(int position, Node* & head) { 
    // Deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        // Storing the node to be deleted in the curr
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}


bool detectLoop(Node* head) {
    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  
    return slow;
}

void removeLoop(Node* head) {
    if( head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 
    temp -> next = NULL;
}


/* Linked List Reversal */
// Iterative
Node* reverse_iterative(Node* head) {
    Node* back = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* fw = curr -> next;
        curr -> next = back;
        back = curr;
        curr = fw;
    }
    return back;
}

// Recursive
pair<Node*, Node*> reverse(Node* head, Node* new_head) {
    if (head -> next == NULL) {
        new_head = head;
        return make_pair(new_head, head);
    } 

    pair<Node*, Node*> fw = reverse(head -> next, NULL);
    head -> next = NULL;
    fw.second -> next = head;
    return make_pair(fw.first, head);
}


int main() {
    //created a new node
    Node* node1 = new Node(1);

    Node* head = node1; 
    Node* tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    
    print(head);

    // pair<Node*, Node*> rev = reverse(head, NULL);
    // print(rev.first);

    Node* rev_iter = reverse_iterative(head);
    print(rev_iter);

    return 0;
}