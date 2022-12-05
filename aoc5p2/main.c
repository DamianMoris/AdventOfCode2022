#include <stdio.h>
#include <string.h>

#define COLS 9
#define ROWS 56

int main()
{
    int moveAmount = 0;
    int fromCol = 0;
    int toCol = 0;
    char garbage[4];
    FILE* file;
    char crates[COLS][ROWS] = {{'S', 'L', 'W'},
                               {'J', 'T', 'N', 'Q'},
                               {'S', 'C', 'H', 'F', 'J'},
                               {'T', 'R', 'M', 'W', 'N', 'G', 'B'},
                               {'T', 'R', 'L', 'S', 'D', 'H', 'Q', 'B'},
                               {'M', 'J', 'B', 'V', 'F', 'H', 'R', 'L'},
                               {'D', 'W', 'R', 'N', 'J', 'M'},
                               {'B', 'Z', 'T', 'F', 'H', 'N', 'D', 'J'},
                               {'H', 'L', 'Q', 'N', 'B', 'F', 'T'}};

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc5.txt", "r");
    if (file){
        while (fscanf(file, "%s", garbage) == 1){
            fscanf(file, "%d", &moveAmount);
            fscanf(file, "%s", garbage);
            fscanf(file, "%d", &fromCol);
            fscanf(file, "%s", garbage);
            fscanf(file, "%d", &toCol);
            for(int i = 0; i < moveAmount; i++)
                crates[toCol - 1][strlen(crates[toCol - 1])] = crates[fromCol - 1][strlen(crates[fromCol - 1]) - moveAmount + i];
            for(int i = 0; i < moveAmount; i++)
                crates[fromCol - 1][strlen(crates[fromCol - 1]) - 1] = '\0';
        }

        for(int i = 0; i < COLS; i++)
            printf("%c", crates[i][strlen(crates[i]) - 1]);
        printf("\n");

        if (feof(file))
            fclose(file);
    }
    return 0;
}
