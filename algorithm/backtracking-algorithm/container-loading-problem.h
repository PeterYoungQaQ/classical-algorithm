/**
 * @author: PeterYoung
 * @date: 2020/12/7 20:50
 * @description: 装载问题
 */

#include <stdio.h>
#include <stdlib.h>

int * Loading(int c1,int w[],int n);// 返回最优解
void Backtrack(int* i,int *B,int *w,int *x);// 回溯
// record the best result
void record(int *rec,int *x,int n);// 记录最优解
void sort(int *num,int n);// 冒泡排序由大到小

void CLP()
{
    // 未按照顺序简历
    int W[7]={30,20,12,10,90,80,40};
    int c1=152,c2=130;
    int *res=Loading(c1,W,7);
    // 输出结果方案
    for(int i=0; i<7; i++)
        printf("%d\t",res[i]);
}

int * Loading(int c1,int w[],int n){
    sort(w,n);// 将载重量由大到小排序
    // x[i]表示第i个集装箱是否装入第一艘船
    // rec记录最优解
    int *x=(int*)malloc(n*sizeof(int));
    if(x==NULL) exit(0);
    int *rec=(int*)malloc(n*sizeof(int));
    if(rec==NULL) exit(0);
    for(int i=0; i<n; i++){
        x[i]=0;
        rec[i]=0;
    }
    // B表示当前第一艘船剩余载重空间，best表示最小的剩余载重空间
    // 求得best最小值即为求得使第一艘船载重最多的情况
    int B=c1,best=c1,i=0;
    do{
        while(i<n){
            // 如果装入后重量不超过C1
            if(B-w[i]>=0){
                B=B-w[i];
                x[i]=1;
            }else{
                x[i] = 0;
            }
            i++;
        }

        if(B<best){
            // 记录此时最优解
            record(rec,x,n);
            best=B;
        }
        // 回溯到可以分支的支点上
        Backtrack(&i,&B,w,x);
    }while(i!=0);
    return rec;
}
void Backtrack(int* i,int *B,int *w,int *x){
    while(*i>0 && x[*i]==0)  (*i)-=1;

    if(x[*i] == 1){
        x[*i]=0;
        *B+=w[*i];
        (*i)++;
    }
}
void record(int *rec,int *x,int n){
    for(int i=0;i<n;i++)
        rec[i]=x[i];
}
void sort(int *num,int n){
    // 冒泡排序
    int tmp;
    for(int i=n-1; i>0; i--)
        for(int j=0; j<i; j++){
            if(num[j]<num[j+1]){
                tmp=num[j];
                num[j]=num[j+1];
                num[j+1]=tmp;
            }
        }
}