#include <stdio.h>

int main()
{
    FILE* file;
    char c;
    char op;
    char me;
    char round;
    int score = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc2.txt", "r");
    if (file){
        while ((c = fgetc(file)) != EOF){
            op = c;
            fgetc(file);
            round = fgetc(file);
            fgetc(file);
            if(round == 'X')
            {
                if(op == 'A')
                    me = 'C';
                else if(op == 'B')
                    me = 'A';
                else if(op == 'C')
                    me = 'B';
            }
            else if(round == 'Y')
                    me = op;
            else if(round == 'Z')
            {
                if(op == 'A')
                    me = 'B';
                else if(op == 'B')
                    me = 'C';
                else if(op == 'C')
                    me = 'A';
            }

            if(op == 'A' && me == 'A')
               score += 4;
            else if(op == 'A' && me == 'B')
               score += 8;
            else if(op == 'A' && me == 'C')
               score += 3;
            else if(op == 'B' && me == 'A')
               score += 1;
            else if(op == 'B' && me == 'B')
               score += 5;
            else if(op == 'B' && me == 'C')
               score += 9;
            else if(op == 'C' && me == 'A')
               score += 7;
            else if(op == 'C' && me == 'B')
               score += 2;
            else if(op == 'C' && me == 'C')
               score += 6;
        }
    }
    if (feof(file))
        fclose(file);
    printf("%d\n", score);
    return 0;
}
