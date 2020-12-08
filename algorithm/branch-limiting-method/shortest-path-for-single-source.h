/**
 * @author: PeterYoung
 * @date: 2020/12/8 17:01
 * @description: 单源最短路径问题，使用分支限界法来实现
 */
void SPFSS(){
    printf("看下边的伪代码");
}

/*搜索算法描述：
    dist:最短距离数组
    prev: 前驱顶点数组
    E：当前的扩展节点
    C:  邻接矩阵
    H： 活节点优先队列
while (true) {  //while循环体完成对解空间内部结点的扩展
     for (int j = 1; j <= n; j++)
       if ((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])) { // 顶点i和j间有边，且此路径长小于原先从源点到j的路径长
         // 顶点i到顶点j可达，且满足控制约束
         dist[j]=E.length+c[E.i][j]; //数组dist记录从源到顶点的距离
         prev[j]=E.i;  //数组prev记录从源到各顶点的路径上的前驱顶点
         // 加入活结点优先队列
         MinHeapNode<Type> N;
         N.i=j;
         N.length=dist[j];
         H.Insert(N);}
     try {H.DeleteMin(E);}         // 取下一扩展结点
     catch (OutOfBounds) {break;}  // 优先队列空
     }
} */