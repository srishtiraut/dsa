class Solution
{
public:
    void inorder(Node* root, vector<int> &in){
        //this fx returns an array containing the data of nodes visited in inorder traversal
        if(root==NULL) return;

        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

    Node *flattenBST(Node *root){
        // code here
        vector<int> inorderVal;
        int n = inorderVal.size();

        inorder(root, inorderVal);

        Node* newRoot = new Node(inorderVal[0]);
        Node* curr = newRoot;
        
        for(int i=1; i<n;i++){
            Node* temp = new Node(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        curr->left = NULL;
        curr->right = NULL;

        return newRoot;
    }
};