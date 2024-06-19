// #include<bits/stdc++.h>
// using namespace std;
// void reachhouse(int src, int dest){
//     cout<<"source"<<src<<"destinatiom"<<dest<<endl;

// if(src==dest){
//     cout<<"at home"<<endl;
//     return;
// }
// //processing for next step
// src++;
// //recursive call
// reachhouse(src,dest);
// }
// int main(){
 
//     int src = 1;
//     int dest = 10;
//     cout<<endl;

//     reachhouse(src,dest);
//     return 0;
// }


// fibonacci series

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// if(n==0){
//     return 0;
// }
// if(n==1){
//     return 1;
// }
// int ans = fibo(n-1)+ fibo(n-2);
// return ans;
    
//     return 0;
// }



//climb stairs
// #include <bits/stdc++.h> 
// int countDistinctWays(int nStairs) {
//    if(nStairs<0){
//        return 0;
//    }
//     if(nStairs==0){
//         return 1;
//     }
    
//     int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
//     return ans;
// }




//say digits
#include<bits/stdc++.h>
using namespace std;

void saydigit(int n, string arr[]){
    if(n==0){
        return ;
    }
    //processing
    int digit = n%10;
    n = n/10;


//recursive call
saydigit(n, arr);
cout<<arr[digit]<<" ";
}
int main(){
        string arr[10] = {"zero", "one", "two", "three","four", "five", "six", "seven", "eight", "nine"};
int n;
cin>>n;
cout<<endl<<endl<<endl;
saydigit(n, arr);
cout<<endl<<endl<<endl;
    return 0;
}