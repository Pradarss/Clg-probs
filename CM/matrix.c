#include<stdio.h>

int main(){  
    int a[10][10],b[10][10],mul[10][10],sum[10][10],r,c,i,j,k;    
    printf("enter the number of row=");    
    scanf("%d",&r);    
    printf("enter the number of column=");    
    scanf("%d",&c);    
    printf("\nenter the first matrix element=\n");    
    for(i=0;i<r;i++){    
        for(j=0;j<c;j++){    
            scanf("%d",&a[i][j]);    
        }    
    }    

    printf("\nenter the second matrix element=\n");    
    for(i=0;i<r;i++){    
        for(j=0;j<c;j++){    
            scanf("%d",&b[i][j]);    
        }    
    }    

    printf("\naddition of the matrix=\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }

    for(i=0;i<r;i++){    
        for(j=0;j<c;j++){    
            printf("%d  ",sum[i][j]);    
        }    
    printf("\n");    
    }  
        
    printf("\nmultiply of the matrix=\n");    
    for(i=0;i<r;i++){    
        for(j=0;j<c;j++){    
            mul[i][j]=0;    
            for(k=0;k<c;k++){    
                mul[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    

    for(i=0;i<r;i++){    
        for(j=0;j<c;j++){    
            printf("%d  ",mul[i][j]);    
        }    
    printf("\n");    
    }    
return 0;  
}  