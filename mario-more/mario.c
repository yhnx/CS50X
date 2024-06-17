#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h;
   do
   {
      h = get_int("Height: ");
   }
   while (h < 1 || h > 8);
   for (int n = 1; n <= h; n++)
   {
      for (int m = 0; m < (h - n); m++)
      {
            printf(" ");
      }
      for (int o = 0; o < n; o++)
      {
            printf("#");
      }
      printf("  ");
      for (int p = 0; p < n; p++)
      {
         printf("#");
      }
      printf("\n");
   }
}