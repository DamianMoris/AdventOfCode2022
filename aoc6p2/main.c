#include <stdio.h>

#define SIZE 14

int main()
{
    FILE* file;
    char c[SIZE];
    int i = 0;
    int stop = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc6.txt", "r");
    if (file){
        while ((c[i++ % SIZE] = fgetc(file)) != EOF){
            if (c[SIZE - 1] != '\0')
                for (int j = 0; j < SIZE && !stop; j++)
                    for (int k = 0; k < SIZE && !stop; k++)
                        if (c[j] == c[k] && j != k)
                            stop = 1;
            if (!stop && i >= SIZE)
                break;
            stop = 0;
        }
        if (feof(file))
            fclose(file);
        printf("%d\n", i);
    }
    return 0;
}
