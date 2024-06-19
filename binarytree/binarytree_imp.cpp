// minimum time to burn a entire binary tree
class Solution {
  public:
Node* createParentMapping(Node* root,int target,
    map<Node*, Node*> &nodeToparent)
    {
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToparent[root]=NULL;
        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
            }
            if(front->left){
                nodeToparent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToparent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int solve(Node* root, map<Node*, Node*> &nodeToparent)
    {
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root]=true;
        
        int ans=0;
        
        while(!q.empty())
        {
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                
                if(nodeToparent[front] && !visited[nodeToparent[front]]){
                    flag=1;
                    q.push(nodeToparent[front]);
                    visited[nodeToparent[front]] = 1;
                }
                
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*>nodeToparent;
        
        Node* targetNode=createParentMapping(root, target, nodeToparent);
        
        int ans= solve(targetNode, nodeToparent);
        
        return ans;
    }
}; // time complexityO(n) //sc O(n)

//code studio
#include <map> BinaryTreeNode<int>*nodetoParentMapping

(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodetoParent, int start)

{
	//For finding Target/Start Node    
    BinaryTreeNode<int> *result = NULL;
	queue<BinaryTreeNode<int> *> q;
	q.push(root);

	// Parent of root is Null

	nodetoParent[root] = NULL;

	while (!q.empty())

	{
		BinaryTreeNode<int> *frontNode = q.front();

		q.pop();

		// Finding the front node

		if (frontNode->data == start)

		{

			result = frontNode;
		}

		if (frontNode->left)

		{

			// Do mapping with parent

			nodetoParent[frontNode->left] = frontNode;

			q.push(frontNode->left);
		}

		if (frontNode->right)

		{

			// Do mapping with parent

			nodetoParent[frontNode->right] = frontNode;

			q.push(frontNode->right);
		}
	}

	return result;

}

int burnTree(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *,
	BinaryTreeNode<int> *> &nodetoParent, int start)

{
	// Step 1 : Craete a visited map

	map<BinaryTreeNode<int> *, bool> visited;

	// step 2 : Create a queue

	queue<BinaryTreeNode<int> *> q;

	q.push(root);

	// Mark root as visited

	visited[root] = true;

	// Creating an answer

	int ans = 0;

	while (!q.empty())

	{
		int size = q.size();

		bool flag = false;

		for (int i = 0; i < size; i++)

		{

			BinaryTreeNode<int> *frontNode = q.front();

			q.pop();

			// Burn the left child if it exixt and it is nor visited

			if (frontNode->left && !visited[frontNode->left])

			{

			 	// Push into queue

				q.push(frontNode->left);

				// Flag will have an eye on if we are adding something in queue

				flag = true;

				// Mark it visited after putting it into queue

				visited[frontNode->left] = true;
			}

			// Burn the right child if it exixt and it is nor visited

			if (frontNode->right && !visited[frontNode->right])

			{

			 	// Push into queue

				q.push(frontNode->right);

				// Flag will have an eye on if we are adding something in queue

				flag = true;

				// Mark it visited after putting it into queue

				visited[frontNode->right] = true;
			}

			// Now burn the parent

			if (nodetoParent[frontNode] && !visited[nodetoParent[frontNode]])

			{

			 	// Push into queue

				q.push(nodetoParent[frontNode]);

				// Flag will have an eye on if we are adding something in queue

				flag = true;

				// Mark it visited after putting it into queue

				visited[nodetoParent[frontNode]] = true;
			}
		}

		if (flag == 1)

		{

			ans++;
		}
	}

	return ans;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)

{
	// Step  1 : Create a mappingg of node to parent

	// Step 2 : Find the target Node

	// Step 3 : Burn the tree 

	map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> nodetoParent;
	BinaryTreeNode<int> *targetNode = nodetoParentMapping(root, nodetoParent, start);
	int ans = burnTree(targetNode, nodetoParent, start);
	return ans;
}