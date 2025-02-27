#include <bits/stdc++.h>
using namespace std;

class Tree{
	public:
	Tree* left = nullptr; Tree* right = nullptr;
	int key;
};

Tree* createNode(int key){
	Tree* t = new Tree();
	t -> key = key;
	return t;
}

Tree* insertNode(Tree* root, int key){
	if(root == nullptr) {
		root = createNode(key);
	} 
	else if(key < root -> key) {
		root -> left = insertNode(root -> left, key);
	}
	else if(key > root -> key){
		root -> right = insertNode(root -> right, key);
	}	
	return root;
}

int distanceFromRoot(Tree* root, int key){
	int dist = 0;
	if(root -> key == key) return dist;
	else if(key > root -> key) {
		dist = 1 + distanceFromRoot(root -> right, key);
	}
	else if(key < root -> key){
		dist = 1 + distanceFromRoot(root -> left, key);
	}
	return dist;
}

int distBetweenTwo(Tree* root, int a, int b){ // using lowest common ancestor.
	if(root ==  nullptr) return 0;
	if(root -> key > a && root -> key > b){
		return distBetweenTwo(root -> left, a, b);
	}
	else if(root -> key < a && root -> key < b){
		return distBetweenTwo(root -> right, a, b);
	}
	else if(root -> key >= a && root -> key <= b){
		return distanceFromRoot(root, a) + distanceFromRoot(root, b);
	}
	
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	Tree* root = createNode(20);
	insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 30);
    insertNode(root, 25);
    insertNode(root, 35);
    int a = 5, b = 55;
	if(a > b) swap(a, b);
    cout << distBetweenTwo(root, 15, 35);
	return 0;
}