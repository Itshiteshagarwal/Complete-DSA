//reverse a linked list
// Node* reverseLinkedList(Node *head)
// {

//     if(head==NULL|| head->next ==NULL){
//         return head;
//     }


//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;
//     while(curr!= NULL){
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr= forward;
//     }

//     return prev;
// }   time complexity O(n)


//find the iddle element of a linked list
// int getlength(Node* head){
//     int len = 0;
//     while(head != NULL){
//     len++;
//     head = head->next;
//      }
//      return len;
// }

// Node *findMiddle(Node *head) {
//     int len = getlength(head);
//     int ans = (len/2);

//     Node* temp = head;
//     int cnt =0;
//     while(cnt<ans){
//         temp = temp->next;
//         cnt++;
//     }
//     return temp;
// }    time complexity O(n) and space O(1)

//----> another approach

// Node* getmiddle(Node* head){
//     if(head==NULL|| head->next == NULL){
//         return head;

//         //2nodes 
//         if(head->next ->next ==NULL){
//             return head->next;
//         }
//     }

//     Node* slow = head;
//     Node* fast  = head->next;

//     while(fast!= NULL){
//         fast = fast->next;
//         if(fast!= NULL){
//             fast = fast->next;
//         }
//         slow = slow->next;
//     }

// }
//  int getlength(Node* head){
//     int len = 0;
//     while(head != NULL){
//     len++;
//     head = head->next;
//      }
//      return len;
// }

// Node *findMiddle(Node *head) {
//   return getmiddle(head);
// }  



//reverse linked list in k groups
// Node* kReverse(Node* head, int k) {
//     //base call
//     if(head == NULL) {
//         return NULL;
//     }
    
//     //step1: reverse first k nodes
//     Node* next = NULL;
//     Node* curr = head;
//     Node* prev = NULL;
//     int count= 0;
    
//     while( curr != NULL && count < k ) {
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;
//         count++;
//     }
    
//     //step2: Recursion dekhlega aage ka 
//     if(next != NULL) {
//         head -> next = kReverse(next,k);
//     }
    
//     //step3: return head of reversed list
//     return prev;
// } space and time complexity both are O(n)



//circularly linked list questions
// bool isCircular(Node* head){

// // Write your code here.

// if(head==NULL){

// return true;

// }

// Node* previous=head;

// Node* temp=head->next;

// while(temp!=NULL && temp!=head){

// previous->next=NULL;

// previous=temp;

// temp=temp->next;

// }

// if(temp==NULL){

// return false;

// }

// return true;

// }


//detect and remove loop in linked list
//three type of uestions will be there
//1. detect cycle in linked list
//2. remove cycle from linked list
//3. begining/ start node of loop in linked list

// Node* floydDetectLoop(Node* head) {

//     if(head == NULL)
//         return NULL;

//     Node* slow = head;
//     Node* fast = head;

//     while(slow != NULL && fast !=NULL) {
        
//         fast = fast -> next;
//         if(fast != NULL) {
//             fast = fast -> next;
//         }

//         slow = slow -> next;

//         if(slow == fast) {
//             return slow;
//         }
//     }

//     return NULL;

// }

// Node* getStartingNode(Node* head) {

//     if(head == NULL) 
//         return NULL;

//     Node* intersection = floydDetectLoop(head);
    
//     if(intersection == NULL)
//         return NULL;
    
//     Node* slow = head;

//     while(slow != intersection) {
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }  

//     return slow;

// }

// Node *removeLoop(Node *head)
// {
//      if( head == NULL)
//         return NULL;

//     Node* startOfLoop = getStartingNode(head);
    
//     if(startOfLoop == NULL)
//         return head;
    
//     Node* temp = startOfLoop;

//     while(temp -> next != startOfLoop) {
//         temp = temp -> next;
//     } 

//     temp -> next = NULL;
//     return head;   
// }


//remove duplicates for a sorted list
// Node * removeDuplicates(Node *head)
// {
//     if(head == NULL){
//         return NULL;
//     }
//     //non empty
//     Node* curr = head;
//     while(curr!= NULL ){
//         if((curr->next != NULL)&& curr->data == curr->next->data){
//             Node* next_next = curr->next->next;
//             Node* nodetodelete = curr->next;
//             delete(nodetodelete);
//             curr->next = next_next;
//         }
//         else{
//             curr = curr->next;
//         }
//     }
//     return head;
// }


