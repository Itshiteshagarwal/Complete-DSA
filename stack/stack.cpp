#include<bits/stdc++.h>
using namespace std;
class Stack{
    //properties
public:
int *arr;
int top;
int size;

//behaviour
Stack(int size){
    this ->size = size;
    arr = new int[size];
    top = -1;
}

    //functions
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }else{
        cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }
    int peek(){
        if(top>=0){
        return arr[top];
        }
        else{
            cout<<"stck is empty";
            return -1;
        }
    }
    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Stack st(5);
    st.push(22);
    st.push(42);
    st.push(44);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.push(66);
    st.push(12);
    st.push(8);
    cout<<st.peek()<<endl;
    if(st.isempty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }





    // stack<int>s;

    // //push
    // s.push(2);
    // s.push(5);

    // //pop
    // s.pop();

    // cout<<"printing top element"<<s.top()<<endl;
    // if(s.empty()){
    // cout<<"is empty"<<endl;  
    // }
    // else{
    //     cout<<"not empty"<<endl;
    // }

    // cout<<"the size of stack is"<<s.size()<<endl;
    return 0;
}


//question -> Two stack
// #include <bits/stdc++.h> 
// class TwoStack {
//     int *arr;
//     int top1;
//     int top2;
//     int size;

// public:

//     // Initialize TwoStack.
//     TwoStack(int s) {
//         this->size = s;
//         top1 = -1;
//         top2 = s;
//         arr= new int[s];
//     }
    
//     // Push in stack 1.
//     void push1(int num) {
//         if(top2 - top1>1){
//             top1++;
//             arr[top1] =num;
//         }
//     }

//     // Push in stack 2.
//     void push2(int num) {
//         if(top2-top1>1){
//             top2--;
//             arr[top2] = num;
//         }
//     }

//     // Pop from stack 1 and return popped element.
//     int pop1() {
//         if(top1>=0){
//             int ans = arr[top1];
//             top1--;
//             return ans;
//         }
//         else{
//             return -1;
//         }
//     }

//     // Pop from stack 2 and return popped element.
//     int pop2() {
//          if(top2<size){
//             int ans = arr[top2];
//             top2++;
//             return ans;
//         }
//         else{
//             return -1;
//         }
//     }
// };


//reverse a string using stack
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// string str = "abcde";
// Stack<char> s;

// for (int i = 0; i < str.length; i++)
// {
//     char ch = str[i];
//     s.push(ch);
// }

// string ans = "";
// while (!s.empty())
// {
//      char ch = s.top();
//      ans.push_back(ch);

//      s.pop();
// }
// cout<<"ans is"<<ans<<endl;
// return 0;

// } time ans space both O(n)
