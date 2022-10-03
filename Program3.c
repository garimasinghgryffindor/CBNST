#include <stdio.h>
#include <math.h>

//  NEWTON RAPHSON
//equation: x^3 - 4x -9

float equation(float x){
    return x*x*x - 4*x -9;
}

float differential(float x){
    return 3*x*x-4;
}

int main(){
    float a, b , e;
    printf("Enter the first initial roots a:  ");
    scanf("%f",&a);
    printf("Enter the tolerable error:  ");
    scanf("%f",&e);

    float c = a - equation(a)/differential(a);

    do{
        a = c;
        c = a - equation(a)/differential(a);
    } while(fabs(equation(c)>e));

    printf("%f\n",c);

    return 0;
}