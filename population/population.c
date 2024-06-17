#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int final = start;
    int n = 0;
    while (final < end)
    {
        int born = final / 3;
        int died = final / 4;
        final = final + born - died;
        n++;
    }
    // TODO: Print number of years
    printf("Years: %i \n", n);
}
