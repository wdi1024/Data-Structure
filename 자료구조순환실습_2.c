#include <stdio.h>
#include <stdlib.h>


void pr(int x) {
   
   if (x > 10) {
      pr(x / 10);
   }
   printf("%d\n", x % 10);
}


int main() {
   int n;
   scanf("%d", &n);
   pr(n);
   return 0;
}