#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
        Node(){}
};

class BST {
    public:
        Node* root;

        BST() {
            root = NULL;
        }

        Node* insert(Node* root,int value) {
            if(root == NULL) {
                root = new Node(value);
                return root;
            }

            if(root->data > value) {
                root->left = insert(root->left,value);
            }else {
                root->right = insert(root->right,value);
            }
            return root;
        }

        Node* insert_iter(Node* root,int *value,int n) {
            // int n = sizeof(value)/sizeof(value[0]);
            for(int i = 0; i < n; i++ ) {
                Node* node = new Node(value[i]);
                Node* parent = NULL;
                
                if (root == NULL) {
                    root = node;
                } else {
                    Node* ptr = root;

                    while(ptr != NULL) {
                        parent = ptr;
                        if(value[i] > ptr->data) {
                            ptr = ptr->right;
                        } else {
                            ptr = ptr->left;
                        }
                    }

                    if(value[i] > parent->data) {
                        parent->right = node;
                    } else {
                        parent->left = node;
                    }
                }
            }
            return root;
        }

        void inorder(Node* root) {
            if(root == NULL) {
                return;
            }
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        Node* deleteNode(Node* root,int val) {
            if(root == NULL) {
                return root;
            }

            if(root->data > val) {
                root->left = deleteNode(root->left,val);
            } else if(root->data < val) {
                root->right = deleteNode(root->right,val);
            } else { // if(root.data == val )
                // Case 1 : For leaf node
                if(root->left == NULL && root->right == NULL) {
                    return NULL;
                }

                // Case 2: For one child
                if(root->left == NULL) {
                    return root->right;
                } else if (root->right == NULL) {
                    return root->left;
                }

                // Case 3 : For Two child
                // 1. Find Inorder Successor
                Node* IS = findIS(root->right);
                cout << "Find IS" << endl;
                // 2. Replace value with inorder successor
                root->data = IS->data;
                // 3. Delete the Node of Inorder Successor
                root->right = deleteNode(root->right,IS->data);
            }
            return root;
        }

        Node* findIS(Node* root) {
            while(root->left != NULL) {
                root = root->left;
            }
            return root;
        }

        bool searchKey(Node* root,int key) {
            if(root == NULL) {
                return false;
            }

            if(root->data == key) {
                return true;
            }
            if(root->data > key) {
                return searchKey(root->left,key);
            } else  {
                return searchKey(root->right,key);
            }
            
        }


};
int main()
{
    int values[] = {5,1,3,4,2,7};
    /*
        BST :
                    5
                  /   \
                 1     7   
                  \  
                   3
                 /  \  
                2    4
    */

    BST* tree = new BST();
    // Insertion Using Iteration
    tree->root = tree->insert_iter(tree->root,values,5);
    // Insertion Using Recursion
    // for(int ele: values) {
    //     tree->root = tree->insert(tree->root,ele);
    // }
    tree->root = tree->deleteNode(tree->root,5);
    tree->inorder(tree->root);
    // cout << endl;
    // cout << tree->searchKey(tree->root,5);
    return 0;
}