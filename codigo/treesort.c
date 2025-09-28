#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct IntNode {
  int value;
  int height;
  struct IntNode *left;
  struct IntNode *right;
} IntNode;

static int node_height(IntNode *n) {
  return n ? n->height : 0;
}

static int max(int a, int b) {
  return a > b ? a : b;
}

static IntNode *create_node(int value) {
  IntNode *n = malloc(sizeof *n);
  if (!n) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  n->value = value;
  n->height = 1;
  n->left = n->right = NULL;
  return n;
}

/* Rotations */
static IntNode *rotate_right(IntNode *y) {
  IntNode *x = y->left;
  IntNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = 1 + max(node_height(y->left), node_height(y->right));
  x->height = 1 + max(node_height(x->left), node_height(x->right));

  return x;
}

static IntNode *rotate_left(IntNode *x) {
  IntNode *y = x->right;
  IntNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = 1 + max(node_height(x->left), node_height(x->right));
  y->height = 1 + max(node_height(y->left), node_height(y->right));

  return y;
}

static int balance_factor(IntNode *n) {
  return n ? node_height(n->left) - node_height(n->right) : 0;
}

/* AVL insert */
static IntNode *insert_node(IntNode *root, int value) {
  if (!root)
    return create_node(value);

  if (value < root->value)
    root->left = insert_node(root->left, value);
  else
    root->right = insert_node(root->right, value);

  root->height = 1 + max(node_height(root->left), node_height(root->right));

  int balance = balance_factor(root);

  // Left heavy
  if (balance > 1 && value < root->left->value)
    return rotate_right(root);

  // Right heavy
  if (balance < -1 && value > root->right->value)
    return rotate_left(root);

  // Left-Right
  if (balance > 1 && value > root->left->value) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
  }

  // Right-Left
  if (balance < -1 && value < root->right->value) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
  }

  return root;
}

static void flatten_inorder(IntNode *node, int **out) {
  if (!node)
    return;
  flatten_inorder(node->left, out);
  **out = node->value;
  (*out)++;
  flatten_inorder(node->right, out);
}

static void free_tree(IntNode *node) {
  if (!node)
    return;
  free_tree(node->left);
  free_tree(node->right);
  free(node);
}

void sort(int a[], size_t n) {
  IntNode *root = NULL;
  for (size_t i = 0; i < n; ++i)
    root = insert_node(root, a[i]);

  int *out = a;
  flatten_inorder(root, &out);
  free_tree(root);
}
