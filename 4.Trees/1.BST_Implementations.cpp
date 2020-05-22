//Chethan J    22/05/2020
//Binary search tree Implimntations:
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

struct BST{

    int data;
    BST* left;
    BST* right;  

};

BST* newBST(int value){

    BST* root  = new BST;
    root->data = value;
    root->left = root->right = NULL;

    return root;
}

//Insert an element:

BST* Insert(BST* &root, int value){
    if(root == NULL){

        root = newBST(value);

    }else if(value <= root->data){

        root->left = Insert(root->left,value);

    }else{

        root->right = Insert(root->right,value);
    }
    return root;
}

//Tree Traversals:

void Preorder(BST *root){ 
    if(!root){ 
        return; 
    } 
     
    cout << root->data << endl; 
    Preorder(root->left);
    Preorder(root->right); 
} 

void Inorder(BST *root){ 
    if(!root){ 
        return; 
    } 

    Inorder(root->left); 
    cout << root->data << endl; 
    Inorder(root->right); 
} 

void Postorder(BST *root){ 
    if(!root){ 
        return; 
    } 
         
    Postorder(root->left);
    Postorder(root->right); 
    cout << root->data << endl; 
}

//search for an element:

void Search(BST* root, int value){

    if(root == NULL){

        cout << "Not Found!" << endl;
        return;

    }else if(root->data == value){

        cout << "Found!" << endl;
        return;

    }else if(value < root->data){

        Search(root->left,value);

    }else{

        Search(root->right,value);

    }
}



int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    BST* root = NULL; 
    

    Insert(root, 30); 
    Insert(root, 20); 
    Insert(root, 40); 
    Insert(root, 70); 
    Insert(root, 60); 
    Insert(root, 80); 

    Search(root,1000);

    Inorder(root); 

    
}
