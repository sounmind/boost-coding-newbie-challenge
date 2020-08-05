#include <stdio.h>

int time = 0;
const int TOTAL_PEOPLE = 7;
int here[TOTAL_PEOPLE] = {1, 2, 3, 4, 5, 6, 7};
int there[TOTAL_PEOPLE] = {0, 0, 0, 0, 0, 0, 0};

void print_here()
{
    printf("\n| ");
    for(int i=0; i<TOTAL_PEOPLE; i++)
    {
        printf(" %d ", here[i]);
    }
    printf(" |====");
}

void print_there()
{
    printf("====| ");
    for(int i=0; i<TOTAL_PEOPLE; i++)
    {
        printf(" %d ", there[i]);
    }
    printf(" |\n");
}

void bridge_cross(int person_fast, int person_slow)
{
    time += here[person_slow];

    printf(">>>> %d, %d >>>>", here[person_fast], here[person_slow]);
    there[person_fast] = here[person_fast]; here[person_fast] = 0;
    there[person_slow] = here[person_slow]; here[person_slow] = 0;
    
    print_here(); print_there();
}

void bridge_return(int person)
{
    time += there[person];

    for(int i=0; i<TOTAL_PEOPLE-1; i++){printf("\t");}

    printf("<<<<< %d <<<<<", there[person]);

    here[person] = there[person];
    there[person] = 0; 

    print_here(); print_there();
}

void cross(int number_of_people)
{
    if(number_of_people==1)
    {   
        bridge_return(0);   // 한 명일 때는 다리를 오고 감에 구분이 없음
    }
    if(number_of_people==2)
    {
        bridge_cross(0, 1);
    }
    if(number_of_people==3)
    {
        cross(2);          
        bridge_return(0);
        bridge_cross(0, 2); 
    }
    if(number_of_people>=4)
    {
        cross(2);
        bridge_return(0);
        bridge_cross(number_of_people-2, number_of_people-1);
        bridge_return(1);
        cross(number_of_people-2);
    }
}



int main(void)
{
    print_here(); print_there();
    cross(TOTAL_PEOPLE);
    printf("\ntotal time = %d\n", time);
    return 0;
}

