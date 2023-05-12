#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/**
 *sum_array - Calculate the sum of elements in an array
 *@arr: The array of integers
 *@size: The size of the array
 *Return: The sum of the array elements
 */
int sum_array(int arr[], int size)
{
int sum = 0;
int i;

for (i = 0; i < size; i++)
sum += arr[i];

return (sum);
}

/**
 *main - Entry point of the program
 *Return: 0 on successful execution
 */
int main(void)
{
int array[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array_size = sizeof(array) / sizeof(array[0]);
int result;

result = sum_array(array, array_size);

printf("The sum of the array is: %d\n", result);

return (0);
}
