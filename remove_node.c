/* remove_node.cpp Fri May 18 2018 10:30:00 Abinaya */
/*
Module:
	remove_node.cpp
Function:
	linked list
Version:
	V1.01a Fri May 18 2018 10:30:00 User Edit level 1

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
	1.01a Friday May 18 2018 10:30:00  Abinaya
	Module created.

*/

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


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
	struct Node *next;
	}Node;

/****************************************************************************\
|
|	Read-only data.
|
|	If program is to be ROM-able, these must all be tagged read-only
|	using the ROM storage class; they may be global.
|
\****************************************************************************/



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
Name:	insert()

Function:
	list insertion

Definition:
	struct Node * insert(
		struct Node *phead_node, head of the list
		int new_data insert element
		);

Description:
	This function insert element in the  linked list

Returns:
	struct Node

*/

Node * insert(
	Node *phead_node,
	int new_data
	)
	{
	Node *pnew_node;

	pnew_node = (Node*)malloc(sizeof(Node));
	if (phead_node == NULL)
		{
		pnew_node->data = new_data;
		pnew_node->next = NULL;
		phead_node = pnew_node;
		}
	else
		{
		struct Node *ptemp_node = phead_node;
		pnew_node->data = new_data;
		pnew_node->next = NULL;
		while (ptemp_node->next != NULL)
			ptemp_node = ptemp_node->next;
		ptemp_node->next = pnew_node;
		}
	return (phead_node);
	}


/*
Name:	find_pre()

Function:
	find previous node

Definition:
	Node * find_pre(
		Node *phead, head of the list
		Node *ptemp find pre
		);

Description:
	This function find the previous node of the given node

Returns:
	struct node

*/
Node * find_pre(
	Node *phead,
	int data
	)
	{
	Node * pre_node = NULL, *current_node;

	pre_node = NULL;
	current_node = phead;
	while (current_node != NULL && current_node->data != data)
		{
		pre_node = current_node;
		current_node = current_node->next;
		}
	if (current_node == NULL)
		{
		printf("Node not found\n");
		}
	return pre_node;
	}


/*
Name:
	delete_node()

Function:
	list deletion

Definition:
	Node * delete_node(
		Node * phead_node, head of the list
		int new_data delete element
		);

Description:
	This function delete the particular element of the list

Returns:
	struct node

*/

Node * delete_node(
	Node *phead_node,
	Node *ptemp
	)
	{
	Node *ptemp_node;

	ptemp_node = phead_node;
	if (phead_node != NULL)
		{
		ptemp_node = find_pre(phead_node, ptemp->data);
		if (ptemp_node != NULL)
			{
			ptemp_node->next = ptemp_node->next->next;
			}
		if (ptemp->data == phead_node->data)
			phead_node = phead_node->next;
		}
	return (phead_node);
	}


/*
Name:
	display()

Function:
	display function

Definition:
	void display(
		Node *phead_node head of the list
		);

Description:
	This function display the element of the  list

Returns:
	Nothing
*/

void display(
	Node *phead_node
	)
	{
	Node *ptemp_node;

	ptemp_node = phead_node;
	if (phead_node != NULL)
		while (ptemp_node != NULL)
			{
			printf("%d ", ptemp_node->data);
			ptemp_node = ptemp_node->next;
			}
	else
		printf("NO eelment");
	printf("\n");
	}


/*
Name:	find_pre()

Function:
	find previous node

Definition:
	Node * find_pre(
		Node *phead, head of the list
		Node *ptemp
		);

Description:
	This function find the previous node of the given node

Returns:
	struct node

*/

Node * find_pre(
	Node *phead,
	Node *ptemp
	)
	{
	Node * pre_node = NULL, *current_node;

	pre_node = NULL;
	current_node = phead;
	while (current_node != NULL && current_node != ptemp)
		{
		pre_node = current_node;
		current_node = current_node->next;
		}
	if (current_node == NULL)
		{
		printf("Node not found\n");
		}
	return (pre_node);
	}


/*
Name:
	swap()

Function:
	swap two nodes

Definition:
	void swap(Node **phead_node, head of the list
		Node *ptemp_node1, swap node1
		Node *ptemp_node2 swap node2
		);

Description:
	This function swap two nodes of the  list

Returns:
	Nothing
*/

void swap(
	Node **phead_node,
	Node *ptemp_node1,
	Node *ptemp_node2
	)
	{
	Node *ptemp_node, *ptemp_node1_pre, *ptemp_node2_pre;

	ptemp_node1_pre = find_pre(*phead_node, ptemp_node1);
	ptemp_node2_pre = find_pre(*phead_node, ptemp_node2);
	if (ptemp_node1_pre != NULL)
		{
		ptemp_node1_pre->next = ptemp_node2;
		}
	else
		*phead_node = ptemp_node2;
	if (ptemp_node2_pre != NULL)
		{
		ptemp_node2_pre->next = ptemp_node1;
		}
	else
		*phead_node = ptemp_node1;
	ptemp_node = ptemp_node1->next;
	ptemp_node1->next = ptemp_node2->next;
	ptemp_node2->next = ptemp_node;
	}


/*
Name:	sort()

Function:
	sort the nodes

Definition:
	Node * sort(
		Node *phead_node
		);

Description:
	This function sort the nodes of the list

Returns:
	struct node
*/

