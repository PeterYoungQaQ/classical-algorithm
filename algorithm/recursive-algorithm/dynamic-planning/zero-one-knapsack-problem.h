/**
 * @author: PeterYoung
 * @date: 2020/12/7 9:49
 * @description: 0/1背包问题
 */


int V[100][100];//前i个物品装入容量为j的背包中获得的最大价值

int max(int a,int b){
    if(a>=b)
        return a;
    else return b;
}

int KnapSack(int n,int weight[],int value[],int C){

    //填表,其中第一行和第一列全为0,即 V(i,0)=V(0,j)=0；
    for(int i=0;i<=n;i++)
        V[i][0]=0;
    for(int j=0;j<=C;j++)
        V[0][j]=0;
    //用到的矩阵部分V[n][C] ,下面输出中并不输出 第1行和第1列

    printf("编号 重量 价值  ");  //菜单栏 1
    for(int i=1;i<=C;i++)
        printf(" %2d ",i);
    printf("\n\n");

    for(int i=1;i<=n;i++){
        printf("%2d   %2d   %2d     ",i,weight[i-1],value[i-1]);  //菜单栏 2 (weight与value都是从0开始存的，所以开始i=1时对应0的位置)

        for(int j=1;j<=C;j++){
            if(j<weight[i-1]){  //包的容量比该商品体积小，装不下，此时的价值与前i-1个的价值是一样的
                V[i][j]=V[i-1][j];
                printf("%2d  ",V[i][j]);
            }
            else{  //还有足够的容量可以装该商品，但装了也不一定达到当前最优价值，所以在装与不装之间选择最优的一个
                V[i][j]=max(V[i-1][j],V[i-1][j-weight[i-1]]+value[i-1]);
                printf("%2d  ",V[i][j]);
            }
        }
        printf("\n");
    }

    return V[n][C];

}

void Judge(int C,int n,const int weight[]){	//判断哪些物品被选中
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));

    for(int i=n;i>=1;i--){
        if(V[i][j]>V[i-1][j]){  //如果装了就标记，然后减去相应容量
            state[i]=1;
            j=j-weight[i-1];
        }
        else
            state[i]=0;
    }
    printf("选中的物品是:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
            printf("%d ",i);
    printf("\n");
}

void zero_one_bag(){

    int n;        //物品数量
    int Capacity;//背包最大容量

    printf("请输入背包的最大容量:");
    scanf("%d",&Capacity);

    printf("输入物品数:");
    scanf("%d",&n);

    int *weight=(int *)malloc(n*sizeof(int));//物品的重量
    int *value=(int *)malloc(n*sizeof(int)); //物品的价值


    printf("请分别输入物品的重量:");
    for(int i=0;i<n;i++)
        scanf("%d",&weight[i]);

    printf("请分别输入物品的价值:");
    for(int i=0;i<n;i++)
        scanf("%d",&value[i]);

    int s=KnapSack(n,weight,value,Capacity);  //获得的最大价值

    Judge(Capacity,n,weight);  //判断那些物品被选择

    printf("最大物品价值为: ");
    printf("%d\n",s);

}
