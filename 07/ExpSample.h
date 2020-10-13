/*
 * @Name:ExpSample.h 
 * @Desriptption: 包含ExpSample.c中函数的定义以及各种声明
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-10-13 19:24:40
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#include "Schrage16807.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#pragma endregion

#pragma region 函数声明
/**
 * @name: ReadAndPreCal(char* name,int N)
 * @fuction: 读取数据，做些预处理
 * @param {origin}:存储原始数据的数组
 * @param {name}:读取文件名
 * @param {N}:数据个数 
 * @return {double*}:存储预处理数据 
 */
double* ReadAndPreCal(char* name,int N);

/**
 * @name: ComArcf(double xi)
 * @fuction: 比较函数的反函数
 * @param {xi}: [0,1]内随机数 
 * @return {double}: x
 */
double ComArcf(double xi);

/**
 * @name: ExpIsLegal(double x,double xi_2)
 * @fuction: 判断舍选是否合法
 * @param {x}: 抽样x
 * @param {xi_2}: 比例随机数 
 * @return {int}: 合法1，不合法0 
 */
int ExpIsLegal(double x,double xi_2);

#pragma endregion
