#include <stdio.h>
#include <math.h>

float equation(float x)
{
    return x*x*x - x*x + 2;
}

float roundoff(float a)
{
    float num = floor(10000*a)/10000;
    
    return num;
}

int main()
{
    float a , b;
    printf("Enter the values of a and b:  ");
    scanf("%f%f",&a,&b);
    
    float c = (a+b)/2.0;
    
    float x , y;
    
    float a_aprox = roundoff(a) , b_aprox = roundoff(b);
    
    x=equation(c) ; 
    y=roundoff(x);
    
    while(a_aprox!=y && b_aprox!=y)
    {
        if(x*equation(a)<0)
        {
            b=c;
            b_aprox = roundoff(b);
            
        } else{
            a=c;
            a_aprox = roundoff(a);
        }
        
        c=(a+b)/2.0;
        x = equation(c);
        y = roundoff(c);
    }
    
    printf("Answer:  %f",c);

    return 0;
}
