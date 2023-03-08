#include<iostream>
using namespace std;
// template<typename T>
class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node* insertAtHead(Node*,int);
    Node* insertAtIdx(Node*, int,int);
    Node* insertInSorted(Node*, int);
    Node* insertAtTail(Node*,int);
    Node* deleteByidx(Node*,int);
    Node* reverseLL(Node*);
    Node* rev(Node*);
    void printLL(Node*);
    void printReverseLL(Node *);
};

Node* Node::deleteByidx(Node* head,int idx){
    if(idx == 1){
        Node* todel = head;
        head = head->next;
        delete todel;
        return head;
    }

    int i = 1;
    Node* temp = head;
    while (i!=idx-1)
    {
        i++;
        temp = temp->next;
    }
    Node* todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
    return head;

    
}
Node* Node::insertAtHead(Node* head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

//  1-base index
Node* Node::insertAtIdx(Node* head,int data,int pos){
    Node* newNode = new Node(data);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return head;
    }
    int i = 1;
    Node* temp = head;
    while (i!=pos-1)
    {
        i++;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* Node::insertInSorted(Node* head,int data){
    int pos = 1;
    Node* temp = head;
    // while(temp!=NULL){
    //     if(temp->data > data){
    //         break;
    //     }
    //     pos++;
    //     temp = temp->next;
    // }

    while (temp->data < data)
    {
        pos++;
        temp =temp->next;
    }
    

    return insertAtIdx(head,data,pos);
}

Node* Node::insertAtTail(Node *head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Reverse Linked List Using Iteration
Node* Node::reverseLL(Node* head){
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    while (curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

//   1 --> 2 --> 3 --> null
//   3 --> 2 --> 1 --> null

//   3-->2 --> null
//   3->2->1->null

//   1 --> 2 --> null
//   2 --> 1 --> null

Node* Node::rev(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void Node::printLL(Node* head){
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Node::printReverseLL(Node* head){
    if(head == NULL){
        return;
    }
    printReverseLL(head->next);
    cout << head->data << " ";
}
int main()
{
    Node* head = NULL;
    int data;
    char ch;
    do
    {   
        cout << "Enter the data" << endl;
        cin >> data;
        head = head->insertAtHead(head,data);
        cout << "Want to Continue" << endl;  
        cin >> ch;
        if(ch == 'n'){
            break;
        }
    }while(true);
    head->insertAtTail(head,200);
    cout << "Linked List" << endl;
    head->printLL(head);
    // head = head->rev(head);
    // cout << "Linked List After Reversing" << endl;
    // head = head->insertAtIdx(head,800,1);
    // head = head->insertInSorted(head,2);
    head = head->deleteByidx(head,1  );
    head->printLL(head);
    
    return 0;
}