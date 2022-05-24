#include <bits/stdc++.h>
using namespace std;

class Node {
	int key;
	Node *left;
	Node *right;
	int height;
};

int height(Node *n){
	if(n != NULL) return n -> height;
	return 0;
}

Node *newNode(int key){
	Node* node = new Node();
	node -> key = key;
	node -> left = NULL;
	node -> right = NULL;
	node -> height = 1;
	
	return node;
}

int balanceFactor(Node *node){
	if(node == NULL) return 0;
	return height(node -> left) - height(node -> right);
}


//   	y                               x
//     / \     Right Rotation          /  \
//    x   T3   - - - - - - - >        T1   y 
//   / \       < - - - - - - -            / \
//  T1  T2     Left Rotation            T2  T3

Node *rightRotation(Node *node){
	Node *x = node -> left;
	Node *t2 = x -> right;

	x -> right = node;
	node -> left t2;

	node -> height = max(height(node -> left), height(node -> right)) + 1;
	x -> height = max(height(x -> left), height(x -> right)) + 1;
	return x;
}

Node *leftRotation(Node *node){
	Node *y = node -> right;
	Node *t2 - y -> left;

	y -> left = node;
	node -> right = t2;

	node -> height = max(height(node -> left), (node -> right)) + 1;
	y -> height = max(height(y -> left), (y -> right)) + 1;
	return y;
}

Node *insert(Node* node, int key){
	if(node == NULL) return newNode(key);
	
	if(key < node -> key){
		node -> left = insert(node -> left, key);
	}else if(key > node -> key){
		node -> right = insert(node -> right, key);
	}else{
		return node;
	}

	node -> height = max(height(node -> left), height(node -> right)) + 1;

	int balance = balanceFactor(node);

	if(balance > 1 && key < node -> left -> key){
		// left left case. rotate right.
		rightRotation(node);
	}

	if(balance > 1 && key > node -> left -> key){
		// left right case. rotate left with node -> left  the rotate right with node.
		node -> left = leftRotation(node -> left);
		rightRotation(node);
	}

	if(balance < -1 && key > node -> right -> key){
		// right right case. rotate left.
		leftRotation(node);
	}

	if(balance < -1 && key < node -> right -> key){
		// right left case. rotate right with node -> right  the rotate left with node.
		node -> right = rightRotation(node -> right);
		leftRotation(node);
	}
	return node;
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}