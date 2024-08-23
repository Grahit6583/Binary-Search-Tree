#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node (int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *Tree(node *root)
{
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    root = new node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data in left child "<<data<<endl;
    root->left = Tree(root->left);
    cout<<"Enter data in rigth child "<<data<<endl;
    root->right = Tree(root->right);
    return root;
}

void levelordertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp = q.front();
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

class info
{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

info solve(node* root,int &ans)
{
    if(root == NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currnode;

    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);

    if(left.isBst && right.isBst && (left.maxi < root->data && root->data < right.mini))
    {
        currnode.isBst = true;
    }
    else
    {
        currnode.isBst = false;
    }

    if(currnode.isBst)
    {
        ans = max(ans,currnode.size);
    }

    return currnode;
}

int largest_bst(node*root)
{
    int max_size = 0;
    info ans = solve(root,max_size);
    return max_size;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node *root = NULL;
    root = Tree(root);
    levelordertraversal(root);
    int ans = largest_bst(root);
    cout<<"the ans is : "<<ans<<endl;
    return 0;
}