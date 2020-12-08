/**
 * @author: PeterYoung
 * @date: 2020/12/8 16:21
 * @description: 0-1背包问题，使用分支限界法
 */


/*这个部分用伪代码来表示*/

/*
 // 上界函数
 // n表示物品总数，cleft为剩余空间
    while (i <= n && w[i] <= cleft){
        cleft -= w[i];                            //w[i]表示i所占空间
        b += p[i];                                 //p[i]表示i的价值
        i++;
        }
    if (i <= n) b+=p[i]/w[i] * cleft;    // 装填剩余容量装满背包
    return b;                            // b为上界函数
*/

/*
 * while (i != n+1) { // 非叶结点
      // 检查当前扩展结点的左儿子结点
      Typew wt = cw + w[i];
      if (wt <= c) { // 左儿子结点为可行结点
         if (cp+p[i] > bestp) bestp = cp+p[i];
         AddLiveNode(up, cp+p[i], cw+w[i], true, i+1);}
         up = Bound(i+1);
      // 检查当前扩展结点的右儿子结点
      if (up >= bestp) // 右子树可能含最优解
           AddLiveNode(up, cp, cw, false, i+1);
         //   取下一个扩展结点（略）}
*/

void bagbranch(){
    printf("看上方伪代码");
}