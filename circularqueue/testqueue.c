#include <stdio.h>
#include "queue.h"
int main() {
    queue q;
    data d;
    qinit(&q);
    while(scanf("%s%u", d.name, &(d.age)) != -1)
        if(!qfull(&q))
            enq(&q, d);
    while(!qempty(&q)) {
        d = deq(&q);
        printf("%s %u\n", d.name, d.age);
    }
    return 0;
}