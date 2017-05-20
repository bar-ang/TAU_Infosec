
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 32

char victory = '\x77';

int main(int argc, char ** argv){
	char * p1; char * p2; char *p3;

	int count = strtol(argv[1],NULL,10);

	p1 = malloc(BUFLEN);
	p2 = malloc(BUFLEN);
	p3 = malloc(BUFLEN);

	memset(p1,victory,count);
	

	printf("%d bytes of data filled.\n[%s]\n[%s]\n[%s]\n",count, p1,p2,p3);

	free(p1);
	free(p2);
	free(p3);

	return 0;
}