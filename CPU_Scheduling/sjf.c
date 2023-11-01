#include<stdio.h>

struct process{
int pid;
int btime;
int wtime;
int ttime;

}p[10];

int totttime=0,totwtime=0;


int sort(int n){
  struct process temp;
  int i,j;
  for(i=0;i<n-1;i++){
  for(j=i+1;j<n;j++){
  if(p[i].btime>p[j].btime){
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;


}


}


}
  return 0;
}

int process_calculation(int n){ 


  for(int i=1;i<n;i++){
  p[i].wtime=p[i-1].wtime+p[i-1].btime;
  p[i].ttime=p[i].wtime+p[i].btime;
}

  for(int i=0;i<n;i++){
  totttime+=p[i].ttime;
  totwtime+=p[i].wtime;

}



return 0;
}

void display(int n){

  for(int i=0;i<n;i++){
  printf("%d\t%d\t%d\t%d\t",p[i].pid,p[i].btime,p[i].ttime,p[i].wtime);
  printf("\n");
}

}


int main()
{
    int i,n;
    
    printf("\nEnter the number of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("\nEnter the process id:p");
    scanf("%d",&p[i].pid);
    printf("\nEnter the burst time:");
    scanf("%d",&p[i].btime);
    
    }
    
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    sort(n);
    process_calculation(n);
    display(n);
    
}