#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(){
	DIR *dp;
	FILE * wfp, *rfp;
	struct dirent *dent;
	char name_data, *file_data;
	int i = 0, c;

	if((dp = opendir("./sample")) == NULL){
		perror("open");
		exit(1);
	}

	chdir("sample");
	if((wfp = fopen("sum.txt", "w")) == NULL){
		perror("write");
		exit(1);
	}

	while (dent = readdir(dp)) {
		name_data = dent->d_name[i++];
		while('.' != name_data)	name_data = dent->d_name[i++]; // .이 나올때 까지 반복
		if('c'== dent->d_name[i]) {

			if((rfp = fopen(("%s", dent->d_name), "r")) == NULL){
				perror(dent->d_name);
				exit(1);
			}
				

			while((c = fgetc(rfp)) != EOF){
				fputc(c, wfp);
			}
		} i = 0;
	}

	closedir(dp);
	fclose(wfp);
	fclose(rfp);

}
