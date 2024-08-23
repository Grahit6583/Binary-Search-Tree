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

void take_input(node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
    
}

void inorder(node*root,vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

node* make_balanced(int s , int e ,vector<int> &in)
{
    if(s>e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = make_balanced(s,mid-1,in);
    root->right = make_balanced(mid+1,e,in);
    return root;
}

node* balanced_tree(node* root)
{
    vector<int> in;
    inorder(root,in);
    int s = 0; 
    return make_balanced(s,in.size()-1,in);
}

void traversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
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

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    node* root = NULL;
    take_input(root);
    traversal(root);
    root = balanced_tree(root);
    traversal(root);
    return 0;
}