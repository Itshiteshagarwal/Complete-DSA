//minimum heap implimentation
// #include <bits/stdc++.h>
// class minHeap {
// public:
//   int arr[1000000];
//   int size;

//   minHeap() {
//     arr[0] = -1;
//     size = 0;
//   }

//   void topDownHeapify(int arr[], int n, int i) {
//     int largest = i, l = (2 * i), r = (2 * i) + 1;
//     if (l <= n && arr[largest] > arr[l]) {
//       largest = l;
//     }
//     if (r <= n && arr[largest] > arr[r]) {
//       largest = r;
//     }
//     if (largest != i) {
//       swap(arr[largest], arr[i]);
//       topDownHeapify(arr, n, largest);
//     }
//   }

//   // Implement the function to insert 'val' in the heap.
//   void insert(int val) {
//     size = size + 1;
//     int i = size;
//     arr[i] = val;
//     while (i > 1) {
//       int parent = i / 2;
//       if (arr[i] < arr[parent]) {
//         swap(arr[i], arr[parent]);
//         i = parent;
//       } else {
//         return;
//       }
//     }
//   }

//   // Implement the function to remove minimum element.
//   void removeMin() {
//     if (size == 0) {
//       return;
//     }

//     arr[1] = arr[size];
//     size--;
//     topDownHeapify(arr, size, 1);
//   }

//   // Implement the function to return minimum element.
//   int minElement() {
//     if (size == 0) {
//       return -1;
//     }
//     return arr[1];
//   }
// };