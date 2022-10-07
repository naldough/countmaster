
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char* arguments[])
{

  int processID;
  int status;
  int NUMBER_OF_CALLS = atoi(arguments[3]);

        arguments[0] = "./countprimes";
	// NUMBER_OF_CALLS = atoi(arguments[3]);
        int processids[NUMBER_OF_CALLS];
        int i;
        int num;
        int total;
        for(i = 0; i < NUMBER_OF_CALLS; i++)
        {
                processids[i] = fork();
                if(processids[i]==0)
                {
                        execvp("./countprimes", arguments);
                }

                else

		{
                waitpid(processID,&status,0);
                num =  WEXITSTATUS(status);

                }
        }

        for(i = 0; i <NUMBER_OF_CALLS; i++)
        {
                waitpid(processids[i],&status,0);
                num = WEXITSTATUS(status);
                total += num;
        }
                printf("The total is %d\n", total);
}


