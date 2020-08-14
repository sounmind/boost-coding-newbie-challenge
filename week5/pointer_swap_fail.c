#include <stdio.h>

void swap_int_pointer(int *pointer1, int *pointer2)
{
    int * temp = pointer1;
    pointer1 = pointer2;
    pointer2 = temp;
}

int main(void)
{
    int num1 = 10, num2 = 20;
    int *pointer1, *pointer2;
    pointer1 = &num1; pointer2 = &num2;
    printf("*pointer1 = %d, *pointer2 = %d \n", *pointer1, *pointer2);

    swap_int_pointer(pointer1, pointer2);
    printf("*pointer1 = %d, *pointer2 = %d \n", *pointer1, *pointer2);
    return 0;
}