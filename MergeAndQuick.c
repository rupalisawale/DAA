#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        if (a[j] < pivot)  
        {  
            i++;  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
} 

void quickSort(int a[], int start, int end)   
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); 
        quickSort(a, start, p - 1);  
        quickSort(a, p + 1, end);  
    }  
}  */

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; 
      
      
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0;  
    j = 0;    
    k = beg;  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  

int main(){
	for(int i=1;i<=1000;i++){
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
		mergeSort(numberArray,0,i*100);
        //quickSort(numberArray,0,i*100);
		t = clock() - t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    	printf("%f\n",time_taken);
    }
}