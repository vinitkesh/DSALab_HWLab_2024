#include<stdio.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ref[1001]={0};
    int count=0;
    for(int i=0;i<k;i++){
        ref[arr[i]]++;
        if(ref[arr[i]]==1){
           count++;
        }
       
    }
    printf("%d ",count);
    for(int i=1;k+i<=n;i++){
       if(--ref[arr[i-1]]==0){
            count--;
       }
       if(++ref[arr[k+i-1]]==1){
        count++;
       }
       printf("%d ",count);
    }
    return 1;
}