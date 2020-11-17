/*
 * @Name: GammaInt.h
 * @Desriptption: 对应于GammaInt.c种各种东西的定义头文件
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-11-17 16:57:13
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define alpha 2
#define Gamma_alpha 1
#define beta 10
#pragma endregion

#pragma region 函数声明
/**
 * @name: Gammaf(double x)
 * @fuction:均值函数 
 * @param {x}: 自变量
 * @return {double}: 对应函数值
 */
double Gammaf(double x);

/**
 * @name: r(double x0, double x)
 * @fuction: Metropolis法里的accept函数
 * @param {x0}: 当前值
 * @param {x}: 演化值
 * @return {double}: 对应概率
 */
double Gammar(double x0, double x);

/**
 * @name: arcXi(double x0, double x)
 * @fuction: 转移函数反函数
 * @param {x0}: 当前值
 * @param {xi}: 随机数
 * @return {double}: 演化值
 */
double GammaarcXi(double x0, double xi);

/**
 * @name: Montef(double* x)
 * @fuction: 为蒙特卡洛方法配置的函数
 * @param {x}:自变量
 * @return {double}:函数值
 */
double Montef(double* x);

/**
 * @name: InArea(double* x_vec)
 * @fuction: 为蒙特卡洛方法配置的函数
 * @param {x}:自变量
 * @return {double}:是否在区域内
 */
int GammaInArea(double* x_vec);
#pragma endregion