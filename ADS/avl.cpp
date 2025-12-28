#include<iostream>
#include<algorithm>
using namespace std;

template <typename T> class AVL{
    private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        int height;
        Node(T val,Node* lt,Node* rt) : data(val), left(lt), right(rt), height(1) {}
    };
    Node* root;
    int height(Node* node){
        return node ? node->height : 0;
    }
    int balanceFactor(Node* node){
        return node ? height(node->left) - height(node->right) : 0;
    }
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right) + 1);
        x->height = max(height(x->left), height(x->right) + 1);
        return x;
    }
    Node* leftRotate(Node* y){
        Node* x = y->right;
        Node* T2 = x->left;
        x->left = y;
        y->right = T2;
        
        x->height = max(height(x->left), height(x->right) + 1);
        y->height = max(height(y->left), height(y->right) + 1);
        return y;
    }
    void insert(const T &val, Node* &t ){
        if(t == nullptr)
        t = new Node(val , nullptr, nullptr);
        else if(val < t->data)
        insert(val,t->left);
        else if(val > t->data)
        insert(val,t->right);
        else 
        return;
       t->height = 1+ max(height(t->left), height(t->right));
    }
    void inorder(Node* &t) const{
        if(t == nullptr)
        return;
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
    public:
    AVL() : root(nullptr) {}
    void insert(const T &val){
        insert(val,root);
    }
    void inorder(){
        inorder(root);
    }
};
 int main(){
     AVL<int> tree;
     tree.insert(10);
     tree.insert(20);
     tree.inorder();
     return 0;
 }