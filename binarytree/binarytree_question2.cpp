// zig-zag traversal
// class Solution{
//     public:
//     //Function to store the zig zag order traversal of tree in a list.
//     vector <int> zigZagTraversal(Node* root)
//     {
//         	vector<int> result;
//     	if(root == NULL)
//     	    return result;
    	
//     	queue<Node*> q;
//     	q.push(root);
    	
//     	bool leftToRight = true;
    	
//     	while(!q.empty()) {
    	    
//     	    int size = q.size();
//     	    vector<int> ans(size);
    	    
//     	    //Level Process
//     	    for(int i=0; i<size; i++) {
    	        
//     	        Node* frontNode = q.front();
//     	        q.pop();
    	        
//     	        //normal insert or reverse insert 
//     	        int index = leftToRight ? i : size - i - 1;
//     	        ans[index] = frontNode -> data;
    	        
//     	        if(frontNode->left)
//     	            q.push(frontNode -> left);
    	            
//     	        if(frontNode->right)
//     	            q.push(frontNode -> right);
//     	    }
    	    
//     	    //direction change karni h
//     	    leftToRight = !leftToRight;
    	   
//     	  for(auto i: ans) {
//     	      result.push_back(i);
//     	  }  
//     	}
//     	    return result;
//     }
// };


//boundary traversal
// class Solution {
// public:
//     void traverseLeft(Node* root, vector<int> &ans) {
//         //base case
//         if( (root == NULL) || (root->left == NULL && root->right == NULL) )
//             return ;
            
//         ans.push_back(root->data);
//         if(root->left)
//             traverseLeft(root->left, ans);
//         else
//             traverseLeft(root->right, ans);
            
//     }
    
//     void traverseLeaf(Node* root, vector<int> &ans) {
//         //base case
//         if(root == NULL)
//             return ;
            
//         if(root->left == NULL && root->right == NULL) {
//             ans.push_back(root->data);
//             return;
//         }
        
//         traverseLeaf(root->left, ans);
//         traverseLeaf(root->right, ans);
        
//     }
    
//     void traverseRight(Node* root, vector<int> &ans) {
//         //base case
//         if( (root == NULL) || (root->left == NULL && root->right == NULL) )
//             return ;
        
//         if(root->right)
//             traverseRight(root->right, ans);
//         else
//             traverseRight(root->left, ans);
            
//         //wapas aagye
//         ans.push_back(root->data);
            
//     }
    
//     vector <int> boundary(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL)
//             return ans;
            
//         ans.push_back(root->data);
        
//         //left part print/store
//         traverseLeft(root->left, ans);
        
//         //traverse Leaf Nodes
        
//         //left subtree
//         traverseLeaf(root->left, ans);
//         //right subtree
//         traverseLeaf(root->right, ans);
        
//         //traverse right part
//         traverseRight(root->right, ans);
        
//         return ans;
        
        
//     }
// };

// class solution{
// //vertical traveral of binary tree
//     public:
//     //Function to find the vertical order traversal of Binary Tree.
//     vector<int> verticalOrder(Node *root)
//     {
//         ;
//         queue< pair<Node*, pair<int,int> > > q;
//         vector<int> ans;
        
//         if(root == NULL)
//             return ans;
            
//         q.push(make_pair(root, make_pair(0,0)));
        
//         while(!q.empty()) {
//             pair<Node*, pair<int,int> > temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second.first;
//             int lvl = temp.second.second;
            
//             nodes[hd][lvl].push_back(frontNode->data);
            
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
//         }
        
//         for(auto i: nodes) {
            
//             for(auto j:i.second) {
                
//                 for(auto k:j.second)
//                 {
//                     ans.push_back(k);
//                 }
//             }
//         }
//         return ans;
//     }
// };


//top view of binary tree
// class Solution
// {
//     public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL) 
//         {
//             return ans;
//         }
        
//         map<int,int> topNode;
//         queue<pair<Node*, int> > q;
        
//         q.push(make_pair(root, 0));
        
//         while(!q.empty()) {
//             pair<Node*, int> temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second;
            
//             //if one value is present for a HD, then do nothing
//             if(topNode.find(hd) == topNode.end())
//                 topNode[hd] = frontNode -> data;
                
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, hd-1));
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, hd+1));
//         }
        
//         for(auto i:topNode) 
//         {
//             ans.push_back(i.second);
//         }
//         return ans;
//     }

// };


//bottom view of binary tree
//    vector<int> ans;
//         if(root == NULL) 
//         {
//             return ans;
//         }
        
//         map<int,int> topNode;
//         queue<pair<Node*, int> > q;
        
//         q.push(make_pair(root, 0));
        
//         while(!q.empty()) {
//             pair<Node*, int> temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second;
            
//             //if one value is present for a HD, then do nothing
//                 topNode[hd] = frontNode -> data;
                
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, hd-1));
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, hd+1));
//         }
        
//         for(auto i:topNode) 
//         {
//             ans.push_back(i.second);
//         }
//         return ans;


//right view of a binary tree
void solve(BinaryTreeNode<int> *root, vector<int> &ans, int level){
    if(root == NULL){
        return ;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right, ans, level+1);
    solve(root->left, ans,level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
        vector<int> ans;
    solve(root, ans, 0);
     for(int i :ans){

        cout<<i<<" ";

    }cout<<"\n";
}


//left view
void solve(BinaryTreeNode<int> *root, vector<int> &ans, int level){
    if(root == NULL){
        return ;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left, ans, level+1);
    solve(root->right, ans,level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
        vector<int> ans;
    solve(root, ans, 0);
     for(int i :ans){

        cout<<i<<" ";

    }cout<<"\n";
}



//diagonal traversal
vector<int> diagonal(Node *root)
{
   
   queue<Node*>q;
   vector<int>ans;
   ans.push_back(root->data);
   if(root->right)q.push(root->right);
   if(root->left)q.push(root->left);
   
  while(!q.empty())
  {
      Node* temp=q.front();
      q.pop();
      ans.push_back(temp->data);
      if(temp->left)q.push(temp->left);
      temp=temp->right;
      while(temp!=NULL)
      {
          ans.push_back(temp->data);
          if(temp->left)
          {
              q.push(temp->left);
          }
          temp=temp->right;
      }
      
      
      
  }
  return ans;
}
