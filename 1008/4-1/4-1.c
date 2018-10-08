#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
	DIR *dp;
	FILE * wfp;
	struct dirent *dent;

	if(dp = opendir("sample")) == NULL){
		perror("open");
		exit(1);
	}

	if(wfp = fopen("sum.txt", "w")) == NULL){
		perror("write");
		exit(1);
	}

	while ((dent = readdir(dp))) {
		if("c" == dent->d_type){ // 여기부분 확인필요. 
			fprintf(wfp, "%s", dent->d_off);
		}
	}

	closedir(dp);

}
