#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int x = fork();

	if(x<0){
		//err
		exit(1);
	}
	else if(x==0){
		execlp("./Exec",".Exec","Aflah",NULL);
		exit(1);
	}
	else{
		printf("Im am parent process");
		exit(1);
	}
	return 0;
}

