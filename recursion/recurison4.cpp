
//recursion with string
//reverse a string
// #include<bits/stdc++.h>
// using namespace std;
// void reverse(string& str, int i, int j){
//     if(i>j){
//         return;
//     }
//     swap(str[i], str[j]);
//     i++;
//     j--;

//     reverse(str, i , j);
// }
// int main(){
    
// string name = "hitesh";
// reverse(name, 0, name.length()-1);
// cout<<name<<endl;

//     return 0;
// }


//check wether the given string is plaindrome or not
// #include<bits/stdc++.h>
// using namespace std;
// bool checkpalindrome(string str , int i , int j){
// if(i>j){
//     return true;
// }

// if(str[i]!= str[j]){
//     return false;
// }
// else{
//     return checkpalindrome(str, i+1, j-1);
// }
// }
// int main(){
//     string name = "abbccbba";
//      bool ispalindrome = checkpalindrome(name, 0 , name.length()-1);
//      if(ispalindrome){
//         cout<<"it is a palindrome"<<endl;
//      }
//      else{
//         cout<<"it isn't palindrome"<<endl;
//      }

//     return 0;
// }



// power of any number
#include<bits/stdc++.h>
using namespace std;
int power(int a , int b){
    if(b==0){
        return 0;
    }
    if(b==1){
        return a;
    }

    int ans = power(a, b/2);

    if(b%2 ==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
int main(){
int a,b;
cin>>a>>b;

int ans = power(a,b);
cout<<"ans is"<<ans<<endl;
return 0;
}

//bubble sort

// #include<bits/stdc++.h>
// using namespace std;
// void sortarray(int arr[] , int n){
//     if(n==0 || n ==1){
//         return ;
//     }
//      for (int i = 0; i < n; i++){
//      if(arr[i]>arr[i+1]){
//         swap(arr[i],arr[i+1]);
//      }
//      }
//      sortarray(arr, n-1);
// }
// int main(){

//     int arr[5] = {2,5,1,6,9};
//     sortarray(arr, 5);
//     for (int i = 0; i < 5; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
//     return 0;

// }

// #include<bits/stdc++.h>
// using namespace std;
// void printfun(int test){
//     if (test<1)
//     {
//         return;
//     }
//     else{
//         cout<<test<<" ";
//         printfun(test-1);
//         cout<<test<<" ";
//         return;
//     }
    
// }
// int main(){
//     int test =3;
//     printfun(test);
//     return 0;
// }
