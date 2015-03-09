#include <stdio.h>
#include <pthread.h>

void* inc_n(void* n)
{
   /* increment n to 100 */
   int *n_pointer = (int *)n;
   while(++(*n_pointer) < 1000000000);
   return NULL;
}

int main()
{

    int x = 0, y = 0;
    pthread_t xIncrement, yIncrement;
    printf("x: %d, y: %d\n", x, y);


    pthread_create(&xIncrement, NULL, inc_n, (void *) &x);
    printf("x increment finished\n");

    pthread_create(&yIncrement, NULL, inc_n, (void *) &y);
    printf("y increment finished\n");

    pthread_join(xIncrement, NULL);
    pthread_join(yIncrement, NULL);

    printf("x: %d, y: %d\n", x, y);
    return 1;
}
