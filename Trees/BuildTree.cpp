#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};  
class BT {
    public: 
        Node* root;
        int idx;

        BT(){
            root = NULL;
            idx = -1;
        }

        Node* buildTreePreorder(int node[]){
            idx++;
            if(node[idx] == -1) {
                return NULL;
            }

            Node* newNode = new Node(node[idx]);
            newNode->left = buildTreePreorder(node);
            newNode->right = buildTreePreorder(node);
            return newNode;
        }


        void preorderRec(Node* root) {
            if(root == NULL) {
                // cout << -1 << " ";
                return;
            }
            cout << root->data << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }

        void preorderIter(Node* root) {
            if(root == NULL) {
                return ;
            }
            stack<Node*> st;
            st.push(root);

            while(!st.empty()) {
                Node* node = st.top();
                cout << node->data << " ";
                st.pop();
                if(node->right != NULL) {
                    st.push(node->right);
                }
                //else{
                //     cout << -1 << " ";
                // }
                if(node->left != NULL) {
                    st.push(node->left);
                }
                //else{
                //     cout << -1 << " ";
                // }
            }
        }

        void postorderIter(Node* root) {
            if(root == NULL) {
                return ;
            }
            stack<Node*> st;
            st.push(root);
            Node* prev = NULL;
            while(!st.empty()) {
                Node* current = st.top();

                if(prev == NULL || prev->left == current || prev->right == current) {
                    if(current->left != NULL) {
                        st.push(current->left);
                    }else if(current->right != NULL) {
                        st.push(current->right);
                    }else {
                        st.pop();
                        cout << current->data << " ";
                    }
                } else if(current->left == prev) {
                    if(current->right != NULL) {
                        st.push(current->right);
                    }else{
                        st.pop();
                        cout << current->data << " ";
                    }
                }else if(current->right == prev) {
                    st.pop();
                    cout << current->data << " ";
                }
                prev = current;
            }

        }

};
int main()
{
    BT* tree = new BT;
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    tree->root = tree->buildTreePreorder(nodes);
    tree->preorderRec(tree->root);
    cout << endl;
    tree->preorderIter(tree->root);
    cout << endl;
    tree->postorderIter(tree->root);  
    return 0;
}