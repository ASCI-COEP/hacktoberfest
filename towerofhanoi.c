#include <stdio.h>

void TOH(int disks, char tower1, char tower2, char tower3){

    if(disks==1){

        printf("Shift the top disk from tower %c to tower %c\n",tower1,tower2);

        return;

    }

    TOH(disks-1,tower1,tower3,tower2);

    printf("Shift the top disk fron tower %c to tower %c\n",tower1,tower2);

    TOH(disks-1,tower3,tower2,tower1);

};

int main(){
    
    int disks;

    printf("Enter the number of disks on the first tower\n");

    scanf("%d",&disks);

    if(disks<1){
        printf("There are no disks to shift\n");
    }

    TOH(disks,'1','2','3');

    printf("Successfully shifted %d disks in tower 1 to tower 2\n",disks);

    return 0;
}
