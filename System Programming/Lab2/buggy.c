#include <stdio.h>
#include <stdlib.h>

struct Data {
	int x;
};
       
int main(int argc, char *argv[])
{
	struct Data *p = malloc(sizeof(struct Data));
	p->x = 22;
        printf("%d\n", p->x);
}
