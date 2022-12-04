#include <stdio.h>

int main()
{
    FILE* file;
    char c;
    char op;
    char me;
    int score = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc2.txt", "r");
    if (file){
        while ((c = fgetc(file)) != EOF){
            op = c;
            fgetc(file);
            me = fgetc(file);
            fgetc(file);
            if(op == 'A' && me == 'X')
               score += 4;
            else if(op == 'A' && me == 'Y')
               score += 8;
            else if(op == 'A' && me == 'Z')
               score += 3;
            else if(op == 'B' && me == 'X')
               score += 1;
            else if(op == 'B' && me == 'Y')
               score += 5;
            else if(op == 'B' && me == 'Z')
               score += 9;
            else if(op == 'C' && me == 'X')
               score += 7;
            else if(op == 'C' && me == 'Y')
               score += 2;
            else if(op == 'C' && me == 'Z')
               score += 6;
        }
    }
    if (feof(file))
        fclose(file);
    printf("%d\n", score);
    return 0;
}
