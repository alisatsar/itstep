#include <stdio.h>
 
#define DAYS_COUNT 7
 
float findAverageTemperature(float temperatures[]);
float findMaximumTemperature(float temperatures[]);
float findMinimumTemperature(float temperatures[]);
 
int main()
{
    float temperatures[DAYS_COUNT];
 
   
    float minTemperature;
    float maxTemperature;
 
    for (int i = 0; i < DAYS_COUNT; i++)
    {
        printf("Please enter temperature "
            "for %i day: ", i + 1);
        scanf("%f", &temperatures[i]);
 
        if (i == 0)
        {
            minTemperature = temperatures[i];
            maxTemperature = temperatures[i];
        }
 
        if (minTemperature > temperatures[i])
        {
            minTemperature = temperatures[i];
        }
        if (maxTemperature < temperatures[i])
        {
            maxTemperature = temperatures[i];
        }
    }
 
    float const averageTemperature =
        findAverageTemperature(temperatures);
   
    printf("Average temperature: %.2f\n",
        averageTemperature);
    printf("Maximum temperature: %.2f\n",
        maxTemperature);
    printf("Minimum temperature: %.2f\n",
        minTemperature);
}
 
float findAverageTemperature(float temperatures[])
{
    float summ = 0;
    for (int i = 0; i < DAYS_COUNT; i++)
    {
        summ += temperatures[i];
    }
    return summ / DAYS_COUNT;
}
