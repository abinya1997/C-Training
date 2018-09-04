/*Factorial_pointer.c Mon Jun 11 2018 01:30:00 Abinaya */
/*
Module:
	Factorial_pointer.c

Function:
	Factorial of a given number

Version:
	V1.01a Mon Jun 11 2018 01:30:00 Abinaya Edit level 1

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
	1.01a Mon Jun 11 2018 01:30:00  Abinaya
	Module created.

*/


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
	Factorial of a given number

Returns:
	Nothing

*/

void Factorial()
	{
	int num;
	int fac;
	int *pnum;

	fac = 1;
	pnum = NULL;
	printf("Enter element\n");
	scanf("%d", &n);
	pnum = &n;
	printf("Factorial of %d is:", n);
	while (*pnum != 0)
		{
		fac *= (*pnum)--;
		}
	printf("%d", fac);
	}
