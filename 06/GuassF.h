/**
 * @ 文件名: GuassF.h
 * @ 功能: 声明与GuassFunction有关的函数与常量
 * @ 作者: YesunHuang,黄阅迅,PB18020631
 * @ 邮箱: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ 日期: 2020年9月30日
 * 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 */

#pragma once

#pragma region 头文件区
#include "Schrage16807.h"
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define G_Atol 1E-5
#pragma endregion

#pragma region 函数声明

/**
 * @ 函数: GRandNToDat(int seed, int* range, int N)
 *
 * @ 功能: 产生多个Guass随机数,并print到文件里
 *
 * @ param{seed}: 种子
 *
 * @ param{N}: 总个数
 *
 * @ param{name}: 输出文件名
 *
 * @ 返回值: 成功为总抽样数，失败为0
 */
int GRandNToDat(int seed,  int N, char* name);

/**
 * @ 函数: LorentzF(double x)
 *
 * @ 功能: 洛伦兹型F的直接抽样累积
 *
 * @ param{x}: 自变量
 *
 * @ 返回值: 函数值
 */
double LorentzF(double x);

#pragma endregion


