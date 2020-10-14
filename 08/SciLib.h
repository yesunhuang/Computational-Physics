/**
 * @ 文件名: SciLib.h
 * @ 功能: 声明与常用科学库与函数有关的函数与常量
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
#include "Schrage16807.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-9
#pragma endregion

#pragma region 函数声明
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
 * @name: DirectSamToDat(double* SigmaPi,char* name,int N)
 * @fuction: 对离散点直接抽样
 * @param {SigmaP}:预处理概率累加数组
 * @param {name}:输出文件名
 * @param {N}:抽样个数
 * @param {M}:离散点个数
 * @return {int}:成功1，失败0 
 */
int DisDirectSamToDat(double* SigmaP,char* name,int Num,int N);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N) 
 * @fuction: 比较法抽样
 * @param {(*Arcf)(double xi_1)}:比较函数的反函数指针
 * @param {(*IsLegal)(double x,double xi_2)}:舍选函数
 * @param {name}:输出文件名
 * @param {N}:抽样个数
 * @return {type} 
 */
int CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N);

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

#pragma endregion
