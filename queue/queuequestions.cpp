//reverse a queue 
// class Solution
// {
//     public:
//     queue<int> rev(queue<int> q)
//     {
//         stack<int> s;
        
//         while(!q.empty()){
//             int element = q.front();
//             q.pop();
//             s.push(element);
//         }
        
//         while(!s.empty()){
//             int element =s.top();
//             s.pop();
//             q.push(element);
//         }
//         return q;
//     }
// }; time and space complex - O(n)


//First negative integer in every window of size K
// vector<long long> printFirstNegativeInteger(long long int A[],
//                                              long long int N, long long int K) {
//          deque<long long int> dq;
//          vector<long long> ans;
//          int negative = -1;
         
//          //process first window
//          for(int i=0; i<K; i++) {
//              if(A[i] < 0) {
//                  dq.push_back(i);
//              }
//          }
         
//          //push ans for FIRST window
//          if(dq.size() > 0) {
//              ans.push_back(A[dq.front()]);
//          }
//          else
//          {
//              ans.push_back(0);
//          }
         
//          //now process for remaining windows
//          for(int i = K; i<N; i++) {
//              //first pop out of window element
             
             
//              if(!dq.empty() && (i - dq.front())>=K ) {
//                  dq.pop_front();
//              }
             
//              //then push current element
//              if(A[i] < 0)
//                 dq.push_back(i);
             
//             // put in ans
//             if(dq.size() > 0) {
//                  ans.push_back(A[dq.front()]);
//             }
//             else
//             {
//                 ans.push_back(0);
//             }
//          }
//          return ans;
//  }


//reverse first k elements of queue
// #include <bits/stdc++.h> 
// queue<int> reverseElements(queue<int> q, int k)
// {
//        stack<int> s;
//     for(int i =0; i<k; i++){
//         int value = q.front();
//         q.pop();
//         s.push(value);
//     }
    
//     while(!s.empty()){
//         int value = s.top();
//         s.pop();
//         q.push(value);
//     }
    
//     int t = q.size() -k;
//     while(t--){
//         int value = q.front();
//         q.pop();
//         q.push(value);
//     }
//     return q;
// } time and space complexity O(n)


//First Non-Repeating character in stream
// class Solution {
// 	public:
// 		string FirstNonRepeating(string A){
// 		    map<char, int> m;
// 		    string ans = "";
// 		    queue<char> q;
		    
// 		    for(int i=0; i<A.length(); i++) {
// 		        char ch = A[i];
		        
// 		        q.push(ch);
// 		        m[ch]++;
		        
// 		        while(!q.empty()) {
// 		            if(m[q.front()] > 1){
// 		                q.pop();
// 		            }
// 		            else
// 		            {
// 		                ans.push_back(q.front());
// 		                break;
// 		            }
// 		        }
// 		        if(q.empty()){
// 		            ans.push_back('#');
// 		        }
// 		    }
// 		    return ans;
// 		}

// };


//circular tour petrol pump
// #include <bits/stdc++.h> 
// int tour(petrolpump p[], int n){

//     int deficit = 0;
//     int balance =0;
//     int start = 0;
//     for (int i = 0; i < n; i++)
//     {
//         balance += p[i].petrol - p[i].distance;
//         if(balance<0){
//             deficit += balance;
//             start = i+1;
//             balance = 0;
//         }
//     }
//     if(deficit+balance>=0){
//         return start;

//     }else{
//         return -1;
//     }
    
// }


//Interleave The First Half Of The Queue With The Second Half
// #include <bits/stdc++.h> 
// void interLeaveQueue(queue < int > & q) {
//     int n = q.size();
//     queue<int> newq;

//     for(int i=0; i<n/2; i++){
//         newq.push(q.front());
//         q.pop();
//     }

//     while(!newq.empty()){ 
//         int value = newq.front();
//         newq.pop();
//         q.push(value);

//         int val = q.front();
//         q.pop();
//         q.push(val);
//     }
// }


//k queue
// #include<iostream>
// using namespace std;

// class kQueue {

//     public:
//         int n;
//         int k;
//         int *front;
//         int *rear;
//         int *arr;
//         int freeSpot;
//         int *next;

//     public:
//         kQueue(int n, int k) {
//             this -> n = n;
//             this -> k = k;
//             front = new int[k];
//             rear = new int[k];
//             for(int i=0; i<k; i++) {
//                 front[i] = -1;
//                 rear[i] = -1;
//             }

//             next = new int[n];
//             for(int i=0; i<n; i++) {
//                 next[i] = i+1;
//             }
//             next[n-1] = -1;
//             arr = new int[n];
//             freeSpot = 0;
//         }    

//         void enqueue(int data, int qn) {

//             //overflow
//             if( freeSpot == -1) {
//                 cout << "No Empty space is present" << endl;
//                 return;
//             }

//             //find first free index
//             int index = freeSpot;

//             //update freespot
//             freeSpot = next[index];

//             //check whther first element
//             if(front[qn-1] == -1){
//                 front[qn-1] = index;
//             }
//             else{
//                 //link new element to the prev element
//                 next[rear[qn-1]] = index;
//             }

//             //update next
//             next[index] = -1;

//             //update rear
//             rear[qn-1] = index;

//             //push element
//             arr[index] = data;
//         }

//         int dequeue(int qn) {
//             //underflow 
//             if(front[qn-1] == -1)
//             {
//                 cout << "Queue UnderFlow " << endl;
//                 return -1;
//             }

//             //find index to pop
//             int index = front[qn-1];

//             //front ko aage badhao
//             front[qn-1] = next[index];

//             //freeSlots ko manage karo
//             next[index] = freeSpot;
//             freeSpot = index;
//             return arr[index];
//         }

// };

// int main() {

//     kQueue q(10, 3);
//     q.enqueue(10, 1);
//     q.enqueue(15,1);
//     q.enqueue(20, 2);
//     q.enqueue(25,1);

//     cout << q.dequeue(1) << endl;
//     cout << q.dequeue(2) << endl;
//     cout << q.dequeue(1) << endl;
//     cout << q.dequeue(1) << endl;

//     cout << q.dequeue(1) << endl;

//     return 0;
// }
//time complexity O(n) space O(1)



//Sum of min & max elements of all subarray of size K
#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
} //time complexity O(n)