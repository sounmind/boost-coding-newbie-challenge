#include <stdio.h>

void bubble_sort(int array_of_number[], int size_of_array);

int main(void) {

    int array_of_number[10] = {23, 3, 56, 5, 1, 7, 13, 9, 6, 11};
    int size_of_array = sizeof(array_of_number)/sizeof(int);
    
    bubble_sort(array_of_number, size_of_array);
    
    for(int i=0; i<size_of_array; i++)
    {
        printf("%d ", array_of_number[i]);
    }

    return 0;
}

void bubble_sort(int array_of_number[], int size_of_array)
{
    int temp = 0;
    for(int i=0; i < size_of_array - 1; i++)
    {
        for(int j=0; j < size_of_array - i - 1; j++)
        {
            if(array_of_number[j] > array_of_number[j+1])
            {
                temp = array_of_number[j];
                array_of_number[j] = array_of_number[j+1];
                array_of_number[j+1] = temp;
            }
        }
    }
    printf("sort completed!\n");
    return;    
}