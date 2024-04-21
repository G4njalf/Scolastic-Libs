using namespace std;
#include <iostream>

struct tree{
    int k;
    tree *left;
    tree *right;
};

typedef tree* ptree;


tree* insert(tree *root, int k){
    if (root == NULL)
    {
        tree *newnode = new tree;
        newnode->k = k;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (k < root->k)
    {
        root->left = insert(root->left, k);
    }
    else
    {
        root->right = insert(root->right, k);
    }
    return root;
}

void printtree(tree *root){
    if (root == NULL)
    {
        return;
    }
    printtree(root->left);
    cout << root->k << " ";
    printtree(root->right);
}

tree* createtree(){
    tree *root = new tree;
    root = NULL;
    return root;
}

bool isLeaf(tree *t){
    if (t == NULL || (t->left == NULL && t->right == NULL))
    {
        return true;
    }
    return false;
}
