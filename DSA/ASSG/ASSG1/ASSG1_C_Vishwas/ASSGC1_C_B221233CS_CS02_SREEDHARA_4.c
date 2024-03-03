#include<stdio.h>
#include<string.h>
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}

int maxprime(int n) {
    for (int i = n - 1; i > 1; i--)
        if (is_prime(i)) return i;
    return -1;
}
void linearprobe(int arr[],int arrsize,int n){
    int hashtable[n];
    for(int i=0;i<n;i++){
        hashtable[i]=-1;
    }
    int colli=0;
    for(int i=0;i<arrsize;i++){
      int ind=arr[i]%n;
      int j;
      for(j=0;j<n;j++){
           // printf("%d->%d\n",j,ind);
        if(hashtable[ind]<0){
           // printf("break found %d->%d\n",j,ind);
            break;
        }
        colli++;
        ind=(ind+1)%n;
      }
      if(j==n){
      //  printf("hi\n");
    //  printf("%d->%d ",j,ind);
        return;
      }
      printf("%d ",ind);
       hashtable[ind]=arr[i];
    }
    printf("\n%d\n",colli);
    return;
}

void quadprobe(int arr[],int arrsize,int n){
    int hashtable[n];
    for(int i=0;i<n;i++){
        hashtable[i]=-1;
    }
    int colli=0;
    for(int i=0;i<arrsize;i++){
      int ind=arr[i]%n;
      int j=0;
      while(j<=n && hashtable[(ind+j*j)%n]>0){
        j++;
        colli++;
      }
      if(j==n){
      //  printf("hi\n");
    //  printf("%d->%d ",j,ind);
        return;
      }
      ind=(ind+j*j)%n;
      printf("%d ",ind);
       hashtable[ind]=arr[i];
    }
    printf("\n%d\n",colli);
    return;
}
void doublehash(int arr[],int arrsize,int n){
    int hashtable[n];
    for(int i=0;i<n;i++){
        hashtable[i]=-1;
    }
    int colli=0;
    for(int i=0;i<arrsize;i++){
      int ind=arr[i]%n;
      int j=0;
      int h1x=arr[i]%n;
      int mx=maxprime(n);
      int h2x=mx-(arr[i]%mx);
      while(j<=n && hashtable[(h1x+j*h2x)%n]>0){
        j++;
        colli++;
      }
      if(j>=n){
        return;
      }
      ind=(h1x+j*h2x)%n;
      printf("%d ",ind);
       hashtable[ind]=arr[i];
    }
    printf("\n%d\n",colli);
}

int main(){
int n;
scanf("%d ",&n);
char str[100];
gets(str);
//puts(str);
int num=0;
int arr[100];
int j=0;
for(int i=0;str[i]!='\0';i++){
    if(str[i]==' '){
      arr[j++]=num;
      num=0;
    }
    else{
        num=num*10+str[i]-'0';
    }
}
arr[j++]=num;
//  for(int i=0;i<j;i++){
//       printf("%d ",arr[i]);
//  }
 linearprobe(arr,j,n);
 quadprobe(arr,j,n);
 doublehash(arr,j,n);
return 1;
}
