#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = k = left;
    j = mid;
    while(i<=mid && j<=right ){
        if(list[i]<=list[k]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }
    if(i>mid){
        for(l = j; l<=right; l++){
            sorted[k++] = list[l];
        }
    }
    else{
        for(l=i; l<mid; l++){
            sorted[k++] = list[l];
        }
    }
    for(l=left; l<right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid, right);
        merge(list, left, mid, right);
    }
}

int main(void){
    int n = 10;
    int list[10];
    for(int i= 0; i<n ; i++){
        list[i] = rand()%100;
    }
    merge_sort(list,0, 9);
    for(int i=0; i<n; i++){
        printf("%d\n",list[i]);
    }
    return 0;
}