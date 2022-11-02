#include<stdio.h>

float y(float x){
    return (1/(1+x*x));
}

void main(){
    float x0,xn,h,s;
    int i,n;
    puts("Enter x0, xn, no. of subintervals:\n");
    scanf("%f \n %f \n %d",&x0,&xn,&n);
    h=(xn-x0)/n;
    s=y(x0)+y(xn)+4*y(x0+h);
    for(i=3;i<=n-1;i+=2){
        s+=4*y(x0+i*h)+2*y(x0+(i-1)*h);
    }
    printf("\nValue of integral is %6.4f\n",(h/3)*s);
}