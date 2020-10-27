#include<iostream>
#include<string>

using namespace std;

class TreeNode{

  public:

    TreeNode(TreeNode* p, string k, string price)
    :parent{p}, key{k}, value{price}
    {
      childL = nullptr;
      childR = nullptr;
    }
    TreeNode* parent;
    TreeNode* childL;
    TreeNode* childR;
    string key;
    string value;
};

TreeNode* gpuTree;

void in_order_tree_walk(TreeNode* root){
  if(root != nullptr){
    in_order_tree_walk(root->childL);
    cout << root->key << '\n';
    in_order_tree_walk(root->childR);
  }
}

int main(){
  TreeNode* node = new TreeNode(nullptr, "gtx 1080ti", "high-end");
  gpuTree = node;
  TreeNode* temp = gpuTree;
  node = new TreeNode(temp , "rtx 2080", "ultra high-end");
  temp -> childL = node;
  node = new TreeNode(temp, "gtx 1070", "old mid-range");
  temp -> childR = node;
  temp = node;
  node = new TreeNode(temp, "gtx 1050ti", "low-range");
  temp -> childR = node;
  node = new TreeNode(temp, "gtx 1660", "mid-range");
  temp -> childL = node;
  temp = node;
  node = new TreeNode(temp, "gtx 970", "old mid-range");
  temp -> childR = node;
  node = new TreeNode(temp, "gtx 780", "old high-end");
  temp -> childL = node;
  in_order_tree_walk(gpuTree);
}
