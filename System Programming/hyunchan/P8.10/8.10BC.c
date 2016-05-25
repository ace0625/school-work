#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf ebuf;
void f2(void);

int main()
{
   int i;
   
    printf("<<B&C. longjmp & setjmp >>\n");
    printf("1 ");
    i = setjmp(ebuf);
    if(i == 0) {
      f2();
      printf("This will not be printed.");
    }
    printf("%d\n", i);


    return 0;
}

void f2(void)
{
   printf("2 ");
   longjmp(ebuf, 3);
}
