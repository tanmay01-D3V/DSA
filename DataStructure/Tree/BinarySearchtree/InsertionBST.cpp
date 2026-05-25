#include <iostream>
using namespace std;

class Node {
public:
   int data;
   Node* left;
   Node* right;

   Node(int value) {
       data = value;
       left = NULL;
       right = NULL;
   }
};

// Insert Function
Node* insert(Node* root, int value) {

   if (root == NULL)
       return new Node(value);

   if (value < root->data)
       root->left = insert(root->left, value);

   else
       root->right = insert(root->right, value);

   return root;
}

// Inorder Function
void inorder(Node* root) {

   if (root == NULL)
       return;

   inorder(root->left);

   cout << root->data << " ";

   inorder(root->right);
}

int main() {

   Node* root = NULL;

   root = insert(root, 50);
   insert(root, 30);
   insert(root, 70);
   insert(root, 20);
   insert(root, 40);
   insert(root, 60);
   insert(root, 80);

   cout << "BST After Insertion: ";

   inorder(root);

   return 0;
}
