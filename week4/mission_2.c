// �ڵ�����ç���� 4���� �˰��� �̼�2��: ģ����� �ִܰŸ��� �ִ� �� ���ϱ�

#include <stdio.h>
#include <stdlib.h>

float mean_of_location(int locations[], int length_of_array);
int sum_of_distance(int locations[], int length_of_array, int one_location);
int is_integer(float number);

int main(void)
{
    // �Է�->���: 12345 -> 3, 2224 -> 2
    // ģ���� ���ڴ� �Ź� �ٸ���, �� ��ġ�� �ߺ��� ���� �� ����
    
    // �׽�Ʈ ���̽�
    // int location_friend[5] = {1, 3, 5, 7, 9};
    // int location_friend[9] = {1, 3, 5, 7, 9, 123, 122, 12, 2};
    // int location_friend[7] = {2, 3, 1, 4, 6, 7, 9};                                  // ������ �Ÿ� ����� �Ҽ��� ���Ϸ� ������ ���
    int location_friend[6] = {5, 2, 3, 6, 4, 1};                                        // ����� '3.5'�� 3�� 4 ��� �Ÿ� ���� ���� ���

    int length_of_array = sizeof(location_friend)/sizeof(int);

    if(is_integer(mean_of_location(location_friend, length_of_array))==0)               // ģ���� ��ġ �� ����� �����̸� �ٷ� �� �� ���
    {
        printf("%d", mean_of_location(location_friend, length_of_array));
    }
    else                                                                                // ����� ������ �ƴϸ�,
    {
        int location_1 = (int)mean_of_location(location_friend, length_of_array);       // ��� �� ���� ���� ������ ��ġ ����
        int location_2 = (int)(mean_of_location(location_friend, length_of_array)+1);
        int sum_1 = sum_of_distance(location_friend, length_of_array, location_1);      // ��ġ �� ģ�� �� �� �Ÿ� �� ���ϱ�
        int sum_2 = sum_of_distance(location_friend, length_of_array, location_2);
        
        if(sum_1 == sum_2)                                                              // �� �̻� ��ġ�� ���� ���� �Ÿ��� ��� ���ٸ�, �� �� ���
        {
            printf("Optimal location = %d and %d\n", location_1, location_2);
        }
        else
        {
            printf("Optimal location = %d\n", sum_1 < sum_2 ? location_1 : location_2); // �Ÿ� ���� ���� ��ġ ��� 
        }
    }
}

int sum_of_distance(int locations[], int length_of_array, int one_location)             // Ư�� ��ġ�� ���� ģ�� �� ���� �Ÿ� ���� ����
{
    int sum = 0;

    for(int i=0; i<length_of_array; i++)
    {
        sum += abs(locations[i]-one_location);                                          // ģ�� ��ġ�� ���� �� ��ġ ������ ������ ��� ���Ѵ�.
    }
    return sum;
}

float mean_of_location(int locations[], int length_of_array)                            // �迭�� �ִ� ��ġ ������ ����� ���� (float��)
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
