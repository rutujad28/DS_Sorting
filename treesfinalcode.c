#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int val) {
    if(root == NULL) {
        return createNode(val);
    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct node* root) {
    if(root == NULL) {
        return;
    }
    
    struct node* stack[MAX_SIZE];
    int top = -1;
    struct node* node = root;

    while (node != NULL || top >= 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        printf("%d ", node->data);
        node = node->right;
    }
}

void preorder(struct node *root) {
    if(root == NULL) {
        return;
    }

    struct node* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        // Pop the element in stack
        struct node* node = stack[top--];
        // And print the popped element
        printf("%d ", node->data);

        if(node->right != NULL) {
            stack[++top] = node->right;
        }
        
        if(node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

int height(struct node* root) {
    int height = 0;
    struct Stack {
        struct node* node;
        int height;
    };
    struct Stack stack[MAX_SIZE];
    int top = -1;
    // The root node and its height of 1 are pushed onto the stack.
    stack[++top] = (struct Stack) { root, 1 };
    
    while (top >= 0) {
        struct Stack current = stack[top--];
        struct node* node = current.node;
        int currentHeight = current.height;
        
        if (currentHeight > height) {
            height = currentHeight;
        }

        if (node->left != NULL) {
            stack[++top] = (struct Stack) { node->left, currentHeight + 1 };
        }

        if (node->right != NULL) {
            stack[++top] = (struct Stack) { node->right, currentHeight + 1 };
        }
    }
    return height;
}

int findMax(struct node* root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1;
    }

    struct node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }

    return current->data;
}

int main() {
    struct node* root = NULL;
    int n, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of the nodes:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder(root);

    printf("\n");

    printf("Preorder traversal of the binary search tree: ");
    preorder(root); 

    printf("\n");

    printf("Height : %d", height(root));

    printf("\n");

    printf("Maximum element is : %d", findMax(root));

    return 0;
}

