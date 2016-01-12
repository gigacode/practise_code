#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
}Node;

Node* inorderToTree(int array[], int low, int high) {
    if(high < low)
        return NULL;
    
    int index = (low + high)/2;
    Node *new_node = new Node;
    new_node->val = array[index];
    new_node->left = inorderToTree(array, low, index-1);
    new_node->right = inorderToTree(array, index+1, high);

    return new_node;
}

void printTree(Node* root) {
    if (root == NULL) 
        return;

    printTree(root->left);
    cout << root->val;
    printTree(root->right);
}

int main(int argc, char** argv) {
   int array[] = {4, 2, 5, 1, 6, 3, 7};
   Node *root = inorderToTree(array, 0, 6);
   printTree(root);
} 
