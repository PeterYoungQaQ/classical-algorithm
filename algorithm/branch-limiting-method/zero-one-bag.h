/**
 * @author: PeterYoung
 * @date: 2020/12/8 16:21
 * @description: 0-1�������⣬ʹ�÷�֧�޽編
 */


/*���������α��������ʾ*/

/*
 // �Ͻ纯��
 // n��ʾ��Ʒ������cleftΪʣ��ռ�
    while (i <= n && w[i] <= cleft){
        cleft -= w[i];                            //w[i]��ʾi��ռ�ռ�
        b += p[i];                                 //p[i]��ʾi�ļ�ֵ
        i++;
        }
    if (i <= n) b+=p[i]/w[i] * cleft;    // װ��ʣ������װ������
    return b;                            // bΪ�Ͻ纯��
*/

/*
 * while (i != n+1) { // ��Ҷ���
      // ��鵱ǰ��չ��������ӽ��
      Typew wt = cw + w[i];
      if (wt <= c) { // ����ӽ��Ϊ���н��
         if (cp+p[i] > bestp) bestp = cp+p[i];
         AddLiveNode(up, cp+p[i], cw+w[i], true, i+1);}
         up = Bound(i+1);
      // ��鵱ǰ��չ�����Ҷ��ӽ��
      if (up >= bestp) // ���������ܺ����Ž�
           AddLiveNode(up, cp, cw, false, i+1);
         //   ȡ��һ����չ��㣨�ԣ�}
*/

void bagbranch(){
    printf("���Ϸ�α����");
}