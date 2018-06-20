/*permutation.c Tue June 12 2018 12:30:00 Abinaya */
/*
Module:	permutation.c

Function:
	permutation of the string
Version:
	V1.01a Tue Jun 12 2018 12:30:00 Abinaya Edit level 1

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
	1.01a Tue Jun 12 2018 12:30:00  Abinaya
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
	permutation

Definition:
	void main(
		};

Description:
	find the pemutation of the given string

Returns:
	Nothing

*/
void main()
{
	char a[10];
	char *arr;
	char *last;
	char * move;
	char *temp;
	char *move2;
	int i;
	int j;
	int length;
	int len1;
	int c;
	int k;
	int count;

	count = 1;
	c = 0;
	printf("Enter string \n");
	scanf("%s", a);
	arr = a;
	printf("String is ");
	length = printf("%s", a);
	printf("\n");
	for (i = 1;i <= length;i++)
		{
		count *= i;
		}
	fir = a[0];
	last = a[length - 1];
	move = last;
	len1 = length-1;
	for (i = 0;i <= count;i++)
		{

		for (j = 0;j < length ;j++)
			{
			if (a[j] == move && j > 0)
				{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				printf("%s ", a);i++;
				}
			if (a[0] == move)
				break;
			}
		if (a[0] == move )
			{
			last = a[len1];
			a[len1] = a[len1 - 1];
			a[len1-1] = last;
			printf("%s ", a);i++;
			if (a[0] == last)
				{
				len1 = length - 1;
				}
			else
				len1--;
			for (j = 0;j < length-1&&i<count;j++)
				{
				temp = a[j+1];
				a[j +1] = a[j];
				a[j] = temp;
				printf("%s ", a);
				i++;
				}
			last = a[len1];
			a[len1] = a[len1 - 1];
			a[len1 - 1] = last;
			printf("%s ", a);
			if (a[0] == last)
				{
				len1 = length - 1;
				}
			else
				len1--;
			}
		}
	}

