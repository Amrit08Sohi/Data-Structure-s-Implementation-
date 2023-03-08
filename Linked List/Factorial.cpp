#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void multiply(Node * head,int num){
    Node* temp = head;
    Node* prev = head;
    int carry = 0;
    while(temp!=NULL){
        int val = num * temp->data + carry;
        temp->data = val%10;
        carry = val/10;
        prev = temp;
        temp = temp->next;
    }
    while (carry!=0)
    {
        prev->next = new Node(carry%10);
        carry = carry/10;
        prev = prev->next;
    }
    
}

/*
        1  <--  2 <-- 0
                  X   6
        7  <--  2 <-- 0

        2 <--- 4
               5
    1<---2 <--- 0

*/

void printLL(Node * head){
    if(head == nullptr){
        return;
    }
    printLL(head->next);
    cout << head->data;
}
int main()
{
    int n;
    cout << "Enter the number whose factorial you want" << endl;
    cin >> n;
    Node* head = new Node(1);
    for(int i = 2; i <= n; i++){
        multiply(head,i);
    } 
    printLL(head);
    return 0;
}