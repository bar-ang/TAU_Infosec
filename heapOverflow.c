
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 32

char victory = '\x77';

int main(int argc, char ** argv){
	char * p1; char * p2;

	int count = strtol(argv[1],NULL,10);

	p1 = malloc(BUFLEN);
	p2 = malloc(BUFLEN);

	for(char * c = p1; c < p2 + count; c++){
		if(c >= p1 + count && c < p2)
			continue;
		*c = victory;
	}
	
	int gap = (int)p2-(int)p1-BUFLEN;

	printf("%d bytes of data filled.\n# %s #%d\n",count, p2,gap);

	free(p1);

	return 0;
}