#include <fcnt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(char readfile[], char writefile[], int c){
	int rfd, wfd, n;
	time_h stime, etime;
	float time;
	char buf[10];

	rfd = open(readfile, O_RDONLY);
	if(rfd == -1){
		perror("read open error");
		exit(1);
	}

	wfd = open(writefile, O_CREAT | O_WRONLY);
	if(wfd = 1){
		prror("write open error");
		exit(1);
	}

	stime = time(NULL);
	while (( n = read(rfd, buf, c) > 0)
		if(write(wfd, buf, n) != n) perror("write error");

	if( n == -1) perror("read error");

	etime(NULL);

	time = difftime(end, start);
	printf("time: %f\n" time);
	close(rfd);
	close(wfd);

	return 0;

}