//remove duplicates from unsorted list
// Node *removeDuplicates(Node *head)
// {
//   	//empty List
//     if(head == NULL)
//         return NULL;
    
//     //non empty list
//     Node* curr = head;
    
//     while(curr != NULL) {
//         Node* temp = curr->next;
//        while(temp!=NULL){
//            if(curr->data = temp->data){
//                 Node* nodeToDelete = curr -> next;
//             delete(nodeToDelete);
//            }
//            else //not equal
//         {
//             curr = curr -> next;
//         }   
//        }
//     }
//         return head; 
// }  time complexity O(n2) and space O(1)


//map wali approach
// Node *removeDuplicates(Node *head)

 

// {

//     if(head==NULL ||head->next==NULL)

//     {

//         return head;

//     }

//     Node* curr=head;

//     Node* prev=NULL;

//     unordered_map<int,bool>visited; 

//     while(curr)

//     {

//         if(visited[curr->data]==true)

//         {

//             prev->next=curr->next;

//             curr=curr->next;

//         }

//         else

//         {

//             visited[curr->data]=true;

//             prev=curr;

//             curr=curr->next;

//         }      

//     }

//     return head;

// }


//sort 0's , 1's , 2's in a linked list
// Node* sortList(Node *head){
// int zerocount = 0;
// int onecount = 0;
// int twocount = 0;

// Node* temp = head;
// while(temp!=NULL){
//     if(temp->data = 0){
//         zerocount++;
//     }
//     else if (temp->data == 1){
//         onecount++;
//     }
//     else if (temp->data == 2){
//         twocount++;
//     }
//     temp = temp->next;
// }
// temp = head;
// while(temp!=NULL){
//     if(zerocount!= 0){
//         temp->data = 0;
//         zerocount--;
//     }
//     else if(onecount!=0){
//         temp->data =1;
//         onecount--;
//     }
//     else if(twocount!=0){
//         temp->data=2;
//         twocount--;
//     }
// }
// return head;
// } //time complex - O(n) space = O(1)

//another approach ------------->
// void insertAtTail(Node* &tail, Node* curr ) {
//     tail -> next = curr;
//     tail = curr;
// }


// Node* sortList(Node *head)
// {
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;
//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;
//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;
    
//     Node* curr = head;
    
//     // create separate list 0s, 1s and 2s
//     while(curr != NULL) {
        
//         int value = curr -> data;
        
//         if(value == 0) {
//             insertAtTail(zeroTail, curr);
//         }
//         else if(value == 1) {
//             insertAtTail(oneTail, curr);
//         }
//         else if(value == 2) {
//             insertAtTail(twoTail, curr);
//         }       
//         curr = curr -> next;
//     }
    
//     //merge 3 sublist
    
//     // 1s list not empty
//     if(oneHead -> next != NULL) {
//         zeroTail -> next = oneHead -> next;
//     }
//     else {
//         //1s list -> empty
//         zeroTail -> next = twoHead -> next;
//     }
    
//     oneTail -> next = twoHead -> next;
//     twoTail -> next = NULL;
    
// 	//setup head 
//     head = zeroHead -> next;
    
//     //delete dummy nodes
//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;
    
//     return head;
// }   without replacing elements

//timecomplexity = O(n)
//space = O(1)

// merge two sorted linked list
//  Node<int>* solve(Node<int>* first, Node<int>* second) {
    //if only one element present in first list
    // if(first->next ==NULL){
    //     first->next = second;
    //     return first;
    // }
    
    // adding all pointers to the list accordingly
    // Node<int>* curr1 = first;
    // Node<int>* next1 = curr1 -> next;
    
    // Node<int>* curr2 = second;
    // Node<int>* next2 = curr2 -> next;
    
    //now we checking the condition that the next element of first list should not be null / list 2 shoud not be null
    // while(next1 != NULL && curr2 != NULL) {
        
    //     if( (curr2 -> data >= curr1 -> data ) 
    //        && ( curr2 -> data <= next1 -> data)) {
            

            //adding node between the first list
            // curr1 -> next = curr2;
            // next2 = curr2->next;
            // curr2 -> next = next1;

            //now we updating the pointers
        //     curr1 = curr2;
        //     curr2 = next2;

        // }
        // else {

            //one step ahead the curr1 and next1 elem
            // curr1 = next1;
            // next1 = next1->next;
            
            //attaching the first list with the second list
