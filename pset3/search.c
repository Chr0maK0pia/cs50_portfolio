#include <cs50.h>
#include <stdio.h>
#include <string.h>
//basic structs.

typedef struct{

    string name;
    int votes;
}
canadite;


int main(void){

canadite people[3];

people[0].name = "Lexi";
people[0].votes = 11;

people[1].name = "Jamie";
people[1].votes = 6;

people[2].name = "Gigi";
people[2].votes = 10;

int highest_vote = 0;
string winner;
for(int i = 0; i < 3; i++)
{
    if(people[i].votes > highest_vote)
    {

        highest_vote = people[i].votes;
        winner = people[i].name;

    }


}




printf("\nvotes: %i", highest_vote);
printf("\nwinner: %s", winner);
printf("\n");

}
