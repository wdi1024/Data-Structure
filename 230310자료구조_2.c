#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    while(n!=0)
    {
        printf("%d\n", n%10);
        n=n/10;
    }
    
    /*int score;
    scanf("%d", &score);

    if(score < 0 || score > 100)
    {
        printf("Wrong Input\n");
    }
    else
    {
        switch(score / 10)
        {
            case 10:
            case 9:
                printf("A\n");
                break;
            case 8:
                printf("B\n");
                break;
            case 7:
                printf("C\n");
                break;
            default:
                printf("D or F\n");
        }
        /*
        if(score >=90 && score <=100)
            printf("A\n");
        else if(score>=80 && score <90)
            printf("B\n");
        else if(score>=70 && score<80)
            printf("C\n");
        else
            printf("D or F\n");
        
       
    }
    */
    return 0;
}

