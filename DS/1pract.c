#include <stdio.h>
struct compmat{
    int row;
    int col;
    int val;
    
};

int main() {
    struct compmat record[100];
    int a ,b, i , j , count=0,k=0;
    printf("Enter the number of rows\n");
    scanf("%d",&a);
    printf("Enter the number of columns\n");
    scanf("%d",&b);
    int sp[a][b];
    printf("Enter the elements of the matrix\n");
    for(i=0;i<a;i++){
        for (j=0; j<b; j++) {
            scanf("%d",&sp[i][j]);
        }
    }
    //Check if the matrix is sparse
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            // printf("%d",sp[i][j]);
            if(sp[i][j] == 0)
                count++;
        }
    }
    if(count > ((a * b)/2)){
        printf("Matrix is a sparse matrix \n");
        for(i=0;i<a;i++){
            for (j=0; j<b; j++) {
                if(sp[i][j]!=0){
                    record[k].row=i;
                    record[k].col=j;
                    record[k].val=sp[i][j];
                    k++;
                    // printf("%d\n",k);
                }
            }
        }
        for (i=0; i<k; i++) {
                printf("\nThe %d element with row %d,column %d,value %d",i+1,record[i].row,record[i].col,record[i].val);
        }
    }
    else{
        printf("Matrix is not sparse matrix\n");}
    
   // printf("%d\n",k);
    return 0;
    
}