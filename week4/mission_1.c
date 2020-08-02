// 코딩뉴비챌린지 4주차 미션1 숫자 애너그램 찾기 (병합정렬 이용)

#include <stdio.h>
#include <stdlib.h>

void is_anagram(int array[], int array_compare[], int length_of_array);
void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);
int is_same_array(int array[], int array_compare[], int length_of_array);

int main(void)
{
    // 테스트 케이스 1 (FALSE)
    int array[5] = {1,2,3,7,5};
    int array_compare[5] = {2,1,4,5,3};

    // 테스트 케이스 2 (TRUE)
    // int array[5] = {1,2,3,4,5};
    // int array_compare[5] = {2,1,4,5,3};

    int length_of_array = sizeof(array)/sizeof(int);

    is_anagram(array, array_compare, length_of_array);

    return 0;
}

void merge_two_area(int array[], int left_end, int middle, int right_end)       // 정렬된 두 배열을 병합
{
    printf("\n-------------------------MERGE TWO AREA-------------------------\n");
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // 병합할 우측 배열의 첫 값의 색인
    int i;

    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // 병합된 배열을 넣을 배열(병합된배열)
    int index_of_sorted_array = left_end;

    
    printf("-------------------------while starts-------------------------\n"); // 1차 병합
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

                                                                                // 2차 병합: 데이터가 남아 있는 한 쪽 배열을 '그대로' 옮긴다.                                                                            
    printf("-------------------------merge rest of it!-------------------------\n");               
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

    if(left_end < right_end)                                                    // left_end 와 right_end가 같은 값이 될 때까지 merge_sort가 재귀적으로 실행된다.
    {   
        middle = (left_end + right_end) / 2;
        
        // 배열의 왼쪽과 오른쪽을 다시 분할
        merge_sort(array, left_end, middle);
        merge_sort(array, middle + 1, right_end);

        // 배열을 정렬하면서 병합
        merge_two_area(array, left_end, middle, right_end);
    }
}

int is_same_array(int array[], int array_compare[], int length_of_array)        // 요소 중 하나라도 틀리면 return 1; 모든 요소가 같으면 return 0;
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

void is_anagram(int array[], int array_compare[], int length_of_array)          // 애너그램이면 TRUE, 아니면 FALSE 출력
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