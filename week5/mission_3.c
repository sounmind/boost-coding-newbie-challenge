#include <stdio.h>

void print_array(int array_of_number[], int size_of_array);
void sort(int n, int arr[]);

int main() 
{ 
    int n = 7; 
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 }; 
    sort(n, arr);

    print_array(arr, n);

    return 0; 
}

void sort(int n, int arr[]) // bubble sort using pointer
{
    int temp = 0;
    for(int i=0; i < n - 1; i++)
    {
        for(int j=0; j < n - i - 1; j++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    printf("sort completed!\n");
    return;   
}

void print_array(int array_of_number[], int size_of_array)
{
    for(int i=0; i<size_of_array; i++)
    {
        printf("| %d ", array_of_number[i]);
    }
    printf("|\n");
}