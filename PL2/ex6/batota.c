#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	srand(time(NULL));
	i = (rand()%5)+1;

	exit(i);
	return 0;
}
