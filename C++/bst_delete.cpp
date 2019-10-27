#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left=NULL;
    node *right =NULL;
    node(int n)
    {
    this->data=n;}
};
int min1=INT_MAX;
int inorder(node *head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }
}

int preorder1(node *root,int n)
{
    if(root!=NULL)
    {
        if(root->left->data==n)
        {
            free(root->left);
            root->left=NULL;
        }
        else
        preorder1(root->left,n);
        if(root->right->data==n)
        {
            free(root->right);
            root->right=NULL;
        }
        else
        preorder1(root->right,n);
    }
}

int findmin1(node *root)
{
    if(root!=NULL)
    {
        findmin1(root->left);
        if(root->data<min1)
        min1=root->data;
        findmin1(root->right);
    }
}

int bfs(node *head)
{
    queue<node *> q;
    q.push(head);
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left)
        q.push(q.front()->left);
        if(q.front()->right)
        q.push(q.front()->right);
        q.pop();
    }
    return 0;
}

//node to be deleted may have only 1 child,2 child or no child

int del(node *temp,node *head)
{
    if(temp->left==NULL||temp->right==NULL)
    {
        if(temp->left)
        {
            temp->data=temp->left->data;
            temp->left=NULL;
            free(temp->left);
        }
        else if(temp->right)
        {
            temp->data=temp->right->data;
            temp->right=NULL;
            free(temp->right);
        }
        // if(head->data>temp->data)
        // if(head->left->data==temp->data)
        // head->left=NULL;
        // else
        // del(temp,head->left);
        // else if(head->data<temp->data)
        // if(head->right->data==temp->data)
        // head->right=NULL;
        // else
        // del(temp,head->right);
    }
    else if(temp->left==NULL&&temp->right==NULL)
    {
        if(head->data>temp->data)
        if(head->left->data==temp->data)
        {head->data=head->left->data;free(head->left);head->left=NULL;}
        else
        del(temp,head->left);
        else if(head->data<temp->data)
        if(head->right->data==temp->data)
        {head->data=head->right->data;free(head->right);head->right=NULL;}
        else
        del(temp,head->right);
    }
    else if(temp->left&&temp->right)
    {
        findmin1(temp);
        preorder1(temp,min1);
    }
}

int main()
{
    node *head=new node(5);
    head->left=new node(3);
    head->right=new node(9);
    head->left->left=new node(1);
    head->left->left->right=new node(2);
    head->left->right=new node(4);
    head->right->left=new node(6);
    head->right->right=new node(10);
    head->right->right->right=new node(12);   
    del(head->left->left->right,head);//no child
    bfs(head);cout<<endl;inorder(head);
    free(head->left->left->right);
    del(head->right,head);//2 child
    free(head->right);
    bfs(head);inorder(head);
    del(head->right->right,head);//1 child
    // free(head->right->right);
    bfs(head);inorder(head);
    return 0;
}
