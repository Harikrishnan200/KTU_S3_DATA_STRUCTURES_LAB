#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    
    int occupied[blocks];
    
     for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
   
       printf("\nProcess No.\tProcess Size\tBlock size.\n");
 
    for (int i = 0; i < proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
    
    
        printf("%d \t\t %d \t\t", i, processSize[i]);
        
 
        if (indexPlaced != -1)
        {
            printf("%d",blockSize[indexPlaced]);
            
            
            occupied[indexPlaced] = 1;
        }
        else
          printf("Not allocated");
        printf("\n");   
    
 
    }
    }
 
int main()
{
    int nb,np,ps[20],bs[20],i,temp=0;
    printf("Enter the no. process:");
    scanf("%d",&np);
    for(i=0;i<np;i++){
    
    printf("Enter the  size of %d process:",++temp);
    scanf("%d",&ps[i]);
    }
    
    
    printf("Enter the no. blocks:");
    scanf("%d",&nb);
   temp=0;
    for(i=0;i<nb;i++){
    printf("Enter the  size of %d block:",++temp);
    scanf("%d",&bs[i]);
    }
 
    implimentBestFit(bs, nb, ps, np);
    return 0 ;
}