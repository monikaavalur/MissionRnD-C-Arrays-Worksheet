/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	if (K <= 0)    //if k is negative or zero return null
		return NULL;
	struct student *Students=0 ; //declaring another struct
	struct student **temp = (struct student**)malloc(len*sizeof(struct student));
	struct student **temp1 = (struct student**)malloc((K)*sizeof(struct student));

	for (int i = 0; i<len; i++)
	{
		temp[i] = &students[i];
	}

	if (K > len )
		return temp;//if k is greater than len or equal to 1 return students
	int index = 0, index1 = 0;
	//arranging the stuct students in descending order
	for (index = 0; index < len; index++)
	{
		for (index1 = index + 1; index1 < len; index1++)
		{
			if (students[index].score < students[index1].score)
			{
				struct student  temp = students[index];
				students[index] = students[index1];
				students[index1] = temp;
			}
		}
	}
	if (K == 1)
		return temp;
	
	//if K is greatr than length then assigning the top k values to another sturcture and returning it
	if (K > 1 || K < len)
	{
		for (index = 0; index < K; index++)
		{
			students[index] = students[index];
		}
			
	}
			for (int i = 0; i<K; i++)
			{
				temp1[i] = &Students[i];
			}
	return temp;
	
}