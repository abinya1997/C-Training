#include"Simple_operation.h"

void main()
	{
	int case_val;
	printf("1.Factorial\n2.Count vowels\n3.Permutation\nEnter choice ");
	scanf("%d",&case_val);
	swich(case_val)
		{
		case 1:
			Factorial();
		break;
		case 2:
			Vowels_count();
		break;
		case 3:
			Permutation();
		break;
		}
	}
