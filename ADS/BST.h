#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T> class BST{
    private:

    struct Node{
        T data;
        Node* left;
        Node* right;
        Node(const T &val, Node *lt,Node *rt) : data(val), left(lt), right(rt) {}
    };
    Node* root;

    void insert(const T &val, Node* &t ){
        if(t == nullptr)
        t = new Node(val , nullptr, nullptr);
        else if(val < t->data)
        insert(val,t->left);
        else if(val > t->data)
        insert(val,t->right);
    }
    bool search(const T &val,Node* t) const{
        if(t== nullptr)
        return false;
        if(val < t->data)
        return search(val,t->left);
        else if(val > t->data)
        return search(val,t->right);
        else 
        return true;
    }
    void inorder(Node* t) const{
        if(t== nullptr)
        return;
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
    void makeEmpty(Node* &t){
        if(t == nullptr)
        return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
    void preorder(Node* t) const{
        if(t == nullptr)
        return;
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
    void postorder(Node* t) const{
        if(t == nullptr)
        return;
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }

    public:
    BST() : root(nullptr) {}
    ~BST(){
        makeEmpty(root);
    }
    void insert(const T &val){
        insert(val,root);
    }
    bool search(const T &val) const{
        return search(val,root);
    }
    void inorder() const{
        inorder(root);
        cout<<endl;
    }
    void postorder() const{
        postorder(root);
        cout<<endl;
    }
    void preorder() const{
        preorder(root);
        cout<<endl;
    }
};
#endif