//recursive f/n to print the digits of a number
// #include<bits/stdc++.h>
// using namespace std;

// int adddigit(int n){
//     int sum = 0;
//     while (n!=0)
//     {
//         sum = sum+n%10;
//         n = n/10;
//     }
//     return sum;
    
// }
// int main(){
// int n = 587;
// cout<<adddigit(n);
// }



//recursive function to print a multipication table
// #include<bits/stdc++.h>
// using namespace std;
// void MultiplicationTable(int num, int i)
// {
//     cout<<"\n";
//     cout<<num<<" X "<<i<<" = "<<num*i;
//     if(i<10)
//         return MultiplicationTable(num, i+1);
// }
// int main()
// {
//     int num,i=0;
//     cin>>num;
//     cout<<"Multiplication Table of "<<num<<" is:";
//     MultiplicationTable(num, 1);
// }




//use recursive function for print factorial of a number
#include<bits/stdc++.h>
using namespace std;
int printfacto(int n){

if(n==0){
    return 1;
}
    return n*printfacto(n-1);
}

int main(){
cout<<printfacto(4);
}