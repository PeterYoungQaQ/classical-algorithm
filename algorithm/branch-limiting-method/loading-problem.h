/**
 * @author: PeterYoung
 * @date: 2020/12/8 17:20
 * @description: װ�����⣬ʹ�÷�֧�޽編
 */

void loading_problem(){
    printf("�������α����");
}
/*
 * //�Ӻ���������ǰ��ڵ�������
void EnQueue(Queue<Type> &Q, Type wt, Type &bestw, int i, int n)
{
    if(i == n)     //����Ҷ���
    {
        if(wt>bestw) bestw = wt ;
    }
    else Q.Add(wt) ; //��Ҷ��㣬����������
}
Type MaxLoading(Type w[],Type c,int n){
    ��  //��ʼ������
    while (true) {  //������ռ���
      // �������ӽ��
      if (Ew + w[i] <= c) 		// x[i] = 1  �ж��Ƿ����װ�ϴ�
         EnQueue(Q, Ew + w[i], bestw, i, n); //��������뵽�������Q��
      // �Ҷ��ӽ�����ǿ��еģ�������뵽Q��
      EnQueue(Q, Ew, bestw, i, n); // x[i] = 0   ������ѡ��,�Һ����ǲ�ѡ,������������.
      Q.Delete(Ew);     		// ȡ��һ��չ���
      if (Ew == -1) {      		// ͬ����β��
         if (Q.IsEmpty())
	return bestw;
         Q.Add(-1);        		// ͬ����β����־
         Q.Delete(Ew);  		// ȡ��һ��չ���
         i++;}                 		// ������һ��
}
��
 //-------------------------------------------------------------------------------
// �㷨�ĸĽ�
 while(true)    {
        //��������
        Type wt=Ew+w[i];   //wtΪ����ӽڵ������
        if(wt<=c)   //��װ��֮�󲻳�������ɳ��ܷ�Χ
            if(wt>bestw) { //��������װ������
                bestw=wt;
                if(i<n) Q.Add(wt);    //���������ӵ�����
            }
        //���Ҷ�����ӵ�����
        if(Ew+r>bestw &&  i<n)
            Q.Add(Ew);   //���ܺ������Ž�
        Q.Delete(Ew);    //ȡ��һ���ڵ�Ϊ��չ�ڵ㲢������������Ew
        if(Ew==-1) {  //����Ƿ���ͬ�����
            if(Q.IsEmpty()) return bestw;    //������ϣ���������ֵ
            Q.Add(-1);    //��ӷֲ��־
            Q.Delete(Ew);    //ȡ��һ��չ���
            i++;
            r-=w[i];    //ʣ�༯װ������
        }
    }

*/