/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int index;
	if (Arr == NULL || len <= 0)
		return NULL;
	Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
	index = 0;
	if (Arr[index]>num)
	{
		for (index = 0; index <= len; index++)
		{
			Arr[index + 1] = Arr[index];
		}
		Arr[0] = num;
	}
	else
	{
		index = len - 1;
		while (num < Arr[index] && index >= 0)
		{
			Arr[index + 1] = Arr[index];
			index--;
		}
		Arr[index + 1] = num;
		len++;
	}
	return Arr;
}