Node * sort(
	Node *phead_node
	)
	{
	Node *ptemp_node1, *ptemp_node, *ptemp_node2;
	int temp_val;

	if (phead_node != NULL)
		{
		printf("Sorting\n");
		ptemp_node1 = NULL;
		ptemp_node = phead_node->next;
		ptemp_node2 = phead_node;
		temp_val = phead_node->data;
		while (ptemp_node2 != NULL)
			{
			while (ptemp_node != NULL)
				{
				if (temp_val > ptemp_node->data)
					{
					ptemp_node1 = ptemp_node;
					ptemp_node = ptemp_node->next;
					temp_val = ptemp_node1->data;
					}
				else
					ptemp_node = ptemp_node->next;
				}
			if (ptemp_node1 != NULL)
				{
				swap(&phead_node, ptemp_node1, ptemp_node2);
				ptemp_node2 = ptemp_node1->next;
				ptemp_node = ptemp_node2;
				temp_val = ptemp_node->data;
				ptemp_node1 = NULL;
				}
			else
				{
				ptemp_node2 = ptemp_node2->next;
				ptemp_node = ptemp_node2;
				if (ptemp_node2 != NULL)
					temp_val = ptemp_node->data;
				}
			}
		display(phead_node);
		}
	else
		printf("No element");
	return (phead_node);
	}


/*
Name:	sum()

Function:
	find sum is equal to zero

Definition:
	Node * sum(
		Node * phead_node
		)

Description:
	This function find the elements whose sum is equal to zero

Returns:
	structure node

*/

Node * sum(
	Node * phead_node
	)
	{
	Node *ptemp_node1, *ptemp_node, *ptemp_node2, *ptemp_node1_pre;
	int loc_var,temp_val;

	loc_val = 0;
	if (phead_node != NULL)
		{
		ptemp_node2 = NULL;
		ptemp_node1_pre = phead_node;
		ptemp_node = phead_node;
		while (ptemp_node->next != NULL)
			{
			ptemp_node = ptemp_node->next;
			}
		temp_val = ptemp_node->data;
		ptemp_node = phead_node;
		while (ptemp_node != NULL)
			{
			loc_var += ptemp_node->data;
			ptemp_node2 = insert(ptemp_node2, ptemp_node->data);
			if (loc_var == 0)
				{
				break;
				}
			else if (loc_var < 0)
				{
				if (ptemp_node->next == NULL)
					{
					ptemp_node2 = delete_node
					(ptemp_node2, ptemp_node);
					loc_var -= ptemp_node->data;
					ptemp_node1 = ptemp_node2;
						if (ptemp_node1 != NULL)
						{
						while (ptemp_node1->next
						!= NULL)
							{
							ptemp_node1
							= ptemp_node1->next;
							}
						ptemp_node = phead_node;
						while (ptemp_node1->data
						!= ptemp_node->data)
							{
							ptemp_node
							= ptemp_node->next;
							}
						ptemp_node2 = delete_node
						(ptemp_node2, ptemp_node);
						loc_var -= ptemp_node->data;
						}
					ptemp_node = ptemp_node->next;
					}
				else
					ptemp_node = ptemp_node->next;
				}
			else if (loc_var > 0)
				{
				ptemp_node2 = delete_node(ptemp_node2,
				ptemp_node);
				loc_var -= ptemp_node->data;
				ptemp_node1 = ptemp_node2;
				if (ptemp_node1 != NULL)
					{
					while (ptemp_node1->next != NULL)
						ptemp_node1
						= ptemp_node1->next;
					ptemp_node = phead_node;
					while (ptemp_node1->data
					!= ptemp_node->data)
						{
						ptemp_node = ptemp_node->next;
						}
					ptemp_node2 = delete_node(ptemp_node2,
					ptemp_node);
					loc_var -= ptemp_node->data;
					}
				ptemp_node = ptemp_node->next;
				}
			if (ptemp_node2 != NULL && ptemp_node2->next != NULL
			&& temp_val == ptemp_node2->next->data)
				{
				ptemp_node = ptemp_node1_pre->next;
				ptemp_node1_pre = ptemp_node1_pre->next;
				ptemp_node2 = NULL;loc_var = 0;
				}
			}
		printf("Delete Node\n");
		display(ptemp_node2);
		ptemp_node = ptemp_node2;
		ptemp_node1 = phead_node;
		while (ptemp_node != NULL)
			{
			phead_node = delete_node(phead_node, ptemp_node);
			ptemp_node = ptemp_node->next;
			}
		printf("\nRemaining node\n");
		display(phead_node);
		}
	else
		printf("No element");
	return (phead_node);
	}


/*
Name:	main()

Function:
	linked list

Definition:
	void main(void
	);

Description:
	sort and remove the node whose sum is equal to zero.

Returns:
	Nothing

*/

int main(void
	)
	{
	unsigned int choice;
	int new_data;
	bool bexit;
	Node *phead_node;

	phead_node = NULL;
	bexit = false;
	while (1)
		{
		printf("Enter choice\n");
		printf("1. Insertion 2.Display 3.Exit\n");
		scanf_s("%d", &choice);
		switch (choice)
			{
			case 1:
				printf("Enter no to insert\n");
				scanf_s("%d", &new_data);
				phead_node = insert(phead_node, new_data);
			break;
			case 2:
				display(phead_node);
			break;
			case 3:
				phead_node=sort(phead_node);
				phead_node=sum(phead_node);
			break;
			case 4:
				bexit = true;
			break;
			default:
			break;
			}
		if (bexit == true)
			break;
		}
	return 0;
	}

