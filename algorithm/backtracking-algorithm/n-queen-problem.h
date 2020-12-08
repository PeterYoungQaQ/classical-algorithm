/**
 * @author: PeterYoung
 * @date: 2020/12/8 13:55
 * @description: n皇后问题
*/

 /* 问题分析
问题的解向量：(x1, x2, … , xn)
采用数组下标 i 表示皇后所在的行号
采用数组元素x[i]表示皇后 i 的列号
思考：采用哪种解空间树？ --排列树
提示：这是排列问题还是子集问题？
-------------------------------------------
剪枝函数
显约束（对解向量的直接约束）：xi =1, 2, … , n
隐约束1：任意两个皇后不同列 ：xi ≠ xj
隐约束2：任意两个皇后不处于同一对角线？
|i-j| ≠ |xi - xj|
*/

#define n 4
bool hash[n+1];
int p[n+1];
int count =0;

 void Generatep(int index)
 {
     //递归边界，生成一个合法方案
     if(index == n +1)
     {
         count++;
         for(int k = 1; k <= n; k++)
         {
             printf("%d ",p[k]);
         }
         printf("\n");
         return ;
     }
     //第ｘ行
     for(int x =1; x <=n; x++)
     {
         //第ｘ行还没有皇后
         if(hash[x] == false)
         {
             bool flag = true;//表示当前的皇后不会和之前的皇后冲突
             for(int pre =1; pre < index; pre++)//遍历之前的皇后
             {
                 if(abs(index - pre) == abs(x - p[pre]))
                 {
                     flag = false;
                     break;
                 }
             }
             //如果可以把皇后放在第ｘ行
             if(flag)
             {
                 //令第index列的皇后的行号为ｘ
                 p[index] = x;
                 //表示第ｘ行已被占用
                 hash[x] = true;
                 //递归处理第index+1　列皇后
                 Generatep(index+1);
                 //递归完毕后，还原第ｘ行为未占有
                 hash[x] = false;
             }
         }
     }
 }

 void nqueen(){
     for(int m =0; m <=8; m++)
     {
         hash[m] = false;
     }

     Generatep(1);
     printf("%d\n",count);
 }


