//rotate a linked list
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
Node *rotate(Node *head, int k)

{

     // Write your code here.

     queue<int>pq;

     Node *ptr = head;

     while(ptr!=NULL)

     {

          pq.push(ptr->data);

           ptr=ptr->next;

     }

 

     int n = pq.size();

     if(k==n || k%n==0)

     {

          return head;

     }

     int loop = k%n;

      int i = 0;

     while(i<n-loop)

     {

        pq.push(pq.front());

        pq.pop(); 

        i++;   

     }

     Node * res = new Node(0);

     Node *ptr1 = res;

     while(!pq.empty())

     {

          ptr1->next = new Node(pq.front());

          pq.pop();

          ptr1 = ptr1->next;

         

     }

  return res->next;

}