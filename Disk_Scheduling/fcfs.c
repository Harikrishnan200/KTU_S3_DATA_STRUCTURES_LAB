#include <stdio.h>
#include <math.h>

void FCFS(int arr[],int head ,int n){
    int seek_count = 0;
    int cur_track, distance;
    for(int i=0;i<n;i++){
        cur_track = arr[i];
        distance = fabs(head - cur_track);  //fabs() is a function used for finding the distance between two points
        seek_count += distance;
        head = cur_track;
    }
    printf("Total no. of seek operations: %d\n",seek_count);
    printf("Seek Sequence is\n");
    for (int i = 0; i<n; i++) {
        printf("%d\n",arr[i]);
    }
}

int main(){
    int arr[30],n,i,head;
    printf("Enter the number of Requests:");
    scanf("%d",&n);
    printf("Enter the Requests sequence:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }    
    printf("Enter initial head position:");
    scanf("%d",&head);
    FCFS(arr,head,n);
}




  
/*  OUTPUT
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
Total no. of seekoperations:640
Seek Sequence is
98
183
37
122
14
124
65
67
