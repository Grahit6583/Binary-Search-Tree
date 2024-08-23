#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node* right;
    node* left;

    node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

void LevelOrderTraversal(node* root)
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

node* ist_in_bst(node* root ,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = ist_in_bst(root->right,data);
    }
    else
    {
        root->left = ist_in_bst(root->left,data);
    }

    return root;
}

void take_input(node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = ist_in_bst(root,data);
        cin>>data;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    cout<<"Enter the data in BST "<<endl;
    take_input(root);

    LevelOrderTraversal(root);


}