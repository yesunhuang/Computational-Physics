/*
 * @Name: MarkovH.h
 * @Desriptption: 声明MarkovH.c里的所有内容
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-11-24 23:58:52
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
 * @name: MetroH(char* name,double* initial,int m,int N,double delta,int seed);
 * @fuction: 进行Metropolis法的模拟，并把Markov数据存在name文件里
 * @param {name}:存储文件名
 * @param {r}:点值数值，里面会存初始点，输出时是最后的状态
 * @param {n}:跟踪点的数量
 * @param {m}:预热步数
 * @param {N}:净步数
 * @param {delta}:位移量
 * @param {seed}:种子
 * @return {double*}:数组，{<x^2>,<y^2>,<x^2+y^2>,eta}
 */
double* MetroH(char* name,double (*r)[2],int n,int m,int N,double delta,int seed);
#pragma endregion

