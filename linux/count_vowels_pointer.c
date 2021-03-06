/*count_vowels_pointer.c Mon Jun 11 2018 01:30:00 Abinaya */
/*
Module:
	count_vowels_pointer.c

Function:
	count the number of vowels and consonants

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
#include"Vowels_Count.h"


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
	count the number of vowels and consonants

Returns:
	Nothing

*/

void Vowels_count()
	{
	char *arr;
	int vow_c, con_c,ch;
	while (1)
		{
		vow_c = 0;
		con_c = 0;
		arr = (char*)malloc(20);
		printf("Enter string\n");
		gets_s(arr, 20);
		while (*arr != NULL)
			{
			if (((*arr == 'a') || (*arr == 'e') || (*arr == 'i') ||
				(*arr == 'o') ||(*arr == 'u'))||
				((*arr == 'A') || (*arr == 'E') ||
				(*arr == 'I') || (*arr == 'O') ||
				(*arr == 'U'))
				)
				vow_c++;
			else
				con_c++;
			arr++;
			}
		printf("Number of vowel %d\nNumber of consonant%d\n", vow_c,
			con_c);
		printf("Do u want to continue 1.yes 2.No\n");
		scanf("%d", &ch);
		if (ch == 2)
			break;
		}
	}
	}