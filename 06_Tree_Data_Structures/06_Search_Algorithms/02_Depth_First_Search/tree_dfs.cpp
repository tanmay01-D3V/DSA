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

void preorderDFS(Node* root) {
   if (root == NULL)
       return;

   cout << root->data << " ";
   preorderDFS(root->left);
   preorderDFS(root->right);
}

void inorderDFS(Node* root) {
   if (root == NULL)
       return;

   inorderDFS(root->left);
   cout << root->data << " ";
   inorderDFS(root->right);
}

void postorderDFS(Node* root) {
   if (root == NULL)
       return;

   postorderDFS(root->left);
   postorderDFS(root->right);
   cout << root->data << " ";
}

int main() {
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);

   cout << "Preorder DFS: ";
   preorderDFS(root);

   cout << "\nInorder DFS: ";
   inorderDFS(root);

   cout << "\nPostorder DFS: ";
   postorderDFS(root);

   return 0;
}
