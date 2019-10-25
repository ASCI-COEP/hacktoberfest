#define MAX(a,b) ((a) > (b) ? (a):(b))
    int height(Node* root) {
        // Write your code here.
        if(!root->left && !root->right){
            return 0;
        }
        if(!root->right){
            return height(root->left)+1;
        }
        if(!root->left){
            return height(root->right)+1;
        }
        return MAX(height(root->left)+1, height(root->right)+1);
    }
