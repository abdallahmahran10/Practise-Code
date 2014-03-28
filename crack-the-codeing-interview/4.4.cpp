#include <iostream>
#include <list>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *root;

Node *newNode(int el)
{
	Node *tmp = new Node();
	tmp->data = el;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void preorder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		printf("\n");		
		preorder(root->left);
		preorder(root->right);		
	}
}

void display()
{
	preorder(root);
}

Node *createTree(int arr[], int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	Node *root = newNode(arr[mid]);
	root->left = createTree(arr, start, mid-1);
	root->right = createTree(arr, mid+1, end);
	return root;
}

int findDepth(Node *root)
{
	if(root == NULL)
		return -1;
	return 1 + max(findDepth(root->left), findDepth(root->right));
}

void createLinkedList(Node *root)
{
	int totalDepth = findDepth(root);
	list<int> *linkedList = new list<int>[totalDepth];

}


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	root = createTree(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	display();
	return 0;
}