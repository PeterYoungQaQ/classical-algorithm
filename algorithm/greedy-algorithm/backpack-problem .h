/**
 * @author: PeterYoung
 * @date: 2020/12/7 16:48
 * @description: ��������
 * �������������̰���㷨��⣬��0-1��������ȴ������̰���㷨��⣡
 */


void package_part(int *w,int *v,double *p,int n,int c,int *flag)
{
    int i,j,temp;
    double tempD,totalValue = 0.0;

    //���㵥��
    for(i=0;i<n;i++)
    {
        p[i] = (double)v[i] / (double)w[i];
        flag[i] = i;
    }
    //���ݵ�������,flag���鱣����Ʒ���±�
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
    //̰�ķ��ó�Ӧ��װ�����Ʒ
    for(i=0;i<n;i++)
    {
        if(c >= w[flag[i]])
        {
            totalValue += v[flag[i]];
            c -= w[flag[i]];
            printf("��%d����Ʒ��������\n",flag[i]);
        }
        else
        {
            totalValue += p[flag[i]] * (double)c / (double) w[flag[i]];
            printf("��%d����Ʒ������%f\n",flag[i],(double)c / (double) w[flag[i]]);
            break;
        }
    }
    printf("�ܼ�ֵΪ:%f",totalValue);
}

void backpack()
{
    int w[5] = {4,6,6,3,6};//ÿ����Ʒ������
    int v[5] = {1,1,1,2,1};//ÿ����Ʒ�ļ�ֵ
    double p[5] = {0,0,0,0,0};//ÿ����Ʒ�ĵ�λ��ֵ
    int flag[5]; //��������
    int n = 5; //��Ʒ�ĸ���
    int c = 10; //�������ݵ�����
    package_part(w,v,p,n,c,flag);
}