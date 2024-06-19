#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        //constructor
        Node(int d){
            this ->data =d;
            this ->prev = NULL;
            this ->next =NULL;
        }

        ~Node(){
            int value = this -> data;
            if(next!= NULL){
                delete next;
                next = NULL;
            }
            cout <<" memory free for node with data"<<value<<endl;
        }
};

//traverse a linked list
    void print(Node* head){
    Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
}

//gives the length of linked list
    int getlength(Node* head){
        int len = 0;
         Node* temp = head;

        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }

      void Insertathead(Node* &head, int d){

        if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        }
        else{
        Node* temp = new Node(d);
        temp -> next = head;
        head ->prev = temp;
        head = temp;
        }
    }

    void Insertattail(Node* &tail, int d){
        if(tail == NULL){
        Node* temp = new Node(d);
        tail= temp;
        }
        Node* temp = new Node(d);
        temp-> prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void Insertatposition(Node* &head, Node* &tail, int position, int d){
        //insert at start
        if(position==1){
            Insertathead(head, d);
            return;
        }
         Node* temp = head;
        int cnt =1;

        while(cnt< position-1){
            temp = temp->next;
            cnt++;
        }

        if(temp->next == NULL){
        Insertattail(tail, d);
        return;
        }

        //creating a node for d
        Node* nodetoinsert = new Node(d);
        nodetoinsert-> next = temp ->next;
        temp -> next -> prev = nodetoinsert;
        temp ->next = nodetoinsert;
        nodetoinsert ->prev = temp;

    }

    void deleteNode(int position, Node* & head){
        //delete first or start node
        if(position ==1){
            Node* temp = head;
            temp -> next ->prev = NULL;
            head = head -> next;
            //memory free
            temp -> next = NULL;
            delete temp;
        }
        else{
            //deleting any middle or last node
            Node* curr  = head;
            Node* prev = NULL;

            int cnt = 1 ;
            while(cnt<position){
                prev = curr;
                curr = curr -> next;
                cnt++;
            }
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;

        }
    }
int main(){
    Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    cout<<getlength(head)<<endl;

    Insertathead(head, 11);    
    print(head);

    Insertathead(head, 13);    
    print(head);

    Insertathead(head, 8);    
    print(head);

    Insertattail(tail, 24);
    print(head);

    Insertatposition(head, tail, 3, 16);
    print(head);

    Insertatposition(head, tail, 1, 7);
    print(head);

    Insertatposition(head, tail, 8, 26);
    print(head);
    cout<<"head"<< head -> data <<endl;
    cout<<"tail"<< tail -> data <<endl;
    
    deleteNode(1, head);
    print(head);
    return 0;
}