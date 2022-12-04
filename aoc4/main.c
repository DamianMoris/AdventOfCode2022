#include <stdio.h>

int main()
{
    FILE* file;
    char c;
    int lowerbound1 = 0;
    int upperbound1 = 0;
    int lowerbound2 = 0;
    int upperbound2 = 0;
    int overlap = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc4.txt", "r");
    if (file){
        while ((c = fgetc(file)) != EOF){
            lowerbound1 = c - 48;
            if((c = fgetc(file)) != '-'){
                lowerbound1 = lowerbound1 * 10 + c - 48;
                fgetc(file);
            }
            upperbound1 = fgetc(file) - 48;
            if((c = fgetc(file)) != ','){
                upperbound1 = upperbound1 * 10 + c - 48;
                fgetc(file);
            }
            lowerbound2 = fgetc(file) - 48;
            if((c = fgetc(file)) != '-'){
                lowerbound2 = lowerbound2 * 10 + c - 48;
                fgetc(file);
            }
            upperbound2 = fgetc(file) - 48;
            if((c = fgetc(file)) != '\n'){
                upperbound2 = upperbound2 * 10 + c - 48;
                fgetc(file);
            }
            if((lowerbound1 >= lowerbound2 && upperbound1 <= upperbound2) || (lowerbound2 >= lowerbound1 && upperbound2 <= upperbound1))
                overlap++;
        }
        if (feof(file))
            fclose(file);
        printf("%d\n", overlap);
    }
    return 0;
}
