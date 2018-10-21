#include<stdio.h>
#include<stdlib.h>
struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};
struct tree* fun(int *arr,int min,int max) {
    if(min > max)
        return NULL;
    int mid = min+ (max-min)/2;
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = arr[mid];
    nn->left = NULL;
    nn->right = NULL;
    nn->left=fun(arr,min,mid-1);
    nn->right=fun(arr,mid+1,max);
    return nn;
}
void inorder(struct tree* node) {
    if(node==NULL)
        return;
    inorder(node->left);
    printf("%d",node->data);
    inorder(node->right);
}
int main() {
    struct tree* node=NULL;
    int arr[]={1,2,3,4,5,6,7};
    int i;
    node=fun(arr,0,6);
    printf("Bianry tree is: ");
    inorder(node);      
    printf("\n"); 
}
