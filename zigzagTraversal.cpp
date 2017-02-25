#include<iostream>
#include<stack>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
void insertIntoBinaryTree(node *root, int data) {
	if(root->data > data) {
		if(root->left != NULL) {
			insertIntoBinaryTree(root->left, data);
		}
		else {
			node * temp = (node *) malloc(sizeof(node));	
			temp->data = data;
			root->left = temp;
			}
	}
	else {
		if(root->right != NULL) {
			insertIntoBinaryTree(root->right, data);	
		}
		else {
			node *temp = (node *)malloc(sizeof(node));
			temp->data = data;
			root->right = temp;
		}
	}
}

void printTreeLevelWiseLeftToRight(node * root) {
	stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	while(!s1.empty() || 
			!s2.empty()) {
				while(!s1.empty()) {
					node *temp = s1.top();
					s1.pop();
					cout<<temp->data<<" ";
					if(temp->right != NULL) {
						s2.push(temp->right);
					}
					if(temp->left != NULL) {
						s2.push(temp->left);
					}
				}
				cout<<"\n";
				while(!s2.empty()) {
					node *temp = s2.top();
					s2.pop();
					cout<<temp->data<<" ";
					if(temp->left != NULL) {
						s1.push(temp->left);
					}
					if(temp->right != NULL) {
						s1.push(temp->right);
					}
				}
				cout<<"\n";
			}
}

int main() {
	node *head = (node *) malloc(sizeof(node));
	head->data = 10;
	insertIntoBinaryTree(head,4);
	insertIntoBinaryTree(head,14);
	insertIntoBinaryTree(head,2);
	insertIntoBinaryTree(head,6);
	insertIntoBinaryTree(head,1);
	insertIntoBinaryTree(head,3);
	insertIntoBinaryTree(head,5);
	insertIntoBinaryTree(head,7);
	insertIntoBinaryTree(head,12);
	insertIntoBinaryTree(head,16);
	insertIntoBinaryTree(head,11);
	insertIntoBinaryTree(head,13);
	insertIntoBinaryTree(head,15);
	insertIntoBinaryTree(head,17);
	printTreeLevelWiseLeftToRight(head);
	return 0;
}
