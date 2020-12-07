/**
 * @author: PeterYoung
 * @date: 2020/12/7 16:48
 * @description: 背包问题
 * 背包问题可以用贪心算法求解，而0-1背包问题却不能用贪心算法求解！
 */


void package_part(int *w,int *v,double *p,int n,int c,int *flag)
{
    int i,j,temp;
    double tempD,totalValue = 0.0;

    //计算单价
    for(i=0;i<n;i++)
    {
        p[i] = (double)v[i] / (double)w[i];
        flag[i] = i;
    }
    //根据单价排序,flag数组保存物品的下标
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(p[j] > p[j-1])
            {
                temp = flag[j];
                flag[j] = flag[j-1];
                flag[j-1] = temp;

                tempD = p[j];
                p[j] = p[j-1];
                p[j-1] = tempD;
            }
        }
    }
    //贪心法得出应该装入的物品
    for(i=0;i<n;i++)
    {
        if(c >= w[flag[i]])
        {
            totalValue += v[flag[i]];
            c -= w[flag[i]];
            printf("第%d号物品整个放入\n",flag[i]);
        }
        else
        {
            totalValue += p[flag[i]] * (double)c / (double) w[flag[i]];
            printf("第%d号物品放入了%f\n",flag[i],(double)c / (double) w[flag[i]]);
            break;
        }
    }
    printf("总价值为:%f",totalValue);
}

void backpack()
{
    int w[5] = {4,6,6,3,6};//每个物品的重量
    int v[5] = {1,1,1,2,1};//每个物品的价值
    double p[5] = {0,0,0,0,0};//每个物品的单位价值
    int flag[5]; //用于排序
    int n = 5; //物品的个数
    int c = 10; //背包能容的重量
    package_part(w,v,p,n,c,flag);
}