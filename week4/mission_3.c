#include <stdio.h>

int time_count = 0; // 총 걸린 시간 전역 변수 선언 

void cross(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY);
void go_and_back(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY);
void cross_who_fast(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY);
void return_from_bridge(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY);
void cross_who_slow(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY);
void bubble_sort(int array_of_number[], int size_of_array);
void print_array(int array[], int length_of_array);

int main(void)
{
    const int LENGTH_OF_ARRAY = 6;

    // 다리 건너기 전 사람들 정렬되어 있다고 가정 // 다리 건너 장소 0으로 초기화
    
    // int here[LENGTH_OF_ARRAY] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    // int there[LENGTH_OF_ARRAY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // int here[LENGTH_OF_ARRAY] = {1, 2, 3, 4, 5}; 
    // int there[LENGTH_OF_ARRAY] = {0, 0, 0, 0, 0};

    int here[LENGTH_OF_ARRAY] = {1, 2, 3, 4, 5, 6}; 
    int there[LENGTH_OF_ARRAY] = {0, 0, 0, 0, 0, 0};

    // int here[LENGTH_OF_ARRAY] = {1, 2, 3}; 
    // int there[LENGTH_OF_ARRAY] = {0, 0, 0};

    // int here[LENGTH_OF_ARRAY] = {1, 2}; 
    // int there[LENGTH_OF_ARRAY] = {0, 0};

    // int here[LENGTH_OF_ARRAY] = {1}; 
    // int there[LENGTH_OF_ARRAY] = {0};

    int left_people_count = LENGTH_OF_ARRAY;                                            // 좌측에 남아 있는 사람들, 점점 줄어든다
    cross(here, there, left_people_count, LENGTH_OF_ARRAY);                             // 다리를 건너보자!

    printf("총 걸린 시간 %d", time_count);


    return 0;
}

void cross(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)   // 재귀가 포함 되어 있는 다리 건너는 함수
{
    print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
    if(left_people_count==0)
    {
        printf("아무도 없었다고 합니다.");
        return;
    }
    if(left_people_count==1)
    {
        print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
        there[0] = here[0];
        printf("%d , 건너다", here[0]);
        here[0] = 0;
        print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
        return;
    }
    if(left_people_count==2)
    {
        cross_who_fast(here, there, left_people_count, LENGTH_OF_ARRAY);
        return;
    }
    if(left_people_count==3)
    {
        cross_who_fast(here, there, left_people_count, LENGTH_OF_ARRAY);
        return_from_bridge(here, there, left_people_count, LENGTH_OF_ARRAY);
        cross_who_slow(here, there, left_people_count, LENGTH_OF_ARRAY);
        return;
    }
    if(left_people_count>=4)
    {
        go_and_back(here, there, left_people_count, LENGTH_OF_ARRAY);
        cross(here, there, left_people_count-2, LENGTH_OF_ARRAY);
    }
}

void go_and_back(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)             // 오고 가고 하는 함수
{
    cross_who_fast(here, there, left_people_count, LENGTH_OF_ARRAY);                                    // 빠른 사람 2명 건넘
    return_from_bridge(here, there, left_people_count, LENGTH_OF_ARRAY);                                // 빠른 사람 1명 돌아옴
    cross_who_slow(here, there, left_people_count, LENGTH_OF_ARRAY);                                    // 느린 사람 2명 건넘
    return_from_bridge(here, there, left_people_count, LENGTH_OF_ARRAY);                                // 빠른 사람 1명 돌아옴
}

void cross_who_fast(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)          // 왼쪽의 빠른 사람 2명이 건넘
{
    int count = 0;

    for(int i=0; i<LENGTH_OF_ARRAY; i++)
    {
        if(here[i]==0)
        {
            continue;
        }
        else
        {
            printf("%2d ", here[i]);
            there[i] = here[i];
            here[i] = 0;
            count++;
        }

        if(count==2)
        {
            time_count += there[i]; // 항상 두번째 값이 크기 때문에 걸린 시간에 대입
            printf(", 건너다\n");
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }
    }
}

void return_from_bridge(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)      // 오른쪽의 빠른 사람 1명이 돌아옴
{
    for(int i=0; i<LENGTH_OF_ARRAY; i++)
    {
        if(there[i]==0)
        {
            continue;
        }
        else
        {
            printf("%2d , 돌아오다\n", there[i]);
            here[i] = there[i];
            time_count += there[i];
            there[i] = 0;
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }
    }
}

void cross_who_slow(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)          // 느린 사람 두 명이 다리를 건넘
{
    int count, max_time = 0;

    for(int i=LENGTH_OF_ARRAY-1; i>=0; i--)
    {
        if(here[i]==0)
        {
            continue;
        }
        else
        {
            if(max_time < here[i])
            {
                max_time = here[i];
            }
            printf("%2d ", here[i]);
            there[i] = here[i];
            here[i] = 0;
            count++;
        }

        if(count==2)
        {
            time_count += max_time;
            printf(", 건너다 \n");
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }   
    }
}

void print_array(int array[], int length_of_array)                                                      // 배열을 출력
{
    printf("| ");
    for(int i=0; i<length_of_array; i++)
    {
        printf("%d ", array[i]);
    }
    printf("end |");
}

void bubble_sort(int array_of_number[], int size_of_array)                                              // 간단한 정렬 (현재 사용X)
{
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
            }
        }
    }
    printf("sort completed!\n");
    return;    
}