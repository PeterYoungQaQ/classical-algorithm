/**
 * @author: PeterYoung
 * @date: 2020/12/7 9:49
 * @description: 0/1��������
 */


int V[100][100];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ

int max(int a,int b){
    if(a>=b)
        return a;
    else return b;
}

int KnapSack(int n,int weight[],int value[],int C){

    //���,���е�һ�к͵�һ��ȫΪ0,�� V(i,0)=V(0,j)=0��
    for(int i=0;i<=n;i++)
        V[i][0]=0;
    for(int j=0;j<=C;j++)
        V[0][j]=0;
    //�õ��ľ��󲿷�V[n][C] ,��������в������ ��1�к͵�1��

    printf("��� ���� ��ֵ  ");  //�˵��� 1
    for(int i=1;i<=C;i++)
        printf(" %2d ",i);
    printf("\n\n");

    for(int i=1;i<=n;i++){
        printf("%2d   %2d   %2d     ",i,weight[i-1],value[i-1]);  //�˵��� 2 (weight��value���Ǵ�0��ʼ��ģ����Կ�ʼi=1ʱ��Ӧ0��λ��)

        for(int j=1;j<=C;j++){
            if(j<weight[i-1]){  //���������ȸ���Ʒ���С��װ���£���ʱ�ļ�ֵ��ǰi-1���ļ�ֵ��һ����
                V[i][j]=V[i-1][j];
                printf("%2d  ",V[i][j]);
            }
            else{  //�����㹻����������װ����Ʒ����װ��Ҳ��һ���ﵽ��ǰ���ż�ֵ��������װ�벻װ֮��ѡ�����ŵ�һ��
                V[i][j]=max(V[i-1][j],V[i-1][j-weight[i-1]]+value[i-1]);
                printf("%2d  ",V[i][j]);
            }
        }
        printf("\n");
    }

    return V[n][C];

}

void Judge(int C,int n,const int weight[]){	//�ж���Щ��Ʒ��ѡ��
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));

    for(int i=n;i>=1;i--){
        if(V[i][j]>V[i-1][j]){  //���װ�˾ͱ�ǣ�Ȼ���ȥ��Ӧ����
            state[i]=1;
            j=j-weight[i-1];
        }
        else
            state[i]=0;
    }
    printf("ѡ�е���Ʒ��:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
            printf("%d ",i);
    printf("\n");
}

void zero_one_bag(){

    int n;        //��Ʒ����
    int Capacity;//�����������

    printf("�����뱳�����������:");
    scanf("%d",&Capacity);

    printf("������Ʒ��:");
    scanf("%d",&n);

    int *weight=(int *)malloc(n*sizeof(int));//��Ʒ������
    int *value=(int *)malloc(n*sizeof(int)); //��Ʒ�ļ�ֵ


    printf("��ֱ�������Ʒ������:");
    for(int i=0;i<n;i++)
        scanf("%d",&weight[i]);

    printf("��ֱ�������Ʒ�ļ�ֵ:");
    for(int i=0;i<n;i++)
        scanf("%d",&value[i]);

    int s=KnapSack(n,weight,value,Capacity);  //��õ�����ֵ

    Judge(Capacity,n,weight);  //�ж���Щ��Ʒ��ѡ��

    printf("�����Ʒ��ֵΪ: ");
    printf("%d\n",s);

}
