#include<iostream>
#include "Suspect.h"
using namespace std;


class AVL{
public:
    struct Node{
        Suspect data;
        int ht;
        Node* left;
        Node* right;

        Node(Suspect d){
            data = d;
            ht = 0;
            left = right = nullptr;
        }
    };

    Node* root;

    AVL(){
        root = nullptr;
    }

    int height(Node* T){ 
        int lh,rh; 
        if(T==NULL) 
            return(0); 
        if(T->left==NULL) 
            lh=0; 
        else 
            lh=1+T->left->ht; 
        if(T->right==NULL) 
            rh=0; 
        else 
            rh=1+T->right->ht;
        if(lh>rh) 
            return(lh); 
        else
            return(rh); 
    }

    int BalanceFactor(Node* T){
        int lh, rh;
        if(T==NULL)
            return 0;
        if(T->left==NULL)
            lh = 0;
        else
            lh = 1 + T->left->ht;

        if(T->right==NULL)
            rh = 0;
        else
            rh = 1 + T->right->ht;

        return (lh-rh);
    }

    Node* RotateRight(Node* x){
        Node* y;
        y = x->left;
        x->left = y->right;
        y->right = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    Node* RotateLeft(Node* x){
        Node* y;
        y = x->right;
        x->right = y->left;
        y->left = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    Node* LR_rotation(Node* T){
        Node* temp = RotateLeft(T->left);
        T->left = temp;
        T = RotateRight(T);
        return T;
    }

    Node* RL_rotation(Node* T){
        Node* temp = RotateRight(T->right);
        T->right = temp;
        T = RotateLeft(T);
        return T;
    }

    Node* insert(Node* node,Suspect s){
        if(node == NULL)
            return new Node(s);
        else if(s.id > node->data.id){
            if(node->right){
                node->right = insert(node->right,s);
            }
            else{
                node->right = new Node(s);
            }
        }
        else if(s.id < node->data.id){
            if(node->left){
                node->left = insert(node->left, s); 
            }
            else{
                node->left = new Node(s);
            }
        }
        else if(s.id == node->data.id){
            cout << "Duplicate ID not allowed!\n";
            return node;
        }

        // Update height
        node->ht = height(node);

        // Get balance factor
        int bf = BalanceFactor(node);

        // LL Case
        if (bf > 1 && s.id < node->left->data.id){
            node = RotateRight(node);
        }

        // RR Case
        else if (bf < -1 && s.id > node->right->data.id){
            node = RotateLeft(node);
        }

        // LR Case
        else if (bf > 1 && s.id > node->left->data.id) {
            node = LR_rotation(node);
        }

        // RL Case
        else if (bf < -1 && s.id < node->right->data.id) {
            node = RL_rotation(node);
        }
        return node;
    }

    Node* search(int id){
        if(root == NULL){
            cout<<"Suspect not found!"<<endl;
            return nullptr;
        }
        else{
            Node* temp = root;
            while(temp != NULL){
                if(id == temp->data.id){
                    return temp;
                }
                else if(id < temp->data.id){
                    temp = temp->left;
                }
                else if(id > temp->data.id){
                    temp = temp->right;
                }
            }
            cout<<"Suspect not found!"<<endl;
            return nullptr;
        }
    }

    Node* deleteNode(Node* node, int id){
        if(node == NULL){
            cout << "Suspect not found!\n";
            return node;
        }

        if(id < node->data.id){
            node->left = deleteNode(node->left, id);
        }
        else if(id > node->data.id){
            node->right = deleteNode(node->right, id);
        }
        else {
            // Case 1: No child or 1 child
            if(node->left == NULL || node->right == NULL){
                Node* temp = (node->left) ? node->left : node->right;

                // No child
                if(temp == NULL){
                    temp = node;
                    node = NULL;
                }
                else {
                    // One child → copy child data
                    *node = *temp;
                }

                delete temp;
            }

            // Case 2: 2 children
            else{
                // Find inorder successor
                Node* temp = node->right;
                while(temp->left != NULL)
                    temp = temp->left;

                // Replace current node with successor
                node->data = temp->data;

                // Delete successor
                node->right = deleteNode(node->right, temp->data.id);
            }
        }

        // If tree had only one node
        if(node == NULL) return node;

        // Step 2: Update height
        node->ht = height(node);

        // Step 3: Check balance factor
        int bf = BalanceFactor(node);

        // Rebalance using 4 AVL cases

        // LL Case
        if(bf > 1 && BalanceFactor(node->left) >= 0)
            return RotateRight(node);

        // LR Case
        if(bf > 1 && BalanceFactor(node->left) < 0){
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // RR Case
        if(bf < -1 && BalanceFactor(node->right) <= 0)
            return RotateLeft(node);

        // RL Case
        if(bf < -1 && BalanceFactor(node->right) > 0){
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void insertSuspect(Suspect s){
        root = insert(root, s);
    }

    void deleteSuspect(int id){
        root = deleteNode(root, id);
    }

    void displayAllSuspects(){
        inorder_traversal(root);
    }

    void inorder_traversal(Node* node){
        if(node){
            inorder_traversal(node->left);
            node->data.display();
            inorder_traversal(node->right);
        }
    }
};
