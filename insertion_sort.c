#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int list[], int n){
    int key, j;
    for(int i=1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key;j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }

}

int main(void){
    int n = 10;
    int list[10];
    for(int i= 0; i<n ; i++){
        list[i] = rand()%100;
    }
    insertion_sort(list, n);
    for(int i=0; i<n; i++){
        printf("%d\n",list[i]);
    }
    return 0;
}