//delete middle element of stack
// #include <bits/stdc++.h> 
// void solve(stack<int>&inputStack, int count, int size) {
//     //base case
//     if(count == size/2) {
//         inputStack.pop();
//         return ;
//     }
    
//     int num = inputStack.top();
//     inputStack.pop();
    
// 	//RECURSIVE CALL
//     solve(inputStack, count+1, size);
    
//     inputStack.push(num);
    
// }

// void deleteMiddle(stack<int>&inputStack, int N){
	
//   	int count = 0;
//     solve(inputStack, count, N);
   
// }



//valid parentheses in stack
// bool isValidParenthesis(string expression)
// {
//   stack<char>s;

//       for(int i=0; i<expression.length(); i++){
//           char ch = expression[i];

//           //if openning bracket , stack push
//           //if close bracket, stack check an pop

//           if(ch == '{' || ch == '(' || ch== '['){
//               s.push(ch);
//           }
//           else{
//             if (!s.empty()) {
//               char top = s.top();
//               if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
//                   (ch == ']' && top == '[')) {
//                 s.pop();
//               } else {
//                 return false;
//               }
//             } else {
//               return false;
//             }
//           }
//       }


//       if(s.empty()){
//           return true;
//       }
//       else{
//           return false;
//       }
// }


//insert an element in the bottom of given stack
// #include <bits/stdc++.h> 
// void solve(stack<int>& s, int x){
//     if(s.empty()){
//         s.push(x);
//         return;
//     }
//     int num =s.top();
//     s.pop();

//     solve(s, x);
//     s.push(num);
// }
// stack<int> pushAtBottom(stack<int>& myStack, int x) 
// {
//      solve(myStack,x);
//      return myStack;
// }



//reverse a stack using recursion
// insertatbottom(stack<int> &s, int element){
//     if(s.empty()){
//         s.push(element);
//         return;
//     }

//     int num = s.top();
//     s.pop();

//     insertatbottom(s, element);
//     s.push(num);
// }
// void reversestack(stack<int> &stack){
//     if(stack.empty()){
//         return;
//     }
//     int num = stack.top();
//     stack.pop;

//     reversestack(stack);
//     insertatbottom(stack, num);
// }



//redundant bracket
// #include <bits/stdc++.h> 

// bool findRedundantBrackets(string &s)
// {
//     stack<char> st;
//     for(int i=0; i<s.length(); i++) {
//         char ch =s[i];
        
//         if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
//             st.push(ch);
//         }
//         else
//         {
//             //ch ya toh ')' hai or lowercase letter
            
//             if(ch == ')') {
//                 bool isRedundant = true;
                
//                 while(st.top() != '(') {
//                     char top = st.top();
//                     if(top == '+' ||top == '-' || top == '*' || top == '/') {
//                         isRedundant = false;
//                     }
//                     st.pop();
//                 }
                
//                 if(isRedundant == true)
//                     return true;
//                 st.pop();
//             }
            
//         } 
//     }
//     return false;
// } time complexity O(n)



//next smaller element
// #include<stack>

// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     stack<int>s;
//     s.push(-1);
//     vector<int> ans(n);
    
//     for(int i = n-1; i>=0; i--){
//         int curr = arr[i];
//         while(s.top()>=curr){
//             s.pop();
//         }

//         ans[i] = s.top();
//         s.push(curr);
//     }
//     return ans;
//     }


//largest rectangular area in histogram
// class Solution {
// private:
//     vector<int> nextSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=n-1; i>=0 ; i--) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
    
//     vector<int> prevSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=0; i<n; i++) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans; 
//     }
    
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerElement(heights, n);
            
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
// }; time ans space complexity are O(n)


//celebrity problem(amazon)
// class Solution 
// {
//     private:
//     bool knows(vector<vector<int> >& M, int a, int b, int n) {
//         if(M[a][b] == 1)
//             return true;
//         else
//             return false;
//     }
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n) 
//     {
//         stack<int> s;
//         //step1: push all element in stack
//         for(int i=0; i<n; i++) {
//             s.push(i);
//         }   
        
//         //step2: get 2 elements and copare them
        
//         while(s.size() > 1) {
            
//             int a = s.top();
//             s.pop();
            
//             int b = s.top();
//             s.pop();
            
//             if(knows(M,a,b,n)){
//                 s.push(b);
//             }
//             else
//             {
//                 s.push(a);
//             }
//         }
//         int ans = s.top();
//         //step3: single element in stack is potential celeb
//         //so verify it
        
//         int zeroCount = 0;
        
//         for(int i=0; i<n; i++) {
//             if(M[ans][i] == 0)
//                 zeroCount++;
//         }
        
//         //all zeroes
//         if(zeroCount != n)
//             return -1;
        
//         //column check
//         int oneCount = 0;
        
//         for(int i=0; i<n; i++) {
//             if(M[i][ans] == 1)
//                 oneCount++;
//         }
        
//         if(oneCount != n-1)
//             return -1;
        
//         return ans;
        
//     }
// }; time and space complexity O(n)


//max rectangle area in 1's with binary
// class Solution{
//   private:
  
//   vector<int> nextSmallerElement(int *arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=n-1; i>=0 ; i--) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
    
//     vector<int> prevSmallerElement(int* arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=0; i<n; i++) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans; 
//     }    
    
  
  
//   int largestRectangleArea(int* heights, int n) {
//         //int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerElement(heights, n);
            
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
//   public:
//     int maxArea(int M[MAX][MAX], int n, int m) {
        
//         //compute area for first row
//         int area = largestRectangleArea(M[0], m);
        
//         for(int i = 1; i<n; i++) {
//             for(int j = 0; j<m; j++) {
                
//                 //row udpate: by adding previous row's value
//                 if(M[i][j] != 0)
//                     M[i][j] = M[i][j] + M[i-1][j];
//                 else
//                     M[i][j] = 0;
//             }
            
//             //entire row is updated now
//             area = max(area, largestRectangleArea(M[i],m));
            
//         }
//         return area;
//     }
// };



// n stacks in a array
#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
     
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        
        //find index
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
}; //time complex - O(1) space complex - O(s+n)



//Design a stack that supports getMin() in O(1) time and O(1) extra space
#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

//sweets and ants
#include <bits/stdc++.h> 
vector<int> sweet(vector<int> S)
{
	int n = S.size();
	stack<int>st;
	vector<int>ans(n,0);

	for(int i=0; i<n; i++){
		st.push(i+1);

		while(!st.empty() && (i+1-st.top())<S[i]){
			ans[st.top()-1] = 1;
			st.pop();
		}
	}
	return ans;
}