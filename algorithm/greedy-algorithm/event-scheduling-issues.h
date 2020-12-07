/**
 * @author: PeterYoung
 * @date: 2020/12/7 16:07
 * @description: 活动安排问题
 */


void greedy(int s[],int f[],int a[],int k);

void ESI()
{

    int s[] = {1,3,0,5,3,5,6,8,8,2,12};
    int f[] = {4,5,6,7,8,9,10,11,12,13,14};
    int k;
    k = sizeof(f)/sizeof(f[0]);
    int *a;
    a = (int*)malloc(sizeof(int)*k);

    greedy(s,f,a,k);
    system("PAUSE");

}

/*
*  s[]：活动的开始时间
*  f[]:活动的结束时间（非降序排列）
*  a[]:0或者1，为0表示活动不被安排，1表示活动被安排
*  k:活动个数
*/

void greedy(int s[],int f[],int a[],int k)
{
    int i;
    int j = 0;
    for(i=0;i<k;i++)
    {
        a[i] = 0;//初始所有活动都未被安排
    }
    a[0] = 1;
    printf("第1个活动被安排\n");
    int count = 1;
    for(i=1;i<k;i++)
    {
        if(s[i] > f[j])
        {
            a[i] = 1;
            printf("开始%d,结束%d.",s[i],f[i]);
            j = i;
            count++;
            printf("第%d个活动被安排\n",i+1);
        }
    }
    printf("总计%d个活动被安排\n",count);
}