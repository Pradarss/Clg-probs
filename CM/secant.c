#include <stdio.h>
#include <math.h>
// #define e 0.001
float f(float x){
    return x *x - 30;
}

int main()
{
    int i = 0;
    float x0, x1, x2;
    printf("enter the values of x0 and x1");
    scanf("%f%f", &x0, &x1);
    do
    {
        x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        i++;
        printf("No of iteration=%d\t", i);
        printf("root=%f\t", x2);
        printf("value of function=%f\n", f(x2));
    } while (fabs(f(x2)) > 0.001);
    return 0;
}