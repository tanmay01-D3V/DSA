#include <iostream>
using namespace std;

void swapValues(int& a, int& b) {
   int temp = a;
   a = b;
   b = temp;
}

void heapify(int heap[], int size, int index) {
   int largest = index;
   int left = 2 * index + 1;
   int right = 2 * index + 2;

   if (left < size && heap[left] > heap[largest])
       largest = left;

   if (right < size && heap[right] > heap[largest])
       largest = right;

   if (largest != index) {
       swapValues(heap[index], heap[largest]);
       heapify(heap, size, largest);
   }
}

void insert(int heap[], int& size, int value) {
   heap[size] = value;
   int index = size;
   size++;

   while (index != 0) {
       int parent = (index - 1) / 2;

       if (heap[parent] < heap[index]) {
           swapValues(heap[parent], heap[index]);
           index = parent;
       } else {
           break;
       }
   }
}

void deleteRoot(int heap[], int& size) {
   if (size == 0) {
       cout << "Heap is empty\n";
       return;
   }

   heap[0] = heap[size - 1];
   size--;

   heapify(heap, size, 0);
}

void printHeap(int heap[], int size) {
   for (int i = 0; i < size; i++)
       cout << heap[i] << " ";
}

int main() {
   int heap[100];
   int size = 0;

   insert(heap, size, 50);
   insert(heap, size, 30);
   insert(heap, size, 40);
   insert(heap, size, 10);
   insert(heap, size, 5);
   insert(heap, size, 20);
   insert(heap, size, 60);

   cout << "Max Heap: ";
   printHeap(heap, size);

   deleteRoot(heap, size);

   cout << "\nAfter Deleting Root: ";
   printHeap(heap, size);

   return 0;
}
