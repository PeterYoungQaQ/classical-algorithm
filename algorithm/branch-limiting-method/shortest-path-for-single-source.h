/**
 * @author: PeterYoung
 * @date: 2020/12/8 17:01
 * @description: ��Դ���·�����⣬ʹ�÷�֧�޽編��ʵ��
 */
void SPFSS(){
    printf("���±ߵ�α����");
}

/*�����㷨������
    dist:��̾�������
    prev: ǰ����������
    E����ǰ����չ�ڵ�
    C:  �ڽӾ���
    H�� ��ڵ����ȶ���
while (true) {  //whileѭ������ɶԽ�ռ��ڲ�������չ
     for (int j = 1; j <= n; j++)
       if ((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])) { // ����i��j���бߣ��Ҵ�·����С��ԭ�ȴ�Դ�㵽j��·����
         // ����i������j�ɴ���������Լ��
         dist[j]=E.length+c[E.i][j]; //����dist��¼��Դ������ľ���
         prev[j]=E.i;  //����prev��¼��Դ���������·���ϵ�ǰ������
         // ����������ȶ���
         MinHeapNode<Type> N;
         N.i=j;
         N.length=dist[j];
         H.Insert(N);}
     try {H.DeleteMin(E);}         // ȡ��һ��չ���
     catch (OutOfBounds) {break;}  // ���ȶ��п�
     }
} */