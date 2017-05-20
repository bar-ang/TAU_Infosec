#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SP_CHAR "\\b"
#define MEAN "Bar is the best"

#define BUFSIZE 1024

int main(int argc, char ** argv){
	int code = open(argv[1],O_RDONLY);
	int c_code = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);



	char buf[BUFSIZE];

	char * wbuf = (char *)malloc(BUFSIZE);

	char * wbufp = wbuf;
	char * bufp = buf;
	char * spp;
	

	int size = BUFSIZE;

	int r = read(code, buf, BUFSIZE);
	
	while(r != 0){
		strcpy(wbufp,bufp);
		spp = strstr(bufp,SP_CHAR);
		
		while(spp != NULL){
			wbufp += spp - bufp;
			strcpy(wbufp,MEAN);
			wbufp += strlen(MEAN) + strlen(SP_CHAR) - 1;
			bufp = spp+2;

			strcpy(wbufp,bufp);
			spp = strstr(bufp,SP_CHAR);
		}


		printf("%s", wbuf);
		write(c_code, wbuf ,strlen(wbuf));
		r = read(code, buf, BUFSIZE);
	}

	close(code);
	close(c_code);


	return 0;
}