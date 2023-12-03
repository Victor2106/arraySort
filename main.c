#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"

//Quick sort
int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);
    return (i + 1);
}

void quickSort(int* array, int low, int high)
{
    if (low < high)
    {
        int index = partition(array, low, high);

        quickSort(array, low,index - 1);
        quickSort(array,index + 1, high);
    }
}

//Merge Sort (Good performance in time but not in space)
//This function was inspired by a site explaining the merge method
void merge(int* array, int low, int m, int high)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
    {
        left[i] = array[low + i];
    }

    for (j = 0; j < n2; j++)
    {
        right[j] = array[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, int low, int high)
{
    if (low < high)
    {
        int m = low + (high - low) / 2;

        mergeSort(array, low, m);
        mergeSort(array, m+1, high);

        merge(array, low, m, high);
    }
}

//Bubble sort (Easy to understand, but not ideal for large arrays)
void bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array, j, j + 1);
            }
        }
    }
}

//Insert Sort
void insertionSort(int* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));

    int size = 10;
    int min = 1;
    int maxValue = 100;

    int * array = initArray(size, min, maxValue);

    printf("Initial array :\n");
    displayArray(array, size);

    printf("Sorted array :\n");

    quickSort(array, 0, size - 1);
    //mergeSort(array, 0, size - 1);
    //bubbleSort(array, size);
    //insertionSort(array, size);

    displayArray(array, size);

    free(array);

    return 0;
}
