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

node* inst_bst(node* root,int data)
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
    cin>> data;
    while (data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
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

void preorder(node*root,vector<int> &in)
{
    if(root == NULL)
    {
        return ;
    }

    in.push_back(root->data);
    preorder(root->left,in);
    preorder(root->right,in);
}

node* solve(vector<int> &preorder ,int mini ,int maxi ,int &i)
{
    if(i >= preorder.size())
    {
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi )
    {
        return NULL;
    }

    node* newroot = new node(preorder[i++]);

    newroot->left = solve(preorder,mini,newroot->data,i);
    newroot->right = solve(preorder,newroot->data,maxi,i);
    return newroot;
}

node* preorderTobst(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder,mini,maxi,i);
}
void print(vector<int> preorder)
{
    int n = preorder.size();
    for(int i = 0 ; i<n ;i++)
    {
        cout<<preorder[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root = NULL;
    take_input(root);
    traversal(root);
    vector<int> in;
    preorder(root,in);
    cout<<"PREORDER"<<endl;
    print(in);
    root = preorderTobst(in);
    cout<<"TRAVERSAL AFTER PREORDER "<<endl;
    traversal(root);
    return  0;
}