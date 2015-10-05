#include<stdio.h>
#define max 300
int count[max][10][max];
int matrix[max][max];
int N;
void counter()
{
 int i,j,k,num,index;
 for(i=0;i<N;i++) {
    for(j=0;j<10;j++)
       count[i][j][0] = 0;
 }
 for(i=0;i<N;i++) {
   for(j=0;j<10;j++) {
    for(k=0;k<N;k++) {
        if(k>0)
           count[i][j][k] = count[i][j][k-1];
        if(matrix[i][k]==j+1) {
             count[i][j][k]++;
        }  
     }
   }
 }
}
int diff(int r1,int c1,int r2,int c2) {
   int i,j,present[10],ret=0;
   for(i=0;i<10;i++)
      present[i] = 0; 
   for(i=r1;i<=r2;i++) {
     for(j=0;j<10;j++) {
        if(c1>0) 
        present[j]=present[j]||(count[i][j][c1-1]<count[i][j][c2]);
        else present[j] = present[j] || (count[i][j][c1]>0||count[i][j][c2]>0);
     }
   }
  for(i=0;i<10;i++)
     ret = ret + present[i];
  return(ret);
}
int main() {
int Q,i,j,r1,r2,c1,c2;
scanf("%d",&N);
for(i=0;i<N;i++) {
 for(j=0;j<N;j++)
   scanf("%d",&matrix[i][j]);
}
counter();
scanf("%d",&Q);
for(i=0;i<Q;i++) {
 scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
 printf("%d\n",diff(r1-1,c1-1,r2-1,c2-1));
}
return(0);
}
