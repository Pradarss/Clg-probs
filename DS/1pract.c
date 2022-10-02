#include<stdio.h>
 
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int sparseMatrix[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                scanf("%d",&sparseMatrix[i][j]);
        }
    }
 
    int size = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compactMatrix[3][size];
 
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
 
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
            printf("%d ", compactMatrix[i][j]);
 
        printf("\n");
    }
return 0;
}