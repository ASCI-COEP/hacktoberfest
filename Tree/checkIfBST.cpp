vector<int> arr;
void lmrtrav(Node* ptr) {
    if(!ptr)
        return;
    lmrtrav(ptr->left);
    arr.push_back(ptr->data);
    lmrtrav(ptr->right);
}

bool checkBST(Node* root) {
    Node* ptr = root;
    lmrtrav(ptr);
    for(int i = 0; i < arr.size()-1; i++)
        if(arr[i] >= arr[i+1])
            return 0;
    return 1;
}
