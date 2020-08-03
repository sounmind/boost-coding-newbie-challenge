#include <stdio.h>

int time_count = 0; // �� �ɸ� �ð� ���� ���� ���� 

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

    // �ٸ� �ǳʱ� �� ����� ���ĵǾ� �ִٰ� ���� // �ٸ� �ǳ� ��� 0���� �ʱ�ȭ
    
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

    int left_people_count = LENGTH_OF_ARRAY;                                            // ������ ���� �ִ� �����, ���� �پ���
    cross(here, there, left_people_count, LENGTH_OF_ARRAY);                             // �ٸ��� �ǳʺ���!

    printf("�� �ɸ� �ð� %d", time_count);


    return 0;
}

void cross(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)   // ��Ͱ� ���� �Ǿ� �ִ� �ٸ� �ǳʴ� �Լ�
{
    print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
    if(left_people_count==0)
    {
        printf("�ƹ��� �����ٰ� �մϴ�.");
        return;
    }
    if(left_people_count==1)
    {
        print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
        there[0] = here[0];
        printf("%d , �ǳʴ�", here[0]);
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

void go_and_back(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)             // ���� ���� �ϴ� �Լ�
{
    cross_who_fast(here, there, left_people_count, LENGTH_OF_ARRAY);                                    // ���� ��� 2�� �ǳ�
    return_from_bridge(here, there, left_people_count, LENGTH_OF_ARRAY);                                // ���� ��� 1�� ���ƿ�
    cross_who_slow(here, there, left_people_count, LENGTH_OF_ARRAY);                                    // ���� ��� 2�� �ǳ�
    return_from_bridge(here, there, left_people_count, LENGTH_OF_ARRAY);                                // ���� ��� 1�� ���ƿ�
}

void cross_who_fast(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)          // ������ ���� ��� 2���� �ǳ�
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
            time_count += there[i]; // �׻� �ι�° ���� ũ�� ������ �ɸ� �ð��� ����
            printf(", �ǳʴ�\n");
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }
    }
}

void return_from_bridge(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)      // �������� ���� ��� 1���� ���ƿ�
{
    for(int i=0; i<LENGTH_OF_ARRAY; i++)
    {
        if(there[i]==0)
        {
            continue;
        }
        else
        {
            printf("%2d , ���ƿ���\n", there[i]);
            here[i] = there[i];
            time_count += there[i];
            there[i] = 0;
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }
    }
}

void cross_who_slow(int here[], int there[], int left_people_count, const int LENGTH_OF_ARRAY)          // ���� ��� �� ���� �ٸ��� �ǳ�
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
            printf(", �ǳʴ� \n");
            print_array(here, LENGTH_OF_ARRAY); print_array(there, LENGTH_OF_ARRAY); printf("\n\n");
            break;
        }   
    }
}

void print_array(int array[], int length_of_array)                                                      // �迭�� ���
{
    printf("| ");
    for(int i=0; i<length_of_array; i++)
    {
        printf("%d ", array[i]);
    }
    printf("end |");
}

void bubble_sort(int array_of_number[], int size_of_array)                                              // ������ ���� (���� ���X)
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