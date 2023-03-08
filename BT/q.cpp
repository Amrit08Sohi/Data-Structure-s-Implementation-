#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
    public:
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

int countNodes(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int sumNodes(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}


double ans;
void getAns(Node *root){
    if(root == NULL){
        return;
    }
    getAns(root->left);
    getAns(root->right);
    int sumOfSubtree = sumNodes(root);
    int nodesCount = countNodes(root);
    ans = max(ans,(double)sumOfSubtree/nodesCount);
}
double maxAvgNode(Node* root){
    getAns(root);
    return ans;
}

int main()
{
    // Node* root = new Node(20);

    // root->left = new Node(12);
    // root->right = new Node(18);

    // root->left->left = new Node(11);
    // root->left->right = new Node(3);

    // root->right->left = new Node(15);
    // root->right->right = new Node(8);

    Node *root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(0);
    cout << "Count of all nodes = " << countNodes(root) << endl;
    cout << "Sum of all nodes = " << sumNodes(root) << endl;;

    cout << maxAvgNode(root);

    return 0;
}