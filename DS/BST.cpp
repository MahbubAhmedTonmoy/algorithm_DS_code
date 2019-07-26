#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{

    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return  temp;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
        root = newnode(data);
    else if(data<=root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}
void Swap( node **a , node **b)
{
    node * temp = *a;
    *a = *b;
    *b = temp;
}
void swapEveryLevelUnit(node *root,int level,int k)
{
    if(root==NULL || (root->left == NULL && root->right == NULL))
        return;
    if((level+1)%k == 0){
            Swap(&root->left, &root->right);
        //node *t = root->left;
        //root->left = root->right;
        //root->right = t;
    }
    swapEveryLevelUnit(root->left,level+1,k);
    swapEveryLevelUnit(root->right,level+1,k);
}

void swapEveryLevel(node *root,int k)
{
    swapEveryLevelUnit(root,1,k);
}

void preorder(struct node *root)///p-left-right
{
    if(root == NULL) return;
    printf(" %d",root->data);
    preorder(root->left);
    preorder(root->right);

}

void inorder(node *root) /// left-p-right
{
    if(root== NULL) return;
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);

}

void postorder()//left-right-p
{

}

int getHeight(node *root)
{
    if(root == NULL) return -1;
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    return 1+max(left,right);
}

bool ifNodeExists(node *root,int data){
    if(root==NULL) return false;
    else if(root->data == data) return true;
    bool res1 = ifNodeExists(root->left, data);

    /* now recur on right subtree */
    bool res2 = ifNodeExists(root->right, data);

    return res1 || res2;
}
int main()
{
     struct node *root;
     root = newnode(5);
     insert(root,2);
     insert(root,3);
     insert(root,4);
     insert(root,8);
     insert(root,7);

    /*root = newnode(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
*/
cout<<"\nHeight of the tree is "<<getHeight(root) <<endl;
preorder(root);
cout<<endl;
    inorder(root);
    cout<<endl;
    swapEveryLevel(root,2);
    preorder(root);
    cout<<endl;
    inorder(root);
cout<<endl;
    if (ifNodeExists(root, 2))
        cout << "YES";
    else
        cout << "NO";


}
