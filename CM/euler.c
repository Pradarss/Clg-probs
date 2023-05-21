#include <stdio.h>

float df(float x, float y){
    return x+y;
}

int main(){
    float x0, y0, h, x, x1, y1;
    puts("Enter the values of x0, y0, h, x ");
    scanf("%f %f %f %f", &x0, &y0, &h, &x);
    x1=x0;
    y1=y0;
    while(1){
        if (x1>x) return 0;
        y1+=h*df(x1, y1);
        x1+=h;
        printf("When x = %3.1f y = %4.2f\n", x1, y1);
    }
}
