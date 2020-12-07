/**
 * @author: PeterYoung
 * @date: 2020/12/7 10:15
 * @description: ���Ŷ��������
 */

int MaxVal = 9999;


//���������ڵ��������ĸ���
double p1[6] = {0,0.15,0.1,0.05,0.1,0.2};
double q1[6] = {0.05,0.1,0.05,0.05,0.05,0.1};

int root[7][7];//��¼���ڵ�
double w[8][8];//���������ܺ�
double e[8][8];//������������

void optimalBST(double *p,double *q,int n)
{
    //��ʼ��ֻ���������������
    for (int i = 1;i <= n + 1;++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //���µ��ϣ��������𲽼���
    for (int len = 1;len <= n;++len)
    {
        for (int i = 1;i <= n - len + 1;++i)
        {
            int j = i + len - 1;
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //��ȡ��С���۵������ĸ�
            for (int k = i;k <= j;++k)
            {
                double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (temp < e[i][j])
                {
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }
}

//������Ŷ�����������������ĸ�
void printRoot()
{
    printf("�������ĸ���\n");
    for (int i = 1;i <= 5;++i)
    {
        for (int j = 1;j <= 5;++j)
        {
            printf("%d",root[i][j]);
            if (j == 5){
                printf("\n");
            }
        }
    }
}

//��ӡ���Ŷ���������Ľṹ
//��ӡ��[i,j]���������Ǹ�r����������������
void printOptimalBST(int i,int j,int r)
{
    int rootChild = root[i][j];//�������ڵ�
    if (rootChild == root[1][5])
    {
        //����������ĸ�
        printf("%d ������ ",rootChild);
        printOptimalBST(i,rootChild - 1,rootChild);
        printOptimalBST(rootChild + 1,j,rootChild);
        return;
    }

    if (j < i - 1)
    {
        return;
    }
    else if (j == i - 1)//���������
    {
        if (j < r)
        {
            printf(" %d �� %d ������",j,r);
        }
        else
            printf(" %d �� %d ���Һ���",j,r);
        return;
    }
    else//�����ڲ����
    {
        if (rootChild < r)
        {
            printf("%d �� %d ������",rootChild,r);
        }
        else
            printf("%d �� %d ���Һ���",rootChild,r);
    }

    printOptimalBST(i,rootChild - 1,rootChild);
    printOptimalBST(rootChild + 1,j,rootChild);
}

void OBST()
{
    optimalBST(p1,q1,5);
    printRoot();
    printf("���Ŷ������ṹ�� ");
    printOptimalBST(1,5,-1);
}


