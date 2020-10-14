/*
 * @Name: IntPro.h
 * @Desriptption: 包含需要计算的积分
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-10-14 10:09:22
 */
#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 函数声明区
/**
 * @name: f1(double* x) 
 * @fuction: 计算第一个被积函数
 * @param {x}: 自变量 
 * @return {double}: 函数值 
 */
double f1(double* x);

/**
 * @name: f2(double* x) 
 * @fuction: 计算第二个被积函数
 * @param {x_vec}: 自变量 
 * @return {double}: 函数值 
 */
double f2(double* x_vec);

/**
 * @name: f3(double* x) 
 * @fuction: 计算常被积函数
 * @param {x_vec}: 自变量 
 * @return {double}: 返回1 
 */
double f3(double* x_vec);

/**
 * @name: InArea1(double* x) 
 * @fuction: 返回常在区域内
 * @param {x_vec}: 自变量 
 * @return {int}: 常返回1 
 */
int InArea12(double* x_vec);

/**
 * @name: InArea2(double* x) 
 * @fuction: 返回是否在多维圆内
 * @param {x_vec}: 自变量 
 * @return {int}: 是返回1，否返回0
 */
int InArea3(double* x_vec);
#pragma endregion 
