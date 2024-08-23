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
        left = NULL;
        right = NULL;
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

node* insert_bst(node* root , int data)
{
    if(root == NULL)
    {
        node* root = new node(data);
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
    cin >> data;
    while(data != -1)
    {
        root = insert_bst(root,data);
        cin>>data;
    }
}

void search(node* root , int key ,node* &suc, node* &pre)
{
    if(root == NULL)
    {
        return ;
    }

    if(root->data == key)
    {
        if(root->left != NULL)
        {
            node* temp = root->left;
            while(temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }

        if(root->right != NULL)
        {
            node* temp = root->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        return ;
    }

    if(key > root->data)
    {
        pre = root;
        return search(root->right,key,suc,pre);
    }
    else
    {
        suc = root;
        return search(root->left,key,suc,pre);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    take_input(root);
    LevelOrderTraversal(root);
    node* suc, *pre = NULL;
    search(root,6,suc,pre);

    if(pre != NULL)
    {
        cout<<"predecessor --> "<<pre->data<<endl;
    }
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor --> " << suc->data;
    else
      cout << "No Successor";
    return 0;
}