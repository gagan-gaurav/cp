#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int val;
	Node* left = NULL;
	Node* right = NULL;
};

Node* newNode(int val){
	Node* node = new Node();
	node -> val = val;
	return node;
}

Node* findLCA(Node* root, int a, int b){
	if(root == NULL) return NULL;

	if(root -> val == a || root -> val == b) return root;

	Node* leftTree = findLCA(root -> left, a, b);
	Node* rightTree = findLCA(root -> right, a, b);
	
	if(leftTree && rightTree) return root;

	return (leftTree != NULL) ? leftTree : rightTree;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->val;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->val;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->val;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->val;
    return 0;

	return 0;
}