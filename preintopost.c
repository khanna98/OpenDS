#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
void postorder(struct node* root) {
    if(root==NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
struct node* cons(int *in ,int *pre,int min,int max) {
    static int count=0;
    if(min>max)
        return NULL;
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=pre[count];
    int index=0;
    for(index=min;index<=max;index++)
    {
        if(in[index]==pre[count])
            break;
    }
    count++;
    nn->left=cons(in,pre,min,index-1);
    nn->right=cons(in,pre,index+1,max);
    return nn;
}
int main() {
    int in[]={3,2,1,4,7,6};
    int pre[]={4,2,3,1,6,7};
    struct node* root=cons(in,pre,0,5);
    postorder(root);
}
