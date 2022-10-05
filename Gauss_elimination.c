#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no of equations :  ");
    scanf("%d", &n);
    int mat[n][n + 1] ;
    int i, j ;
    for (i = 0 ; i<n ; i++)
    {
        printf("Enter the coeff of the %d var equation :  ",i+1);
        for (j=0 ; j<n ; j++)
            scanf("%d" , &mat[i][j]);
        printf ("Enter the value of the equation :  ");
        scanf("%d",&mat[i][j]);
    }

    for(i=0 ; i<n-1 ; i++)
    {   
        int diagonal = mat[i][i];
        for (j=i+1 ; j<n ; j++){
            int k;
            // for 1 equation
            int r = mat[j][i];
            for(k=0; k<n+1 ; k++)
            {
                mat[j][k] -= r*mat[i][k]/diagonal;
            }
        }
    }

    // backsubstituting
    for (i = n - 1; i >= 0 ; i--)
    {
        int substituting = mat[i][n]/mat[i][i];
        for (j=i-1 ; j>=0 ; j--)
        {
            mat[j][n] -= mat[j][i]*substituting;
            mat[j][i]=0;
        }
    }

    //Solution

    for(i = 0 ; i<n ; i++){
        printf("Solution for variable %d = %d\n",i+1,mat[i][n]/mat[i][i]);
    }

    return 0;
}
    
    
    