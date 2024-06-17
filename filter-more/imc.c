#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Enter a: Enter b: Enter c: ");
    int a, b, c;
    scanf("%i\n", &a);
    scanf("%i\n", &b);
    scanf("%i\n", &c);
    double d = sqrt(b * b - 4 * a * c);
    float x = (-a + d )/(2 * a);
    float y = (-a - d)/(2 * a);
    printf("Roots are: %f %f", x, y);

}