//             if(next1 == NULL){
//                 curr1->next = curr2;
//                 return first;
//             }
            
//         }
        
        
//     }
    
//     return first;
// }

// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//     if(first == NULL)
//         return second;
    
//     if(second == NULL)
//         return first;
    
//     if(first -> data <= second -> data ){
//         return solve(first, second);
//     }
//     else
//     {
//         return solve(second, first);
//     }
    
    
// }




//check plaindorme in linked list
//time and space complexity is O(n)
// class Solution{
//   private:
//     Node* getMid(Node* head ) {
//         Node* slow = head;
//         Node* fast = head -> next;
        
//         while(fast != NULL && fast-> next != NULL) {
//             fast = fast -> next -> next;
//             slow = slow -> next;
//         }
        
//         return slow;
//     }
//     Node* reverse(Node* head) {
        
//         Node* curr = head;
//         Node* prev = NULL;
//         Node* next = NULL;
        
//         while(curr != NULL) {
//             next = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         if(head -> next == NULL) {
//             return true;
//         }
        
//         //step 1 -> find Middle
//         Node* middle = getMid(head);
//         //cout << "Middle " << middle->data << endl;
        
//         //step2 -> reverse List after Middle
//         Node* temp = middle -> next;
//         middle -> next = reverse(temp);
        
//         //step3 - Compare both halves
//         Node* head1 = head;
//         Node* head2 = middle -> next;
        
//         while(head2 != NULL) {
//             if(head2->data != head1->data) {
//                 return 0;
//             }
//             head1 = head1 -> next;
//             head2 = head2 -> next;
//         }
    
//         //step4 - repeat step 2
//         temp = middle -> next;
//         middle -> next = reverse(temp);
        
//         return true;
//     }
// };


// sum of two linked list
// class Solution
// {
//     private:
//     Node* reverse(Node* head) {
        
//         Node* curr = head;
//         Node* prev = NULL;
//         Node* next = NULL;
        
//         while(curr != NULL) {
//             next = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
    
//     void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
//         Node* temp = new Node(val);
//         //empty list
//         if(head == NULL) {
//             head = temp;
//             tail = temp;
//             return;
//         }
//         else
//         {
//             tail -> next = temp;
//             tail = temp;
//         }
//     }
    
//     struct Node* add(struct Node* first, struct Node* second) {
//         int carry = 0;
        
//         Node* ansHead = NULL;
//         Node* ansTail = NULL;
        
//         while(first != NULL || second != NULL || carry != 0) {
            
//             int val1 = 0;
//             if(first != NULL)
//                 val1 = first -> data;
                
//             int val2 = 0;
//             if(second !=NULL)
//                 val2 = second -> data;
            
            
//             int sum = carry + val1 + val2;
            
//             int digit = sum%10;
            
//             //create node and add in answer Linked List
//             insertAtTail(ansHead, ansTail, digit);
            
//             carry = sum/10;
//             if(first != NULL)
//                 first = first -> next;
            
//             if(second != NULL)
//                 second = second -> next;
//         }
//         return ansHead;
//     }
//     public:
//     //Function to add two numbers represented by linked list.
//     struct Node* addTwoLists(struct Node* first, struct Node* second)
//     {
//         //step 1 -  reverse input LL
//         first = reverse(first);
//         second = reverse(second);
        
//         //step2 - add 2 LL
//         Node* ans = add(first, second);
        
//         //step 3 
//         ans = reverse(ans);
        
//         return ans;
//     }
// }; t.c = O(m+n) and s.c. = O(m+n)






//clone a liked list with random pointers
//first approach
// class Solution
// {
//     private:
//     void insertattail(Node* &head, Node* &tail, int d){
//         Node* newnode = new Node(d);
//         if(head!=NULL){
//             head = newnode;
//             tail = newnode;
//             return;
//         }
//         else{
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }
    
//     public:
//     Node *copyList(Node *head)
//     {
//         //step 1 create a clone list
//         Node* clonehead = NULL;
//         Node* clonetail = NULL;
        
//         Node* temp = head;
        
//         while(temp!=NULL){
//             insertattail(clonehead, clonetail, temp->data);
//             temp = temp->next;
//         }
//         //step 2 create a map
        
//         unordered_map<Node*, Node*>oldtonewnode;
        
//         Node* originalnode = head;
//         Node* clonenode = clonehead;
        
