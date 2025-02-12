#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int t, a[3][2];
    
    for(int i =0;i<3;i++)
    {
    	pipe(a[i]);
    	t = fork();
    	if(t==0){
    		break;
    	}
    	int v = rand()%10;
    	char s[10];
    	sprintf(s, "%d", v); 
    	write(a[i][1], s, 2); 
        wait(NULL);
    }
    for(int i =0;i<3;i++){
	    if(t==0){
	    	char p[10]; 
		read(a[i][0], p, sizeof(p)); 
		printf("%s\n",p);
	    }
    }
    return 0;
}