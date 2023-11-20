#include <stdio.h>
#include <stdlib.h>

int main()
{
    int price, cnt, money;
    int total;

    scanf("%d %d %d", &price, &cnt, &money); 
    
    total = price * cnt;

    if(total>money)
    {
        printf("모자란 금액: %d\n", total-money);
    }
    else
    {
        printf("금액이 모자라지 않습니다. \n");
    }
    return 0;
}

/* 
ambersent(&)+변수 = 그 변수의 주소를 계산해라.
Python을 제외한 모든 언어는 문자와 문자열을 엄격하게 구분함 ex) 문자는 'a', 문자열은 "a"같은 방식. 
*/