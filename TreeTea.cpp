#include<iostream>
#include<string>

using namespace std;

class TreeNode{
//Note that even though this is a basic program I fully understand
  public:
	//create Tree structure
    TreeNode(TreeNode* p, string k, string classification)
    :parent{p}, key{k}, value{classification}
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

TreeNode* gpuTree;//create gputree

void in_order_tree_walk(TreeNode* father){
  if(father != nullptr){//if the father node has a value other than null
    in_order_tree_walk(father -> childL);//point to the left child value
    cout << father -> key << '\n';//print out the key to the node
    in_order_tree_walk(father -> childR);//point to the right child value
  }
}
//Main method
int main(){
  TreeNode* node = new TreeNode(nullptr, "gtx 1080ti", "high-end");//creates root value
  gpuTree = node;//establishes this as the base node
  TreeNode* temp = gpuTree;//creates an object that can be used to easily create and declare parents
  node = new TreeNode(temp , "rtx 2080", "ultra high-end");//left child value is greater than parent
  temp -> childL = node;//point to the left child node and assign the above information
  node = new TreeNode(temp, "gtx 1070", "old mid-range");//right child value is less than parent
  temp -> childR = node;//point the the right child node and assign the information
  temp = node;//create new parent node using gtx 1070
  node = new TreeNode(temp, "gtx 1050ti", "low-range");
  temp -> childR = node;
  node = new TreeNode(temp, "gtx 1660", "mid-range");
  temp -> childL = node;
  temp = node;//makes gtx 1660 parent
  node = new TreeNode(temp, "gtx 970", "old mid-range");
  temp -> childR = node;
  node = new TreeNode(temp, "gtx 780", "old high-end");
  temp -> childL = node;
  temp = node;//makes gtx 780 new parent
  node = new TreeNode(temp, "gtx 750", "old low-end");
  temp -> childR = node;
  node = new TreeNode(temp, "gtx 770", "old mid-range");
  temp -> childL = node;
  in_order_tree_walk(gpuTree);
}
