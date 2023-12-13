#include <stdio.h>
#include "laps.h"

/**
 * 
 */
typedef struct
{
    size_t id;
    size_t laps;
} Car;

static Car *cars = NULL;
static size_t num_cars = 0;

/**
 * race_state - track the laps of the race cars using a truc and static memory
 * @id: is the array of cars
 * @size: is the size of the array
 * Return: void
 */

void race_state(int *id, size_t size)
{
    size_t i, j, carExist;

    if (id == 0)
    {
        free(cars);
        cars = NULL;
        num_cars = 0;
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
    // Sort cars by identifier
    for (i = 0; i < num_cars - 1; ++i) {
        for (j = 0; j < num_cars - 1 - i; ++j) {
            if (cars[j].id > cars[j + 1].id) {
                // Swap cars
                Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }

    /*print state of the race*/
    printf("Race state:\n");
    for (i = 0; i < num_cars; i++)
    {
        if ( i < num_cars - 1)
            printf("Car %li [%li laps]\n", cars[i].id, cars[i].laps);
        else
             printf("Car %li [%li laps]", cars[i].id, cars[i].laps);
    }
    printf("\n");
}
