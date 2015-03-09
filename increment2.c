#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}
int main()
{
	int shm_id;
	pid_t pid;
	int *a, *b;
    int x = 0, y = 0;
	
	
	
    printf("x: %d, y: %d\n", x, y);
	
		inc_n(&x);
		printf("x increment finished\n");
	pid = fork();
	if(pid == 0){
		inc_n(&y);
		printf("y increment finished\n");
		printf("x: %d, y: %d\n", x, y);
		return 0;
	}
	wait();
    return 1;
	
}
