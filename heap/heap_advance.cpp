//kth largest sum subarray
#include<algorithm>
// int getKthLargest(vector<int> &arr, int k)
// {
// 	vector<int> sumstore;
// 	int n = arr.size();
// 	for(int i =0; i<n; i++){
// 		int sum =0;

// 		for(int j=i; j<n; j++){
// 			sum += arr[j];
// 			sumstore.push_back(sum);
// 		}
// 	}
// 	sort(sumstore.begin(), sumstore.end());
// 	return sumstore[sumstore.size()-k];
// }


//merege k sorted arrays
// #include <bits/stdc++.h> 
// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
// {
//     vector<int> ans;
//     priority_queue<int,vector<int>,greater<int>> p;
//     for(auto i:kArrays){
//       for (auto j : i) {
//         p.push(j);
//       }
//     }
//     while(!p.empty()){
//         ans.push_back(p.top());
//         p.pop();
//     }
//     return ans
//     }

//merge k sorted list
// #include<queue>
// class compare {
// public:
    
//     bool operator()(Node<int>* a, Node<int>* b) {
//         return a->data > b->data;
//     }
// };


// Node<int>* mergeKLists(std::vector<Node<int>*>& listArray) {
//     std::priority_queue<Node<int>*, std::vector<Node<int>*>, compare> minheap;
//     int k = listArray.size();
//     if (k == 0)
//         return nullptr;

//     for (int i = 0; i < k; i++) {
//         if (listArray[i] != nullptr) {
//             minheap.push(listArray[i]);
//         }
//     }

//     Node<int>* head = nullptr;
//     Node<int>* tail = nullptr;

//     while (!minheap.empty()) {
//         Node<int>* temp = minheap.top();
//         minheap.pop();

//         if (temp->next != nullptr) {
//             minheap.push(temp->next);
//         }

//         if (head == nullptr) {
//             head = temp;
//             tail = temp;
//         } else {
//             tail->next = temp;
//             tail = temp;
//         }
//     }

//     return head;
// } O(Nlogk) N -> total no of nodes in given array
//sc O(k)
