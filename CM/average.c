#include <stdio.h>
int main(){
    int num, sum = 0;
    float avg;
    
    for (int i = 1; i <= 10; i++)
        sum = sum + i;
    
    avg = sum / 10.0;
    
    printf("Sum of 10 numbers:\n 1+2+3+4+5+6+7+8+9+10 = %d\n\nAverage of 10 numbers:\n (1+2+3+4+5+6+7+8+9+10)/10 = %.2f", sum, avg);

    return 0;
}