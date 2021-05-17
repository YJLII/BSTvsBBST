#include<stdio.h>
struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
}BST;

struct AVLTreeNode {
    int data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
}AVL;

struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return Find(root->left, data);
    else if (data > root->data)
        return Find(root->right, data);
    return root;
}


struct BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL) {
        root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
        if (root == NULL) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->left = root->right = NULL;
        }
    }
    else {
        if (data < root->data)   root->left = Insert(root->left, data);
        else if (data > root->data)   root->right = Insert(root->right, data);
    }
    return root;
}//For Number 1
struct AVLTreeNode* Insert(struct AVLTreeNode* root, int data) {
    if (!root) {
        root = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode*));
        if (!root) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if (data < root->data) {  // 왼쪽으로
        root->left = Insert(root->left, data);
        if ((Height(root->left) - Height(root->right)) == 2) {
            if (data < root->left->data)    // LeftLeft
                root = SingleRotateLeft(root);
            else root = DoubleRotatewithLeft(root);   // LeftRight
        }
    }
    else if (data > root->data) {  // 오른쪽으로
        root->right = Insert(root->right, data);
        if ((Height(root->right) - Height(root->left)) == 2) {
            if (data > root->right->data)    // RightRight
                root = SingleRotateRight(root);
            else root = DoubleRotatewithRight(root);   // RightLeft
        }
    }
    // 데이터가 트리 안에 이미 있다면 아무것도 안 한다
    root->height = max(Height(root->left), Height(root->right)) + 1;
    return root;
}

int main(void)
{

}