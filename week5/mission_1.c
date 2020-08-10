#include <stdio.h>

int main(void)
{
    int arr[6][5] = {   
                        {1, 2, 3, 4, 5}, 
                        {6, 7, 8, 9, 10}, 
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20}, 
                        {21, 22, 23, 24, 25}, 
                        {26, 27, 28, 29, 30}
                    };

    int lengthOfArrColumn = sizeof(arr[0])/sizeof(int);
    int lengthOfArrRow =  sizeof(arr)/sizeof(int)/lengthOfArrColumn;

    printf("column length: %d\n", lengthOfArrColumn);
    printf("row length: %d\n", lengthOfArrRow);
    
    /*
    print array arr backward(in reverse order)
    26    27    28    29    30
    21    22    23    24    25
    ¡¦
    6    7    8    9    10
    1    2    3    4     5
    */

    for(int i=lengthOfArrRow-1; i>=0; i--)
    {
        for(int j=0; j<lengthOfArrColumn; j++)
        {
            // printf("%2d ",  arr[i][j]                  );
            // printf("%2d ",  ( * (arr+i) )[j]           );
            printf("%2d ",  * ( ( * (arr+i) ) + j )    );
        }
        printf("\n");
    }

    return 0;
}