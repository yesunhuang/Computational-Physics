/**
 * @ 文件名: Marsaglia.h
 * @ 功能: 声明与Sphere有关的函数与常量
 * @ 作者: YesunHuang,黄阅迅,PB18020631
 * @ 邮箱: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ 日期: 2020年9月29日
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
 * @ 函数:MRandNToDat(int seed,int N, char* name)
 *
 * @ 功能:生成平面投影随机数 
 *
 * @ param{seed}:种子
 *
 * @ param{N}:个数
 *
 * @ param{name}:文件名
 *
 * @ 返回值: 成功1，失败0
 */
int MRandNToDat(int seed, int N, char* name);

#pragma endregion

