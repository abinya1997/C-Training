/*binary_search.cpp Mon May 28 2018 12:57:00 Abinaya */
/*
Module:	binary_search.c

Function:
	binary search
Version:
	V1.01a Mon May 28 2018 12:57:00 Abinaya Edit level 1

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
	1.01a Mon May 28 2018 12:57:00  Abinaya
	Module created.

*/
#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>


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
	Node *pnew_node = (Node*)malloc(sizeof
		(Node));
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
Name:	display()

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
			printf(" %u %d %u\n", ptemp_node,ptemp_node->data,ptemp_node->next);
			ptemp_node = ptemp_node->next;
			}
	else
		printf("NO eelment");
	printf("\n");
	}

/*
Name:	find_mid()

Function:
	find mid element

Definition:
	Node * find_mid(
		Node * phead,
		Node *tail
		);

Description:
	This function find the middle element of the  list

Returns:
	Node

*/
Node * find_mid(Node * phead, Node *tail)
	{
	Node * ptemp;
	int len;

	len = 0;
	ptemp = phead;
	while (phead != tail)
		{
		if ((len & 1) != 0)
			ptemp = ptemp->next;
		len++;
		phead = phead->next;
		}
	return ptemp;
	}

/*
Name:	binarysearch()

Function:
	search the element

Definition:
	Node * binarysearch(
		Node *phead,
		Node *ptail,int num
		);

Description:
	This function find the element of the  list

Returns:
	Node if element found else NULL

*/
Node * binarysearch(Node *phead,Node *ptail,int num)
	{
	while (phead != ptail)
		{
		Node * pmid = find_mid(phead, ptail);
		if (num > pmid->data)
			{
			phead = pmid->next;
			}
		else if (num < pmid->data)
			{
			ptail = pmid;
			}
		else
			return pmid;
		}
	return NULL;
	}

/*
Name:	merge()

Function:
	merge the element

Definition:
	Node * merge(
		Node *head,
		Node *tail
		);

Description:
	This function merge the element in ascending order

Returns:
	Node

*/
Node * merge(Node *head, Node *tail)
	{
	Node * pnew_node;

	pnew_node = NULL;
	if (head == NULL)
		return tail;
	else if (tail == NULL)
		return head;
	else if (head->data <= tail->data)
		{
		pnew_node = head;
		pnew_node->next = merge(head->next, tail->next);
		}
	else if (head->data >= tail->data)
		{
		pnew_node = tail;
		pnew_node->next = merge(head, tail->next);
		}
	return pnew_node;
	}

/*
Name:	mergesort()

Function:
	sort the list

Definition:
	Node * mergesort(
		Node *head,
		Node *tail
		);

Description:
	This function sort the element of the  list

Returns:
	Node

*/
Node * mergesort(Node *head,Node *tail)
	{
	if (head != tail)
		{
		Node *ptemp = find_mid(head, tail);
		mergesort(head, ptemp);
		mergesort(ptemp->next, tail);
		head=merge(head, tail);
		}
	return head;
	}


/*
Name:	main()

Function:
	sort and search

Definition:
	int main(
		};

Description:
	This function sort the list in merge sort and search the element of the  list

Returns:
	Nothing

*/
void main()
	{
	Node *phead_node;
	Node *ptemp_node;
	int ch;
	int new_data;
	int data;

	boolean bexit = false;
	phead_node = NULL;
	ptemp_node =  NULL;
	data = 0;
	new_data = 0;
	ch = 0;
	while (1)
		{
		printf("Enter choice\n");
		printf("1.insert 2.display 3.search 4.sort 5.exit\n");
		scanf_s("%d", &ch);
		switch (ch)
			{
			case 1:printf("Enter element to insert\n");
				scanf_s("%d", &new_data);
				phead_node = insert(phead_node, new_data);
			break;
			case 2:
				display(phead_node);
			break;
			case 3:
				printf("Enter no to search\n");
				scanf_s("%d", &data);
				ptemp_node=binarysearch(phead_node, NULL, data);
				if (ptemp_node != NULL)
					printf("Current node Addres-%u Data-%d
						Nextnode Address-%u\n",
						ptemp_node,
						ptemp_node->data,
						ptemp_node->next
						);
				else
					printf("Element not found");
			break;
			case 4:
				phead_node = mergesort(phead_node, NULL);
				display(phead_node);
			break;
			case 5: bexit=true;
			break;
			default:
			break;
			}
		if(bexit==true)
			break;
		}

	}

