//House Robber II

#include <bits/stdc++.h>
long long solve(vector<int>&values)
{
    long long prev1=values[0];
    long long prev2=0;
    for(int i=1;i<values.size();++i){
    long long pic = values[i];
    if(i>1)pic+=prev2;
    long long notPic= prev1;
      long long curr=max(pic,notPic);
      prev2=prev1;
      prev1=curr;
    } 
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int size=valueInHouse.size();
    if(size==1)return valueInHouse[0];
    vector<int>temp1,temp2;
    for(int i=0;i<size;++i)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=size-1)temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1),solve(temp2));
}