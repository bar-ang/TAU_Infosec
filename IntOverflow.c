#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define STR_MAX 32
int main(int argc, char ** argv){
	int size;
	char str[STR_MAX];

	size = strlen(argv[1]);

	if(size > STR_MAX){
		printf("String is too long\n");
		return -1;
	}
	printf("\"%s\"\n%d bytes\nThanks!\n", argv[1], size);
	return 0;
}