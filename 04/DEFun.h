/**
 * @ 文件名: DEFun.h
 * @ 功能: 声明与DEFun有关的函数与常量
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
 * @ 函数: RFunToDat(int seed,char* name,int N)
 *
 * @ 功能: 产生满足根式概率函数的随机数并打印到文件
 *
 * @ param{seed}: 种子
 *
 * @ param{name}:打印文件名
 *
 * @ param{N}:个数
 *
 * @ 返回值: 成功1，失败0
 */
int RFunToDat(int seed,char* name,int N);

/**
 * @ 函数: LFunToDat(int seed,char* name,int N)
 *
 * @ 功能: 产生满足Lorentz概率函数的随机数并打印到文件
 *
 * @ param{seed}: 种子
 *
 * @ param{m}: 函数参数m
 *
 * @ param{name}: 打印文件名
 *
 * @ param{N}: 个数
 *
 * @ 返回值: 成功1，失败0
 */
int LFunToDat(int seed,double m, char* name, int N);

#pragma endregion