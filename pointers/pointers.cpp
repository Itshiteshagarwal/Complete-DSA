#include<bits/stdc++.h>
using namespace std;
void print(int *p){
    cout<<p<<endl;
    cout<<*p<<endl;
}

void update(int *p){
    *p = *p+1;
}
int getsum(int arr[], int n){
    cout<<sizeof(arr)<<endl;
    int sum = 0;
    for(int i =0; i<=n; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
// #include<bits/stdc++.h>
// using namespace std;
// int main(){ 

//     int x= 10;
//     int *p =&x; // & uses for check the address
//     cout<<x<<endl;
//     cout<<p<<endl;
//     cout<<*p<<endl;  //pointer cancel pointer
//     cout<<&x<<endl;
//     cout<<"the size of x is: "<<sizeof(x)<<endl;
//     cout<<"the size of pointer is :"<<sizeof(p)<<endl;
//     return 0;
// }



//double pointer, array pointer, char array pointer
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// int arr[10] = {2,5,6};
// cout<<"address of first memory block is"<<arr<<endl;
// cout<<"address of first memory block is"<<&arr[0]<<endl;

// cout<<"first value of array is :  "<<*arr<<endl;
// cout<<"next value of array is :  "<<*arr+1<<endl;
// cout<<"next array value of array is :  "<<*(arr+1)<<endl;
// cout<<"next value of array is :  "<<(*arr)+1<<endl;


    // return 0;
    // } 


//difference btw array and pointers
// int temp[10] = {1,2,3};
// cout<<sizeof(temp)<<endl;
// cout<<"1st char"<<sizeof(*temp)<<endl;
// cout<<"2nd char"<<sizeof(&temp)<<endl;
// cout<<sizeof(temp)<<endl;
// int *p = &temp[0];
// cout<<sizeof(p)<<endl;
// cout<<sizeof(*p)<<endl;
// cout<<sizeof(&p)<<endl;



// int a[20] = {1,2,3,5};
// cout<<&a[0]<<endl;
// cout<<&a<<endl;
// cout<<a<<endl;

// int *p = &a[0];
// cout<<p<<endl;
// cout<<*p<<endl;
// cout<<&p<<endl;



//symbol table
// int arr[10];
//error
//arr =arr+1;

// int *ptr = &arr[0];
// cout<<ptr<<endl;
// ptr = ptr+1;
// cout<<ptr<<endl;


//char array
// int arr[5] = {1,2,3,4,5};
// char ch[6] = "abcde";
 
//  cout<<arr<<endl;
//  cout<<ch<<endl;

//  char *c = &ch[0];
// cout<<c<<endl;


// char temp = 'z';
// char *p = &temp;
// cout<<p<<endl;



//pointers and functions

int value = 5;
int *p = &value;
// print(p);
cout<<"before"<<*p<<endl;
update(p);
cout<<"after"<<*p<<endl;


int arr[5] = { 1,2,3,4,5};
cout<<"sum is"<<getsum(arr, 5)<<endl;
return 0;
}