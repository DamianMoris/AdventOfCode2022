#include <stdio.h>

int main()
{
    FILE* file;
    char c;
    int cal = 0;
    int sum = 0;
    int highest1 = 0;
    int highest2 = 0;
    int highest3 = 0;

    file = fopen("D:\\Users\\PC\\Documents\\Programmakes\\AdventOfCode2022\\aoc1.txt", "r");
    if (file){
        while ((c = fgetc(file)) != EOF){
            if (c != '\n')
                cal = cal * 10 + c - 48;
            else{
                if(cal > 0)
                    sum += cal;
                else
                {
                    if (sum > highest3 && sum < highest2 && sum < highest1)
                        highest3 = sum;
                    if (sum > highest3 && sum > highest2 && sum < highest1)
                        highest2 = sum;
                    if (sum > highest3 && sum > highest2 && sum > highest1)
                        highest1 = sum;
                    sum = 0;
                }
                cal = 0;
            }
        }
        if (feof(file))
            fclose(file);
        printf("%d\n", highest1 + highest2 + highest3);
    }
    return 0;
}
