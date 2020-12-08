#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "algorithm/recursive-algorithm/divide-and-conquer-algorithm/mergequeue.h"
#include "algorithm/recursive-algorithm/divide-and-conquer-algorithm/speedqueue.h"
#include "algorithm/recursive-algorithm/divide-and-conquer-algorithm/rankselect.h"
#include "algorithm/recursive-algorithm/divide-and-conquer-algorithm/routedate.h"
#include "algorithm/recursive-algorithm/dynamic-planning/mulit-matrix.h"
#include "algorithm/recursive-algorithm/dynamic-planning/longest-common-subsequence.h"
#include "algorithm/recursive-algorithm/dynamic-planning/zero-one-knapsack-problem.h"
#include "algorithm/recursive-algorithm/dynamic-planning/optima-binary-search-tree.h"
#include "algorithm/greedy-algorithm/event-scheduling-issues.h"
#include "algorithm/greedy-algorithm/backpack-problem.h"
#include "algorithm/greedy-algorithm/single-source-shortest-paths.h"
#include "algorithm/backtracking-algorithm/container-loading-problem.h"
#include "algorithm/backtracking-algorithm/n-queen-problem.h"
#include "algorithm/branch-limiting-method/zero-one-bag.h"
#include "algorithm/branch-limiting-method/shortest-path-for-single-source.h"
#include "algorithm/branch-limiting-method/loading-problem.h"

int main() {
//---------------------------------------------------------------------------------
    /*�ݹ��㷨*/
    // 1.���η�
    // merge_queue(); // �ϲ�����
    // speedqueue(); // ��������
    // rankselect(); //����ʱ��ѡ������
    // routedate(); //ѭ�����ճ̱�����
    // 2.��̬�滮�㷨
    // multimatrix(); // ������������
    // LCS(); // ���������������
    // zero_one_bag(); // 0/1�������⣬ʹ�ö�̬�滮��
    // OBST(); // ���Ŷ��������
// --------------------------------------------------------------------------------
    /*̰���㷨*/
    // ESI(); // ���������
    // backpack(); // ��������
    // Dijkstra(); // ��̵�Դ·������
// --------------------------------------------------------------------------------
    /*�����㷨*/
    // CLP(); // װ������
    // nqueen(); // n�ʺ�����
//---------------------------------------------------------------------------------
    /*��֧�޽��㷨*/
    // bagbranch(); // 0/1�������⣬ʹ�÷�֧�޽編
    // SPFSS();    // ��Դ·��������⣬ʹ�÷�֧�޽編
    // loading_problem(); // װ�����⣬ʹ�÷�֧�޽編
    return 0;
}

