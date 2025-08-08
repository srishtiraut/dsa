struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Info{
    int lowerbound;
    int upperBound;
    bool isBST;
    int sizeOfTree;
}

Info solve(Node* root, int &ans){
    //base case
    if(root==NULL) return {INT_MIN, INT_MAX, true, 0};

    //call for left subtree
    Info left = solve(root->left, ans);
    //call for right subtree
    Info right = solve(root->right, ans);

    Info currentNode;
    currentNode.size = left.size + right.size + 1;
    currentNode.upperBound = max(root->data, right.upperBound);
    currentNode.lowerBound = max(root->data, left.lowerBound);

    if(left.isBST 
        and 
       right.isBST 
        and
       root->data > left.upperBound
        and
       root->data < right.lowerBound){
        currentNode.isBST = true;
       }else{
        currentNode.isBST = false;
       }

       //update ans
       if(currentNode.isBST){
        ans = max(ans, currentNode.size);
       }
       return currentNode;

}

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root){
    	//Your code here
        int sizeOfLargestBST = 0;
        Info ans = solve(root, sizeOfLargestBST);
        return sizeOfLargestBST;
    }
};