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
        right = NULL;
        left = NULL;
    }
};

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

node* LCA_bst(node* root,node* p,node* q)
{
    if(root == NULL)
    {
        return root;
    }

    if(root->data < p->data && root->data < q->data)
    {
        return LCA_bst(root->right,p,q);
    }

    if(root->data > p->data && root->data > q->data)
    {
        return LCA_bst(root->left,p,q);
    }

    return root;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    take_input(root);
    traversal(root);
    node* p ;
    p = new node(1);
    node* q;
    q = new node(3);
    node* temp = LCA_bst(root,p,q);
    cout<<endl<<"output is "<<endl;
    cout<<temp->data<<endl;
    return 0;
}