/*file_20180608a.c Mon Jun 08 2018 12:30:00 Abinaya */
/*
Module:	file_20180608a.c

Function:
	File operation
Version:
	V1.01a Mon Jun 08 2018 12:30:00 Abinaya Edit level 1

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
	1.01a Mon Jun 08 2018 12:30:00  Abinaya
	Module created.

*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


/****************************************************************************\
|
|	Manifest constants & typedefs.
|
|	This is strictly for private types and constants which will not
|	be exported.
|
\****************************************************************************/


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
struct node
	{
	int id;
	char name[20];
	char des[20];
	}emp, emp1;


/*
Name:	main()

Function:
	data insert,delete,search and edit from the file.

Definition:
	void main(
		};

Description:
	This function get the data from user and store the data in file.
	Then delete,search and edit data from file.

Returns:
	Nothing

*/

void main()
	{
	int choice;
	int emp_id;
	int option;
	int flag;
	int position;
	int position1;
	int location;
	int bexit;
	char emp_name[20];
	char *temp, *temp1;
	char destin[20];
	FILE *detail;
	FILE *detail1;
	unsigned int index;
	unsigned int count;

	index = 0;
	flag = 0;
	option = 0;
	position = 0;
	position1 = 0;
	temp = NULL;
	temp1 = NULL;
	emp_id = 0;
	bexit = 0;
	count = 0;
	location = 0;
	choice = 0;
	while(1)
		{
		printf("1.Insert 2.Search 3.Edit 4.Display 5.Delete
		6.Exit \n Enter choice \n");
		scanf("%d", &choice);
		switch (choice)
			{
			case 1:
				detail = fopen("detail.txt", "r+");
				location = 0;
				printf("Enter no of data insert\n");
				scanf("%d", &count);
				//printf("%d", ftell(detail));
				for (index = 0;index < count;++index)
					{
					flag = 0;
					printf("Enter id\n");
					scanf("%d", &emp.id);
					printf("Enter name\n");
					scanf("%s", emp.name);
					printf("Enter Team\n");
					scanf("%s", emp.des);
					fseek(detail, 0, SEEK_SET);
					while (fread(&emp1,
					sizeof(emp), 1, detail) == 1)
						{
						location = ftell(detail);
						if (emp.id == emp1.id)
							{
							flag = 1;
							break;
							}
						}
					if (flag != 1)
						{
						if (location != 0)
							{
							fseek(detail, 0,
							SEEK_SET
							);
							fseek(detail, location,
							SEEK_CUR
							);
							}
						fwrite(&emp,
						sizeof(emp), 1, detail);
						}
					else
						printf("Dublicate data");
					}
				fseek(detail, 0, SEEK_SET);
				fclose(detail);
			break;
			case 2:
				detail = fopen("detail.txt", "r+");
				fseek(detail, 0, SEEK_SET);
				printf("Do u want to search data using id or
				name press \n 1.Id 2.Name\n");
				scanf("%d", &option);
				if (option == 1)
					{
					printf("Enter id");
					scanf("%d", &emp_id);
					while (fread(&emp, sizeof(emp),
						1, detail) == 1)
						{
						if (emp.id == emp_id)
							{
							printf("Id\tName\t\t
							Team\n%d\t%s\t\t%s\n",
							emp.id, emp.name,
							emp.des
							);
							break;
							}
						}
					}
				else
					{
					flag = 0;
					printf("Enter name\n");
					scanf("%s", emp_name);
					while (fread(&emp,
					sizeof(emp), 1, detail) == 1)
						{
						temp = emp_name;
						temp1 = emp.name;
						while (*temp1 != NULL &&
						(*temp1 != ' ')
							)
							{
							if (*temp != *temp1)
								{
								flag = 1;
								break;
								}
							temp = ++temp;
							temp1 = ++temp1;

							}
						if (flag == 0)
							{
							printf("Id\tName\t\t
							Designation\n%d\t%s
							\t\t%s\n",
							emp.id, emp.name,
							emp.des);

							break;
							}
						else
							{
							printf("Data not
								founnd\n");
							flag = 0;
							}
						}
					}
				fclose(detail);
			break;
			case 3:
				detail = fopen("detail.txt", "r+");
				flag = 0;
				fseek(detail, 0, SEEK_SET);
				printf("Enter id\n");
				scanf("%d", &emp_id);
				position = 0;
				while (fread(&emp,
				sizeof(emp), 1, detail) == 1
				)
					{

					position1 = position;
					position = ftell(detail);
					//printf("%d ", position1);
					if (emp.id == emp_id)
						{
						printf("Data in the file\n\n");
						printf("Id\tName\t\t
						Designation\n%d\t%s\t\t%s",
						emp.id, emp.name, emp.des);
						flag= 1;
						}
					if (flag== 1)
						break;
					}
				fseek(detail, 0, SEEK_SET);
				printf("\n");
				if (flag== 1)
					{
					printf("Do u wnt to modify data press
					1.Id 2.Name 3.Team\n");
					scanf("%d", &op);
					fseek(detail, position1, SEEK_CUR);
					switch (op)
						{
						case 1:
							printf("Enter new
							id\n");
							scanf("%d", &emp_id);
							emp.id = emp_id;
							fwrite(&emp,
							sizeof(emp),
							1, detail);
							break;
						case 2:
							printf("Enter new
							name\n");
							scanf("%s", emp.name);
							//emp.name = emp_name;
							fwrite(&emp,
							sizeof(emp),
							1, detail);
							break;
						case 3:printf("Enter new
						team name\n");
							scanf("%s", emp.des);
							//emp.des = destin;
							fwrite(&emp,
							sizeof(emp),
							1, detail
							);
							break;
						}
					}
					else
						printf("Data not found\n");
					fclose(detail);
			break;
			case 4:
				detail = fopen("detail.txt", "r+");
				fseek(detail, 0, SEEK_SET);
				printf("\nId\tName\t\tDesignation\n");
				while (fread(&emp, sizeof(emp), 1, detail) ==1)
					{
					//if(emp.id != 0)
					printf("%d\t%s\t\t%s\n",
					emp.id, emp.name, emp.des);
					//fgetc(detail);
				}
				printf("\n");
				fclose(detail);
			break;
			case 5:
				detail = fopen("detail.txt", "r+");
				detail1 = fopen("detail1.txt", "w+");
				printf("Enter id\n");
				scanf("%d", &emp_id);
				position = 0;
				while (fread(&emp,
				sizeof(emp),
				1, detail) == 1
				)
					{
					if (emp.id != emp_id)
						{
						fwrite(&emp,
						sizeof(emp),
						1,
						detail1);
						}
					else
						position = 1;
					}
				if (position == 1)
					{
					remove(detail);
					detail = fopen("detail.txt", "w+");
					fseek(detail, 0, SEEK_SET);
					fseek(detail1, 0, SEEK_SET);
					while (fread(&emp,
					sizeof(emp),
					1,
					detail1) == 1)
						{
						fwrite(&emp,
						sizeof(emp), 1, detail);
						}
					}
				else
					printf("Data not found");
				fclose(detail);
				fclose(detail1);
			break;
			case 6:
				bexit = 1;
			break;
			default:
			break;
			}
		if (bexit == 1)
			{
			break;
			}
		}
	}

