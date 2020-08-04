#include <stdio.h> // 문제 설명은 아래에

int time = 0;
const int TOTAL_PEOPLE = 3;
int here[TOTAL_PEOPLE+1] = {0, 1, 2, 3};    // 코드 가독성을 위해 배열 크기 선언 및 초기화 시, 크기를 1 추가하고 그 자리에 0을 초기화.

void bridge_cross(int person_fast, int person_slow)
{
    time += here[person_slow];
    printf("%d, %d\n", here[person_fast], here[person_slow]);
}

void bridge_return(int person)
{
    time += here[person];
    printf("%d\n", here[person]);
}

void cross(int number_of_people)
{
    if(number_of_people==1)
    {   
        bridge_return(2);   // 한 명일 때는 다리를 오고 감에 구분이 없음
    }
    if(number_of_people==2)
    {
        bridge_cross(1, 2);
    }
    if(number_of_people==3)
    {
        cross(2);          
        bridge_return(1);
        bridge_cross(1, 3); 
    }
    if(number_of_people>=4)
    {
        cross(2);
        bridge_return(1);
        bridge_cross(number_of_people-1, number_of_people);
        bridge_return(2);
        cross(number_of_people-2);
    }
}

int main(void)
{
    cross(TOTAL_PEOPLE);
    printf("%d\n", time);
    return 0;
}

/*

1. 미션 제목
최단 시간에 다리건너기

2. 지시문
N명의 사람들로 구성된 한 그룹이 밤중에 다리를 건너려고 합니다. 한 번에 최대 두 명 까지만 다리를 건널 수 있으며 다리 위를 지나가는 사람들은 반드시 손전등을 가지고 가야 합니다. n명의 사람들한테는 손전등이 한 개밖에 없기 때문에 남아 있는 사람들이 다리를 건너려면 어떤 식으로든 손전등을 가지고 다시 다리를 건너지 않은 사람들이 있는 곳으로 돌아가는 일을 해야합니다. 사람마다 다리를 건너는 속도가 다른데, 그룹의 속도는 가장 느린 구성원의 속도에 따라 결정됩니다. 가장 짧은 시간 안에 n명이 모두 다리를 건널 수 있는 방법과 그 시간을 출력하는 프로그램을 작성해봅시다.
입력으로 첫 줄에는 n이 입력되며 그 다음 줄부터 n개의 줄에 걸쳐서 각 사람들이 다리를 건너는 시간이 입력됩니다. 입력은 100명을 넘기지 않습니다.
출력은 맨 첫 줄에는 n명의 사람들이 모두 다리를 건너는데 걸리는 총 시간을 출력하고, 그 다음줄부터는 그 과정을 출력하면 됩니다. 이 때 각 줄에는 정수가 하나 또는 두 개가 들어가는데, 이 정수는 어떤 사람들이 다리를 건너가는지를 나타냅니다. 각 사람은 그 사람이 건너가는데 걸리는 시간으로 표시하며, 건너가고 오는 순서대로 출력해야 합니다. 최소 시간을 달성하는 방법이 여러가지가 있을 경우 그 중 아무 방법이나 출력해도 괜찮습니다. 완전한 프로그램을 작성하기 어려운 경우에는 pseudo code를 작성해도 좋습니다. 다만 이 경우에는 최대한 자세히 적어야 합니다. 숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에서 따로 선언하는 것으로 가정합니다.

예)
입력값:
4
1
2
5
10


출력값:
17
1 2
1
5 10
2
1 2

*/