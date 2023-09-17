#include <bits/stdc++.h>
using namespace std;
// segregate LL by even and odd positions
class Node
{
public:
    int value;
    Node *next;
    Node(int value) : value(value), next(nullptr){};
};
Node *oddEvenLinkedList(Node *head) {
    Node* evenNodeHead = new Node(-1);
    Node* ptr1 = evenNodeHead;
    Node* oddNodeHead = new Node(-1);
    Node* ptr2 = oddNodeHead;

    Node* temp = head;
    int i = 1;
    while(temp!=NULL) {
        if(i%2!=0) { // odd position
            ptr2->next = temp;
            ptr2 = ptr2->next; 
        } else { // even position
            ptr1->next = temp;
            ptr1 = ptr1->next;
        }
        i++;
        temp = temp->next;
    }
    // Handle the case when the number of nodes are odd
    ptr1->next = nullptr;
    // join odd index LL to even index LL
    ptr2->next = evenNodeHead->next;
    // return new Head
    return oddNodeHead->next;

}
int main()
{
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(-2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(7);
    // // head->next->next->next->next->next = new Node(5);
    head = oddEvenLinkedList(head);
    Node* temp = head;
    while(temp!=nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    return 0;
}