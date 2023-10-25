#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int key;
    vector<TreeNode*> children;

    TreeNode(int _key) : key(_key) {}
};

void countChildren(TreeNode* node, vector<int>& childCounts) {
    int numChildren = node->children.size();

    for (TreeNode* child : node->children) {
        countChildren(child, childCounts);
        numChildren += childCounts[child->key - 1];
    }

    childCounts[node->key - 1] = numChildren;
}
int main() {
    int n, key;
    cin >> n;
    vector<TreeNode*> nodes(n);

    for (int i = 0; i < n; i++) {
      nodes[i] = new TreeNode(i + 1);
    }
    
    for (int i = 1; i < n; i++) {
        cin >> key;
        nodes[key - 1]->children.push_back(nodes[i]);
    }

    vector<int> childCounts(n, 0);
    countChildren(nodes[0], childCounts);

    for (int i = 0; i < n; i++) {
      cout << childCounts[i] << " ";
    }

    for (TreeNode* node : nodes) {
        delete node;
    }
}