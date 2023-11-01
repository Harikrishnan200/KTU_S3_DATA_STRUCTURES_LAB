#include<stdio.h>

struct process{
int priority;
int pid;
int btime;
int comptime;
int wtime;
int ttime;

}pr[10];

float tottat=0.0,totwt=0.0;

void swap(int n){
int i,j;

struct process temp;

for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(pr[i].priority>pr[j].priority){
temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;



}


}


}

}

void process_calculation(int n){
   int i;

   pr[0].comptime=pr[0].btime;
   pr[0].wtime=0;
   for(int i=1;i<n;i++){
       pr[i].comptime=pr[i].btime+pr[i-1].comptime;



}

    for(int i=0;i<n;i++){

      pr[i].ttime=pr[i].comptime;
      pr[i].wtime=pr[i].ttime-pr[i].btime;
      tottat +=pr[i].ttime;
      totwt +=pr[i].wtime;


}

}


void display(int n){


   for(int i=0;i<n;i++){

      printf("process[%d]\t%d\t%d\t%d\t%d",pr[i].pid,pr[i].btime,pr[i].priority,pr[i].ttime,pr[i].wtime);
      printf("\n");
}

   printf("\nTotal turn around time:%f",tottat);
   printf("\nAverage turn around time:%f",tottat/n);
   printf("\nTotal waiting time:%f",totwt);
   printf("\nAverage waiting time:%f",totwt/n);

}


int main()
{
    int i,j=0,n,pno;
    printf("Enter the no. of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    
    printf("\nEnter the burst time and priority of process %d:",++j);
    scanf("%d%d",&pr[i].btime,&pr[i].priority);
    pno=i;
    pr[i].pid=++pno;
    
    
    
    }
    swap(n);
    process_calculation(n);
    display(n);
]