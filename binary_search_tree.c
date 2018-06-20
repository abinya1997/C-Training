
/*binary_search_tree.c Tue May 29 2018 12:30:00 Abinaya */
/*
Module:	binary_search_tree.c

Function:
	binary search tree
Version:
	V1.01a Tue May 29 2018 12:30:00 Abinaya Edit level 1

Copyright notice:
	This file copyright (C) 2018 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY 14850

	An unpublished work. All rights reserved.

	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation.

Author:
	Abinaya, MCCI May 2018

Revision history:
	1.01a Monday May 29 2018 12:30:00  Abinaya
	Module created.
	1.01b Monday Jun 05 2018 12:30:00  Abinaya
	print module
*/
#include "stdafx.h"
#include<stdlib.h>
struct Node * find_min(struct Node *root);
void print(struct Node *root);
Node * insert(struct Node *root, int val);

/****************************************************************************\
|
|	Manifest constants & typedefs.
|
|	This is strictly for private types and constants which will not
|	be exported.
|
\****************************************************************************/

typedef struct Node
	{
	int data;
	struct Node *left;
	struct Node *right;
	}Node;
typedef struct node
	{
	int data;
	struct node * child;
	struct node *next;
	}List;

/****************************************************************************\
|
|	Read-only data.
|
|	If program is to be ROM-able, these must all be tagged read-only
|	using the ROM storage class; they may be global.
|
\****************************************************************************/

static int count = 0;

/****************************************************************************\
|
|	VARIABLES:
|
|	If program is to be ROM-able, these must be initialized
|	using the BSS keyword.  (This allows for compilers that require
|	every variable to have an initializer.)  Note that only those
|	variables owned by this module should be declared here, using the BSS
|	keyword; this allows for linkers that dislike multiple declarations
|	of objects.
|
\****************************************************************************/
/*
 Name:	print()

 Function:
 	print

 Definition:
 	void print(
		struct Node *root
		);

 Description:
 	This function print element in the tree

 Returns:
 	Nothing

*/

void print()
{
	List *list;
	List *loc;
	List *pre;
	int i;

	pre = NULL;
	list = l;
	if (l != NULL)
	{
		printf("\t");
		while(list != NULL)
		{
			//for(ii=0;i<)
			loc = list;
			while (loc != NULL)
			{
				printf("%d ", loc->data);
				loc = loc->next;
			}
			printf("\n\t");
			list = list->child;
		}
	}

}


/*
Name:	insert()

Function:
	list insertion

Definition:
	Node * insert(
		struct Node *root,
		int val insert element
		);

Description:
	This function insert element in the  linked list

Returns:
	struct Node

*/
Node* insert(
	struct Node *root,
	int val
	)
	{
	if (root == NULL)
		{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
		}
	else
		{

		if (val < root->data)
			{
			root->left = insert(root->left, val);
			}
		else
			{
			root->right = insert(root->right, val);
			}
		}
	return root;
	}


/*
Name:	delete()

Function:
	delete node

Definition:
	Node * insert(
		struct Node *root2,
		int val
		);

Description:
	This function delete element in the tree

Returns:
	struct Node

*/
Node* delete_node(
	struct Node *root2,
	int val
	)
	{
	Node * temp1, *temp;

	if (root2 != NULL)
		if (val < root2->data)
			root2->left = delete_node(root2->left, val);
		else if (val > root2->data)
			root2->right = delete_node(root2->right, val);
		else
			{
			if (root2->left == NULL)
				{
				struct Node *temp = root2->right;
				free(root2);
				return (temp);
				}
			else if (root2->right == NULL)
				{
				struct Node *temp = root2->left;
				free(root2);
				return (temp);
				}
			temp = find_min(root2);
			if (temp != NULL)
				{
				temp1 = temp->left;
				root2->data = temp->left->data;
				temp->left = temp->left->right;
				}
			else
				{
				temp1 = root2->right;
				root2->data = root2->right->data;
				root2->right = root2->right->right;
				}
			free(temp1);
			}
	else
		printf("Node not found\n");
	return root2;
	}


/*
Name:	find_min()

Function:
	minimum node

Definition:
	Node* find_min(
		 Node *root3
		);

Description:
	This function find the minimum element in the tree

Returns:
	struct Node

*/
Node* find_min(
	 Node *root3
	)
	{
	root3 = root3->right;
	while (root3->left != NULL)
		{
		root3 = root3->left;
		}
	return (root3);
	}

/*
Name:	search()

Function:
	search element

Definition:
	void search(
		Node *root,
		int val
		);

Description:
	This function search element in the tree

Returns:
	Nothing

*/
void search(Node *root, int val)
	{
	Node *temp;

	count++;
	if (root != NULL)
		if ((root->left != NULL && root->left->data == val ) ||
		(root->right != NULL && root->right->data == val))
			{
			printf("parent node %d\n", root->data);
			if (root->right!=NULL && root->right->data == val)
				{
				temp = root->right;
				if(root->left != NULL)
					printf("Sibling node %d", root->left->data);
				}
			else
				{
				temp = root->left;
				if (root->right != NULL)
				printf("Sibling node %d", root->right->data);
				}
			printf("children ");
			if (temp->left != NULL)
				{
				printf("%d ", temp->left->data);
				}
			else
				{
				printf("NULL ");
				}
			if (temp->right != NULL)
				printf("%d \n", temp->right->data);
			else
				printf("NULL \n");


			return;
			}

		else
			{
			if (root->data < val)
				{
				search(root->right, val);
				}
			else if (root->data > val)
				{
				search(root->left, val);
				}
			else
				{
				printf("root node %d\n", root->data);
				printf("child->left :%d child->right : %d\n", root->left->data, root->right->data);
				return;
				}
			}
	else
		printf("Not found\n");
	}


/*
Name:	main()

Function:
	binary search tree

Definition:
	int main(
		void
		);

Description:
	This module is implementation of binary search tree

Returns:
	Nothing

*/
void main()
	{
	int insert_no;
	int del_no;
	int data;
	int ch;
	bool bexit;
	Node *root;
	Node * temp;

	bexit = false;
	root = NULL;
	temp = NULL;
	while (1)
		{
		printf("1.insert 2.display 3.search 4.delete 5.exit\n");
		printf("Enter choice\n");
		scanf_s("%d", &ch);
		switch (ch)
			{
			case 1:
				printf("Enter number of data\n");
				scanf_s("%d", &co);
				printf("%d", co);
				printf("enter elements\n");
				for (i = 0;i < co;i++)
					{
					check1 = scanf_s("%d", &insert_no);
					if (check1 != 0)
						{
						root = insert(root, insert_no);
						}
					else
						{
						printf("Wrong value");
						}
					}
			break;

			case 2:
				if (root != NULL)
					{
					printf("%d ", root->data);
					print(root);
					printf("\n");
					}
				else
					printf("Tree empty\n");
			break;

			case 3:
				printf("Enter search element\n");
				scanf_s("%d", &data);
				search(root, data);
				printf("\nflow %d ", count);
				count = 0;
			break;
			case 4:
				printf("Enter del no\n");
				scanf_s("%d", &del_no);
				root = delete_node(root, del_no);
			break;
			case 5:
				bexit = true;
			break;
			default:
			break;
			}
		if (bexit == true)
			break;
		}

	}