Shared_sender
#include<sys/ipc.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main() {
   void *shared_memory;
   char buffer[100];
   int shmid;
 
   shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
   printf("Key of the Shared memory:%d\n",shmid);
 
   shared_memory=shmat(shmid,NULL,0);
   printf("Process attached at %p\n",shared_memory);
   printf("Enter some data to write to shared memory:\n");
   read(0,buffer,100);
   strcpy(shared_memory,buffer);
   printf("You wrote is:%s",(char*)shared_memory);


 }

 /*OUTPUT


 Key of the shared memory :0
Process attached at 0x7fb8b8b67000
Enter some data to write to shared memory: Hai this is the data written by sender process
You wrote is: Hai this is the data written by sender process  */
