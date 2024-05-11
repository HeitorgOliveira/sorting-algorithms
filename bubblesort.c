#include <stdio.h>
#include <stdlib.h>

void sort(int *unsorted, int size);

//This program gets an unsorted file and sorts the numbers on another file;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR: Not enough arguments, expected 2\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("ERROR: File not found \n");
        return 1;
    }
    char aux[100];
    int numbers[100];
    int i = 0;
    while (fgets(aux, 100, file) != NULL)
    {
        numbers[i] = atoi(aux);
        i++;
    }
    sort(numbers, i);
    for (int j = 0; j < i; j++)
    {
        printf("%i\n", numbers[j]);
    }
    fclose(file);
}

void sort(int *unsorted, int size)
{
    int aux;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (unsorted[j] <= unsorted[i])
            {
                aux = unsorted[i];
                unsorted[i] = unsorted[j];
                unsorted[j] = aux;
            }
        }
    }
}