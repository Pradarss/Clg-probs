#include <stdio.h>

float y(float x){
    return 1/(1+x*x);
}
int main(){
    float a, b, h, sum, value;
    int i, n, j;
    sum = 0;
    printf("Enter a=x0, b=xn, number of subintervals: ");
    scanf("%f %f %d", &a, &b, &n);
    h=(b-a)/n;
    sum = y(a)+y(b);
    for (i=1; i<n; i++){
        if (i%3==0){
            sum = sum +2*y(a+i*h);
        }
        else {
            sum=sum+3*y(a+i*h);
        }
    }
    value=(3*h/8)*sum;
    printf("Value of integral is %f\n", value);
    return 0;
}
