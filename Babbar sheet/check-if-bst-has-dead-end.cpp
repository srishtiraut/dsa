struct Node {
int data;
Node * right, * left;
}



class Solution{
  public:

    bool findDeadEndAtLeafNode(Node* root, int min, int max){
        if(!root) return false;

        if(min==max) return true;

        return findDeadEndAtLeafNode(root->left, min, root->data-1)
        ||
        findDeadEndAtLeafNode(root->right, root->data+1,max);
    }

    bool isDeadEnd(Node *root){
        //Your code here
        //for each node find the range
        return findDeadEndAtLeafNode(root, 1, INT_MAX);
    }
};