#include<stdio.h>

struct process{
  int btime;
  int wtime;
  int ttime;
  int id;
  }p[20];
  
  float tot_ttime=0,tot_wtime=0;
  
  
 int process_calculation(int n) {
    
   p[0].wtime= 0;
   
    
    for (int  i = 1; i < n ; i++ ){
        p[i].wtime =  p[i-1].btime + p[i-1].wtime;
        tot_wtime+=p[i].wtime;
        }
        
    for (int  i = 0; i < n ; i++){
        p[i].ttime = p[i].btime + p[i].wtime;
        tot_ttime+=p[i].ttime;
        }
   
 }
 
 int display(int n){
printf("Processes   Burst time   Waiting time   TAT\n");
 
 for (int  i=0; i<n; i++)
    {
        
        printf("   p%d ",p[i].id);
        printf("       %d ", p[i].btime );
        printf("           %d",p[i].wtime );
        printf("             %d\n",p[i].ttime );
    }
    printf("\nAverage waiting time = %f",tot_wtime/n);
    printf("\nAverage turn around time = %f",tot_ttime/n);
 
 
 }


int main()
{
   int n,i;
   printf("Enter the no. of process:");
   scanf("%d",&n);
   for(i=0;i<n;i++){
     printf("Enter the process id:p");
     scanf("%d",&p[i].id);
     printf("Enter the burst time of p%d:",p[i].id);
     scanf("%d",&p[i].btime);
  }
    process_calculation(n);
    display(n);
    }