#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n){
    int min, temp;
    for(int i=0; i<n-1 ; i++){
        for(int j=i+1; j<n; j++){
            min = i;
            if(list[j]<list[i]){
                min = j;
            }
            SWAP(list[i], list[min], temp);
        }
    }
}

int main(void){
    int n = 10;
    int list[10];
    for(int i= 0; i<n ; i++){
        list[i] = rand()%100;
    }
    selection_sort(list, n);
    for(int i=0; i<n; i++){
        printf("%d\n",list[i]);
    }
    return 0;
}