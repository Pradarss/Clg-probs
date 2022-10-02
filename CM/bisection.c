#include<stdio.h>
#include<math.h>

void f(float x){
    return (x*x*x - 4*x - 9);
}

void bisect(float *x,float a,float b,int *itr){
    *x=(a+b)/2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5");
}

int main(){
    
return 0;
}