#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int K_large(node* root ,int &i ,int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int right = K_large(root->right,i,k);

    if(right != -1)
    {
        cout<<right<<endl;
        return right;
    }

    i++;
    if(i == k)
    {
        return root->data;
    }

    return K_large(root->left,i,k);
}

node* inst_bst(node* root , int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root->data > data)
    {
        root->left = inst_bst(root->left,data);
    }
    else
    {
        root->right = inst_bst(root->right,data);
    }
    return root;
}

void take_intput(node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    cout<<"Enter the data in BST "<<endl;
    take_intput(root);
    int i = 0 ;
    int count = 0 ;
    int num = K_large(root,i,3);
    cout<<num<<endl;
    return 0;
}