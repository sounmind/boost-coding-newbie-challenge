#include <stdio.h>
#include <stdlib.h>

void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);

int main(void)
{
    // 테스트 케이스
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

void merge_two_area(int array[], int left_end, int middle, int right_end)       // 정렬된 두 배열을 병합
{
    printf("\n-------------------------MERGE TWO AREA-------------------------\n");
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // 병합할 우측 배열의 첫 값의 색인
    int i;

    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // 병합된 배열을 넣을 배열(병합된배열)
    int index_of_sorted_array = left_end;

    
    printf("-------------------------while starts-------------------------\n");    // 1차 병합
    while(left_side_index <= middle && right_side_index <= right_end)           // 왼쪽끝과 오른쪽끝부터 시작되는 색인값 중 어느 하나가 한 쪽의 배열을 벗어날 때까지 병합된배열에 정렬된 값을 대입한다.
    {
        if(array[left_side_index] <= array[right_side_index])                   // 좌측 배열의 첫 값 <= 우측 배열의 첫 값 ex: {2, 8, 4, 7},  
        {
            sorted_array[index_of_sorted_array] = array[left_side_index++];     // 병합된배열의 첫번째에 좌측 배열 첫 값 대입한 뒤, 좌측 배열 색인+1
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
        else                                                                    // 좌측 배열 첫 값 > 우측 배열 첫 값 ex: {5, 7, 2, 9}, {2, 6, 7, 1, 3, 5}
        {
            sorted_array[index_of_sorted_array] = array[right_side_index++];    // 병합된배열의 첫번째에 우측 배열 첫 값 대입한 뒤, 우측 배열 색인+1
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
        
        index_of_sorted_array++; 
    }                                                                           // 이 while을 통해 양쪽 배열 중 한 쪽은 모두 정렬되어 병합된배열에 들어가게 된다.                                                                        

                                                                                
    printf("-------------------------merge rest of it!-------------------------\n");               // 2차 병합: 데이터가 남아 있는 한 쪽 배열을 '그대로' 옮긴다.
    if(left_side_index > middle)                                                // 왼쪽 배열이 모두 옮겨지고 오른쪽 배열이 남았다면,
    { 
        for(i = right_side_index; i <= right_end; i++, index_of_sorted_array++)
        {
            sorted_array[index_of_sorted_array] = array[i];
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
    }
    else                                                                        // 오른쪽 배열이 모두 옮겨지고 왼쪽 배열이 남았다면,
    {
        for(i = left_side_index; i <= middle; i++, index_of_sorted_array++)
        {
            sorted_array[index_of_sorted_array] = array[i];
            printf("%d inserted\n", sorted_array[index_of_sorted_array]);
        }
    }
    
    
    for(i = left_end; i <= right_end; i++)                                      // 병합된 정렬을 원래 배열에 대입
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

    if(left_end < right_end) // left_end 와 right_end가 같은 값이 될 때까지 merge_sort가 재귀적으로 실행된다.
    {   
        middle = (left_end + right_end) / 2;
        
        // 배열의 왼쪽과 오른쪽을 다시 분할
        merge_sort(array, left_end, middle);
        merge_sort(array, middle + 1, right_end);

        // 배열을 정렬하면서 병합
        merge_two_area(array, left_end, middle, right_end);
    }
}