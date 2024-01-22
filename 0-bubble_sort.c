#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - implements bubble sort
 * @array: the array
 * @size: size of the array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int counter = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1, size);
				counter++;
			}
		}
		if (counter < 1)
		{
			break;
		}
		counter = 0;
	}
}

/**
 * swap - swap two elements
 * @array: the array
 * @prev: index of first element
 * @next: index of second element
 * @size: size of the array
 * Return: nothing
 */

void swap(int *array, int prev, int next, int size)
{
	int temp;

	temp = array[prev];
	array[prev] = array[next];
	array[next] = temp;
	print_array(array, size);
}
