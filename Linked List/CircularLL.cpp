#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
    }

    static Node* tail;
    Node* insert(Node* head,int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            newNode->next = newNode;
            head = newNode;
            tail = head;
            return tail;
        }    
        newNode->next = head;
        tail->next = newNode;
        return newNode;
    }

    void deleteByVal(Node* &head,int val){
        if(head->data == val){
            Node* todelete = head; 
            head = head->next;
            tail->next = head;
            delete todelete;
            return;
        }

        Node *temp = head;
        while(temp->next->data != val){
            temp = temp->next;
        } 
        if(temp->next == tail){
            Node* todelete = temp->next;
            tail = temp;
            temp->next = temp->next->next;
            delete todelete;
            return;
        }
        Node* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }



    void printLL(Node* head){
        Node* temp = head;
        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp!=head);
    }
};
Node* Node::tail = NULL;
int main()
{
    Node* head = NULL;
    head = head->insert(head,100);
    head = head->insert(head,200);
    head = head->insert(head,300);
    head = head->insert(head,400);
    head->deleteByVal(head,100);
    head->deleteByVal(head,200);
    head = head->insert(head,4000);
    head = head->insert(head,40000);
    head->printLL(head);

    return 0;
}