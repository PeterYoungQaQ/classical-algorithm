/**
 * @author: PeterYoung
 * @date: 2020/12/7 16:07
 * @description: ���������
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
*  s[]����Ŀ�ʼʱ��
*  f[]:��Ľ���ʱ�䣨�ǽ������У�
*  a[]:0����1��Ϊ0��ʾ��������ţ�1��ʾ�������
*  k:�����
*/

void greedy(int s[],int f[],int a[],int k)
{
    int i;
    int j = 0;
    for(i=0;i<k;i++)
    {
        a[i] = 0;//��ʼ���л��δ������
    }
    a[0] = 1;
    printf("��1���������\n");
    int count = 1;
    for(i=1;i<k;i++)
    {
        if(s[i] > f[j])
        {
            a[i] = 1;
            printf("��ʼ%d,����%d.",s[i],f[i]);
            j = i;
            count++;
            printf("��%d���������\n",i+1);
        }
    }
    printf("�ܼ�%d���������\n",count);
}