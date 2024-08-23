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

node* inst_bst(node* root,int data)
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
    while(data != -1)
    {
        root = inst_bst(root,data);
        cin>>data;
    }
}

void ConvertBstintoDLL(node* root , node* &head)
{
    if(root == NULL)
    {
        return ;
    }
    ConvertBstintoDLL(root->right,head);
    root->right = head;
    if(head != NULL)
    {
        head->left = root;
    }

    head = root;
    ConvertBstintoDLL(root->left,head);
}

node* mergelinklist(node* head1 , node* head2)
{
    node* head = NULL;
    node* tail = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data < head2 -> data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countnodes(node* head)
{
    int cnt = 0;
    node* temp = head;
    while (temp!=NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

node* sortedLLBST(node* &head ,int n)
{
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    node* left = sortedLLBST(head,n/2);
    node* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLBST(head,n-n/2-1);
    return root;
}

node* merge_bst(node* root1,node* root2)
{
    node *head1, *head2 = NULL;
    ConvertBstintoDLL(root1,head1);
    head1->left = NULL;
    cout<<"hello"<<endl;
    ConvertBstintoDLL(root2,head2);
    head2->left = NULL;

    node* head = mergelinklist(head1,head2);

    return sortedLLBST(head,countnodes(head));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node* root1 = NULL;
    cout<<"Enter the data in BST-1"<<endl;
    take_input(root1);

    LevelOrderTraversal(root1);
    node* root2 = NULL;
    cout<<"Enter the data in BST-2"<<endl;
    take_input(root2);

    LevelOrderTraversal(root2);
    node* root = merge_bst(root1,root2);
    cout<<"Enter the data in BST-2"<<endl;
    LevelOrderTraversal(root);
}