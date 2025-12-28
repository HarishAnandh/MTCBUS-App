#include<iostream>
#include "BST.h"
using namespace std;


int main(){
    BST<int> tree;
    for(int i =0;i<10;i++){
    int x;
     cin>>x;
    switch(x){
        case 1: cin>>x;
                tree.insert(x);
                break;
        case 2: cin>>x;
                if(tree.search(x))
                cout<<x<<"found"<<endl;
                else
                cout<<"not found"<<endl;
                break;
        case 3: tree.inorder();
                break;
        case 4: tree.preorder();
                break;
        case 5: tree.postorder();
                break;
    }
}
    return 0;
}