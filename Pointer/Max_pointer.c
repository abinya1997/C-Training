/*Max_pointer.c Mon Jun 11 2018 12:30:00 Abinaya */
/*
Module:
	Max_pointer.c

Function:
	implementation of list

Version:
	V1.01a Mon Jun 11 2018 12:30:00 Abinaya Edit level 1

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
	1.01a Mon Jun 11 2018 12:30:00  Abinaya
	Module created.

*/
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

/*
Name:	main()

Function:
	Pointer

Definition:
	void main(
		};

Description:
	Maximum number between two numbers using a pointer

Returns:
	Nothing

*/

int main()
	{
	int num;
	int num1;
	int *n1;
	int *n2;

	n1 = NULL;
	n2 = NULL;
	printf("Enter no1\n");
	scanf("%d", &num);
	printf("Enter no2\n");
	scanf("%d", &num1);
	n1 = &num;
	n2 = &num1;
	if (*n1 < *n2)
		printf("maximum no is %d", *n2);
	else
		printf("Maximum no is %d", *n1);
	}