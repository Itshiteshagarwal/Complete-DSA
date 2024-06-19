#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data =d;
        this->left =NULL;
        this->right =NULL;
    }
};
void inordertraversal(Node* root){
    if(root == NULL){
        return;
    }
  
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

void preordertraversal(Node* root){
    if(root == NULL){
        return;
    }
      cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(Node* root){
    if(root == NULL){
        return;
    }
  
    postordertraversal(root->left);
    postordertraversal(root->right);
        cout<<root->data<<" ";
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


Node* inserttobst(Node* root, int d){
     if(root == NULL){
        root = new Node(d);
        return root;
     }

     if(d > root->data){
        root->right = inserttobst(root->right, d);
     }
     else{
        root->left = inserttobst(root->left, d);
     }
     return root;
}
Node* minval(Node* root){

    Node* temp =root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxval(Node* root){

    Node* temp =root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


Node* deleteFromBST(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL) {
            Node* minValueNode = minval(root->right);
            root->data = minValueNode->data;
            root->right = deleteFromBST(root->right, minValueNode->data);
            return root;
        }
    } else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    } // tc o(n) sc O(h)
    
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = inserttobst(root, data);
        cin>>data;
    }
}
int main(){
    Node* root = NULL;
    cout<<"enter data to crwate bst";
    takeinput(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    
    cout<<"inorder traversal is:"<<endl;
    inordertraversal(root);
    cout<<endl;

    cout<<"preordertraversal is:"<<endl;
    preordertraversal(root);
    cout<<endl;

    cout<<"postordertraversal is:"<<endl;
    postordertraversal(root);
    cout<<endl;

    cout<<"minimum value in this bst is :"<<endl;
    cout<< minval(root)->data;
    cout<<endl;

    cout<<"maximum value in this bst is :"<<endl;
    cout<< maxval(root)->data;
    cout<<endl;

    root = deleteFromBST(root, 30);

     cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    
    cout<<"inorder traversal is:"<<endl;
    inordertraversal(root);
    cout<<endl;

    cout<<"preordertraversal is:"<<endl;
    preordertraversal(root);
    cout<<endl;

    cout<<"postordertraversal is:"<<endl;
    postordertraversal(root);
    cout<<endl;

    cout<<"minimum value in this bst is :"<<endl;
    cout<< minval(root)->data;
    cout<<endl;

    cout<<"maximum value in this bst is :"<<endl;
    cout<< maxval(root)->data;
    cout<<endl;


    return 0;
} //O(logn)   


 //search in bst
// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     if(root == NULL){
//         return false;
//     }
//     if(root->data == x){
//         return true;
//     }

//     if(root->data>x){
//         //left part
//         return searchInBST(root->left,  x);
//     }
//     else{
//         return searchInBST(root->right,  x);
//     }
// }