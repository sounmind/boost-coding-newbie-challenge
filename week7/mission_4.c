// sorting without repeated number
#include <stdio.h>
#include <stdlib.h>

void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);
int remove_repeated_number(int array[], int length_of_array);

/* �ð����⵵

���� �� ���� ���ڵ��� �������� ������ ����, �ߺ��� ���ڵ��� �����Ѵ�.
���Ŀ� ����� �������� �Լ��� �ð����⵵�� N log N �̰�
�ߺ��� ���ڸ� �����ϴ� �Լ��� �ð����⵵�� N �̴�.
���� ��ü �ð����⵵�� N log N �̴�.

*/

int main(void)
{
    int numbers[] = {2, 6, 7, 3, 1, 4, 5, 7, 2, 1, 3, 1, 5, 10, 23, 10, 29, 11, 15};
    int N = sizeof(numbers) / sizeof(numbers[0]);

    printf("original array:\t\t");
    for(int i=0; i<N; i++)
        printf("%2d ", numbers[i]);
    
    printf("\nsorted array:\t\t");
    merge_sort(numbers, 0, N-1);
    for(int i=0; i<N; i++)
        printf("%2d ", numbers[i]);
    
    printf("\nremove repeated number:\t");
    int new_array_length = remove_repeated_number(numbers, N);
    for(int i = 0; i <= new_array_length; i++)
        printf("%2d ", numbers[i]);
}


int remove_repeated_number(int array[], int length_of_array)
{
    int i, k;   // i�� �ߺ� �ִ� �迭�� ���� ����, k�� �ߺ� ���� �迭�� ���� ����
    for(i=0, k=0; i<length_of_array-1; i++)
    {
        if(array[i] != array[i+1])      // �ߺ��� �ƴ� ���
            array[++k] = array[i+1];    // k��°�� ���ο� ���� �ִ´�
    }
    return k;                           // �ߺ� ���� �迭�� ���̸� ��ȯ�Ѵ�
}

void merge_two_area(int array[], int left_end, int middle, int right_end)       // ���ĵ� �� �迭�� ����
{
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // ������ ���� �迭�� ù ���� ����
    int i;
    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // ���յ� �迭�� ���� �迭(���յȹ迭)
    int index_of_sorted_array = left_end;
    while(left_side_index <= middle && right_side_index <= right_end)           // ���ʳ��� �����ʳ����� ���۵Ǵ� ���ΰ� �� ��� �ϳ��� �� ���� �迭�� ��� ������ ���յȹ迭�� ���ĵ� ���� �����Ѵ�.
    {
        if(array[left_side_index] <= array[right_side_index])                   // ���� �迭�� ù �� <= ���� �迭�� ù �� ex: {2, 8, 4, 7},  
            sorted_array[index_of_sorted_array] = array[left_side_index++];     // ���յȹ迭�� ù��°�� ���� �迭 ù �� ������ ��, ���� �迭 ����+1
        else                                                                    // ���� �迭 ù �� > ���� �迭 ù �� ex: {5, 7, 2, 9}, {2, 6, 7, 1, 3, 5}
            sorted_array[index_of_sorted_array] = array[right_side_index++];    // ���յȹ迭�� ù��°�� ���� �迭 ù �� ������ ��, ���� �迭 ����+1
        index_of_sorted_array++; 
    }                                                                           // �� while�� ���� ���� �迭 �� �� ���� ��� ���ĵǾ� ���յȹ迭�� ���� �ȴ�.                                                                        
    if(left_side_index > middle)                                                // ���� �迭�� ��� �Ű����� ������ �迭�� ���Ҵٸ�,
    {
        for(i = right_side_index; i <= right_end; i++, index_of_sorted_array++)
            sorted_array[index_of_sorted_array] = array[i];
    }
    else                                                                        // ������ �迭�� ��� �Ű����� ���� �迭�� ���Ҵٸ�,
    {
        for(i = left_side_index; i <= middle; i++, index_of_sorted_array++)
            sorted_array[index_of_sorted_array] = array[i];
    }
    for(i = left_end; i <= right_end; i++)                                      // ���յ� ������ ���� �迭�� ����
        array[i] = sorted_array[i];
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

// �������� ����: å <���� C ���α׷���>