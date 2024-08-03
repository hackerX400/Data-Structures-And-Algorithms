#include <bits/stdtr1c++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for inserting in root left " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in root right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<vector<<int> lot;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp.data);
        }
        lot.push_back(level);
    }
}   
// LNR
void inOrder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void inOrder_it(node* root){
    if(root == NULL) return;
    stack<Node*> st;
    vector<int> ans;

    while(root != NULL ||!st.empty()){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        ans.push(st.top()->val);
        st.pop();
        root = root->right;
    }
}
// NLR
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void preOrder(node *root){
    stack(node*) st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()){
        ans.push(st.top()->data);
        st.pop();
        if(root->left) st.push(root->left);
        if(root->right) st.push(root->right);
    }
}
// LRN
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void postOrder(node* root){
    stack<node*> st,st2;
    vector<int> ans;
    st.push(root);
    while(!st.empty()){
        st2.push(st1.top());
        st.pop();
        if(root->left) st.push(root->left);
        if(root->right) st.push(root->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
}
int main()
{
    node *root = NULL;
    //  creating a tree
    root = buildTree(root);
    // 1 5 10 -1 -1 12 -1 -1 6 13 -1 -1 14 -1 -1
    // traversing the root
    cout << "printing travel order " << endl;
    levelOrderTraversal(root);
    cout << "printing inoder traversel" << endl;
    inOrder(root);
    cout<<endl;
    cout << "printing preoder traversal" << endl;
    preOrder(root);
    cout<<endl;
    cout << "printing post order travesal" << endl;
    postOrder(root);
    return 0;
}
