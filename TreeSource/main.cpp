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
    TreeNode<int>* root = take_input();
    printTree(root);
}









