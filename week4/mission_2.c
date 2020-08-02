// 코딩뉴비챌린지 4주차 알고리즘 미션2번: 친구들과 최단거리에 있는 집 구하기

#include <stdio.h>
#include <stdlib.h>

float mean_of_location(int locations[], int length_of_array);
int sum_of_distance(int locations[], int length_of_array, int one_location);
int is_integer(float number);

int main(void)
{
    // 입력->출력: 12345 -> 3, 2224 -> 2
    // 친구의 숫자는 매번 다르고, 집 위치는 중복이 있을 수 있음
    
    // 테스트 케이스
    // int location_friend[5] = {1, 3, 5, 7, 9};
    // int location_friend[9] = {1, 3, 5, 7, 9, 123, 122, 12, 2};
    // int location_friend[7] = {2, 3, 1, 4, 6, 7, 9};                                  // 무조건 거리 평균이 소수점 이하로 나오는 경우
    int location_friend[6] = {5, 2, 3, 6, 4, 1};                                        // 평균이 '3.5'라서 3과 4 모두 거리 합이 같은 경우

    int length_of_array = sizeof(location_friend)/sizeof(int);

    if(is_integer(mean_of_location(location_friend, length_of_array))==0)               // 친구들 위치 간 평균이 정수이면 바로 그 값 출력
    {
        printf("%d", mean_of_location(location_friend, length_of_array));
    }
    else                                                                                // 평균이 정수가 아니면,
    {
        int location_1 = (int)mean_of_location(location_friend, length_of_array);       // 평균 양 쪽의 정수 값으로 위치 선정
        int location_2 = (int)(mean_of_location(location_friend, length_of_array)+1);
        int sum_1 = sum_of_distance(location_friend, length_of_array, location_1);      // 위치 별 친구 집 간 거리 합 구하기
        int sum_2 = sum_of_distance(location_friend, length_of_array, location_2);
        
        if(sum_1 == sum_2)                                                              // 두 이사 위치에 대한 예상 거리가 모두 같다면, 둘 다 출력
        {
            printf("Optimal location = %d and %d\n", location_1, location_2);
        }
        else
        {
            printf("Optimal location = %d\n", sum_1 < sum_2 ? location_1 : location_2); // 거리 합이 작은 위치 출력 
        }
    }
}

int sum_of_distance(int locations[], int length_of_array, int one_location)             // 특정 위치에 대한 친구 집 간의 거리 합을 구함
{
    int sum = 0;

    for(int i=0; i<length_of_array; i++)
    {
        sum += abs(locations[i]-one_location);                                          // 친구 위치와 본인 집 위치 차이의 절댓값을 모두 더한다.
    }
    return sum;
}

float mean_of_location(int locations[], int length_of_array)                            // 배열에 있는 위치 값들의 평균을 구함 (float형)
{
    float sum_of_location = 0;
    for(int i = 0; i < length_of_array; i++)
    {
        sum_of_location += locations[i];
    }
    return sum_of_location / length_of_array;
}

int is_integer(float number)                                                            
{
    if(number - (int)number == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
