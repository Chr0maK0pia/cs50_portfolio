#include <cs50.h>
#include <stdio.h>


int main(void){

int wanted_num = 5;
bool found_num = false;
int nums[] = {3,5,7,3,2,5,6,4,9,7};

for(int i = 0; i < 10; i++){

    if(nums[i] == wanted_num)
    {

        printf("Found number %i", wanted_num);
        found_num = true;

        //hello 

    }



}

if(found_num == false)
{

    printf("Num not found");

}

}
