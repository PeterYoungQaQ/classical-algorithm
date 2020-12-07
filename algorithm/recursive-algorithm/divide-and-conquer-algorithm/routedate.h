/**
 * @author: PeterYoung
 * @date: 2020/12/6 16:31
 * @description:循环赛日程表问题
 */
#include<stdio.h>
#include<math.h>
void gametable(int k)
{
    int a[100][100];
    int n,temp,i,j,p,t;
    n=2;//k=0两个参赛选手日程可以直接求得
    a[1][1]=1;a[1][2]=2;
    a[2][1]=2;a[2][2]=1;


    for(t=1;t<k;t++)//迭代处理，依次处理2^n....2^k个选手的比赛日程
    {
        temp=n;n=n*2;//填左下角元素
        for(i=temp+1;i<=n;i++)
            for(j=1;j<=temp;j++)
                a[i][j]=a[i-temp][j]+temp;//左下角和左上角元素的对应关系
        for(i=1;i<=temp;i++)//将左下角元素抄到右上角
            for(j=temp+1;j<=n;j++)
                a[i][j]=a[i+temp][(j+temp)%n];
        for(i=temp+1;i<=n;i++)//将左上角元素抄到右下角
            for(j=temp+1;j<=n;j++)
                a[i][j]=a[i-temp][j-temp];

    }
    printf("参赛人数为:%d\n(第i行第j列表示和第i个选手在第j天比赛的选手序号)\n",n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
            if(j==n)
                printf("\n");
        }
}
void routedate()
{
    int k;
    printf("比赛选手个数为n(n=2^k)，请输入参数K(K>0):\n");
    scanf("%d",&k);
    if(k!=0)
        gametable(k);

}