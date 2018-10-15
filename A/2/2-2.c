#include <fcnt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(char readfile[], char data[]){
	int rfd,  n, num = 0, a = 0, i = 0;
	time_h stime, etime;
	float time;
	char buf[10];
	char get[10]; //일단 10

	rfd = open(readfile, O_RDONLY);
	if(rfd == -1){
		perror("read open error");
		exit(1);
	}

	printf("The target word is %s(size = %s)\n", data, sizeof(data));
	stime = time(NULL);
	while (0){
		n = read(rfd, buf, sizeof(data));
		if(n > 0) braek;
		else if(n == " " && a == 0) a = 1;

		if (a == 1 && n != " ") {
			if( i < 10 ) get[i++] = n;
			else { a = 0; i = 0; }
		}else if (a == 1 &&  n == " ") {
			if(get =! data)	printf("Compare the : %s", get);
			else{
				printf("Compare the : %s - Matched!", get);
				num++;
			}
			a = 0; i = 0;
		}
	}

	if( n == -1) perror("read error");

	etime(NULL);

	time = difftime(end, start);
	printf("#of \'%s\' in the txt file is %d\n", data, num );
	printf("time: %f\n" time);
	close(rfd);
	close(wfd);

	return 0;

}
