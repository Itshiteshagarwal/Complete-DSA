//sum of longest blood line
// class Solution
// {
// public:
    
//     void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
//         //base case
//         if( root == NULL ) {
            
//             if(len > maxLen) 
//             {
//                 maxLen = len;
//                 maxSum = sum;
//             }
//             else if(len == maxLen) 
//             {
//                 maxSum = max(sum, maxSum);
//             }
//             return;
//         }
        
//         sum = sum + root->data;
        
//         solve(root->left, sum, maxSum, len+1, maxLen);
//         solve(root->right, sum, maxSum, len+1, maxLen);

//     }
    
//     int sumOfLongRootToLeafPath(Node *root)
//     {
//         int len = 0;
//         int maxLen = 0;
        
//         int sum = 0;
//         int maxSum = INT_MIN;
        
//         solve(root, sum, maxSum, len, maxLen);
        
//         return maxSum;
//     }
// }; time complexity O(n) space O(h);

//longest common ancestor in binary 

//     public:
//     //Function to return the lowest common ancestor in a Binary Tree.
//     Node* lca(Node* root ,int n1 ,int n2 )
//     {
//        if(root == NULL){
//            return NULL;
//        } 
       
//        if(root->data == n1 || root->data ==n2){
//            return root;
//        }
       
//        Node* leftans = lca(root->left,n1,n2);
//        Node* rightans = lca(root->right,n1,n2);
       
//        if(leftans != NULL && rightans!=NULL)
//        return root;
//        else if(leftans != NULL && rightans==NULL)
//        return leftans;
//        else if(leftans== NULL && rightans!=NULL)
//        return rightans;
//        else
//        return NULL;
//     }
// }; //time complexityO(n), space O(h)


//kth ancestor in binary tree
// Node* solve(Node* root, int &k, int node) {
//     //base case
//     if(root == NULL)
//         return NULL;
        
//     if(root->data == node) 
//     {
//         return root;
//     }
    
//     Node* leftAns = solve(root->left, k, node);
//     Node* rightAns = solve(root->right, k, node);


//     //wapas
//     if(leftAns != NULL && rightAns == NULL) 
//     {
//         k--;
//         if(k<=0) 
//         {
//             //answer lock
//             k = INT_MAX;
//             return root;
//         }
//         return leftAns;
//     }
    
//     if(leftAns == NULL && rightAns != NULL) {
//         k--;
//         if(k<=0) 
//         {
//             //answer lock
//             k = INT_MAX;
//             return root;
//         }
//         return rightAns;
//     }
//     return NULL;
    

// }
// int kthAncestor(Node *root, int k, int node)
// {
//     Node* ans = solve(root, k, node);
//     if(ans == NULL || ans->data == node)
//         return -1;
//     else
//         return ans->data;
// } tc - O(n) sc -O(h)

//max sum of non adjacent nodes
// class Solution{
//   public:
//     pair<int,int> solve(Node* root) {
//         //base case
//         if(root == NULL) {
//             pair<int,int> p = make_pair(0,0);
//             return p;
//         }
        
//         pair<int,int> left = solve(root->left);
//         pair<int,int> right = solve(root->right);
        
//         pair<int,int> res;
        
//         res.first = root->data + left.second + right.second;
        
//         res.second = max(left.first, left.second) + max(right.first, right.second);
        
//         return res;
        
//     }
//     int getMaxSum(Node *root) 
//     {
//         pair<int,int> ans = solve(root);
//         return max(ans.first, ans.second);
//     }
// }; tc O(n) sc O(h)

//***************************************************************************************//
//Construct a BT from Inorder/PreOrder traversal
//  class Solution{
//     private:
//     int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
//         for(int i = inorderStart ; i<=inorderEnd ;i++){
//             if(in[i]==element){
//                 return i ; 
//             }
//         }
//         return -1 ;
//     }
//     Node* solve(int in[],int pre[], int &index ,int inorderStart , int inorderEnd , int n){
//         if(index>=n || inorderStart>inorderEnd){
//             return NULL ;
//         }
        
//         int element = pre[index++] ; // At every interation index is increasing
//         Node* root  = new Node(element); 
//         int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
//         root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
//         root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
//         return root ;
        
//     }
//     public:
    
//     Node* buildTree(int in[],int pre[], int n)
//     {
//         // Code here
//          int preorderindex  = 0 ;  //Pre order is NLR so First element is root .
         
//          Node* ans = solve(in , pre , preorderindex , 0  , n-1 , n );
//          return ans ;
//     }
// };


//same problem using vector
// int findPos(vector<int> &inorder, int element, int n){
//     for(int i = 0; i< n; i++){
//         if(inorder[i] == element)
//             return i;
//     }
//     return -1;
// }
// TreeNode<int>* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n){
//     if(index >= n || inorderStart > inorderEnd)
//         return NULL;
    
//     int element = preorder[index++];
//     TreeNode<int> *root = new TreeNode<int>(element);
//     int pos = findPos(inorder, element, n);
    
//     root->left = solve(inorder, preorder, index, inorderStart, pos-1, n);
//     root->right = solve(inorder, preorder, index, pos+1, inorderEnd, n);
    
//     return root;
// }


// TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
// {
// 	int preOrderIndex = 0;
//     int n = preorder.size();
    
//     TreeNode<int>* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
//     return ans;
// }



//tree from postorder and inorder
    int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    Node* solve(int in[],int post[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n);
  
        
        return root ;
        
    }
    
    Node* buildTree(int in[],int post[], int n)
    {
        // Code here
         int postorderindex  = n-1 ;  //Pre order is NLR so First element is root .
         
         Node* ans = solve(in , post , postorderindex , 0  , n-1 , n );
         return ans ;
    }
