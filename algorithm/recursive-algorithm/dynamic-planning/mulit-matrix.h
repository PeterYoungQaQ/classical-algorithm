/**
 * @author: PeterYoung
 * @date: 2020/12/6 16:49
 * @description: ������������
 */
#include <stdio.h>
#define N1 20
void MatrixChain(int p[N1],int n,int m[N1][N1],int s[N1][N1]){
    int i,j,t,k;
    int r;             //��¼��˵ľ����������
    for(i=1;i<=n;i++){
        m[i][i]=0;         //��һ���������ʱ����˴���Ϊ 0
    }
    //���������������ʼһ�ε���
    for(r=2;r<=n;r++){
        //��ĳ������ʼ
        for(i=1;i<=n-r+1;i++){
            //��ĳ������Ľ���
            j=i+r-1;
            //�õ��� i �� j �������˵Ĵ���
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            //�õ��������˶Ͽ���λ��
            s[i][j]=i;
            //Ѱ�Ҽ����Ų�ͬ���������˴�������Сֵ���޸� m ���飬�ͶϿ���λ�� s ����
            for(k=i+1;k<j;k++){
                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}

void multimatrix(void){
    int n,n1,m1,i,j=2;
    int p[N1]={0};          //�洢������к�������
    int m[N1][N1]={0};        //�洢�����������˵���С����
    int s[N1][N1]={0};        //�洢�����������˶Ͽ���λ��
    printf("������������:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("�������%d��������к���(n1*m1 ��ʽ):",i);
        scanf("%d*%d",&n1,&m1);
        if(i==1){
            p[0]=n1;
            p[1]=m1;
        }
        else{
            p[j++]=m1;
        }
    }
    printf("\n��¼�����к���:\n");
    for(i=0;i<=n;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    MatrixChain(p,n,m,s);
    printf("\n������˵���С��������Ϊ:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d  ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n������˶Ͽ���λ�þ���Ϊ:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    printf("������С��˴���Ϊ:%d\n",m[1][n]);
}
