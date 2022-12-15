#include <stdio.h>
#include <math.h>


void gioithieu()
{
    printf(" \t\t |-------------------------------------------------------|\n");
    printf(" \t\t |                                                       |\n");
    printf(" \t\t |              DO AN LAP TRINH TINH TOAN                |\n"); 
    printf(" \t\t |       Tinh dinh thuc cua ma tran vuong cap n          |\n");
    printf(" \t\t |   Giao vien huong dan :   Vo Duc Hoang                |\n");
    printf(" \t\t |       Thanh vien nhom :   Nguyen Thi Le               |\n");
    printf(" \t\t |                           Nguyen Quoc Cuong           |\n");
    printf(" \t\t |               Lop     :   21TCLC-DT2                  |\n");
    printf(" \t\t |               Nhom    :   21.12A                      |\n"); 
    printf(" \t\t |                                                       |\n");
    printf(" \t\t |-------------------------------------------------------|\n"); 
}
void nhap (float a [100][100], int n) { 
    int i,j; 
    for ( i=0; i<n; i++) { 
        for (j=0; j<n; j++){ 
            printf (" a[%d][%d] = ", i,j); 
            scanf ("%f", &a[i][j]) ; 
                 } 
         } 
} 
  
void xuat ( float a[100][100], int n){ 
    int i, j; 
    for (i=0; i<n; i++) { 
        for (j=0; j<n; j++) { 
            printf ("%10.3f", a[i][j]); 
        } 
        printf ("\n"); 
    } 
} 

void ghiFile(float a[100][100], int n, char tenFile[50]){
    int i, j;
    FILE *f;
    f = fopen(tenFile, "w");
    if(f==NULL){
        printf("\n Loi mo file");
        return;
    }
    
    fprintf(f, "%d\n", n);
    for(i=0; i<n; i++){
        for ( j=0; j<n; j++) {
            fprintf(f, "   %.2f   ", a[i][j]);
        }
        fprintf(f,"\n");
    } 
    fclose(f);
}

void docFile(float a[100][100], int &n, char tenFile[50]){
    int i, j;
    FILE *f;
    f = fopen(tenFile, "r");
    if(f==NULL){
        printf("\n Loi mo file");
        return;
    }
    fscanf(f, "%d", &n);
    
    for( i=0; i<n; i++){
        for(  j=0; j<n; j++) {
            fscanf(f, "%f", &a[i][j]);
        }
    }
    fclose(f);
}
void luufile(float a[][100], float D,int n)
{   int i, j;
    FILE*f;
    f= fopen("input.txt","w");
  
    fprintf(f,"     Ma tra co bac la %d\n",n);
    fprintf(f,"   Ma tran la \n");
    for ( i=0;i<n;i++)
  {
    for ( j=0;j<n;j++)
   {

    fprintf(f,"  %.2f  ",a[i][j]);
    
  }
  fprintf(f,"\n");
}
   fprintf(f," \n Dinh thuc cua ma tran \n %.2f  ",D);
    fclose(f);
}

void checkcot(float a[][100], int D[],int n)
{ 
    int i, j;
   for ( i = 0;i <n;++i) D[i] = 0;

    for ( j = 0;j<n;++j){
        int isZero = 1;
        for ( i = 0;i<n;++i)
        {
            if (a[i][j] != 0) { isZero = 0; break; }
        }

        D[j] = isZero;
    }
}
void checkhang(float a[][100], int C[],int n)
{
    int i, j;
    for ( i = 0;i <n;++i) C[i] = 0;

    for (j = 0;j<n;++j){
        int isZero = 1;
        for ( i = 0;i<n;++i)
        {
            if (a[j][i] != 0) { isZero = 0; break; }
        }

        C[j] = isZero;
    }
}
float Det(float a[][100],int n)
{
    float m,d=1;
    int i,j,k,demcot=0,demhang=0;
    // su dung mang D[i] check xem ma tran co cot full = 0 ko 
    // su dung mang C[i] check xem ma tran co hang full =0 ko
    int D[n],C[n];
    checkcot(a,D,n);
    checkhang(a,C,n);
     printf("\n");
     printf("\n ma tran ban dau \n");
      xuat(a,n);
      // nếu ma trận có số cột full 0 >=1 thì sẽ in ra det= 0 
    for ( i=0;i<n;++i)
    {
        if (D[i]!=0)
        {
            
            demcot+=1;
        }
    }
    printf("\n so cot full 0 trong ma tran = %d\n",demcot);
    for ( i=0;i<n;++i)
    {
        if (C[i]!=0)
        {
            
            demhang+=1;
        }
    }
        printf("\n so hang full 0 trong ma tran = %d",demhang);
    // kiem tra neu co >= 1 cot hoac >=1 hang co full 0 thi in ra dinh thuc = 0
    if (demcot >= 1 || demhang >=1)
    {
        return d=0;

    }
    else {
        // bien doi ve ma tran tam giac tren 
        for ( i=0;i<n;i++){ 
        if(a[i][i]==0){ 
            k=i+1; 
            while ((k<n)&&(a[k][i]==0))  k++; 
            if (k>=(n)){ 
                break; }

            else{                
                for ( j=i;j<n;j++) { 
                    float t=a[i][j]; 
                    a[i][j]=-a[k][j]; 
                    a[k][j]=t; 
                } 
            } 
        } 
        for ( j=i+1;j<n;j++) { 
            m=-a[j][i]/a[i][i]; 
            for (k=i;k<n;k++) {  
                a[j][k]=a[j][k]+a[i][k]*m; 
            } 
        } 
    } 
        printf("\n\n\t ma tran tam giac thu duoc \n");
    xuat(a,n); 
    // tinh dinh thuc cua ma tran 
    for ( i=0; i<n; i++){  
        d=d*a[i][i]; 
        if (a[i][i]==0){ 
            return 0;  
        } 
    } 
    return d; 
    }
}
int main()
{  float a[100][100],D;
	int n;
    gioithieu();
    printf("\n                 ---------TIM DINH THUC CUA MA TRAN VUONG CAP n---------\n ");
    
  //   printf("moi ban nhap n=");
	 // scanf("%d", &n);
  //    printf("\n Nhap vao he so cua ma tran vuong cap n\n");
    
  //    nhap(a,n); 
  //   ghiFile(a, n, "output.txt");
docFile(a, n, "output.txt");
printf("                             -------Ma tran co bac la %d --------\n\n",n);
D=Det(a,n);
printf("\n\n     Dinh thuc cua ma tran la Det=%.2f\n\n",D);
luufile (a,D,n);

    

}
