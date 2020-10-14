/*
 * @Name: CLTheorem.h
 * @Desriptption: 包含中心极限定理证明所需的各种定义和预设
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-10-14 20:17:43
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符

#pragma endregion

#pragma region 函数声明

/**
 * @name: BinoDis(double p,int n)
 * @fuction: 返回SigmaP数组
 * @param {p}:概率 
 * @param {n}:离散点个数
 * @return {double*}:SigmaP数组 
 */
double* BinoDis(double p,int n); 

/**
 * @name: PoissionDis(double lambda)
 * @fuction: 返回SigmaP数组
 * @param {lambda}:分布常数 
 * @param {n}:离散值
 * @return {double*}:SigmaP数组 
 */
double* PoissionDis(double lambda,int n);

/**
 * @name: ArcExpDis(double xi)
 * @fuction: 返回指数分布的反函数
 * @param {xi}: 随机数 
 * @return {double}: 抽样x 
 */
double ArcExpDis(double xi);
#pragma endregion