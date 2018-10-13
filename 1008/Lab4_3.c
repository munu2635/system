#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


int main(int argc, char *argv[]){
	DIR *dp;
	int i = -2;
	char *loc, loc_name[BUFSIZ], mvloc[BUFSIZ], mvloc_name[BUFSIZ], *name;
	char input_loc[BUFSIZ], *ptr;
	struct dirent *dent;

	strcpy(input_loc, argv[1]);
	ptr = strtok(input_loc, "/");

	while(ptr != NULL){
		name = ptr;
		ptr = strtok(NULL, "/");
	}

//	printf("name : %s\n", name);
	strcpy(input_loc, argv[1]);
	loc = strtok(input_loc, name);

//	printf("argv[1] : %s\n", argv[1]);
//	printf("loc : %s\n", loc);
	strcpy(mvloc, loc);
	strcat(mvloc, argv[3]);
	strcat(mvloc, "/");

	if((dp = opendir(loc)) == NULL){ perror("opendir loc"); exit(1); }
	if(mkdir(mvloc, 0755) == -1){ perror("mkdir mvloc"); exit(1); }

	while((dent = readdir(dp))) {
		if(((strstr(dent->d_name, name)) != NULL) && (i > -1)) {
			if((i%atoi(argv[2])) == 0){
				strcpy(loc_name, loc);
				strcat(loc_name, dent->d_name);
				strcpy(mvloc_name, mvloc);
				strcat(mvloc_name, dent->d_name);
//				printf("%s -- %s \n",loc_name, mvloc_name);
				symlink(loc_name, mvloc_name);
			}
		}
		i++;
	}
	return 0;
}


