#include <stdio.h>
#include "laps.h"
#define arrSize 100

/**
 * 
 */
void race_state(int *id, size_t size){
    /*static int laps;*/
    static size_t cars[arrSize],raceCars = 0, laps = 0;
    size_t i;

    /*check if argumemts are not null*/
    if (id == NULL || size == 0)
        return;

    /*initital insert ids in to the carr array*/
    if (raceCars == 0)
    {
        for (i = 0; i < size; i++){
        
            if(cars[i] != (size_t)id[i])
            {
                cars[i] = (size_t)id[i];
                printf("Car %li joined the race\n", cars[i]);
                raceCars += 1;
            }
        }
        printf("Race state:\n");
        for (i = 0; i <= raceCars - 1 ; i++)
        {
            printf("Car %li [%li laps]\n",cars[i], laps);
        }
    }
    /*if we already have race cars i want to only add the new ones*/
    if (raceCars > 0)
    {
        printf("we enter second if %li\n", raceCars);
        for (i = 0; i < raceCars; i++){
            /*i need this safe guard statement because some how im adding A BUNCH O RANDOM NUMBERS AS CARS*/
            if (cars[i] > 0 && cars[i] != 0)
            {
                if(cars[i] != (size_t)id[i])
                {
                    cars[i] = (size_t)id[i];
                    printf("car %li joined the race\n", cars[i]);
                    raceCars += 1;
                }
            }
        }
        laps += 1;
        printf("Race state:\n");
        for (i = 0; i <= raceCars - 1 ; i++)
        {
            if (cars[i] > 0 && cars[i] != 0)
                printf("Car %li [%li laps]\n",cars[i], laps);
        }
        
    }

    /*if carsize is not 0 meaning we already initialize the race
    we need push the new added cars with out overide the olds data*/
    
}