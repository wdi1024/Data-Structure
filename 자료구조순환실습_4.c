#include <stdio.h>
#include <stdlib.h>

int findMax(int n, int arr[]) {
   if (n==1)
      return arr[0];
   else
      return arr[n-1]> findMax(n-1, arr) ? arr[n-1] : findMax(n-1, arr);
}
 
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N] ;
    for (int i = 0; i<N; i++)
        scanf("%d", &arr[i]);
    printf("%d",findMax(N, arr)); //최댓값 출력
    return 0;
}