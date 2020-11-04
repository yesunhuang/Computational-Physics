/*
 * @Name: SquarePerco.h
 * @Desriptption: 实现方格渗透的蒙特卡洛模拟
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-11-04 10:50:43
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#pragma endregion

#pragma region 函数声明
/**
 * @name: MontePerco(double p,int seed,int N)
 * @fuction: 蒙特卡洛模拟渗透过程
 * @param {p}: 方格标记概率
 * @param {seed}: 种子
 * @param {N}: 图点边长
 * @return {int**}: 标记数组
 */
int** MontePerco(double p,int seed,int N);

/**
 * @name:CalCluster(int** map,int N)
 * @fuction: 标记和计算团块大小
 * @param {map}: 标记地图
 * @param {char*}: 输出文件名
 * @param {N}: 图点边长
 * @return {int**}: 团块地图
 */
int** CalClusterToDat(int** map,char* name,int N); 

/**
 * @name:dfs(int** clusterMap,int x,int y)
 * @fuction: 深搜找团块
 * @param {clusterMap}: 团块地图
 * @param {map}: 标记地图
 * @param {N}: 图点边长
 * @param {x}: x坐标
 * @param {y}: y坐标
 * @return {int}:成功1，失败0
 */
int dfs(int** clusterMap,int** map,int x,int y,int N);

#pragma endregion
