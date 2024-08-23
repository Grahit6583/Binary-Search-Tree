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
        left  = NULL;
    }
};

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

int two_sum(node* root , int target)
{
    vector<int> in;
    inorder(root,in);
    int i =0;
    int j = in.size()-1;

    while(i<j)
    {
        int sum = in[i]+ in[j];
        if(sum == target)
        {
            return 1;
        }
        else if(sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return 0;
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
    while(data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    node* root = NULL;
    take_input(root);

    int ans = two_sum(root,9);
    cout<<ans<<endl;
    return 0;
}