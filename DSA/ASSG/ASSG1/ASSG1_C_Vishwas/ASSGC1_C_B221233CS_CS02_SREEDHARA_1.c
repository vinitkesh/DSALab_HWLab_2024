#include<stdio.h>
void unio(int A[],int B[],int m,int n){
    if(m==0 && n==0){
        printf("-1\n");
        return;
    }
    //printf("HI\n");
    int arr[2*(m>n ? m:n)];
    int hash=2*(m>n ? m:n);
    for(int i=0;i<hash;i++){
        arr[i]=-1;
    }
    for(int i=0;i<m;i++){
        int in=A[i]%hash;
        while(arr[in]>=0 ){
            if(arr[in]==A[i]){
                //printf("existed %d\n",arr[in]);
                goto cont;
            }
           (in++)%hash;
        }
        arr[in]=A[i];
         printf("%d ",arr[in]);
      cont : continue;
    }
    for(int i=0;i<n;i++){
        int in=B[i]%hash;
        while(arr[in]>=0){
            if(arr[in]==B[i]){
                goto ont;
            }
            (in++)%hash;
        }
        arr[in]=B[i];
        printf("%d ",arr[in]);
      ont : continue;
    }
    // for(int i=0;i<hash;i++){
    //     if(arr[i]>0)
    //      printf("%d ",arr[i]);
    // }
    printf("\n");
    
}

//#include<stdio.h>
void ando(int B[],int A[],int n,int m){
    //printf("HI\n");
    int ctr=0;
    int arr[2*(m>n ? m:n)];
    int hash=2*(m>n ? m:n);
    for(int i=0;i<hash;i++){
        arr[i]=-1;
    }
    for(int i=0;i<m;i++){
        int in=A[i]%hash;
        while(arr[in]>=0 ){
            if(arr[in]==A[i]){
                //printf("existed %d\n",arr[in]);
                goto cont;
            }
           (in++)%hash;
        }
        arr[in]=A[i];
       //  printf("%d ",arr[in]);
      cont : continue;
    }
    for(int i=0;i<n;i++){
        int in=B[i]%hash;
        while(arr[in]>=0){
            if(arr[in]==B[i]){
                 printf("%d ",arr[in]);
                 arr[in]=101;ctr=1;
                goto ont;
            }
            (in++)%hash;
        }
      
       
      ont : continue;
    }
    // for(int i=0;i<hash;i++){
    //     if(arr[i]>0)
    //      printf("%d ",arr[i]);
    // }
    if(!ctr){printf("-1");}
    printf("\n");
    
}
void mino(int A[],int B[],int m,int n){
   // printf("HI\n");
     int ctr=0;
    int arr[2*(m>n ? m:n)];
    int hash=2*(m>n ? m:n);
    for(int i=0;i<hash;i++){
        arr[i]=-1;
    }
    for(int i=0;i<n;i++){
        int in=B[i]%hash;
        while(arr[in]>=0){
            if(arr[in]==B[i]){
                goto ont;
            }
            (in++)%hash;
        }
        arr[in]=B[i];
        //printf("%d ",arr[in]);
      ont : continue;
    }
    for(int i=0;i<m;i++){
        int in=A[i]%hash;
        while(arr[in]>=0 ){
            if(arr[in]==A[i]){
                  //printf("existed %d\n",arr[in]);
                goto cont;
            }
           (in++)%hash;
        }
        arr[in]=A[i];
        ctr=1;
        printf("%d ",A[i]);
      cont : continue;
    }
    
    // for(int i=0;i<hash;i++){
    //     if(arr[i]>0)
    //      printf("%d ",arr[i]);
    // }
    if(!ctr){printf("-1");}
    printf("\n");
    
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int A[m],B[n];
    for(int i=0;i<m;i++){
       // printf("ENTER %d->number\n",i);
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
       // printf("ENTER %d->number\n",i);
        scanf("%d",&B[i]);  
    }
    char ch;
    char a,b;
   while(1){
    //printf("ENTER ch: ");
    scanf(" %c",&ch);
      //printf("%c %c\n",ch,ch);// Add a space before %c to skip whitespace characters
    switch(ch){
        case 'u' : scanf(" %c %c",&a,&b); // Add a space before each %c
                   // printf("%c %c\n",a,b);
                    if(a=='A' && b=='B')   unio(A,B,m,n);
                    else if(b=='A' && a=='B') unio(B,A,n,m);
                  break;
        case 'i' :  scanf(" %c %c",&a,&b); // Add a space before each %c
                    //printf("%c %c\n",a,b);
                    if(a=='A' && b=='B')   ando(A,B,m,n);
                    else if(b=='A' && a=='B') ando(B,A,n,m);
                    break; 
        case 's' :  scanf(" %c %c",&a,&b); // Add a space before each %c
                    //printf("%c %c\n",a,b);
                    if(a=='A' && b=='B')   mino(A,B,m,n);
                    else if(b=='A' && a=='B') mino(B,A,n,m);
                    break;                     
        case 'e' : return 1;          
    }
}

}