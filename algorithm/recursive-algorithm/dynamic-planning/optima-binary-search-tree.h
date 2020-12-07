/**
 * @author: PeterYoung
 * @date: 2020/12/7 10:15
 * @description: 最优二叉查找树
 */

int MaxVal = 9999;


//搜索到根节点和虚拟键的概率
double p1[6] = {0,0.15,0.1,0.05,0.1,0.2};
double q1[6] = {0.05,0.1,0.05,0.05,0.05,0.1};

int root[7][7];//记录根节点
double w[8][8];//子树概率总和
double e[8][8];//子树期望代价

void optimalBST(double *p,double *q,int n)
{
    //初始化只包括虚拟键的子树
    for (int i = 1;i <= n + 1;++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //由下到上，由左到右逐步计算
    for (int len = 1;len <= n;++len)
    {
        for (int i = 1;i <= n - len + 1;++i)
        {
            int j = i + len - 1;
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //求取最小代价的子树的根
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

//输出最优二叉查找树所有子树的根
void printRoot()
{
    printf("各子树的根：\n");
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

//打印最优二叉查找树的结构
//打印出[i,j]子树，它是根r的左子树和右子树
void printOptimalBST(int i,int j,int r)
{
    int rootChild = root[i][j];//子树根节点
    if (rootChild == root[1][5])
    {
        //输出整棵树的根
        printf("%d 是主根 ",rootChild);
        printOptimalBST(i,rootChild - 1,rootChild);
        printOptimalBST(rootChild + 1,j,rootChild);
        return;
    }

    if (j < i - 1)
    {
        return;
    }
    else if (j == i - 1)//遇到虚拟键
    {
        if (j < r)
        {
            printf(" %d 是 %d 的左孩子",j,r);
        }
        else
            printf(" %d 是 %d 的右孩子",j,r);
        return;
    }
    else//遇到内部结点
    {
        if (rootChild < r)
        {
            printf("%d 是 %d 的左孩子",rootChild,r);
        }
        else
            printf("%d 是 %d 的右孩子",rootChild,r);
    }

    printOptimalBST(i,rootChild - 1,rootChild);
    printOptimalBST(rootChild + 1,j,rootChild);
}

void OBST()
{
    optimalBST(p1,q1,5);
    printRoot();
    printf("最优二叉树结构： ");
    printOptimalBST(1,5,-1);
}


