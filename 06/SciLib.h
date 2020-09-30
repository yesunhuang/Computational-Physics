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
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-6
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
 * @ param{rtol}:相对误差
 *
 * @ 返回值: 反函数值,失败nan
 */
double ArcFun(double (*f)(double x), double fx,double* range, double atol);
#pragma endregion
