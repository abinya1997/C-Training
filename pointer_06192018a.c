/*pointer_06192018a.c Tue Jun 19 2018 2:30:00 Abinaya */
/*
Module:	pointer_06192018a.c

Function:
	string operation using pointer

Version:
	V1.01a Tue Jun 19 2018 2:30:00 Abinaya Edit level 1

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
	1.01a Tue Jun 19 2018 2:30:00  Abinaya
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
	string operation using pointer

Definition:
	void main(
		};

Description:
	This function find the length of the string, compare the string and
	change the string into uppercase.

Returns:
	Nothing

*/

void main()
	{
	unsigned int choice;
	char *string;
	char *string1;
	int index1;
	int index1;
	int bexit;
	unsigned int len;
	int num;
	long int num1;

	num1 = 0;
	num = 0;
	len = 0;
	bexit = 0;
	index = 0;
	index1 = 0;
	string1 = NULL;
	string = NULL;
	choice = 0;
	while (1)
		{
		printf("1.string Length\n2.String Concatination\n3.atoi\n4.
			String compare\n5.Uppercase\n6.Exit\n");
		printf("Enter choice\n");
		scanf("%d", &choice);
		str = (char *) malloc(20);
		str1 = (char *) malloc(20);
		switch (choice)
			{
			case 1:
				len = 0;
				printf("Enter string\n");
				gets_s(string, 20);
				while (*string++ != NULL)
					{
					len++;
					}
				printf("Length is %d\n", len);
			break;
			case 2:
				printf("Enter string1\n");
				gets_s(string, 20);
				printf("Enter string2\n");
				gets_s(string1, 20);
				for (index = 0;*(string + index) != NULL;
					++index
					);
				len = index;
				for (index = 0;*(string1 + index) !=
					NULL;++index
					)
					{
					*(string + len + index) =
					*(string1 + index);
					}
				for (index1 = 0;index1 < (len + index);
					++index1
					)
				printf("%c", *(string + index1));
				printf("\n");
			break;
			case 3:
				printf("Enter number\n");
				gets_s(string, 20);
				len = 0;
				for (index= 0;*(string + index) != NULL;
					++index
					);
				if (*(string + index) == NULL)
					if (index < 10)
						{
						for (index = 0;(
							*(string + index))
							!= NULL;i++
							)
							{
							num = num * 10 +
							(*(string + index)
							- 48);
							}
						printf("int is %d\n", num);
						}
					else
						{
						for (index = 0;*(string +
							index)!= NULL;
							++index
							)
							{
							num1 = num1 * 10 +
							(*(string + i) - 48);
							}
						printf("long int is %ld\n",
							num1);
						}
				else
					printf("Wrong value");
				break;
			case 4:
				printf("Enter string1\n");
				gets_s(string, 20);
				printf("Enter string2\n");
				gets_s(string1, 20);
				for (index= 0;*(string +index) != NULL;i++)
					{
					if(*(string + index) != *(string1 + index))
						if ((*(string + index) >= 'A') &&
							(*(string + index) <= 'Z')
							)
							{
							if (*(string + index) !=
								(*(string1 + index)
								- 32)
								)
								{
								break;
								}
							}
						else
							{
							if((*(string + index) >=
								'a')&&
								(*(string + index)
								<= 'z')
								)
								{
								if (
								(*(string + index)
								- 32)
								!= *(string1 + index)
								)
									{
									break;
									}
								}
							}
					}
				if (*(string + index) != NULL)
					{
					printf("Not equal\n");
					}
				else
					printf("Equal\n");
			break;
			case 5:
				printf("Enter string\n");
				gets_s(string, 20);
				for(index = 0;*(string + index)!= NULL;++index)
					{
					if ((*(string + index) >= 'a')&&
						(*(string + index) <= 'z')
						)
					*(string + index) -= 32;
					}
				printf("%s\n", string);
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

