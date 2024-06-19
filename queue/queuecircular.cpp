#include<bits/stdc++.h>
using namespace std;
 class circularqueue{
    int *arr;
    int front;
    int rear;
    int size;


 public:
 circular queue(int n){
    size = n;
    arr = new int[n];
    front =  rear = -1;

 }

 bool nqueue(int value){
    if((front == 0 && rear == size-1)||(rear == (front-1)%(size-1))){
        cout<<"queue is full "<<endl;
        return false;
    }
    elseif(front == -1){

        front = rear = 0;
        // arr[rear] = value;
    }
    elseif(rear == size-1 && front!=0){
        rear = 0;
        // arr[rear] = value;

    }
    else{
        rear++;
        // arr[rear] = value;
    }
        arr[rear] = value;
        return true;
 }

 int dequeue(){
    if(front == -1){
        cout<<"queue is empty "<<endl;
        return false;
    }
    int ans = arr[front];
    arr[front] = -1;
    elseif(front == rear){
        front  = rear = -1;
    }
    elseif(front == size-1){
        front = 0;

    }
    else{
        front++;
    }
    return ans;
 }
 };