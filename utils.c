#include <stdio.h>
#include <stdlib.h>

int rangeRandom(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int * initArray(int size, int min, int maxValue)
{
    int * array = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        array[i] = rangeRandom(min, maxValue);
    }

    return array;
}

void displayArray(int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void swap(int * array, int i, int j)
{
    if (i != j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}