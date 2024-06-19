
//for factorial
// #include<bits/stdc++.h>
// using namespace std;
// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     int num = factorial(n-1);
//     int deno  = n*num;
//     return deno;
// }
// int main(){
          
//  int n;
//  cin>>n;
//  int ans =  factorial(n);
//  cout<<ans<<endl;


//     return 0;
// }



//2^n code

// #include<bits/stdc++.h>
// using namespace std;
// int power(int n){
//     if(n ==0){
//         return 1;
//     }

//         int small = power(n-1);
//         int big = 2*small;
//         return big;
// }
// int main(){

//     int n;
//     cin>>n;

//     int ans = power(n);
//     cout<<ans<<endl;
//     return 0;

// }

//for print counting
// #include<bits/stdc++.h>
// using namespace std;

// void print(int n){
//     if(n==0){
//         return ;
//     }
//     cout<<n<<endl;
//     print(n-1);
// }
// int main(){
//     int n;
//     cin>>n;

//     print(n);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0){
        return ;
    }
  
    print(n-1);
      cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;

    print(n);
    return 0;
}