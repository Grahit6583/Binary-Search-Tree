#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public: 
    int data;
    node* left;
    node* right;
    node (int data)
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

node* inst_bst(node* root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root->data > data)
    {
        root->left = inst_bst(root->left , data);
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

    while(data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
    return ;
}

bool Validate_bst(node* root ,int min , int max)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data >= min && root->data <= max)
    {
        bool left = Validate_bst(root->left,min,root->data);
        bool right = Validate_bst(root->right,root->data,max);
        return left && right;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    take_input(root);
    traversal(root);

    if(Validate_bst(root,INT_MIN,INT_MAX))
    {
        cout<<"valid Tree"<<endl;
    }
    else
    {
        cout<<"tree is not valid"<<endl;
    }

    return 0;
}