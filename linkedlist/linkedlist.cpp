#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    //constrctor uses
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this ->data;
        if(this->next != NULL){
            delete next;
            this ->next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }

};
//reference bcoz new copy na bne orignal me hi changes ho 
    void Insertathead(Node* &head, int d){
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }

    void Insertattail(Node* &tail, int d){
        Node* temp = new Node(d);
        tail ->next = temp;
        tail = temp;
    }

    void print(Node* &head){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp ->data<<" ";
            temp = temp->next;

        }
        cout<<endl;
    }

    void Insertatposition(Node* &head, Node* &tail,int position, int d){
        if(position == 1){
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
        Node* nodetoinsert = new Node(d);
        nodetoinsert-> next = temp ->next;
        temp -> next = nodetoinsert;
    }

    void deletenode(int position, Node* &head){
        Node* temp = head;
         if(position==1){
            head = head -> next;
            temp -> next = NULL;
            delete temp;
         }
         else{
            Node* currnt = head;
            Node* prev = NULL;

            int cnt =1;
            while(cnt < position){
                prev = currnt;
                currnt = currnt->next;
                cnt++;
            }
            prev->next = currnt->next;
            currnt -> next = NULL;
            delete currnt;
         }
    }

int main(){
    //new node 
    Node* node1 = new Node(10);
    // cout<<node1 ->data <<endl;
    // cout<<node1 ->next <<endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);
    Insertattail(tail, 12);
    print(head);
    Insertattail(tail, 15);
    print(head);
    Insertatposition(head, tail, 3, 14);
    print(head);

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    deletenode(1, head);
    print(head);
     deletenode(3, head);
    print(head);
    return 0;
}