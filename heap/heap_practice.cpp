//kth smallest element using max heap
// #include <bits/stdc++.h> 
// int kthSmallest(vector<int> input, int k)
// {
//     priority_queue<int>pq;
//     for(int i=0; i<k; i++){
//         pq.push(input[i]);
//     }
//     int n = input.size();
//     for(int i=k; i<n; i++){
//         if(input[i]<pq.top()){
//             pq.pop();
//             pq.push(input[i]);
//         }
//     }
//     return pq.top();
// }tc O(logn) sc O(1)


//kth largest element using minheap
// #include <bits/stdc++.h> 
//  int findKthLargest(vector<int>& nums, int k) {

//   priority_queue<int,vector<int>, greater<int>> pq;

//   for(int i =0; i<nums.size(); i++){
//     if(i<k){
//       pq.push(nums[i]);
//     }
//     else{
//       if(nums[i]>pq.top()){
//         pq.pop();
//         pq.push(nums[i]);
//       }
//     }
//   }
// return pq.top();
// }tc O(logn) sc O(1)



//is binary tree is a heap or not?
// int totalcount( BinaryTreeNode<int>*root )
// {
//     if (!root) return 0;
//     return 1+totalcount(root->left)+totalcount(root->right);
// }

// bool isComplete(BinaryTreeNode<int>*root,int index,int count)
// {
//    if (!root) return true;
//    if (index>=count) return false;
//    bool left=isComplete(root->left, 2*index+1,count);
//    bool right=isComplete(root->right, 2*index+2,count);
//    return left && right;
// }
// bool isMaxHeap(BinaryTreeNode<int>* root)
// {
//     if (!root->left && !root->right) return true;
//     if (!root->right)
//     {
//         return root->data>=root->left->data;
//     }
//     bool left=isMaxHeap(root->left);
//     bool right=isMaxHeap(root->right);
//     return left && right && root->data>=root->left->data && root->data>=root->right->data;
// }
// bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
// {
//     int count=totalcount(root);
//     return isComplete(root,0,count) && isMaxHeap(root);

// }
//time complex - O(n) space O(h)






//merge to binary max heap
// #include <bits/stdc++.h> 
//     void heapify(std::vector<int> &arr, int n, int i) {
//         int largest = i;
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;

//         if (left < n && arr[left] > arr[largest]) {
//             largest = left;
//         }

//         if (right < n && arr[right] > arr[largest]) {
//             largest = right;
//         }

//         if (largest != i) {
//             std::swap(arr[i], arr[largest]);
//             heapify(arr, n, largest);
//         }
//     }
// vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
//          std::vector<int> ans;

//         for (auto i : arr1) {
//             ans.push_back(i);
//         }

//         for (auto i : arr2) {
//             ans.push_back(i);
//         }

//         int size = ans.size();
//         for (int i = size / 2 - 1; i >= 0; i--) {
//             heapify(ans, size, i);
//         }

//         return ans;
// }


//minimum cost of rope
// long long connectRopes(int* arr, int n)
// {
//             priority_queue<long long, vector<long long>, greater<long long>> pq;
        
//         for(int i=0; i<n; i++){
//             pq.push(arr[i]);
//         }
        
//         long long  cost = 0;
//         while(pq.size()>1){
//             long long a = pq.top();
//             pq.pop();
//             long long b = pq.top();
//             pq.pop();
            
//             long long sum =a+b;
//             cost += sum;
//             pq.push(sum);
//         }
//         return cost;
// }

//tc O(nlogn) && sc O(n)



//bst to min heap
// #include<queue>
// void solve(BinaryTreeNode<int>* root, vector<int> &ans){
//        if(root == NULL)
//            return;
    
//     solve(root->left, ans);
//     ans.push_back(root->data);
//     solve(root->right, ans);
// }
// BinaryTreeNode<int>* convert(BinaryTreeNode<int>* root, vector<int> &ans, int &i){
//     if(root == NULL)
//         return NULL;
    
//     root->data = ans[i++];
//     convert(root->left, ans, i);
//     convert(root->right, ans, i);
// }
// BinaryTreeNode<int>* bstToMinHeap(BinaryTreeNode<int>* root) 
// {
//     vector<int> ans;
//     solve(root, ans);
//     priority_queue<int, vector<int>, greater<int>> min;
    
//     for(int i = 0; i < ans.size(); i++){
//         min.push(ans[i]);
//     }
//     int i = 0;
//     convert(root, ans, i);
//     return root;
// }