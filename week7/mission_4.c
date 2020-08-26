// sorting without repeated number
#include <stdio.h>
#include <stdlib.h>

void merge_two_area(int array[], int left_end, int middle, int right_end);
void merge_sort(int array[], int left_end, int right_end);
int remove_repeated_number(int array[], int length_of_array);

/* 시간복잡도

정렬 시 먼저 숫자들을 오름차로 정렬한 다음, 중복된 숫자들을 제거한다.
정렬에 사용한 병합정렬 함수의 시간복잡도는 N log N 이고
중복된 숫자를 제거하는 함수의 시간복잡도는 N 이다.
따라서 전체 시간복잡도는 N log N 이다.

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
    int i, k;   // i는 중복 있는 배열을 위한 색인, k는 중복 없는 배열을 위한 색인
    for(i=0, k=0; i<length_of_array-1; i++)
    {
        if(array[i] != array[i+1])      // 중복이 아닐 경우
            array[++k] = array[i+1];    // k번째에 새로운 값을 넣는다
    }
    return k;                           // 중복 없는 배열의 길이를 반환한다
}

void merge_two_area(int array[], int left_end, int middle, int right_end)       // 정렬된 두 배열을 병합
{
    int left_side_index = left_end;
    int right_side_index = middle+1;                                            // 병합할 우측 배열의 첫 값의 색인
    int i;
    int * sorted_array = (int*)malloc(sizeof(int)*(right_end+1));               // 병합된 배열을 넣을 배열(병합된배열)
    int index_of_sorted_array = left_end;
    while(left_side_index <= middle && right_side_index <= right_end)           // 왼쪽끝과 오른쪽끝부터 시작되는 색인값 중 어느 하나가 한 쪽의 배열을 벗어날 때까지 병합된배열에 정렬된 값을 대입한다.
    {
        if(array[left_side_index] <= array[right_side_index])                   // 좌측 배열의 첫 값 <= 우측 배열의 첫 값 ex: {2, 8, 4, 7},  
            sorted_array[index_of_sorted_array] = array[left_side_index++];     // 병합된배열의 첫번째에 좌측 배열 첫 값 대입한 뒤, 좌측 배열 색인+1
        else                                                                    // 좌측 배열 첫 값 > 우측 배열 첫 값 ex: {5, 7, 2, 9}, {2, 6, 7, 1, 3, 5}
            sorted_array[index_of_sorted_array] = array[right_side_index++];    // 병합된배열의 첫번째에 우측 배열 첫 값 대입한 뒤, 우측 배열 색인+1
        index_of_sorted_array++; 
    }                                                                           // 이 while을 통해 양쪽 배열 중 한 쪽은 모두 정렬되어 병합된배열에 들어가게 된다.                                                                        
    if(left_side_index > middle)                                                // 왼쪽 배열이 모두 옮겨지고 오른쪽 배열이 남았다면,
    {
        for(i = right_side_index; i <= right_end; i++, index_of_sorted_array++)
            sorted_array[index_of_sorted_array] = array[i];
    }
    else                                                                        // 오른쪽 배열이 모두 옮겨지고 왼쪽 배열이 남았다면,
    {
        for(i = left_side_index; i <= middle; i++, index_of_sorted_array++)
            sorted_array[index_of_sorted_array] = array[i];
    }
    for(i = left_end; i <= right_end; i++)                                      // 병합된 정렬을 원래 배열에 대입
        array[i] = sorted_array[i];
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

// 병합정렬 참조: 책 <열혈 C 프로그래밍>