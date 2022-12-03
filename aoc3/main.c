#include <stdio.h>
#include <string.h>

int getPriority(char);

int main()
{
    char rucksack[50];
    int sum = 0;
    int stop = 0;
    FILE* file;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc3.txt", "r");
    if (file){
        while (fscanf(file, "%s", rucksack) == 1){
            for(int i = 0; i < (int)(strlen(rucksack) / 2) && !stop; i++)
                for(int j = (int)(strlen(rucksack) / 2); j < (int)strlen(rucksack) && !stop; j++)
                    if (rucksack[i] == rucksack[j] && !stop){
                        stop = 1;
                        sum += getPriority(rucksack[i]);
                    }
            stop = 0;
        }
        if (feof(file))
            fclose(file);
        printf("%d\n", sum);
    }
    return 0;
}

int getPriority(char c)
{
    if (c >= 97 && c <= 122)
        return (c - 96);
    else
        return (c - 38);
}
