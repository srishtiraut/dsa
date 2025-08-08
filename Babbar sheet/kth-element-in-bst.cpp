int solve(Node *root, int &i, int k){
    if(root==NULL) return -1;

    //left call
    int left = solve(root->left, i, k);
    if(left != -1) return left;
    //we are standing at node in LNR
    i++;
    if(i==k) return root->data;
    //right call
    return solve(root->right, i, k);
}

int KthSmallestElement(Node *root, int k) {
    // add code here.
    int ans = solve(root, i, k);
    return ans;
}