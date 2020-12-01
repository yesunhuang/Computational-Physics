/*
 * @Name: chaos.h
 * @Desriptption:定义关于chaos的一系列函数 
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-12-01 22:00:25
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
 //初始值
#define INITAL 0.01
#pragma endregion

#pragma region 函数声明
/**
 * @name: double f(double xn)
 * @fuction: 迭代方程
 * @param {xn}: 第n个值
 * @param {lambda}: lambda值
 * @return {double}: 第n+1个值
 */
double f(double xn,double lambda);

/**
 * @name: classify(double* arr,double n,double fuz)
 * @fuction: 分类数据
 * @param {arr}: 需要分类的数组
 * @param {n}:数个数
 * @param {fuz}:模糊度
 * @return {int}: 总类别数
 */
int classify(double* arr,int n,double fuz);

/**
 * @name: chaosToDat(double* lambda,int M,int N)
 * @fuction: 计算和打印数据
 * @param {name}:输出文件名
 * @param {lambda}: lambda数组
 * @param {n}:lambda的个数
 * @param {M}:热化值
 * @param {N}:迭代值
 * @param {RE}:相对精度要求
 * @return {int}: 成功1，失败0
 */
int chaosToDat(char** name,double* lambda,int n,int M,int N,double RE);
#pragma endregion