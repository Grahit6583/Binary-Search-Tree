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

node* inst_bst(node* root ,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root->data < data)
    {
        root->right = inst_bst(root->right,data);
    }
    else
    {
        root->left = inst_bst(root->left,data);
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

void inorder(node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

node* flatten(node* root)
{
    vector<int> in;
    inorder(root,in);
    int n = in.size();
    node* newroot = new node(in[0]);
    node* curr = newroot;

    for(int i =1 ; i<n ; i++)
    {
        node* temp = new node(in[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right= NULL;
    return newroot;
}

void traversal(node* root)
{
    queue<node*> q;
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

void show(node* root)
{
    node* temp = root;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    node* root = NULL;
    take_input(root);
    traversal(root);
    root = flatten(root);
    cout<<"hello"<<endl;
    cout<<endl;
    show(root);
    return 0;
}