/*compare_node.cpp Thu May 24 2018 4:30:00 Abinaya */
/*
Module:
	compare_node.cpp

Function:
	linked list
Version:
	V1.01a Thu May 24 2018 4:30:00 User Edit level 1

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
	1.01a Thursday May 24 2018 4:30:00  Abinaya
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

	ptemp_node=phead_node;
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
Name:	main()

Function:
	linked list

Definition:
	void main(void
		);

Description:
	This function compare two lists and display list in reverse order.

Returns:
	Nothing

*/

void main(void
	)
	{
	int choice;
	int new_data;
	int no_list1;
	int no_list2;
	int flag;
	int ch;
	bool bexit;
	Node *phead_node;
	Node *phead_node1;
	Node *ptemp_node;
	Node *ptemp_node1;
	Node *ptemp_node2;

	no_list1 = 0;
	no_list2 = 0;
	flag = 0;
	bexit = 0;
	phead_node = NULL;
	phead_node1 = NULL;
	while (1)
		{
		printf("Enter choice\n");
		printf("1.Insert list1  2.Insert list2 3.Display
		4.compare 5.Reverse print 6.Exit\n");
		scanf_s("%d", &ch);
		switch (ch)
			{
			case 1:
				do
					{
					printf("Enter element of list1\n");
					scanf_s("%d", &new_data);
					no_list1++;
					phead_node = insert(phead_node, new_data);
					printf("do u want to insert
					another element 1.yes 2.no\n");
					scanf_s("%d", &choice);
					} while (choice == 1);
			break;
			case 2:
				do
					{
					printf("Enter element of list2\n");
					scanf_s("%d", &new_data);
					no_list2++;
					phead_node1 = insert(phead_node1, new_data);
					printf("do u want to insert
					another element 1.yes 2.no\n");
					scanf_s("%d", &choice);
					} while (choice == 1);
			break;
			case 3:
				printf("List 1 elements  :");
				display(phead_node);
				printf("List 2 elements  :");
				display(phead_node1);
			break;
			case 4:
				flag = 0;
				ptemp_node = phead_node;
				ptemp_node1 = phead_node1;
				if (no_list1 == no_list2)
					{
					while (no_list1 != 0)
						{
						if (ptemp_node->data !=
						ptemp_node1->data)
							{
							flag = 1;
							break;
							}
						else
							{
							ptemp_node = ptemp_node->next;
							ptemp_node1 =
							ptemp_node1->next;
							}
						no_list1--;
						}

					if (flag == 1)
						{
						printf("list1 , list2 are not same\n");
						}
					else
						printf("List1, list2 are same\n");
					}
				else
					printf("list1 , list2 are not same\n");
			break;
			case 5:
				ptemp_node = phead_node;
				ptemp_node1 = NULL;
				if (ptemp_node != NULL)
					{
					while (ptemp_node != ptemp_node1)
						{
						if (ptemp_node->next == ptemp_node1)
							{
							ptemp_node1 = ptemp_node;
							printf("%d ",
							ptemp_node->data);
							ptemp_node = phead_node;
							}
						else
							ptemp_node = ptemp_node->next;
						}
					}
				else
					printf("Empty list\n");
			break;
			case 6:
				bexit = true;
			break;
			default:
			break;
			}
		if (bexit == true)
			break;
		}
	}

