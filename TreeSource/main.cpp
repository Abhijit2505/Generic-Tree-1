#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data)
    {
        this -> data = data;
    }
};

TreeNode<int>* take_input_levelwise()
{
    int rootdata;
    cout << "Enter data : " << endl;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter numbers of child node of "<< front -> data << " : " << endl;
        int numchild;
        cin >> numchild;
        for(int i=0;i<numchild;i++)
        {
            int child_data;
            cout << "Enter " << i << " th child of " << front -> data << endl;
            cin >> child_data;
            TreeNode<int>* child = new TreeNode<int>(child_data);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* take_input()
{
    int root_data;
    cout << "Enter the root data :" << endl;
    cin >> root_data;
    TreeNode<int>* root = new TreeNode<int>(root_data);

    int n;
    cout << "Enter the number of children of the root data :" << endl;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        TreeNode<int>* child = take_input();
        root -> children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << ": ";
    for(int i=0;i<root -> children.size();i++)
    {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;
    for(int i=0;i<root -> children.size();i++)
    {
        printTree(root -> children[i]);
    }
}

int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root -> children.push_back(node1);
    root -> children.push_back(node2);*/
    TreeNode<int>* root = take_input_levelwise();
    printTree(root);
}









