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
	int  sum, i = 0;
	char *cwd;

	sum = ('U'+'b'+'u'+'n'+'t'+'u')%12;
	if((dp1 = opendir("sample2")) == NULL){	perror("opendir : sample2"); exit(1); }

	printf("\n");
	while((dent1 = readdir(dp1))){
		printf("Read: %2s   Cur offset:%d \n", dent1->d_name, (int)dent1->d_off);
		if(sum == (int)dent1->d_off) ubuntu = dent1;
	}

	printf("\n");
	if(ubuntu != NULL){
		printf("Read %s\n\n",ubuntu->d_name);
		chdir("sample2");

		if((dp2 = opendir(ubuntu->d_name)) == NULL){ perror("opendir 2"); exit(1); }
		while((dent2 = readdir(dp2))){
			if((int)dent2->d_type == 4){
				chdir(ubuntu->d_name);
				if((dp3 = opendir(dent2->d_name)) == NULL ){ perror("opendir 3"); exit(1); }
				while((dent3 = readdir(dp3))){ i++; }

				if(i < 3){
					if(rmdir(dent2->d_name) == -1){ perror(dent2->d_name); exit(1);	}
					printf("%s 폴더를 삭제 했습니다.\n", dent2->d_name);
				}else{
					cwd = getcwd(NULL, BUFSIZ);
					printf("%s/%s\n", cwd, dent2->d_name);
				}
				chdir("..");
				i=0;
			}
		}
	}

	closedir(dp1);
	closedir(dp2);
	closedir(dp3);
	return 0;
}
