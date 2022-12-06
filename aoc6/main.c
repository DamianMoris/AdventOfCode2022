#include <stdio.h>

int main()
{
    FILE* file;
    char c[4];
    int i = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc6.txt", "r");
    if (file){
        while ((c[i++ % 4] = fgetc(file)) != EOF){
            if (c[0] != c[1] && c[0] != c[2] && c[0] != c[3] && c[1] != c[2] && c[1] != c[3] && c[2] != c[3] && c[3] != '\0')
                break;
        }
        if (feof(file))
            fclose(file);
        printf("%d\n", i);
    }
    return 0;
}
