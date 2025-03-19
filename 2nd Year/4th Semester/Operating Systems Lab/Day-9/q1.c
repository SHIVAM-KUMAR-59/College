#include<stdio.h>
#include<pthread.h>

void *f(void * data){
	pthread_t t;
	int d = *((int *)data);
	int e = d/2;
	printf("%d\n",d);
	if(d>1){
		pthread_create(&t, NULL, f, &e);
		pthread_join(t,NULL);
	}
	return NULL;
}

int main(){
	pthread_t t1;
	int a =16;
	
	pthread_create(&t1, NULL, f, &a);
	pthread_join(t1,NULL);
	
	return 0;
}