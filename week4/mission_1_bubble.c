#include <stdio.h>

void bubble_sort(int array_of_number[], int size_of_array);
int is_same_array(int array[], int array_compare[], int length_of_array);  
void print_array(int array[], int length_of_array);


int main(void) {

    int array_of_number[5] = {1, 3, 2, 5, 4};       // 첫번째 배열
    int array_to_be_compared[5] ={3, 2, 5, 4, 1};   // 두번째 배열(비교할 배열)
    
    int length_of_array = sizeof(array_of_number)/sizeof(int);    // 배열의 길이(배열 원소 개수) 구하기
    
    bubble_sort(array_of_number, length_of_array);
    bubble_sort(array_to_be_compared, length_of_array);
    
    int result = is_same_array(array_of_number, array_to_be_compared, length_of_array);
    if(result == 0)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    
    return 0;
}

void bubble_sort(int array_of_number[], int size_of_array)  // 거품정렬 함수
{
    printf("---------sort start!---------\n");
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
                printf("exchanged ");
            }
            else
            {
                printf("no change ");
            }
            print_array(array_of_number, size_of_array);
        }

    }
    printf("---------sort completed!---------\n");
    return;    
}

int is_same_array(int array[], int array_compare[], int length_of_array)    // 같은 배열인지 확인하는 함수       // 요소 중 하나라도 틀리면 return 1; 모든 요소가 같으면 return 0;
{
    for(int i = 0; i < length_of_array; i++)
    {
        if(array[i] != array_compare[i])
        {
            return 1;
        }
    }
    return 0;
}

void print_array(int array[], int length_of_array)
{
    for(int i = 0; i < length_of_array; i++)
    {
        printf("|");
        printf(" %d ", array[i]);
    }
    printf("|\n");
    return;
}