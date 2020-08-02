#include <stdio.h>
#include <stdlib.h>

void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);

int main(void)
{
    // �׽�Ʈ ���̽�
    // int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int array[8] = {5, 6, 7, 8, 1, 2, 3, 4};
     int array[8] = {2, 6, 7, 15, 1, 4, 5, 10};
    // int array[7] = {2, 4, 5, 11, 1, 3, 9};
    // int array[6] = {1, 11, 15, 4, 5, 10};
    // int array[5] = {15, 20, 29, 5, 10};

    int length_of_array = sizeof(array)/sizeof(int);

    printf("original array: ");
    for(int i=0; i<length_of_array; i++)
    {
        printf(" %3d ", array[i]);
    }
    printf("\n");

    merge_sort(array, 0, 7);

    printf("sorted array: ");
    for(int i=0; i<length_of_array; i++)
    {
        printf(" %3d ", array[i]);
    }
}

void merge_two_area(int array[], int left_end, int middle, int right_end)       // ���ĵ� �� �迭�� ����
{
    printf("\n-------------------------MERGE TWO AREA-------------------------\n");
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // ������ ���� �迭�� ù ���� ����
    int i;

    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // ���յ� �迭�� ���� �迭(���յȹ迭)
    int index_of_sorted_array = left_end;

    
    printf("-------------------------while starts-------------------------\n");    // 1�� ����
    while(left_side_index <= middle && right_side_index <= right_end)           // ���ʳ��� �����ʳ����� ���۵Ǵ� ���ΰ� �� ��� �ϳ��� �� ���� �迭�� ��� ������ ���յȹ迭�� ���ĵ� ���� �����Ѵ�.
    {
        if(array[left_side_index] <= array[right_side_index])                   // ���� �迭�� ù �� <= ���� �迭�� ù �� ex: {2, 8, 4, 7},  
        {
            sorted_array[index_of_sorted_array] = array[left_side_index++];     // ���յȹ迭�� ù��°�� ���� �迭 ù �� ������ ��, ���� �迭 ����+1
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
        else                                                                    // ���� �迭 ù �� > ���� �迭 ù �� ex: {5, 7, 2, 9}, {2, 6, 7, 1, 3, 5}
        {
            sorted_array[index_of_sorted_array] = array[right_side_index++];    // ���յȹ迭�� ù��°�� ���� �迭 ù �� ������ ��, ���� �迭 ����+1
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
        
        index_of_sorted_array++; 
    }                                                                           // �� while�� ���� ���� �迭 �� �� ���� ��� ���ĵǾ� ���յȹ迭�� ���� �ȴ�.                                                                        

                                                                                
    printf("-------------------------merge rest of it!-------------------------\n");               // 2�� ����: �����Ͱ� ���� �ִ� �� �� �迭�� '�״��' �ű��.
    if(left_side_index > middle)                                                // ���� �迭�� ��� �Ű����� ������ �迭�� ���Ҵٸ�,
    { 
        for(i = right_side_index; i <= right_end; i++, index_of_sorted_array++)
        {
            sorted_array[index_of_sorted_array] = array[i];
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
    }
    else                                                                        // ������ �迭�� ��� �Ű����� ���� �迭�� ���Ҵٸ�,
    {
        for(i = left_side_index; i <= middle; i++, index_of_sorted_array++)
        {
            sorted_array[index_of_sorted_array] = array[i];
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
    }
    
    
    for(i = left_end; i <= right_end; i++)                                      // ���յ� ������ ���� �迭�� ����
    {
        array[i] = sorted_array[i];
        printf("|%d", array[i]);
    }
    printf("|\n");
    printf("-------------------------SORT COMPLETED-------------------------\n");
    free(sorted_array);
}

void merge_sort(int array[], int left_end, int right_end)
{
    int middle;

    if(left_end < right_end) // left_end �� right_end�� ���� ���� �� ������ merge_sort�� ��������� ����ȴ�.
    {   
        middle = (left_end + right_end) / 2;
        
        // �迭�� ���ʰ� �������� �ٽ� ����
        merge_sort(array, left_end, middle);
        merge_sort(array, middle + 1, right_end);

        // �迭�� �����ϸ鼭 ����
        merge_two_area(array, left_end, middle, right_end);
    }
}