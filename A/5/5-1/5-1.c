#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	struct ustname uts;

	if(uname(&uts) == -1){
		perror("uname");
		exit(1);
	}
	mkdir(


	return 0;
}

