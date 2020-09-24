/**
 * @ 文件名: Fibonacci.h
 * @ 功能: 声明与Fibonaccii有关的函数与常量
 * @ 作者: YesunHuang,黄阅迅,PB18020631
 * @ 邮箱: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ 日期: 2020年9月24日
 * 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 */

#pragma once

#pragma region 头文件区
#include "Schrage16807.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define OTimes +
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#pragma endregion

#pragma region 函数声明

//以下为各种函数声明
/**
 * @ 函数: int Fibonacci(int* cache, int q, int p)
 *
 * @ 功能: 返回Fibonacci数列的下一个数
 *
 * @ param{cache}:用于生成下一个数的缓存数组
 *
 * @ param{n}:当前序号
 *
 * @ param{q}:延迟量
 *
 * @ param{p}:延迟量
 *
 * @ 返回值: 下一个数
 */
int Fibonacci(int* cache, int n, int q, int p);

/**
 * @ 函数: int FibRandNToDat(int seed, double* range, int N, char* name,int p,int q)
 *
 * @ 功能: 生成一定量的Fibonacci伪随机数列并打印到dat里
 *
 * @ param{seed}: 种子
 *
 * @ param{range}: 范围
 *
 * @ param{N}: 总个数
 *
 * @ param{name}: 输出文件名
 *
 * @ param{p}: 延迟量
 *
 * @ param{q}: 延迟量
 *
 * @ 返回值: 成功1，失败0
 */
int FibRandNToDat(int seed, double* range, int N, char* name,int p,int q);

/**
 * @ 函数: ReadAndCalScale(char* name, int N)
 *
 * @ 功能: 从dat里计算符合x<y<z的数的比例；
 *
 * @ param{N}: 总个数
 *
 * @ param{name}: 读入文件名
 *
 * @ 返回值: 成功1，失败0
 */
double ReadAndCalScale(char* name, int N);
#pragma endregion
