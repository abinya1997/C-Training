/*reverse_stack.c Wed Jun 06 2018 12:30:00 Abinaya */
/*
Module:	reverse_stack.c

Function:
	reverse the data
Version:
	V1.01a Wed Jun 06 2018 12:30:00 Abinaya Edit level 1

Copyright notice:
	This file copyright (C) 2018 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY 14850

	An unpublished work. All rights reserved.

	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation.

Author:
	Abinaya, MCCI Jun 2018

Revision history:
	1.01a Wed Jun 06 2018 12:30:00  Abinaya
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


typedef struct node
	{
	char *val;
	int len;
	struct node *next;
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
Name:	main()

Function:
	reverse the data

Definition:
	int main(
		};

Description:
	This function get the data from file and store the data in stack.
	Then print the data in reverse order.

Returns:
	Nothing

*/
void main(
	)
	{
	FILE * source;
	FILE * fout;
	char get;
	char data;
	Node *head;
	Node *temp;
	Node *temp1;
	int ch,
	int choice;
	int con;
	int index;
	char pstr[100];
	char arr[20];

	head = NULL;
	do
		{
		head = NULL;
		source = fopen("C:\\Users\\Abinaya\\Documents\\source.txt",
			"r+");
		fout = fopen("C:\\Users\\Abinaya\\Documents\\fout.txt", "w+");
		printf("Data in the file\n");
		while ((get = fgetc(source)) != EOF)
			{
			printf("%c", get);
			}
		printf("\nDo you want to insert data\n \t 1.Yes 2.NO\n");
		scanf("%d", &choice);
		if (choice == 1)
			{
			printf("Enter data\n");
			scanf("%s", pstr);
			fseek(source, 0, SEEK_END);
			fputc(' ', source);
			for (index = 0;index < strlen(pstr);++index)
				{
				fputc(pstr[index], source);
				}
			fseek(source, 0, SEEK_SET);
			}
		if (source != NULL)
			{
			while ((get = fgetc(source)) != EOF)
				{
				i = 0;
				arr[i] = get;
				while ((get = fgetc(source))!=EOF && get!= ' ')
					arr[++i] = get;
				if (head != NULL)
					{
					temp = (Node *)malloc(sizeof(Node));
					temp->val = arr;
					temp->len = i + 1;
					temp->next = head;
					head = temp;
					}
				else
					{
					temp = (Node *)malloc(sizeof(Node));
					temp->val = arr;
					temp->len = i + 1;
					temp->next = NULL;
					head = temp;
					}
				}
			}
		else
			printf("Error:open file\n");
		printf("If you want reverse \n\t1.Yes 2.No\n");
		scanf("%d", &ch);
		if (ch == 1)
			{
			printf("\n");
			if (fout != NULL)
				{
				while (head != NULL)
					{
					for (index = head->len - 1;index >= 0;--index)
						{
						fputc(head->val[index], fout);
						printf("%c", head->val[index]);
						}
					temp1 = head;
					head = head->next;
					free(temp1);
					printf(" ");
					}
				fseek(fout, 0, SEEK_SET);
				printf("\n");
				}
			else
				printf("Not found\n");
			}
		fclose(source);
		fclose(fout);
		printf("Do u want to continue.. 1.Yes 2.No\n");
		scanf("%d", &con);
		} while (con == 1);
	}

