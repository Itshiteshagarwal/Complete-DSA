#include<bits/stdc++.h>
using namespace std;
  class queue{
    int *arr;
    int front;
    int rear;
    int size;
  }
public:
queue(){
    size = 10001;
    arr = new int[size];
    front =0;
    rear =0;
}

bool isempty(){
    if(front == rear){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int data){
    if(rear == size){
        cout<<"queue is full";
    }
    else{
        arr[rear] = data;
        rear++;
    }
}

int dequeue(){
    if(front == rear){
        return -1;
    }
    else{
        int ans = arr[front];
        arr[front] = -1;
        front++;
    if(front == rear){
        front =0;
        rear =0;
    }
    return ans;
    }
}    

int front{
    if(front == rear){
        return -1;
    }
    else{
        arr[front];
    }
}

int main()
{

    // queue<int> q;
    // q.push(11);
    // cout<<"front of queue is "<<q.front()<<endl;
    // q.push(15);
    // cout<<"front of queue is "<<q.front()<<endl;
    // q.push(13);
    // cout<<"front of queue is "<<q.front()<<endl;
    // cout<<"size of queue is "<<q.size()<<endl;
    // q.pop();
    // cout<<"size of queue is "<<q.size()<<endl;

    // if(q.empty()){
    //     cout<<"queue is empty"<<endl;
    // }
    // else{
    //     cout<<"queue isnot empty"<<endl;
    // }


return 0;
}