//         while(originalnode!=NULL && clonenode!= NULL){
//             oldtonewnode[originalnode] = clonenode;
//             originalnode = originalnode->next;
//             clonenode= clonenode->next;
//         }
        
//         originalnode = head;
//         clonenode = clonehead;
        
//         while(originalnode!=NULL){
//             clonenode->arb = oldtonewnode[originalnode->arb];
//             originalnode = originalnode ->next;
//             clonenode = clonenode->next;
//         }
        
//         return clonehead;
//     }
// };



//another approach for clone linked list
// class Solution
// {
//     private:
//     void insertattail(Node* &head, Node* &tail, int d){
//         Node* newnode = new Node(d);
        
//         if(head == NULL){
//             head = newnode;
//             tail = newnode;
//         }
//         else{
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }
//     public:
//     Node *copyList(Node *head)
//     {
//         Node* clonehead = NULL;
//         Node* clonetail = NULL;
        
//         Node* temp = head;
//         while(temp!= NULL){
//             insertattail(clonehead, clonetail, temp->data);
//             temp = temp->next;
//         }
        
//         Node* originalnode = head;
//         Node* clonenode = clonehead;
        
//         while(originalnode!= NULL && clonenode!= NULL){
//             Node* next = originalnode->next;
//             originalnode->next = clonenode;
//             originalnode = next;
            
//             next = clonenode->next;
//             clonenode->next = originalnode;
//             clonenode = next;
//         }
        
//         temp = head;
//         while(temp!=NULL){
//             if(temp->next!=NULL){
//                 temp->next->arb = temp->arb
//                 ? temp->arb->next: temp->arb;
//             }
//             temp = temp->next->next;
//         }
        
//         originalnode = head;
//         clonenode = clonehead;
        
//         while(originalnode!= NULL && clonenode!=NULL){
//             originalnode->next = clonenode->next;
//             originalnode = originalnode->next;
            
//             if(originalnode!= NULL){
//                 clonenode->next = originalnode->next;
//             }
//             clonenode = clonenode->next;
//         }
//         return clonehead;
//     }

// };

//merge sort in linked list
// node* findmid(node* head){
//     node* slow = head;
//     node* fast = head->next;
//     while(fast!=NULL && fast->next!=NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// node* merge(node* left, node* right){
//     if(left == NULL){
//         return right;
//     }
//     if(right == NULL){
//         return left;
//     }
//     node* ans = new node(-1);
//     node* temp = ans;

//     while(left!= NULL && right!=NULL){
//         if(left->data<right->data){
//             temp->next = left;
//             temp = left;
//             left = left->next;
//         }
//         else{
//             temp->next = right;
//             temp = right;
//             right = right->next;
//         }
//     }
//     while(left!=NULL){
//             temp->next = left;
//             temp = left;
//             left = left->next;       
//     }
//     while(right!=NULL){
//             temp->next = right;
//             temp = right;
//             right = right->next;       
//     }
//     ans = ans->next;
//     return ans;
// }
// node* mergeSort(node *head) {
//     //base case
//     if(head == NULL|| head->next == NULL){
//         return head;
//     }
// //break the list into two parts after finding mid element
//     node* mid = findmid(head);

//     node* left = head;
//     node* right =mid->next;
//     mid->next = NULL;
// //recursive call for sort both halves
//     left = mergeSort(left);
//     right = mergeSort(right);

//     //merge both left and right halves
//     node* result = merge(left,right);
//     return result;


// } time - O(nlogn) space - O(logn)



//flatten the linked list
// Node* mergeTwoLists(Node* a, Node* b) {

    

//     Node *temp = new Node(0);

//     Node *res = temp; 

    

//     while(a != NULL && b != NULL) {

//         if(a->data < b->data) {

//             temp->child = a; 

//             temp = temp->child; 

//             a = a->child; 

//         }

//         else {

//             temp->child = b;

//             temp = temp->child; 

//             b = b->child; 

//         }

//     }

    

//     if(a) temp->child = a; 

//     else temp->child = b; 

    

//     return res -> child; 

    

// }

// Node* flattenLinkedList(Node* head) 

// {

//     if(head == NULL || head->next == NULL){
// 		return head;
// 	} 

 

//     Node* L2 = flattenLinkedList(head->next);

//     head->next = NULL;

//     Node* nhead = mergeTwoLists(head, L2);

//     return nhead;

// }
