#include<stdio.h>
int main(){
   int i,j,n,a[50],frame[10],no,k,avail,count=0;
   printf("\n ENTER THE NUMBER OF PAGES:");
   scanf("%d",&n);
   printf("\n ENTER THE PAGE NUMBER :");
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }  
   printf("\n ENTER THE NUMBER OF FRAMES :");
   scanf("%d",&no);
   for(i=0;i<no;i++)
   frame[i]= -1;
   j=0;
   printf("\tref string\t page frames\n");
   for(i=0;i<n;i++){
      printf("%d\t\t",a[i]);
      avail=0;
      for(k=0;k<no;k++){
         if(frame[k]==a[i]){
            avail=1;
         }
        } 
        if (avail==0){
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
        }
      for(k=0;k<no;k++){
        printf("%d\t",frame[k]);
       }
      printf("\n");
    }
    printf("Page Fault Is %d",count);
}




    /*OUTPUT
ENTER THE NUMBER OF PAGES:10
ENTER THE PAGE NUMBER :4
7
6
1
7
6
1
2
7
2
ENTER THE NUMBER OF FRAMES :3
ref string page frames
4 4 -1 -1
7 4 7 -1
6 4 7 6
1 1 7 6
7 1 7 6
6 1 7 6
1 1 7 6
2 1 2 6
7 1 2 7
2 1 2 7
Page Fault Is 6
