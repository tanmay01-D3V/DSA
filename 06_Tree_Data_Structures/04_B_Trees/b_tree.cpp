#include <iostream>
using namespace std;

class BTreeNode {
public:
   int* keys;
   int minimumDegree;
   BTreeNode** children;
   int keyCount;
   bool leaf;

   BTreeNode(int degree, bool isLeaf) {
       minimumDegree = degree;
       leaf = isLeaf;
       keys = new int[2 * minimumDegree - 1];
       children = new BTreeNode*[2 * minimumDegree];
       keyCount = 0;

       for (int i = 0; i < 2 * minimumDegree; i++)
           children[i] = NULL;
   }

   void traverse() {
       int i;

       for (i = 0; i < keyCount; i++) {
           if (!leaf)
               children[i]->traverse();

           cout << keys[i] << " ";
       }

       if (!leaf)
           children[i]->traverse();
   }

   BTreeNode* search(int key) {
       int i = 0;

       while (i < keyCount && key > keys[i])
           i++;

       if (i < keyCount && keys[i] == key)
           return this;

       if (leaf)
           return NULL;

       return children[i]->search(key);
   }

   void insertNonFull(int key) {
       int i = keyCount - 1;

       if (leaf) {
           while (i >= 0 && keys[i] > key) {
               keys[i + 1] = keys[i];
               i--;
           }

           keys[i + 1] = key;
           keyCount++;
       } else {
           while (i >= 0 && keys[i] > key)
               i--;

           if (children[i + 1]->keyCount == 2 * minimumDegree - 1) {
               splitChild(i + 1, children[i + 1]);

               if (keys[i + 1] < key)
                   i++;
           }

           children[i + 1]->insertNonFull(key);
       }
   }

   void splitChild(int index, BTreeNode* fullChild) {
       BTreeNode* newChild = new BTreeNode(fullChild->minimumDegree, fullChild->leaf);
       newChild->keyCount = minimumDegree - 1;

       for (int j = 0; j < minimumDegree - 1; j++)
           newChild->keys[j] = fullChild->keys[j + minimumDegree];

       if (!fullChild->leaf) {
           for (int j = 0; j < minimumDegree; j++)
               newChild->children[j] = fullChild->children[j + minimumDegree];
       }

       fullChild->keyCount = minimumDegree - 1;

       for (int j = keyCount; j >= index + 1; j--)
           children[j + 1] = children[j];

       children[index + 1] = newChild;

       for (int j = keyCount - 1; j >= index; j--)
           keys[j + 1] = keys[j];

       keys[index] = fullChild->keys[minimumDegree - 1];
       keyCount++;
   }
};

class BTree {
public:
   BTreeNode* root;
   int minimumDegree;

   BTree(int degree) {
       root = NULL;
       minimumDegree = degree;
   }

   void traverse() {
       if (root != NULL)
           root->traverse();
   }

   BTreeNode* search(int key) {
       if (root == NULL)
           return NULL;

       return root->search(key);
   }

   void insert(int key) {
       if (root == NULL) {
           root = new BTreeNode(minimumDegree, true);
           root->keys[0] = key;
           root->keyCount = 1;
           return;
       }

       if (root->keyCount == 2 * minimumDegree - 1) {
           BTreeNode* newRoot = new BTreeNode(minimumDegree, false);
           newRoot->children[0] = root;
           newRoot->splitChild(0, root);

           int i = 0;
           if (newRoot->keys[0] < key)
               i++;

           newRoot->children[i]->insertNonFull(key);
           root = newRoot;
       } else {
           root->insertNonFull(key);
       }
   }
};

int main() {
   BTree tree(3);

   tree.insert(10);
   tree.insert(20);
   tree.insert(5);
   tree.insert(6);
   tree.insert(12);
   tree.insert(30);
   tree.insert(7);
   tree.insert(17);

   cout << "B-Tree Traversal: ";
   tree.traverse();

   int key = 6;

   if (tree.search(key) != NULL)
       cout << "\nElement Found";
   else
       cout << "\nElement Not Found";

   return 0;
}
