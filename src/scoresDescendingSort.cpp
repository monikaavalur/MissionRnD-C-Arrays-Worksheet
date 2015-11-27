/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	struct student temp;
	int index = 0, index1 = 0;
	if (len<0 || students == NULL)
		return NULL;
	if (len == 1)
		return students;

	for (index = 0; index <len; ++index)
	{
		for (index1 = index + 1; index1 <len; ++index1)

		{
			if (students[index].score < students[index1].score)
			{
				temp = students[index];
				students[index] = students[index1];
				students[index1] = temp;
			}
		}
	}

	return students;
}