#include<stdio.h>
#include<stdlib.h>


int main(){

	FILE *f;
	f = fopen("new.txt","w");
	if (f == NULL)
	    {
	        printf("ERROR Creating File!");
	        exit(1);
	    }
	for(int i=0; i<100000 ; i++){
		int num = rand()%100000;
		fprintf(f,"%d\n",num);
	}
	printf("DONE!!");
	fclose(f);
	return 0;
}
