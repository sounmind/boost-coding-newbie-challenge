// �ڵ�����ç���� 4���� �̼�1 ���� �ֳʱ׷� ã�� (�������� �̿�)

#include <stdio.h>
#include <stdlib.h>

void is_anagram(int array[], int array_compare[], int length_of_array);
void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);
int is_same_array(int array[], int array_compare[], int length_of_array);

int main(void)
{
    // �׽�Ʈ ���̽� 1 (FALSE)
    int array[5] = {1,2,3,7,5};
    int array_compare[5] = {2,1,4,5,3};

    // �׽�Ʈ ���̽� 2 (TRUE)
    // int array[5] = {1,2,3,4,5};
    // int array_compare[5] = {2,1,4,5,3};

    int length_of_array = sizeof(array)/sizeof(int);

    is_anagram(array, array_compare, length_of_array);

    return 0;
}

void merge_two_area(int array[], int left_end, int middle, int right_end)       // ���ĵ� �� �迭�� ����
{
    printf("\n-------------------------MERGE TWO AREA-------------------------\n");
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // ������ ���� �迭�� ù ���� ����
    int i;

    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // ���յ� �迭�� ���� �迭(���յȹ迭)
    int index_of_sorted_array = left_end;

    
    printf("-------------------------while starts-------------------------\n"); // 1�� ����
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

                                                                                // 2�� ����: �����Ͱ� ���� �ִ� �� �� �迭�� '�״��' �ű��.                                                                            
    printf("-------------------------merge rest of it!-------------------------\n");               
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

    if(left_end < right_end)                                                    // left_end �� right_end�� ���� ���� �� ������ merge_sort�� ��������� ����ȴ�.
    {   
        middle = (left_end + right_end) / 2;
        
        // �迭�� ���ʰ� �������� �ٽ� ����
        merge_sort(array, left_end, middle);
        merge_sort(array, middle + 1, right_end);

        // �迭�� �����ϸ鼭 ����
        merge_two_area(array, left_end, middle, right_end);
    }
}

int is_same_array(int array[], int array_compare[], int length_of_array)        // ��� �� �ϳ��� Ʋ���� return 1; ��� ��Ұ� ������ return 0;
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

void is_anagram(int array[], int array_compare[], int length_of_array)          // �ֳʱ׷��̸� TRUE, �ƴϸ� FALSE ���
{
    merge_sort(array, 0, length_of_array-1);
    merge_sort(array_compare, 0, length_of_array-1);

    if(is_same_array(array, array_compare, length_of_array)==0)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE"); 
    }
}