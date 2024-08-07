// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 4
// Description: find the largest zigzag path in a binary tree.
#include "binTree.h"
using namespace std;

binTree::binTree()
{
    root = nullptr;
}

binTree::~binTree()
{
    deallocateTree(root);
}

void binTree::deallocateTree(binTreeNode* r)
{
    if(r->left == nullptr && r->right == nullptr)
    {
        delete r;                                                                           // delete current node if node is at the end of the tree
        return;
    }

    if(r->left != nullptr)                                                                  // checks left side first until it reaches the end
        deallocateTree(r->left);
    if(r->right != nullptr)                                                                 // checks right side second until it reaches the end
        deallocateTree(r->right);

    r->left == nullptr;                                                                     // sets the left and right pointers to null
    r->right == nullptr;
    delete r;                                                                               // deletes current node working its way up the tree
}

void binTree::buildTree(vector<string> locations)
{
    root = buildTree(new binTreeNode(), locations, 0);
}

binTreeNode* binTree::buildTree(binTreeNode* r, vector<string> locations, int index)
{
    if(index >= locations.size() || locations[index] == "_")
    {
        delete r;                                                                           // deletes created node if there is nothing to be inserted
        return nullptr;
    }

    r->location = locations[index];                                                         // sets nodes data
    r->left = buildTree(new binTreeNode(), locations, index*2+1);                           // builds the left side of the current tree branch
    r->right = buildTree(new binTreeNode(), locations, index*2+2);                          // builds the right side of the current tree branch

    return r;
}

vector<string> binTree::zigzag()
{
    vector<string> leftVec;                                                                 // holds the largest zigzag of the left side of the tree
    vector<string> rightVec;                                                                // holds the largest zigzag of the right side of the tree

    if(root == nullptr)
        return leftVec;                                                                     // returns an empty vector if tree is empty

    leftVec.push_back(root->location);                                                      // pushes the root onto the vector to pass as a parameter
    rightVec.push_back(root->location);

    // true = left, false = right
    leftVec = zigzag(root->left, true, leftVec);
    rightVec = zigzag(root->right, false, rightVec);
    
    if(leftVec.size() > rightVec.size())                                                    // checks which vector had the larger zigzag
        return leftVec;
    
    return rightVec;
}

vector<string> binTree::zigzag(binTreeNode* r, bool childType, vector<string> path)
{
    vector<string> re_Start;                                                                // used to pass as a parameter when zigzag path fails
    vector<string> temp;                                                                    // used to hold a zigzag if there is more than one. 
    if(r == nullptr)
        return path;

    path.push_back(r->location);
    re_Start.push_back(r->location);
    // true = left, false = right
    if(childType == true)
    {
        temp = zigzag(r->left, true, re_Start);
        path = zigzag(r->right, false, path);
    }
    else
    {
        path = zigzag(r->left, true, path);
        temp = zigzag(r->right, false, re_Start);
    }

    if(temp.size() > path.size())                                                           // compares the two paths and returns the larger one
        return temp;

    return path;
}