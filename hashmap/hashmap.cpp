//by using hash table insertion deletion and searching done in O(1) constant time
#include<bits/stdc++.h>
using namespace std;
int main(){
    //creation of unorderd map
    unordered_map<string, int>m;
    //insertion  in maps
    //way1
    pair<string, int> p = make_pair("babber", 3);
    m.insert(p);
    //way2
    pair<string, int> pair2("love" , 2);
    m.insert(pair2);
    //way3
    m["mera"] = 1;
    m["mera"] = 2;

    //find in hashmap/ searching in hashmep

    cout<<m["mera"]<<endl;
    cout<<m.at("babber")<<endl;

//it makes a entry for unknown key corresponding to 0
    cout<<m["unknown key"]<<endl;

//it gives error
    cout<<m.at("unknown key")<<endl;

//size checking
cout<<m.size()<<endl;


//to check presence - if absent - 0 & if present - 1
cout<<m.count("bro")<<endl;


//erase function
m.erase("love");
cout<<m.size()<<endl;

//traversal in map
// for(auto i:m){
//     cout<<i.first<<" "<< i.second<<endl;
// }

//iterator
unordered_map<string, int> :: iterator it = m.begin();
while(it != m.end()){
 cout<<it->first <<" "<<it->second<<endl;
 it++;
}

    return 0;
}
