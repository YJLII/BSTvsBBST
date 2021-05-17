#include <stdio.h>
#include<time.h>
#include<malloc.h>
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

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

struct BinarySearchTreeNode* BSTFind(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return BSTFind(root->left, data);
    else if (data > root->data)
        return BSTFind(root->right, data);
    return root;
}


struct BinarySearchTreeNode* BSTInsert(struct BinarySearchTreeNode* root, int data) {
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
        if (data < root->data)   root->left = BSTInsert(root->left, data);
        else if (data > root->data)   root->right = BSTInsert(root->right, data);
    }
    return root;
}//For Number 1
int Height(struct AVLTreeNode* root) {
    if (!root) return -1;
    else return root->height;
}

struct AVLTreeNode* SingleRotateLeft(struct AVLTreeNode* X) {
    struct AVLTreeNode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = max(Height(X->left), Height(X->right)) + 1;
    W->height = max(Height(W->left), X->height) + 1;
    return W; //새 루트 노드
}
struct AVLTreeNode* SingleRotateRight(struct AVLTreeNode* W) {
    struct AVLTreeNode* X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = max(Height(W->left), Height(W->right)) + 1;
    X->height = max(W->height, Height(X->right)) + 1;
    return X;
}
struct AVLTreeNode* DoubleRotatewithLeft(struct AVLTreeNode* Z) {
    Z->left = SingleRotateRight(Z->left);
    return  SingleRotateLeft(Z);
}
struct AVLTreeNode* DoubleRotatewithRight(struct AVLTreeNode* X) {
    X->right = SingleRotateLeft(X->right);
    return  SingleRotateRight(X);
}

struct AVLTreeNode* AVLInsert(struct AVLTreeNode* root, int data) {
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
        root->left = AVLInsert(root->left, data);
        if ((Height(root->left) - Height(root->right)) == 2) {
            if (data < root->left->data)    // LeftLeft
                root = SingleRotateLeft(root);
            else root = DoubleRotatewithLeft(root);   // LeftRight
        }
    }
    else if (data > root->data) {  // 오른쪽으로
        root->right = AVLInsert(root->right, data);
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


void forQuestion01(){
    srand(time(NULL));
    int RandomNumber = (rand() * 3)%100001;
    printf("%d", RandomNumber);

}

int main(void)
{
    forQuestion01();
}