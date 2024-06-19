#include<bits/stdc++.h>
using namespace std;

void update (int **p2){
    // p = p+1; ---> no changes
    // *p=*p+1; ---> p ke address me changes hue

    // **p2 = **p2+1; ---> i ka value change krega
}
int main(){
    //double pointers
    // int i = 5;
    // int *p = &i;
    // int **p2 = &p;

    // cout<<endl<<"abhi tak sab mast chal rha"<<endl;
    // cout<<"printing p "<<p<<endl;
    // cout<<"address of p"<<&p<<endl;
    // cout<<*p2<<endl; 
    // cout<<*p<<endl;
    // cout<<**p2<<endl;
    // cout<<i<<endl; 


    //pointers and functions
int  i = 5;
int *p = &i;
int **p2 = &p;

cout<<"before"<<i<<endl;
cout<<"before"<<p<<endl;
cout<<"before"<<p2<<endl;
update(p2);
cout<<"after"<<i<<endl;
cout<<"after"<<p<<endl;
cout<<"after"<<p2<<endl;


    return 0;
}