#include <stdio.h>

struct easter_egg_t{
    int teglo;
    double qkost;
    double health;
};

int beat(struct easter_egg_t egg1, struct easter_egg_t egg2)
{
    double shteta;
    int result = 0;

    while(1)
    {
        shteta = (egg1.health + egg2.health) / 2;
        egg1.health -= shteta * egg1.qkost;
        egg2.health -= shteta * egg2.qkost;

        if(egg1.health <= 0 && egg2.health <= 0)
        {
            result = 3;
            break;
        }
        else if(egg1.health <= 0)
        {
            result = 2;
            break;
        }
        else if(egg2.health <= 0)
        {
            result = 1;
            break;
        }
        else if(result == 3)
            break;
    
        result = 3;
    }
   
    return result;
}

int main()
{
    struct easter_egg_t egg1;
    struct easter_egg_t egg2;

    egg1.teglo = 10;
    egg1.qkost = 1;
    egg1.health = 10;

    egg2.teglo = 10;
    egg2.qkost = 1;
    egg2.health = 10;

    beat(egg1, egg2);

    printf("%d\n", beat(egg1, egg2));
}