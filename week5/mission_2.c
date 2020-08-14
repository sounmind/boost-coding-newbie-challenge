#include <stdio.h>
#include <memory.h>

void print(int n[], int v){
    if(v==1)
    {
        printf("arr[4] : ");
        for(int i=0; i<4; i++) printf("%d\t", n[i]); // arr ���
        printf("\n\n");
    }
    else
    {
        printf("src[7] : ");
        for(int i=0; i<7; i++) printf("%d\t", n[i]); // src ���
        printf("\n\n");
    }
}

void printX(int n[])
{
    printf("arr[4] : ");
    for(int i=0; i<4; i++) printf("%#x\t", n[i]); // 16������ 0x �ٿ��� ���
    printf("\n\n");
}

int main(void)
{
    int arr[4] = {0, 0, 0, 0};
    int src[7] = {1, 2, 3, 4, 5, 6, 7};
    float result;
    print(arr,1);
    print(src,2);
    
    ////////�޸� �ʱ�ȭ(memset)////////
    printf("AFTER memset(arr, 15, sizeof(int)*4)\n");
    memset(arr, 15, sizeof(int)*4);     //memset(void *dest, int c, size_t count)
    print(arr, 1);     //����� 10���� ������ �ʴ� ���� : memset�� 1����Ʈ ������ �ʱ�ȭ�ϱ� ������ 1����Ʈ�� 10���� ������ 4���� �迭�� �� �ε����� ���� ��. 
                       //���� : https://m.blog.naver.com/PostView.nhn?blogId=dd1587&logNo=221059593458&proxyReferer=https:%2F%2Fwww.google.com%2F
    printX(arr);
    
    /////////�޸� ����(memcpy)/////////
    printf("AFTER memcpy(arr, src, sizeof(int)*4)\n");
    memcpy(arr, src, sizeof(int)*4);    ///memcpy(void *dest, void *src, size_t count)
    print(arr, 1);
    
    /////////�޸� �̵�(memmove)/////////
    printf("AFTER memmove(arr, arr+1, sizeof(int)*3\n");
    memmove(arr, arr+1, sizeof(int)*3); //memmove(void *dest, const void *src, size_t n)
    print(arr, 1);

    /////////�޸� ��(memcmp)/////////
    printf("AFTER memcmp(arr, src, sizeof(arr)\n");
    
    int array_1[5] = {1, 0, 1, 3, 5};
    int array_2[5] = {1, 0, 1, 5, 7};
    result = memcmp(array_1, array_2, 3);
    // print(arr, 1);
    // print(src, 2);

    printf("result = %f\n", result);

    if(result == 0) 
        printf("Not same\n");
    else if(result == 1) 
        printf("former one is bigger than later one\n");
    else 
        printf("former one is smaller than later one.\n");
}