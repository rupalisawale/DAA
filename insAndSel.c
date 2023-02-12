#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int*a , int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selSort(int* arr , int size){
	for(int i=0;i<size-1;i++){
		int minId = i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[minId]){
				minId = j;
			}
		}
		if(i!=minId){
			swap(&arr[i],&arr[minId]);
		}
	}
}

void insertSort(int *arr, int n){
	int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
	
	/*int i=0;
	int arr[100];
	while(i<=100){
		arr[i] = rand();
		i++;
		printf("%d\n",arr[i]);
	}*/
	for(int i=1;i<=100;i++){
		int j=0;
		int numberArray[100000];
		FILE *f;
		f = fopen("new.txt","r");
		for (j = 0; j < 100000; j++){
       	 	fscanf(f, "%d,", &numberArray[j] );
    		}
    	fclose(f);
		clock_t t;
    	t = clock();
		insertSort(numberArray,i*100);
		t = clock() - t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    	printf("%f\n",time_taken);
		
    }
	/*for(int j=0;j<100000;j++){
		printf("%d\n",numberArray[j]);		
	}
	fclose(f);
	i=0;
	f = fopen("new.txt","r");
	for (i = 0; i < 100000; i++){
       	 fscanf(f, "%d,", &numberArray[i] );
    	}
    	for(int j=0;j<100000;j++){
		printf("%d\n",numberArray[j]);
	}
	/*int i=0;
	int arr[100];
	while(i<=100){
		arr[i] = rand();
		i++;
		printf("%d\n",arr[i]);
	}
	insertSort(numberArray,100000);
	printf("The sorted array is");
	for(int j=0;j<100000;j++){
		printf("%d\n",numberArray[j]);		
	}
	fclose(f);
	
    fun();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("fun() took %f seconds to execute \n", time_taken);*/
	
}
