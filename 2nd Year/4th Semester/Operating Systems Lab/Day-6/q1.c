#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int t, a[2];
	pipe(a);
	
	t=fork();
	if(t>0){
		write(a[1],"ABC",3);
	}
	else{
		char p[10];
		read(a[0],p,sizeof(p));
		printf("%s \n", p);
	}
}