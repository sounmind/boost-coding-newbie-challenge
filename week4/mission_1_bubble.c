#include <stdio.h>

void bubble_sort(int array_of_number[], int size_of_array);
int is_same_array(int array[], int array_compare[], int length_of_array);  
void print_array(int array[], int length_of_array);


int main(void) {

    int array_of_number[5] = {1, 3, 2, 5, 4};       // ù��° �迭
    int array_to_be_compared[5] ={3, 2, 5, 4, 1};   // �ι�° �迭(���� �迭)
    
    int length_of_array = sizeof(array_of_number)/sizeof(int);    // �迭�� ����(�迭 ���� ����) ���ϱ�
    
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

void bubble_sort(int array_of_number[], int size_of_array)  // ��ǰ���� �Լ�
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

int is_same_array(int array[], int array_compare[], int length_of_array)    // ���� �迭���� Ȯ���ϴ� �Լ�       // ��� �� �ϳ��� Ʋ���� return 1; ��� ��Ұ� ������ return 0;
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