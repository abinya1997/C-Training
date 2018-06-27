/* circular_linked_list.c Tue May 15 2018 10:30:00 Abinaya */
/*
Module:
	circulae_linked_list.c
Function:
	Circular linked list implementation

Version:
	V1.01a Tue May 15 2018 10:30:00 Abinaya Edit level nn

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
	1.00A Tue May 15 2018 10:30:00 Abinaya
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

static int size_list=0;

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
	singly circular linked list insertion

Definition:
	struct Node * insert(
		struct Node *phead, head of the list
		int new_data        insert element
		)
Description:
	This function insert element in the singly circular linked list

Returns:
	struct Node

*/
struct Node * insert(struct Node *phead, int new_data)
	{
	int  af_no;
	int choice;
	int flag;

	flag = 0;
	if (phead == NULL)
		{
		struct Node *pnew_node = (struct Node*)malloc(sizeof
			(struct Node));
		pnew_node->data = new_data;
		pnew_node->next = pnew_node;
		phead = pnew_node;
		}
	else
		{
		printf("Enter choice to insert\n");
		printf("1.insert begining 2.insert last 3.insert after\n");
		scanf_s("%d", &choice);
		switch (choice)
			{
			case 1:
				{
				struct Node *pnew_node = (struct Node*)malloc
					(sizeof(struct Node));
				pnew_node->data = new_data;
				pnew_node->next = phead->next;
				phead->next = pnew_node;
				}
			break;
			case 2:
				{
				struct Node *pnew_node = (struct Node*)malloc
					(sizeof(struct Node));
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

				printf("Enter the no after insertion\n");
				scanf_s("%d", &af_no);
				struct Node *pnew_node = (struct Node*)malloc(
					sizeof(struct Node));
				struct Node *ptemp = phead;
				pnew_node->data = new_data;
				while (ptemp->data != af_no)
					{
					ptemp = ptemp->next;
					if (ptemp == phead)
					{
						flag = 1;
						break;
					}
					}
				if (ptemp->data == af_no)
					{
					pnew_node->next = ptemp->next;
					ptemp->next = pnew_node;
					}
				else
					printf("Enter wrong value\n");
				}
			break;
			}
			if (choice > 3 || choice < 0)
				printf("Wrong value\n");
		}
	return (phead);
	}

/*
Name:
	delete_node()

Function:
	singly circular linked list deletion

Definition:
	struct Node * delete_node(
	struct Node * phead, head of the list
	int new_data         delete element
	)

Description:
	This function delete the particular element of the singly circular
	linked list

Returns:
	struct Node

*/
struct Node * delete_node(struct Node * phead, int new_data)
	{
	struct Node *ptemp;
	int flag;

	flag = 0;
	ptemp = phead;
	while (phead!=NULL && ptemp->next->data != new_data)
		{
		ptemp = ptemp->next;
		if (ptemp == phead)
			{
			flag = 1;
			break;
			}
		}
	if ((flag == 1 && new_data!=phead->data)||phead==NULL)
		{
		printf("Element not found\n");
		}
	else
	{
		printf("%d", size_list);
		if (size_list == 1 && new_data == phead->data)
		{
			phead = NULL;
		}
		else
			{
			ptemp->next = ptemp->next->next;
			if (new_data == phead->data)
				phead = ptemp->next;
			}
		}
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
	This function display the element of the singly circular linked list

Returns:
	Nothing
*/
void display_node(struct Node *phead)
	{
	struct Node *ptemp;

	ptemp = phead;
	if (phead != NULL)
	{
		do
		{
			printf("%d ", ptemp->data);
			ptemp = ptemp->next;
		} while (ptemp != phead);
	}
	else
		printf("NULL");
	printf("\n");
	}

/*
Name:
	search_node()

Function:
	search function

Definition:
	void display(
	struct Node *phead//head of the list
	)

Description:
	This function search the element of the singly circular linked list

Returns:
	Nothing
*/
void search_node(struct Node *phead)
{
	struct Node *ptemp;
	int del_no;
	int flag;

	ptemp = phead;
	flag = 0;
	printf("search \n Enter no");
	scanf_s("%d", &del_no);
	ptemp = phead;
	while (phead!=NULL && ptemp->next->data != del_no)
		{
		ptemp = ptemp->next;
		if (ptemp == phead)
			{
			flag = 1;
			break;
			}
		}
	if (phead!=NULL && (flag == 0||phead->data==del_no))
		{
		printf("previous element,address %d %u\n", *(&ptemp->data),
			ptemp);
		printf("current element,address %d %u\n", ptemp->next->data,
			ptemp->next);
		printf("Next element,address %d %u\n", ptemp->next->next->data,
			ptemp->next->next);
		}
	else
		printf("No not found\n");
	}

/*
Name:
	main()

Function:
	singly circular linked list

Definition:
	void main(void
	);

Description:
	implementation of singly linked list insertion,deletion,assending and
	decending order of element.

Returns:
	Nothing

*/
int main()
	{
	int choice, del_no, new_data, af_no;
	int temp_val, temp_val2, no_node = 0, i;
	struct Node *phead = NULL;
	unsigned int large = 0;
	unsigned int new_data1,del_no1;
	struct Node *ptemp, *ptemp2 = NULL;

	new_data1 = 0;

	do
		{
		printf("Enter choice sizeof double & data (%u)(%lf)\n",
			sizeof(new_data1), new_data1);
		printf("1. Insertion 2.Deletion 3.display 4.Search\n");
		scanf("%d", &choice);
		switch (choice)
			{
			case 1:
				printf("Enter integer number to insert\n");
				scanf("%d", &new_data);

				new_data = (int)new_data1;
				if (new_data==new_data1)
					{
					if (large < new_data)
						large = new_data;
					phead = insert(phead, new_data);
					size_list++;
					}
				else
					printf("\nNumber is not integer\n");
			break;
			case 2:
				{
				printf("Enter number to delete\n");
				scanf("%lf", &del_no1);
				del_no =(int) del_no1;
				if (del_no == del_no1)
					{
					phead = delete_node(phead, del_no);
					size_list--;
					}
				else
					{
					printf("Enter no is not integer\n");
					}
				}
			break;
			case 3:
				{
				display_node(phead);
				}
			break;
			case 4:
				{
				search_node(phead);
				}
			break;
			}
		} while (choice <= 4);
	if (choice > 4)
		printf("Enter elem within limit");
	if (phead != NULL)
		{
		ptemp = phead->next;
		ptemp2 = phead;
		temp_val = phead->data;
		temp_val2 = 0;
		printf("Assending order\n");
		while (no_node != size_list)
			{
			no_node++;
			for (i = 0;i < size_list;i++)
				{
				if (temp_val > ptemp->data &&
					temp_val2 < ptemp->data)
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
					temp_val = large;
					}
				ptemp = phead;
			}
		printf("\nDecending order\n");
		temp_val = 0;
		temp_val2 = large + 1;
		no_node = 0;
		while (no_node != size_list)
			{
			no_node++;
			for (i = 0;i < size_list;i++)
				{
				if (temp_val < ptemp->data &&
					temp_val2 > ptemp->data)
					{
					temp_val = ptemp->data;
					ptemp = ptemp->next;
					}
				else
					ptemp = ptemp->next;
				}
			if (temp_val < temp_val2)
				{
				temp_val2 = temp_val;
				printf(" %d ", temp_val);
				temp_val = 0;
				}
			ptemp = phead;
			}
		}
	}

