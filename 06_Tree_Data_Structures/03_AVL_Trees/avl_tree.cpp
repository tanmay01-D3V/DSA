#include <iostream>
using namespace std;

class Node {
public:
   int data;
   int height;
   Node* left;
   Node* right;

   Node(int value) {
       data = value;
       height = 1;
       left = NULL;
       right = NULL;
   }
};

int height(Node* root) {
   if (root == NULL)
       return 0;

   return root->height;
}

int getBalance(Node* root) {
   if (root == NULL)
       return 0;

   return height(root->left) - height(root->right);
}

int maximum(int a, int b) {
   return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
   Node* x = y->left;
   Node* temp = x->right;

   x->right = y;
   y->left = temp;

   y->height = maximum(height(y->left), height(y->right)) + 1;
   x->height = maximum(height(x->left), height(x->right)) + 1;

   return x;
}

Node* leftRotate(Node* x) {
   Node* y = x->right;
   Node* temp = y->left;

   y->left = x;
   x->right = temp;

   x->height = maximum(height(x->left), height(x->right)) + 1;
   y->height = maximum(height(y->left), height(y->right)) + 1;

   return y;
}

Node* insert(Node* root, int value) {
   if (root == NULL)
       return new Node(value);

   if (value < root->data)
       root->left = insert(root->left, value);
   else if (value > root->data)
       root->right = insert(root->right, value);
   else
       return root;

   root->height = maximum(height(root->left), height(root->right)) + 1;

   int balance = getBalance(root);

   // Left Left Case
   if (balance > 1 && value < root->left->data)
       return rightRotate(root);

   // Right Right Case
   if (balance < -1 && value > root->right->data)
       return leftRotate(root);

   // Left Right Case
   if (balance > 1 && value > root->left->data) {
       root->left = leftRotate(root->left);
       return rightRotate(root);
   }

   // Right Left Case
   if (balance < -1 && value < root->right->data) {
       root->right = rightRotate(root->right);
       return leftRotate(root);
   }

   return root;
}

void inorder(Node* root) {
   if (root == NULL)
       return;

   inorder(root->left);
   cout << root->data << " ";
   inorder(root->right);
}

void preorder(Node* root) {
   if (root == NULL)
       return;

   cout << root->data << " ";
   preorder(root->left);
   preorder(root->right);
}

int main() {
   Node* root = NULL;

   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 30);
   root = insert(root, 40);
   root = insert(root, 50);
   root = insert(root, 25);

   cout << "Inorder Traversal: ";
   inorder(root);

   cout << "\nPreorder Traversal: ";
   preorder(root);

   return 0;
}
