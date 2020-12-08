/**
 * @author: PeterYoung
 * @date: 2020/12/7 20:50
 * @description: װ������
 */

#include <stdio.h>
#include <stdlib.h>

int * Loading(int c1,int w[],int n);// �������Ž�
void Backtrack(int* i,int *B,int *w,int *x);// ����
// record the best result
void record(int *rec,int *x,int n);// ��¼���Ž�
void sort(int *num,int n);// ð�������ɴ�С

void CLP()
{
    // δ����˳�����
    int W[7]={30,20,12,10,90,80,40};
    int c1=152,c2=130;
    int *res=Loading(c1,W,7);
    // ����������
    for(int i=0; i<7; i++)
        printf("%d\t",res[i]);
}

int * Loading(int c1,int w[],int n){
    sort(w,n);// ���������ɴ�С����
    // x[i]��ʾ��i����װ���Ƿ�װ���һ�Ҵ�
    // rec��¼���Ž�
    int *x=(int*)malloc(n*sizeof(int));
    if(x==NULL) exit(0);
    int *rec=(int*)malloc(n*sizeof(int));
    if(rec==NULL) exit(0);
    for(int i=0; i<n; i++){
        x[i]=0;
        rec[i]=0;
    }
    // B��ʾ��ǰ��һ�Ҵ�ʣ�����ؿռ䣬best��ʾ��С��ʣ�����ؿռ�
    // ���best��Сֵ��Ϊ���ʹ��һ�Ҵ������������
    int B=c1,best=c1,i=0;
    do{
        while(i<n){
            // ���װ�������������C1
            if(B-w[i]>=0){
                B=B-w[i];
                x[i]=1;
            }else{
                x[i] = 0;
            }
            i++;
        }

        if(B<best){
            // ��¼��ʱ���Ž�
            record(rec,x,n);
            best=B;
        }
        // ���ݵ����Է�֧��֧����
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
    // ð������
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