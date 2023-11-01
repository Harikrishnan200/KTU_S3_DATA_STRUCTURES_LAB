#include<stdio.h>
#include<stdlib.h>

int main(){
    int head,count=0,
    RQ[100],i,n,TotalHeadMoment=0;
    printf("Enter the number of Requests:");
    scanf("%d",&n);
    printf("Enter the Requests sequence:");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("Enter initial head position:");
    scanf("%d",&head);
    while(count!=n){
        int min=1000,d,index;
        for(i=0;i<n;i++){
            d=abs(RQ[i]-head);  //abs()  is a function used for finding the avg distance between two points
            if(min>d){
               min=d;
               index=i;
            }
        }
        TotalHeadMoment=TotalHeadMoment+min;
        head=RQ[index];
        RQ[index]=1000;
        count++;
    }   
    printf("Total head movement is %d",TotalHeadMoment);
}



/*   OUTPUT
Enter the number of Requests:8
Enter the Requests sequence:98
183
37
122
14
124
65
67
Enter initial head position:53
Total head movement is 23