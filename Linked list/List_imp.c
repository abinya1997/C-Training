/*List_imp.c Tue may 08 2018 12:30:00 Abinaya */
/*
Module:
	List_imp.c

Function:
	implementation of list

Version:
	V1.01a Tue May 08 2018 12:30:00 Abinaya Edit level 1

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
	1.01a Tue May 08 2018 12:30:00  Abinaya
	Module created.

*/
#include<stdlib.h>
#include<string.h>


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
Name:	main()

Function:
	list implemetation

Definition:
	void main(
		};

Description:
	Create a single link list that will add, delete, display ,search and
	sort the elements.

Returns:
	Nothing

*/

int main()
	{
	int ch;
	int del_no;
	int new_data;
	int af_no;
	int size_list;
	int temp_val;
	int temp_val2,
	int j;
	int k;
	int i;
	struct Node *head = NULL;

	head = NULL;
	j = 0;
	size_list = 0;
	do
		{

		printf("enter choice\n");
		printf("1. Insertion 2.Deletion 3.display");
		scanf_s("%d", &ch);
		switch (ch)
			{
			case 1:
				printf("enter no to insert\n");
				scanf_s("%d", &new_data);;
				if (head == NULL)
					{
					struct Node *new_node = (struct Node*)malloc(sizeof
					(struct Node));
					new_node->data = new_data;
					new_node->next = new_node;
					head = new_node;
					size_list++;
					}
				else
					{
					printf("enter choice to insert\n");
					printf("1.insert begining 2.insert last 3.insert after");
					scanf_s("%d", &ch);
					if (ch < 4)
						size_list++;
					switch (ch)
						{
						case 1:
							{
							struct Node *new_node = (struct Node*)malloc(sizeof
							(struct Node));
							new_node->data = new_data;
							new_node->next = head->next;
							head->next = new_node;
							}
						break;
						case 2:
							{
							struct Node *new_node =
							(struct Node*)malloc
							(sizeof(struct Node));
							struct Node *temp = head;
							while (temp->next != head)
							temp = temp->next;
							new_node->data = new_data;
							new_node->next = head;
							temp->next = new_node;
							}
						break;
						case 3:
							{
							printf("enter the no after
								insertion\n");
							scanf_s("%d", &af_no);
							struct Node *new_node =
							(struct Node*)malloc
							(sizeof(struct Node));
							struct Node *temp = head;
							new_node->data = new_data;
							while (temp->data != af_no)
								{
								temp = temp->next;
								}
							new_node->next = temp->next;
							temp->next = new_node;
							}
						break;
						}
					}
			break;
			case 2:
				{
				printf("enter no to delete\n");
				//c=getchar();
				scanf_s("%d", &del_no);
				struct Node *temp = head;
				while (temp->next->data != del_no)
					{
					temp = temp->next;
					}
				temp->next = temp->next->next;
				if (del_no == head->data)
				head = temp->next;
				size_list--;
				}
			break;
			case 3:
				{
				struct Node *temp = head;
				do
					{
					printf("%d", temp->data);
					temp = temp->next;
					} while (temp != head);
				}
			break;
			}
		} while (ch < 4);
	struct Node *temp,*temp2=NULL;
	temp = head;
	printf("enter no");
	scanf_s("%d", &del_no);
	while (temp->data != del_no)
		{
		temp2 = temp;
		temp = temp->next;
		}
	printf("previous element,address %d %u\n", temp2->data, temp2);
	printf("current element,address %d %u\n", temp->data);
	printf("Next element,address %d %u\n", temp->next->data, temp->next);
	temp = head;
	while (temp->next->data != del_no)
		{
		temp = temp->next;
		}
	printf("previous element,address %d %u\n", temp->data, temp);
	printf("current element,address %d %u\n", temp->next->data, temp->next);
	printf("Next element,address %d %u\n", temp->next->next->data, temp->next->next);
	temp = head->next;
	temp2 = head;
	temp_val = head->data;
	temp_val2 = 0;
	k = size_list;
	printf("assending");
		{
		while (j == size_list)
			{
			for(i=0;i<size_list;i++)
				{
				if (temp_val > temp->data&&temp_val2<temp->data)
					{
					temp = temp->next;
					temp_val = temp->data;
					}
				else
					temp = temp->next;
				}
			printf("%d", temp_val);
			if (temp_val > temp_val2)
				{
				printf("%d", temp_val);
				temp_val2 = temp_val;j++;
				}
			}
		}
	}

