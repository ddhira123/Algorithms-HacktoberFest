
#include <stdio.h>
void checkTri(int a,int b,int c)
{
     if(a==b && b==c)
    {
        printf("Equilateral triangle.");
    }
    else if(a==b || a==c || b==c)
    {
        printf("Isosceles triangle.");
    }
    else
    {
        printf("Scalene triangle.");
    }
void main()
{
    int side1, side2, side3;
    printf("Enter three sides of triangle: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    checkTri(side1,side2,side3);
   

}
