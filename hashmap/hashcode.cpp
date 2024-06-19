#include<bits/stdc++.h>
using namespace std;
int main(){

    return 0;
}
//here we gonna use bucket arrayfor storing the key value pairs 
//ans we use hash code for it 
//hash code is the combination of hash code and compression function

//to convert a data type into int for mapping the data from array of index we use hash code

//to make the output in the range which we got from the hash code we use copression f/n for it

//  basically hash code is use for conversion to int ans uniform distribution


//collision 
//in hash code different string whcih hold same character hash code same generates for them and this process is known as collision 

//collision handling techniques
//open hashing - put at same place (in open hasing on particular index where we need to store same string there is a seprate chain presents like linked list and data start accordingly fron start node)

//closed addressing - it put the same string to another place by using this f/n
//Hi(a) = h(a)+ Fi(a)

//in ith attempt find the place where we have to store
//in linear probing fi is always equal to i

//quadtratic probic - in this the f(i) is always equal to (i)2


//complexity analysis
//hashcode = tcO(1)

// in map if(n/b)>0.7 it means its complexity is O(n)
// if the value of n means entries are increase in map in this case we also need to increase the number of boxes as well to maintain the tc
//steps
//rehashing
//no of bucket * 2
//n/b is become half
//rehash all entries
//same steps are going to apply for delete and searching
