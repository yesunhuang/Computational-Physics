/**
 * @ 文件名: Sphere.h
 * @ 功能: 声明与Sphere有关的函数与常量
 * @ 作者: YesunHuang,黄阅迅,PB18020631
 * @ 邮箱: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ 日期: 2020年9月28日
 * 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 */

#pragma once



#pragma region 宏定义区
 //以下为各类常数及操作符
#define M_PI 3.14159265358979323846
#pragma endregion

#pragma region 头文件区
#include "Schrage16807.h"
#pragma endregion

#pragma region 函数声明
/**
 * @ 函数:SRandNToDat(int seed, double rho, double N, char* name)
 *
 * @ 功能:生成球面随机数 
 *
 * @ param{seed}:种子数组,[seed1,seed2]
 *
 * @ param{rho}:半径
 *
 * @ param{N}:个数
 *
 * @ param{name}:文件名
 *
 * @ 返回值: 成功1，失败0
 */
int SRandNToDat(int seed, double rho, int N, char* name);

/**
 * @ 函数:NSRandNToDat(int* seed, double rho, double N, char* name)
 *
 * @ 功能:用一种比较蠢的方法生成球面随机数
 *
 * @ param{seed}:种子数组[seed1,seed2,seed3]
 *
 * @ param{rho}:半径
 *
 * @ param{N}:个数
 *
 * @ param{name}:文件名
 *
 * @ 返回值: 成功1，失败0
 */
int NSRandNToDat(int seed, double rho, int N, char* name);

#pragma endregion

