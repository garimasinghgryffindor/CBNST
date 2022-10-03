#include <stdio.h>
#include <math.h>

//  REGULA FALSI
//equation: x^3 - 4x -9

float equation(float x){
    return x*x*x - 4*x -9;
}

int main(){
    float a, b , e;
    printf("Enter the first initial roots a & b:  ");
    scanf("%f%f",&a,&b);
    printf("Enter the tolerable error:  ");
    scanf("%f",&e);

    float c = a - (b-a)*equation(a)/(equation(b)-equation(a));
    float x = equation(c);

    do{
        if(x*equation(a)<0){
            b = c;
        } else {
            a = c;
        }
        c = a - (b-a)*equation(a)/(equation(b)-equation(a));
        x = equation(c);
    } while(fabs(equation(c))>e);

    printf("%f\n",c);

    return 0;
}
