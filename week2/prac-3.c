#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int dayToFood(char day[]); // �Լ� ��� ����

int main(void)
{
    char dayInput[7]; // ������ �Է¹��� ���� �迭 ���� (�ѱ� �ϳ� 2����Ʈ*3 + �� ���ܹ���)

    while(1)
    {
        printf("�� ~ �Ͽ��� �� �ϳ��� ������ �Է��ϼ���(��: ������): ");
        scanf("%s", dayInput);

        if(dayToFood(dayInput)==0) // ���Ͽ� ���� ���� ��°� ���ÿ� ���� �˻� (0�̸� ����� ���� ��)
        {   break;  }
    }

    return 0;
}





int dayToFood(char day[]) // ���Ͽ� ���� ���� ���
{
    char *food = NULL;

    if(!strcmp(day, "������"))
    {   food = "û����";        }
    else if(!strcmp(day, "ȭ����"))
    {   food = "�����";        }
    else if(!strcmp(day, "������"))
    {   food = "�����";      }
    else if(!strcmp(day, "�����"))
    {   food = "Į����";        }
    else if(!strcmp(day, "�ݿ���"))
    {   food = "�ø�";          }
    else if(!strcmp(day, "�����"))
    {   food = "�ҺҰ��";      }
    else if(!strcmp(day, "�Ͽ���"))
    {   food = "����Ұ��";    }
    else // �߸��� ������ �Է����� ���
    {
        printf("��, �ٽ� �Է��ϼ���...\n");
        return 1;
    }

    printf("%s : %s", day, food);

    return 0;
}