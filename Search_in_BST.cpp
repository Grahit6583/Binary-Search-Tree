#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class node
{
    public:
    int data;
    node* right;
    node* left;
    node(int d)
    {
        this->data = d;
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

node* insert_bst(node* root,int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right =  insert_bst(root->right , d);
    }
    else
    {
        root->left =  insert_bst(root->left, d);
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

bool search(node* root , int key)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == key)
    {
        return true;
    }

    if(key > root->data)
    {
        return search(root->right,key);
    }
    else
    {
        return search(root->left,key);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    cout<<"Enter the data in BST"<<endl;
    take_input(root);

    LevelOrderTraversal(root);
    int element;
    cout<<"Enter the element to find "<<endl;
    cin>>element;
    cout<< search(root,element);
    return 0;
}