#include<iostream>
#include<queue>
using namespace std;
struct Node {
    int key;
    struct Node* left, *right;
};
struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

void insert(struct Node** tem, int key)
{
    queue<struct Node*> q;
    q.push(*tem);
    // Do level order traversal until we find
    // an empty place.
        while (!q.empty()) {
            struct Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                int x=temp->key;
                if(x>key) {
                    temp->key=key;
                    key=x;
                }
                temp->left=newNode(key);
                break;
            } else
                q.push(temp->left);

            if (!temp->right) {
                int x=temp->key;
                if(x>key){
                    temp->key=key;
                    key=x;
                }
                temp->right = newNode(key);
                break;
            } else
                q.push(temp->right);
        }
}
void inorder(struct Node* root) {
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main()
{
    struct Node* root = NULL;
    int arr[]={2,7,5,11,1};
    int i;
    root=newNode(arr[0]);
    for(i=1;i<5;i++) {
        insert(&root,arr[i]);
    }
    inorder(root);    
    return 0;
}
