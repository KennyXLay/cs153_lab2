#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{
	int PScheduler(void);
  
	PScheduler();
	return 0;
 }
  
    
     int PScheduler(void){

	int pid;
	int i, j, k;
        printf(1, "\n  Testing the scheduler. 0 being the highest priority and 31 being the lowest priority. The parent processes will switch to priority 0\n");
        set_prior(1);
        for (i = 0; i <  3; i++) {
 		pid = fork();
		if (pid > 0 ) {
			continue;
		}
		else if ( pid == 0) {
			set_prior(30-15*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<1000;k++) {
				asm("nop"); 
			}
		}
		printf(1, "\n child# %d with priority %d has finished \n",getpid(),30-15*i);		
		exit();
        	}	
        	else {
			printf(2," \n Error \n");
			
        	}
	}

	if(pid > 0){
		for(i = 0; i <  3; i++) {
			wait();
		}
	printf(1,"\n Processes with lowest value 0 (highest prio) will go first and then up. \n");
	exit();
	}
	return 0;
}
