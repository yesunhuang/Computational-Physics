/**
 * @ 文件名: Schrage16807.h
 * @ 功能: 声明与Schrage有关的函数与常量
 * @ 作者: YesunHuang,黄阅迅,PB18020631
 * @ 邮箱: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ 日期: 2020年9月22日
 * 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 */

#pragma once

#pragma region 头文件区
#include "malloc.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#pragma endregion

#pragma region 宏定义区
//以下为各类常数及操作符
#define M_16807 2147483647 
#define A_16807 16807	
#define R_16807 2836
#define Q_16807 127773
#pragma endregion

#pragma region 函数声明
/**
 * @ 函数: int Shrage(int seed)
 *
 * @ 功能: Shrage生产随机数
 *
 * @ param{seed}: 种子
 *
 * @ 返回值: 下一个随机数
 */
int Shrage(int seed);

/**
 * @ 函数: double* RandN(int seed, int* range)
 *
 * @ 功能: 产生多个随机数
 *
 * @ param{seed}: 种子
 *
 * @ param{range}: 范围
 *
 * @ param{N}: 总个数
 *
 * @ 返回值: 包含多个随机数的数组,所以记得free啊
 */
double* RandN(int seed, double* range,int N);

/**
 * @ 函数: int Seed()
 *
 * @ 功能: 利用日期产生种子
 *
 * @ 返回值: 种子
 */
int Seed();

/**
 * @ 函数: RandNToDat(int seed, int* range, int N)
 *
 * @ 功能: 产生多个随机数,并print到文件里
 *
 * @ param{seed}: 种子
 *
 * @ param{range}: 范围
 *
 * @ param{N}: 总个数
 *
 * @ param{name}: 输出文件名
 *
 * @ 返回值: 成功1，失败0
 */
int RandNToDat(int seed, double* range, int N,char* name);

/**
 * @ 函数: ReadAndCalAvg(char* name, int k)
 *
 * @ 功能: 从dat中读入数据并计算<x^k>
 *
 * @ param{name}:文件名
 *
 * @ param{k}: 阶次
 *
 * @ param{N}: 总个数
 *
 * @ 返回值: 计算值
 */
double ReadAndCalAvg(char* name, int k,int N);

/**
 * @ 函数: ReadAndCalCorr(char* name,int k,int N)
 *
 * @ 功能: 从dat中读入数据并计算C(l)
 *
 * @ param{name}:文件名
 *
 * @ param{l}: 阶次
 *
 * @ param{N}: 总个数
 *
 * @ 返回值: 计算值
 */
double ReadAndCalCorr(char* name, int l, int N);

/**
 * @ 函数: RecurrentIndex(int maxIndex, int rawIndex)
 *
 * @ 功能: 计算循环数组索引
 *
 * @ param{maxIndex}:最大索引
 *
 * @ param{rawIndex}:原始索引 
 *
 * @ 返回值: 合法索引。
 */
int RecurrentIndex(int length, int rawIndex);


#pragma endregion
