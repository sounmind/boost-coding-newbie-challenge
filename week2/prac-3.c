#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int dayToFood(char day[]); // 함수 헤더 선언

int main(void)
{
    char dayInput[7]; // 요일을 입력받을 문자 배열 선언 (한글 하나 2바이트*3 + 널 종단문자)

    while(1)
    {
        printf("월 ~ 일요일 중 하나의 요일을 입력하세요(예: 수요일): ");
        scanf("%s", dayInput);

        if(dayToFood(dayInput)==0) // 요일에 대한 음식 출력과 동시에 조건 검사 (0이면 제대로 나온 것)
        {   break;  }
    }

    return 0;
}





int dayToFood(char day[]) // 요일에 대한 음식 출력
{
    char *food = NULL;

    if(!strcmp(day, "월요일"))
    {   food = "청국장";        }
    else if(!strcmp(day, "화요일"))
    {   food = "비빔밥";        }
    else if(!strcmp(day, "수요일"))
    {   food = "된장찌개";      }
    else if(!strcmp(day, "목요일"))
    {   food = "칼국수";        }
    else if(!strcmp(day, "금요일"))
    {   food = "냉면";          }
    else if(!strcmp(day, "토요일"))
    {   food = "소불고기";      }
    else if(!strcmp(day, "일요일"))
    {   food = "오삼불고기";    }
    else // 잘못된 요일을 입력했을 경우
    {
        printf("앗, 다시 입력하세요...\n");
        return 1;
    }

    printf("%s : %s", day, food);

    return 0;
}