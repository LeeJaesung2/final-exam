#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int list[], int n){
    int temp;
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(list[j+1]<list[j]){
                SWAP(list[j],list[j+1],temp);
            }
        }
    }

}

int main(void){
    int n = 10;
    int list[10];
    for(int i= 0; i<n ; i++){
        list[i] = rand()%100;
    }
    bubble_sort(list, n);
    for(int i=0; i<n; i++){
        printf("%d\n",list[i]);
    }
    return 0;
}