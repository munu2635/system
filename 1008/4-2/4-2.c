#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
 	DIR *dp1, *dp2, *dp3;
	struct dirent *dent1, *ubuntu = NULL, *dent2, *dent3;
	int  sum;
	char *cwd;

	sum = ('U'+'b'+'u'+'n'+'t'+'u')%12;
	if((dp1 = opendir("sample2")) == NULL){
		perror("opendir : sample2");
		exit(1);
	}

	while((dent1 = readdir(dp1))){
		printf("Read: %2s   Cur offset:%d \n", dent1->d_name, (int)dent1->d_off);
		if(sum == (int)dent1->d_off) ubuntu = dent1;
	}

	if(ubuntu != NULL){

		printf("Read %s\n",ubuntu->d_name);
		chdir("sample2");

		if((dp2 = opendir(ubuntu->d_name)) == NULL){
			perror("opendir");
				exit(1);
		}

		while((dent2 = readdir(dp2))){
			if((int)dent2->d_type == 4){
				//폴더 안이 비었는지여부만 확인 하면 된다 .

				if((int)buf.st_size == 0){
					if(rmdir(dent2->d_name) == -1){
						perror(dent2->d_name);
						exit(1);
					}
					printf("%s 폴더를 삭제 했습니다.", dent2->d_name);
				}else{
					cwd = getcwd(NULL, BUFSIZ);
					printf("%s/%s\n", cwd, dent2->d_name);
				}
			}
		}
	}

	closedir(dp1);
	closedir(dp2);
	return 0;
}
