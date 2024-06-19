 //complete binary tree
 //->every level is completely filled expect the last level
 //-> nodes always added fron the left side

//heap -> maxheap - har node ka child parent se small hoga
// minheap - parent node child se choti hogi

 //node => i*index;
 //left child -> 2*i 
 //right child 2*i+1
 //parent i/2


 //time complexity of insertion O(logn) 

#include<bits/stdc++.h>
using namespace std;
//reate a class for cbst
class heap{
public:
     int arr[100];
     int size = 0;

     heap(){
        arr[0] = -1;
        size = 0;
     }
//inserting nodes in cbst
     void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
     }

    void print(){
        for(int i =1; i<= size; i++){
            cout<<arr[i];
        }cout<<endl;
    }
//delete a root node from cbt
    void deletefromheap(){
        if(size == 0){
            cout<<"nothing to delete";
        } cout<<endl;

        arr[1] = arr[size];
        size --;

        int i = 1;
       while(i<size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex<size && arr[i]<arr[leftindex]){
                swap(arr[i] , arr[leftindex]);
                i = leftindex;
            }

            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else{
                return ;
            }
       }
    }
};
//heapify algorithm
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
        if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap (arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

} // time complexity O(log n)

//algo for sorting the heap
void heapsort(int arr[], int n){
    int size = n;

    while(size>1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr,size, 1);
    }

}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();
    h.print();

//for check that it is acbst or nt we use heapify algo
    int arr[6] = {-1,54,53,55,52,50};
    int n =5;
    //heap creation
    for(int i =n/2; i>0; i--){
        heapify(arr, n , i);
    }
//printing the heap;
    cout<<"printing the array"<<endl;
    for (int i = 1; i <=n; i++)
    {
       cout<< arr[i]<< " ";
    }cout<<endl;

//sorting the heap
    heapsort(arr, n);
    cout<<"printing the array"<<endl;
//again printing the heap
    for (int i = 1; i <=n; i++)
    {
       cout<< arr[i]<< " ";
    }cout<<endl;

    

    //priority queue
    cout<<"using priorty queue here";
    // max heap

    priority_queue<int> pq;
    pq.push(5);
    pq.push(7);
    pq.push(9);
    pq.push(11);
    pq.push(13);
    pq.push(15);

    cout<<"element at top root"<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top root"<<pq.top()<<endl;
    cout<<" size of max heap is"<<pq.size()<<endl;
    if(!pq.empty()){
        cout<<"pq not empty"<<endl;

    }
    else{
        cout<<"pq is completely empty"<<endl;
    }

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(12);
    minheap.push(17);
    minheap.push(19);
    minheap.push(14);
    minheap.push(11);

    cout<<"element at top root"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top root"<<minheap.top()<<endl;
    cout<<" size of min heap is"<<minheap.size()<<endl;
    if(!minheap.empty()){
        cout<<"minheap not empty"<<endl;

    }
    else{
        cout<<"minheap is completely empty"<<endl;
    }
    return 0;
}