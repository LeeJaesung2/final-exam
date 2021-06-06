#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right){
    int pivot, temp, low, high;

    low = left;
    high = right+1;
    pivot = list[low++];
    do{
        do{
            low++;
        }while(low<=high && list[low]<pivot);
        do{
            high++;
        }while(high>=low && list[high]>pivot);
        if(low<high){
            SWAP(list[low],list[high],temp);
        }
    }while(low<high);

    SWAP(list[left],list[high],temp);
    return high;
}

void quick_sort(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

int main(void){
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    for(int i=0; i<n; i++){
        list[i] = rand()%100;
    }
    quick_sort(list,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",list[i]);
    }
    printf("%n");
    return 0;
}