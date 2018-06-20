/* Linked_List.c Mon May 14 2018 10:30:00 Abinaya */
/*
Module:
	Linked_List.c

Function:
	linked list implementation

Version:
	V1.01a Mon May 14 2018 10:30:00 Abinaya Edit level nn

Copyright notice:
	This file copyright (C) 2018 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY 14850

	An unpublished work. All rights reserved.

	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation.

Author:
	Abinaya P, MCCI May 2018

Revision history:
	1.00A Tue May 14 2018 10:30:00 Abinaya
	Module created.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/****************************************************************************\
|
|	Manifest constants & typedefs.
|
|	This is strictly for private types and constants which will not
|	be exported.
|
\****************************************************************************/

struct Node
	{
	int data;
	struct Node *next;
	};

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
Name:
	insert()

Function:
	linked list insertion

Definition:
	struct Node * insert(
		struct Node *phead, head of the list
		int new_data insert element
	)
Description:
	This function insert element in the linked list

Returns:
	struct Node

*/
struct Node * insert(struct Node *phead, int new_data)
{
	int  af_no;
	int ch;

	if (phead == NULL)
	{
		struct Node *pnew_node = (struct Node*)malloc(sizeof
		(struct Node));
		pnew_node->data = new_data;
		pnew_node->next = pnew_node;
		phead = pnew_node;
		size_list++;
	}
	else
	{
		printf("enter choice to insert\n");
		printf("1.insert begining 2.insert last 3.insert after\n");
		scanf_s("%d", &ch);
		if (ch < 4)
			size_list++;
		switch (ch)
			{
			case 1:
				{
				struct Node *pnew_node = (struct Node*)malloc(sizeof
					(struct Node));
				pnew_node->data = new_data;
				pnew_node->next = phead->next;
				phead->next = pnew_node;
				}
			break;
			case 2:
				{
				struct Node *pnew_node = (struct Node*)malloc(sizeof
					(struct Node));
				struct Node *ptemp = phead;
				while (ptemp->next != phead)
				ptemp = ptemp->next;
				pnew_node->data = new_data;
				pnew_node->next = phead;
				ptemp->next = pnew_node;
				}
			break;
			case 3:
				{
				printf("enter the no after insertion\n");
				scanf_s("%d", &af_no);
				struct Node *pnew_node = (struct Node*)malloc(sizeof
					(struct Node));
				struct Node *ptemp = phead;
				pnew_node->data = new_data;
				while (ptemp->data != af_no)
					{
					ptemp = ptemp->next;
					}
				pnew_node->next = ptemp->next;
				ptemp->next = pnew_node;
				}
			break;
			}

		}
	return (phead);
	}

/*
Name:
	delete_node()

Function:
	linked list deletion

Definition:
	struct Node * delete_node(
		struct Node * phead, head of the list
		int new_data delete element
		)

Description:
	This function delete the particular element of the linked list

Returns:
	struct Node
*/
struct Node * delete_node(struct Node * phead, int del_no)
{
	struct Node *ptemp = phead;

	while (ptemp->next->data != del_no)
	{
		ptemp = ptemp->next;
	}
	ptemp->next = ptemp->next->next;
	if (del_no == phead->data)
		phead = ptemp->next;
	return phead;
}

/*
Name:
	delete_node()

Function:
	display function

Definition:
	void display(
		struct Node *phead//head of the list
		)

Description:
	This function display the element of the linked list

Returns:
	Nothing
*/
void display(struct Node *phead)
{
	struct Node *ptemp;

	ptemp = phead;
	do
	{
		printf("%d", ptemp->data);
		ptemp = ptemp->next;
	} while (ptemp != phead);
}

/*
Name:
	main()

Function:
	linked list

Definition:
	void main(void
		);

Description:
	implementation of linked list insertion,deletion,assending and decending order of element.

Returns:
	Nothing

*/
void main()
{
	int ch;
	int del_no;
	int new_data;
	int af_no;
	int size_list;
	int temp_val;
	int temp_val2;
	int j;
	int k;
	int i;
	struct Node *phead;
	struct Node *ptemp;
	struct Node *ptemp2;

	ptemp2 = NULL;
	j = 0;
	size_list = 0;
	ptemp = NULL;
	phead = NULL;
	do
		{
		printf("enter choice\n");
		printf("1. Insertion 2.Deletion 3.display\n");
		scanf_s("%d", &ch);
		switch (ch)
			{
			case 1:
				printf("enter no to insert\n");
				scanf_s("%d", &new_data);
				phead = insert(phead, new_data);
				size_list++;
			break;
			case 2:
				{
				printf("enter no to delete\n");
				scanf_s("%d", &del_no);
				size_list--;
				phead = delete_node(phead, del_no);
				}
			break;
			case 3:
				{
				display(phead);
				}
			break;
			}

		}while (ch < 4);
	ptemp = phead;
	printf("search \n enter no");
	scanf("%d", &del_no);
	ptemp = phead;
	while (ptemp->next->data != del_no)
		{
		ptemp = ptemp->next;
		}
	printf("previous element,address %d %u\n", ptemp->data,
		ptemp);
	printf("current element,address %d %u\n", ptemp->next->data,
		ptemp->next);
	printf("Next element,address %d %u\n", ptemp->next->next->data,
		ptemp->next->next);
	ptemp = phead->next;
	ptemp2 = phead;
	temp_val = phead->data;
	temp_val2 = 0;
	printf("assending order\n");
	while (j != size_list)
		{
		j++;
		for (i = 0;i < size_list;i++)
			{
			if (temp_val > ptemp->data && temp_val2 < ptemp->data)
				{
				temp_val = ptemp->data;
				ptemp = ptemp->next;
				}
			else
				ptemp = ptemp->next;
			}
		if (temp_val > temp_val2)
			{
			temp_val2 = temp_val;
			printf(" %d ", temp_val);
			temp_val = 100;
			}
		ptemp = phead;
		}
	printf("decending order\n");
	temp_val = 0;
	temp_val2 = 100;
	j = 0;
	while (j != size_list)
		{
		j++;
		for (i = 0;i < size_list;i++)
			{
			if (temp_val < ptemp->data && temp_val2 > ptemp->data)
				{
				temp_val = ptemp->data;
				ptemp = ptemp->next;
				}
			else
				ptemp = ptemp->next;
			}
		if (temp_val < temp_val2)
			{

			temp_val2 = temp_val;printf(" %d ", temp_val);
			temp_val = 0;
			}
		ptemp = phead;
		}
	getchar();
	}

