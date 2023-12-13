#include <stdio.h>
#include "laps.h"
#define arrSize 100

/**
 * 
 */
typedef struct {
    size_t id;
    size_t laps;
} Car;

static Car *cars = NULL;
static size_t num_cars = 0;

/**
 * 
 */

void race_state(int *id, size_t size)
{
    size_t i, j , carExist;

    if (id == 0)
    {
        free(cars);
        cars = NULL;
        num_cars = 0;
        puts("All memory is free");
        return;
    }
    /* Allocate memory for the new cars*/
    cars = realloc(cars, (num_cars + size) * sizeof(Car));

    for (i = 0; i < size; i++)
    {
         carExist = 0;
        for (j = 0; j < num_cars; j++)
        {
            /*if we enter this if it means the car already exist*/
            if (cars[j].id == (size_t)id[i])
            {
                cars[j].laps++;
                carExist = 1;
                break;
            }
        }

        if (!carExist)
        {
            cars[num_cars].id = id[i];
            cars[num_cars].laps = 0;
            num_cars++;
            printf("Car %li joined the race\n", cars[i].id);
        }
    }

    /*print state of the race*/
    for (i = 0; i < num_cars; i++)
    {
        printf("Car %li [%li laps]\n", cars[i].id, cars[i].laps);
    }
    printf("\n");
}
