/**
 * @ 文件名: SciLib.h
 * @ 功能: 声明与常用科学库与函数有关的函数与常量，合并了Schrage 与SciLib,
 * 并且修正了之前拼错的函数名称
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
#include "math.h"
#include "malloc.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-9
#define M_16807 2147483647 
#define A_16807 16807	
#define R_16807 2836
#define Q_16807 127773
#pragma endregion

#pragma region 函数声明
/**
 * @name: Factorial(int n)
 * @fuction: 求阶乘
 * @param {n}: 阶乘值数 
 * @return {int}: 阶乘值 
 */
int Factorial(int n);

/**
 * @name: Permu(int n,int k)
 * @fuction: 求排列数
 * @param {n}: 物件数
 * @param {k}: 要求排列个数 
 * @return {int}: 排列数
 */
int Permu(int n,int k);

/**
 * @name: Combin(int n,int k)
 * @fuction: 求组合数
 * @param {n}: 物件数
 * @param {k}: 要求组合个数 
 * @return {int}: 组合数
 */
int Combin(int n,int k);

/**
 * @ 函数: int Schrage(int seed)
 *
 * @ 功能: Schrage生产随机数
 *
 * @ param{seed}: 种子
 *
 * @ 返回值: 下一个随机数
 */
int Schrage(int seed);

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

/**
 * @ 函数: ArcFun(double (*f)(double x), double fx, double* range, double rtol)
 *
 * @ 功能: 二分法计算反函数
 *
 * @ param{f}:函数指针
 *
 * @ param{fx}:函数值
 *
 * @ param{range}:[start,end]，二分范围，null为实数域
 *
 * @ param{atol}:绝对误差
 *
 * @ 返回值: 反函数值,失败nan
 */
double ArcFun(double (*f)(double x), double fx,double* range, double atol);

/**
 * @name: BinarySearch(double* arr,double key,double len)
 * @fuction: 二分法查值
 * @param {arr}: 输入数组 
 * @param {key}: 查找目标
 * @param {len}:数组长度
 * @return {int}: 目标键值 
 */
int BinarySearch(double* arr,double key,double len);

/**
 * @name: ConDirectSamToDat(double* SigmaPi,char* name,int N)
 * @fuction: 对连续点直接抽样
 * @param {(*Arcf)(double xi)}:反函数
 * @param {name}:输出文件名
 * @param {N}:抽样个数
 * @return {int}:成功1，失败0 
 */
int ConDirectSamToDat(double (*Arcf)(double xi),char* name,int N);

/**
 * @name: ConDirectSam(double* SigmaPi,char* name,int N)
 * @fuction: 对连续点直接抽样
 * @param {(*Arcf)(double xi)}:反函数
 * @param {N}:抽样个数
 * @param {seed}:种子
 * @return {double*}:包含抽样的double数组，请记得free
 */
double* ConDirectSam(double (*Arcf)(double xi),int N,int seed);

/**
 * @name: DirectSamToDat(double* SigmaPi,char* name,int Num,int N)
 * @fuction: 对离散点直接抽样
 * @param {SigmaP}:预处理概率累加数组
 * @param {name}:输出文件名
 * @param {Num}:离散点个数
 * @param {N}:抽样个数
 * @return {int}:成功1，失败0 
 */
int DisDirectSamToDat(double* SigmaP,char* name,int Num,int N);

/**
 * @name: DirectSamToDat(double* SigmaPi,int N)
 * @fuction: 对离散点直接抽样
 * @param {SigmaP}:预处理概率累加数组
 * @param {Num}:离散点个数
 * @param {N}:抽样个数
 * @return {int*}:包含抽样的数组，记得free 
 */
int* DisDirectSam(double* SigmaP,int Num,int N,int seed);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N) 
 * @fuction: 比较法抽样
 * @param {(*Arcf)(double xi_1)}:比较函数的反函数指针
 * @param {(*IsLegal)(double x,double xi_2)}:舍选函数
 * @param {name}:输出文件名
 * @param {N}:抽样个数
 * @param {seed}:种子
 * @return {int}:成功1，失败0 
 */
int CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),int N) 
 * @fuction: 比较法抽样
 * @param {(*Arcf)(double xi_1)}:比较函数的反函数指针
 * @param {(*IsLegal)(double x,double xi_2)}:舍选函数
 * @param {N}:抽样个数
 * @param {seed}:种子
 * @return {double*}:包含抽样的数组
 */
double* ComSam(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),int N,int seed);

/**
 * @name: MonteInt(double (*f)(double* x_vec),double** range,int Dim,int (*InArea)(double* x_vec),int N,int seed)
 * @fuction: 用蒙特卡洛平均值法计算任意维度任意区域的积分
 * @param {(*f)(double* x_vec)}: 被积函数
 * @param {dim}: 维度
 * @param {range}: 抽样域
 * @param {(*InArea)(double* x_vec)}: 舍弃函数
 * @param {N}: 总有效抽样数
 * @param {seed}: 种子
 * @return {double*}: {积分值,抽样效率} 
 */
double* MonteInt(double (*f)(double* x_vec),int dim,double (*range)[2],int (*InArea)(double* x_vec),int N,int seed);

/**
 * @name: double* MHMonteInt(double (*f)(double x),double (*r)(double x_0,double x),double (*arcXi)(double x_0,double xi),int N,int M,int seed);
 * @fuction: 用Metropolis抽样方法计算积分
 * @param {(*f)(double* x_vec)}: 均值函数
 * @param {r}: Accept概率函数
 * @param {arcXi}: 抽样逆函数
 * @param {M}:热化抽样数
 * @param {N}: 总有效抽样数
 * @param {seed}: 种子
 * @param {x_0}: 初始值
 * @return {double*}: {积分值,抽样效率} 
 */
double* MetroMonteInt(double (*f)(double x),
                      double (*r)(double x_0,double x),
                      double (*arcXi)(double x_0,double xi),
                      int N,int M,int seed,
                      double x0);
#pragma endregion
