
//is sorted array
// #include<bits/stdc++.h>
// using namespace std;
// bool issorted(int arr[], int size){
//     if(size==0 || size ==1){
//         return true;
//     }
//     if(arr[0]>arr[1]){
//         return false;
//     }
//     else{
//         bool remainingpart = issorted(arr+1, size-1);
//         return remainingpart;
//     }
// }

// int main(){
// int arr[5] = {2,4,6,8,9};
// int size = 5;

// bool ans = issorted(arr, size);
// if(ans){
//     cout<<"array is sorted"<<endl;
// }
// else{
//     cout<<"array isn't sorted"<<endl;
// }
//     return 0;
// }


//sum of array

// #include<bits/stdc++.h>
// using namespace std;
// int getsum(int arr[], int size){
//     if(size==0){
//         return 0;
//     }
//     if(size ==1){
//         return arr[0];
//     }
//     int remainpart = getsum(arr+1, size-1);
//     int sum = arr[0]+remainpart;
//     return sum;
// }
// int main(){

// int arr[5] = {2,4,6,8,9};
// int size = 5;
// int sum = getsum(arr , size);
// cout<<"sum is"<<sum<<endl;
//     return 0;
// }



//linear search
// #include<bits/stdc++.h>
// using namespace std;
// void print(int arr[], int n){
//     cout<<"size of array is"<<n<<endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;
    
// }
// bool search(int arr[], int size, int key){
// print(arr, size);

//     if(size==0){

//         return false;
//     }
//     if(arr[0]==key){
//         return true;
//     }
//     else{
//         bool remainingpart = search(arr+1, size-1, key);
//         return remainingpart;
//     }
// }
// int main(){
// int arr[5] = {3,5,1,2,6};
// int size = 5;
// int key =2;
//  bool ans = search(arr,size, key);
// if(ans){
//     cout<<"present"<<endl;
// }
// else{
//     cout<<"not present"<<endl;
// }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// void print(int arr[], int s, int e) {

//     for(int i=s; i<=e; i++) {
//         cout << arr[i] << " ";
//     } cout << endl;
// }

// bool binarySearch(int *arr, int s, int e , int k ) {

//     //base case

//     //element not found
//     if(s>e)
//         return false;

//     int mid = s + (e-s)/2;

//     //element found
//     if(arr[mid] == k)
//         return true;

//     if(arr[mid] < k) {
//         return binarySearch(arr, mid+1, e, k);
//     }
//     else{
//         return binarySearch(arr, s, mid-1, k);
//     }
// }


// int main() {

//     int arr[11] = {2,4,6,10,14,18,22,38,49,55,222};
//     int size = 11;
//     int key = 222;

//     cout << "Present or not " << binarySearch(arr, 0, size-1, key) << endl;

//     return 0;
// }



//code studio binary search
// int solve(int *arr, int s, int e , int k ) {

//     //base case

//     //element not found
//     if(s>e)
//         return -1;

//     int mid = s + (e-s)/2;

//     //element found
//     if(arr[mid] == k)
//         return mid;

//     if(arr[mid] < k) {
//         return solve(arr, mid+1, e, k);
//     }
//     else{
//         return solve(arr, s, mid-1, k);
//     }
// }

// int binarySearch(int *input, int n, int val)
// {
//    int ans = solve(input,.0,n-1,val);
// }