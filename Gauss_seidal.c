//  GAUSS SEIDEL
#include <stdio.h>
#include <math.h>

int main(){

    int n;
    printf("Enter the no of equations :  ");
    scanf("%d",&n);
    float mat[n][n+1];
    float sol[n];
    int i,j;
    float e;
    for (i = 0 ; i<n ; i++)
    {
        printf("Enter the coeff of the %d var equation :  ",i+1);
        for (j=0 ; j<n ; j++)
            scanf("%f" , &mat[i][j]);
        printf ("Enter the value of the equation :  ");
        scanf("%f",&mat[i][j]);
    }

    printf("Enter the max tolerable error: ");
    scanf("%f",&e);
    for(i=0 ; i<n ; i++){
        sol[i] = 0;
    }

    int f=0 ; 
    do{
        for(i=0 ; i<n ; i++){
            float sum = 0;
            for(j=0 ; j<n ; j++){
                if(j!=i){
                    sum += mat[i][j]*sol[j];
                }
            }
            
            float sol_i = (mat[i][n] - sum)/((float)mat[i][i]);
            float err = fabs(sol_i - sol[i]);
            if(err > e);
            else{
                f=1;
            }
            sol[i] = sol_i;
        }
    }while(f==0);

    printf("Solution of the equation:\n");
    for(i=0 ; i<n ; i++){
        printf("var %d = %f\n" , i+1 , sol[i]);
    }

    return 0;
}