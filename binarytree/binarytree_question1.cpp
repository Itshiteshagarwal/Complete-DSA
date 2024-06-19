
//height of binary tree
// class Solution{
//     public:
//     //Function to find the height of a binary tree.
    
//     int height(struct Node* node){
//         // code here check node is empty or not
//         if(node == NULL){
//             return 0;
//         }
            //height of left and right
//         int left = height(node->left);
//         int right = height(node->right);
        
//         int ans =  max(left, right) +1;
//         return ans;
        
//     }
// }; time complexity and space complexO(n),O(h)


//diameter of a binary tree
// class Solution {
//     private:
//         int height(struct Node* node){
//         // code here check node is empty or not
//         if(node == NULL){
//             return 0;
//         }
//         int left = height(node->left);
//         int right = height(node->right);
        
//         int ans =  max(left, right) +1;
//         return ans;
        
//     }
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         if(root == NULL){
//             return 0;
//         }
        
//         int op1 = diameter(root->left);
//         int op2 = diameter(root->right);
//         int op3 = height(root->left) + height(root->right) + 1;
        
//         int ans = max(op1, max(op2,op3));
//         return ans;
//     }
// }; time complex -O(n^2)



//another approach with O(n complexity)
// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
    
//     pair<int,int> diameterFast(Node* root) {
//         //base case
//         if(root == NULL) {
//             pair<int,int> p = make_pair(0,0);
//             return p;
//         }
        
//         pair<int,int> left = diameterFast(root->left);
//         pair<int,int> right = diameterFast(root->right);
        
//         int op1 = left.first;
//         int op2 = right.first;
//         int op3 = left.second + right.second + 1;
        
//         pair<int,int> ans;
//         ans.first = max(op1, max(op2, op3));;
//         ans.second = max(left.second , right.second) + 1;

//         return ans;
//     }
//     int diameter(Node* root) {
    
//         return diameterFast(root).first;
        
//     }
// };


//for check a binary tree is balanced or not
// class Solution{
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     pair<bool, int> isBalancedFast(Node* root) {
//                 // base case
//         if(root == NULL)
//         {
//             pair<bool, int> p = make_pair(true,0);
//             return p;
//         }
        
//         pair<int,int> left = isBalancedFast(root->left);
//         pair<int,int> right = isBalancedFast(root->right);
        
        
//         bool leftAns = left.first;
//         bool rightAns = right.first;
        
//         bool diff = abs (left.second - right.second ) <=1;
        
//         pair<bool,int> ans;
//         ans.second = max(left.second, right.second) + 1;
        
//         if(leftAns && rightAns && diff) {
//            ans.first = true;
//         }
//         else
//         {
//             ans.first = false;
//         }
//         return ans;
//     }
//     bool isBalanced(Node *root)
//     {
//         return isBalancedFast(root).first;
//     }
    
// };


//determine two tree are identical
// class Solution
// {
//     public:
//     //Function to check if two trees are identical.
//     bool isIdentical(Node *r1, Node *r2)
//     {
//         if(r1==NULL && r2==NULL){
//             return true;
//         }
//         if(r1==NULL && r2!=NULL){
//             return false;
//         }
//         if(r1!=NULL && r2 ==NULL){
//             return false;
//         }
        
//         bool left = isIdentical(r1->left, r2->left);
//         bool right = isIdentical(r1->right, r2->right);
//         bool curr = r1->data == r2->data;
        
//         if(left &&right&&curr){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };//time complexO(n) && spaceO(1)


//sum of binary tree
class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
}; //time O(n) space O(h)