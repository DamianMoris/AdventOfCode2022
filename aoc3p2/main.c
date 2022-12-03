#include <stdio.h>
#include <string.h>

int getPriority(char);

int main()
{
    char line1[50];
    char line2[50];
    char line3[50];
    char buffer[50];
    int iBuf = 0;
    int sum = 0;
    int stop = 0;
    FILE* file;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc3.txt", "r");
    if (file){
        while (fscanf(file, "%s", line1) == 1){
            fscanf(file, "%s", line2);
            fscanf(file, "%s", line3);
            for (int i = 0; i < strlen(line1); i++)
                for (int j = 0; j < strlen(line2); j++)
                    if (line1[i] == line2[j])
                        buffer[iBuf++] = line1[i];
            stop = 0;
            iBuf = 0;

            for (int i = 0; i < (int)strlen(line3) && !stop; i++)
                for(int j = 0; j < (int)strlen(buffer) && !stop; j++)
                    if (line3[i] == buffer[j] && !stop){
                        stop = 1;
                        sum += getPriority(line3[i]);
                    }
            memset(line1, 0, sizeof(line3));
            memset(line2, 0, sizeof(line3));
            memset(line3, 0, sizeof(line3));
            memset(buffer, 0, sizeof(buffer));
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
