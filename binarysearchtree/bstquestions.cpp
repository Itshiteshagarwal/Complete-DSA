//validate bst
bool isbst(BinaryTreeNode<int> *root, int minval, intmaxval) {
    if(root == NULL){
        return true;
    }
    if(root->data >= minval && root->data <= maxval){
        bool left = isbst(root, minval, root->data);
        bool right = isbst(root, root->data, maxval);
        return left && right;
    }
    else
    return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isbst(root, INT_MIN, INT_MAX);
}

//

//find kth smallest element in bst
int solve (BinaryTreeNode<int>* root, int k, int &i){
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k);

    if(left!=NULL){
        return left;
    }
    i++;
    if(i==k)
    return root->data
    return solve(root->right, i, k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    int ans = solve(root, i k);
    return ans;
}  //O(n) tc , O(n) sc


//kth largest number
void rec(TreeNode<int>* root,int &k,int &ans)
{
    if(root == NULL)
    return ;
    rec(root->right,k,ans);
    k--;
    if(k==0)
    {
        ans=root->data;
        return;
    }
    rec(root->left,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans=-1;
    rec(root,k,ans);
    return ans;
}

//Two Sum IV - Input is a BST
void inorder(BinaryTreeNode<int>* root, vector<int> &inorderval){
    if(root == NULL){
        return;
    }

    inorder(root->left, inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderval;
    inorder(root, inorderval);

    while(i<j){
        int sum  = inorderval[i] + inorderval[j];
        if(sum ==  target)
        return true;

        else if(sum > target)
        j--;

        else
        i++;

    }
    return false;
}

// flatten a bst to linked list
void inorder(TreeNode<int>* root,vector<int> &inorderval){
    if(root == NULL){
        return;
    }

    inorder(root->left,  inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderval;
    inorder(root, inorderval);
    int n = inorderval.size();
    TreeNode<int>* newroot = new TreeNode<int>(inorderval[0]);
   TreeNode<int>* curr = newroot;

   for(int i =1; i<n; i++){
       TreeNode<int>* temp = new TreeNode<int>(inorderval[i]);
       curr->left = NULL;
       curr->right = temp;
       curr = temp;
   }

   curr->left =NULL;
   curr->right = NULL;

   return newroot;

}


//normal bst to balanced bst
void inorder(TreeNode<int>* root,vector<int> &inorderval){
    if(root == NULL){
        return;
    }

    inorder(root->left,  inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);
}
TreeNode<int>* inordetobst(int s, int e,   vector<int> &inorderval)
{
    if(s>e)
    return NULL;

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorderval[mid]);
    root->left = inordetobst(s, mid-1, inorderval);
    root->right = inordetobst(mid+1,  e, inorderval);
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderval;
    inorder(root, inorderval);
    

    return inordetobst( 0, inorderval.size()-1, inorderval);
    

}

//preorder traversal of a bst 
BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i ){
    if(i>=preorder.size())
        return NULL;
    if(preorder[i]<mini || preorder[i]>maxi)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder,mini, root->data, i);
    root->right = solve(preorder, root->data,  maxi,  i);
    return root;

}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder,  mini, maxi,  i);
}


//merge two bst
//approach 1 *************************************
void inorder(TreeNode<int> *root, vector<int> &in)
{
    // Base Case
    if(root == NULL)
    {
        return;
    }
    // LNR
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
vector<int> merge(vector<int>a, vector<int>b)

{
    vector<int>ans (a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while(i < a.size())
    {
        ans[k++] = a[i++];
    }

    while(j < b.size())
    {
        ans[k++] = b[j++];
    }
    return ans;
}
TreeNode<int> *inordertoBST(int s, int e, vector    vector<int>mergeArray = merge(bst1, bst2);
    int s = 0, e = mergeArray.size()-1;
    // Used Merged inorder array to build BST
    return inordertoBST(s, e, mergeArray);
}  //time complexit O(m+n)


//approach 2 ***************************************
//using flatten linked list
 void convertintosortedll(TreeNode<int> *root, TreeNode<int> *&head, TreeNode<int> *&prev) {
    if (root == NULL)
        return;

    convertintosortedll(root->left, head, prev);

    if (prev == NULL) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertintosortedll(root->right, head, prev);
}

TreeNode<int> *mergelinklist(TreeNode<int> *head1, TreeNode<int> *head2) {
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data) {
        head = head1;
        tail = head1;
        head1 = head1->right;
    } else {
        head = head2;
        tail = head2;
        head2 = head2->right;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    if (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
    } else if (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
    }

    return head;
}

int countnnodes(TreeNode<int> *head) {
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int> *sortedlltobst(TreeNode<int> *&head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    TreeNode<int> *left = sortedlltobst(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;
    head = head->right;

    root->right = sortedlltobst(head, n - n / 2 - 1);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    TreeNode<int> *head1 = NULL;
    TreeNode<int> *prev1 = NULL;
    convertintosortedll(root1, head1, prev1);

    TreeNode<int> *head2 = NULL;
    TreeNode<int> *prev2 = NULL;
    convertintosortedll(root2, head2, prev2);

    TreeNode<int> *mergedHead = mergelinklist(head1, head2);

    return sortedlltobst(mergedHead, countnnodes(mergedHead));
}

//size of largest bst in a binary tree
//create a class for basic four details
class info{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

//write a solve function to complete the four steps
info solve(TreeNode<int>* root, int &ans){
    // base case
    if(root == NULL) return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;
    curr.mini = min(left.mini, root->data);
    curr.maxi = max(right.maxi, root->data);
    curr.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini) ) {
        curr.isBST = true;
    }
    else curr.isBST = false;

    if(curr.isBST == true) {
        ans = max(ans, curr.size);
        }
    
    return curr;
}

int largestBST(TreeNode<int>* root) 
{
    int max_size = 0;
    info temp = solve(root, max_size);
    return max_size;
}  //time and spc comp O(n)

