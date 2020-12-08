/**
 * @author: PeterYoung
 * @date: 2020/12/8 17:20
 * @description: 装载问题，使用分支限界法
 */

void loading_problem(){
    printf("看下面的伪代码");
}
/*
 * //子函数，将当前活节点加入队列
void EnQueue(Queue<Type> &Q, Type wt, Type &bestw, int i, int n)
{
    if(i == n)     //可行叶结点
    {
        if(wt>bestw) bestw = wt ;
    }
    else Q.Add(wt) ; //非叶结点，加入活结点队列
}
Type MaxLoading(Type w[],Type c,int n){
    …  //初始化数据
    while (true) {  //搜索解空间树
      // 检查左儿子结点
      if (Ew + w[i] <= c) 		// x[i] = 1  判断是否可以装上船
         EnQueue(Q, Ew + w[i], bestw, i, n); //将活结点加入到活结点队列Q中
      // 右儿子结点总是可行的，将其加入到Q中
      EnQueue(Q, Ew, bestw, i, n); // x[i] = 0   左孩子是选择,右孩子是不选,总有其它方案.
      Q.Delete(Ew);     		// 取下一扩展结点
      if (Ew == -1) {      		// 同层结点尾部
         if (Q.IsEmpty())
	return bestw;
         Q.Add(-1);        		// 同层结点尾部标志
         Q.Delete(Ew);  		// 取下一扩展结点
         i++;}                 		// 进入下一层
}
｝
 //-------------------------------------------------------------------------------
// 算法的改进
 while(true)    {
        //检查左儿子
        Type wt=Ew+w[i];   //wt为左儿子节点的重量
        if(wt<=c)   //若装载之后不超过船体可承受范围
            if(wt>bestw) { //更新最优装载重量
                bestw=wt;
                if(i<n) Q.Add(wt);    //将左儿子添加到队列
            }
        //将右儿子添加到队列
        if(Ew+r>bestw &&  i<n)
            Q.Add(Ew);   //可能含有最优解
        Q.Delete(Ew);    //取下一个节点为扩展节点并将重量保存在Ew
        if(Ew==-1) {  //检查是否到了同层结束
            if(Q.IsEmpty()) return bestw;    //遍历完毕，返回最优值
            Q.Add(-1);    //添加分层标志
            Q.Delete(Ew);    //取下一扩展结点
            i++;
            r-=w[i];    //剩余集装箱重量
        }
    }

*/