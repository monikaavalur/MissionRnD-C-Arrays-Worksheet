/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int index, index1, index2 = 0, temp;
	if (Arr == NULL || len < 0)
		return NULL;
	for (index = 0; index < len; index++)
	{
		for (index1 = index + 1; index1 < len; index1++)
		{
			if (Arr[index] >= Arr[index1])
			{
				temp = Arr[index];
				Arr[index] = Arr[index1];
				Arr[index1] = temp;
			}
		}
	}

	for (index = 0; index < len; index++)
	{
		for (index1 = index + 1; index1 < len; index1++)
		{
			if (Arr[index] == Arr[index1])
			{
				for (index2 = index1; index2 < len; index2++)
				{
					Arr[index2] = Arr[index2 + 1];
				}
				len--;
			}
			else
				index1++;
		}

	}

	return Arr;
}