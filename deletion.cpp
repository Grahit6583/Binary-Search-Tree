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

void traversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

node* insert_bst(node* root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = insert_bst(root->right,data);
    }
    else
    {
        root->left = insert_bst(root->left,data);
    }

    return root;
}

void take_input(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insert_bst(root,data);
        cin>>data;
    }
}

node* min(node* root)
{
    node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* delete_node(node* root , int element)
{
    if(root == NULL)
    {
        return root;
    }

    if(root->data == element)
    {
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->right != NULL && root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL)
        {
            int mini = min(root->right)->data;
            root->data = mini;
            root->right = delete_node(root->right,mini);
            return root; 
        }
    }
    else if(root->data > element)
    {
        root->left = delete_node(root->left,element);
        return root;
    }
    else
    {
        root->right = delete_node(root->right,element);
        return root;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    cout<<"Enter the data in BST"<<endl;
    take_input(root);

    traversal(root);
    cout<<"TREE AFTER DELETION "<<endl;
    root = delete_node(root,1);
    traversal(root);
    return 0;
}