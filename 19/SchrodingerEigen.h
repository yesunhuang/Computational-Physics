/*
 * @Name: SchrodingerEigen.h
 * @Desriptption: 计算对称薛定谔方程的函数
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-12-22 20:19:38
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
 //方便替换势能函数
#define SCHROV inftyConstantV 
#pragma endregion

#pragma region 函数声明
/**
 * @name: inftyConstantV(double x); 
 * @fuction: 势能函数
 * @param {x}:x坐标
 * @return {double}:势能值
 */
double inftyConstantV(double x); 

/**
 * @name: inftyConstantV(double x); 
 * @fuction: Numerov求解器索取的f函数
 * @param {x}:x坐标
 * @return {double}:势能值
 */
double schroNumerovF(double x);

/**
 * @name: findEigenValueToDat(char* name,double* span,int step);
 * @fuction: 寻找能量本征值并写入文件中
 * @param {name}:文件头
 * @param {ESpan}:能量范围
 * @param {EStep}:枚举步幅
 * @param {xspan}:x求解区间
 * @param {xStep}:x求解步数
 * @param {epsilon}:相对允差
 * @param {initial}:x初始值
 * @return {None}
 */
void findEigenValueToDat(char* name,
                         double* ESpan,int EStep,
                         double *xSpan,int xStep,double* initial,
                         double epsilon);
#pragma endregion
