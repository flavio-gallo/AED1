// EXERCÍCIO 1466 - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node* node, int val) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (val < node->val) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

void bfs(Node* root) {
    if (root == NULL) return;
    
    Node* queue[505];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    int first = 1;

    while (front < rear) {
        Node* current = queue[front++];
        
        if (!first) printf(" ");
        printf("%d", current->val);
        first = 0;

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int c, n, val;
    scanf("%d", &c);
    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        Node* root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &val);
            root = insert(root, val);
        }
        printf("Case %d:\n", i);
        bfs(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}
