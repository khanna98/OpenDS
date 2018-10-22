#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    int height;
    struct tree* left;
    struct tree* right;
};
int height(struct tree* temp) {
    if(temp==NULL)
        return 0;
    else
        return temp->height;
}
int max(int a,int b) {
    if(a>b)
        return a;
    else
        return b;
}
int getbalance(struct tree* temp) {
    if(temp==NULL)
        return 0;
    else {
        return (height(temp->left)-height(temp->right));
    }
}
struct tree* leftrotate(struct tree* x) {
    struct tree* y=x->right;
    struct tree* T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    return y;
}
struct tree* rightrotate(struct tree* y) {
    struct tree* x=y->left;
    struct tree* T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->left));
    return x;
}
struct tree* insert(struct tree* temp,int data){
    if(temp==NULL) {
        struct tree* nn=(struct tree*)malloc(sizeof(struct tree));
        nn->data=data;
        nn->height=1;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }   
    if(temp->data>data){
        temp->left=insert(temp->left,data);
    }
    else if(temp->data<data){
        temp->right=insert(temp->right,data);
    }
    else
        return temp;
    
    temp->height=1+max(height(temp->left),height(temp->right));

    int balance=getbalance(temp);

    if(balance>1 && data<temp->left->data) {
        return  rightrotate(temp);
    }
    if(balance>1 && data>temp->left->data) {
        temp->left=leftrotate(temp->left);
        return rightrotate(temp);
    }
    if(balance<-1 && data<temp->right->data) {
        temp->right=rightrotate(temp->right);
        return leftrotate(temp);
    }
    if(balance<-1 && data>temp->right->data) {
        return leftrotate(temp);
    }
    return temp;
}
void inorder(struct tree* head) {
    if(head==NULL)
        return;
    inorder(head->left);
    printf(" %d ",head->data);
    inorder(head->right);
}
int main(){
    struct tree* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,-1);    
    head=insert(head,-5);
    inorder(head);
}
