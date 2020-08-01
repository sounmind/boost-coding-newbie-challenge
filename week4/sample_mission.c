#include <stdio.h>

int main(void) {  
  int number[5] = {1, 2, 7, 9, 1};
  int temp;
  for (int i=0; i < 5; i++)
  {
    for (int j=0; j < 5 - i - 1; j++ )
    {
      if (number[j] > number[j+1])
      {
        temp = number[j];
        number[j] = number[j+1];
        number[j+1] = temp;
      }
    }
  }

  for (int i=0; i < 5; i++)
  {
    printf("%d", number[i]);
  }
  return 0;
}