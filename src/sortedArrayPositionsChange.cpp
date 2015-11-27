/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int index, temp, index1;
	if (Arr == NULL || len < 0)
		return NULL;

	for (index = 0; index < len; index++)
	{
		for (index1 = index + 1; index1<len; index1++)
		{
			if (Arr[index]>Arr[index1])
			{
				temp = Arr[index];
				Arr[index] = Arr[index1];
				Arr[index1] = temp;
			}
		}
	}
	return Arr;
}