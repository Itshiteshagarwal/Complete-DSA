//steps of morris traversal algorithm
//make root as current
    //current = root
//while(root!= Null)
//if left not exist 
//visit(current)
//current = current->right

//else
// predecessor(ek baar left jao then right jao jb tk null na mil jaye) =  find(curr)
// if(predecessor->right == NULL)
// pred->right = current
//current = current->left


//else
//pred->right = NULL
//visit(current)
//current = current->right


 
/* Driver program to test above functions*/
// int main()
// {

//     struct tNode* root = newtNode(1);
//     root->left = newtNode(2);
//     root->right = newtNode(3);
//     root->left->left = newtNode(4);
//     root->left->right = newtNode(5);
 
//     MorrisTraversal(root);
 
//     return 0;
// }


//another approach
TreeNode* findprecesedor(TreeNode* root){
    TreeNode* curr = root->left;
    while(curr->right!=NULL && curr->right!=root){
        curr = curr->right;
    }
    return curr;
}

void inorderMorrisTraversal(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* precesedor = findprecesedor(curr);
            if(precesedor->right == NULL){
                precesedor->right = curr;
                curr = curr->left;
            }
            else if(precesedor->right = curr){
                precesedor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }

        }
    }
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    inorderMorrisTraversal(root,ans);    
    return ans; 
} //time complexity O(n) space O(1);



//flatten a binary tree into linked list
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left){
               Node* prev = curr->left;
                
                while(prev->right)
                    prev = prev->right;
                    prev->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
            }
             curr = curr->right;
            
        }
        //left part NULL krege
    }
}; //tc O(n) ans sc O(1)


// Predecessor And Successor In BST
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Iterative Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int pred = -1;
    int succ = -1;
    BinaryTreeNode<int>* temp = root;
    while(temp != NULL){
        if(temp->data == key) 
        break;
        else if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }
    // Predecessor
    if(temp != NULL){
        BinaryTreeNode<int>* adv = temp->left;
        while(adv != NULL){
            pred = adv->data;
            adv = adv->right;
        }
    }

     // Successor
    if(temp != NULL){
        BinaryTreeNode<int>* adv = temp->right;
        while(adv != NULL){
            succ = adv->data;
            adv = adv->left;
        }
    }   

    pair<int, int> p = make_pair(pred, succ);
    return p;
}

//Lca in bst
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root == NULL){
        return NULL;
    }

    if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right, P,Q);
    }
        if(root->data>P->data && root->data>Q->data){
        return LCAinaBST(root->left, P,Q);
    }
    return root;
}