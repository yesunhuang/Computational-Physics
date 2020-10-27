/*
 * @Name:BackWalk.h 
 * @Desriptption: 声明回归行走的相关函数。
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-10-27 20:16:26
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
 * @name: EstimateBWP(int seed,char* name,int d,int N,int maxStep)
 * @fuction: 估计每一步回到原点的概率，并打印至文件中。
 * @param {seed}:种子
 * @param {name}:输出文件名
 * @param {d}:维度
 * @param {N}:总行走数
 * @param {maxStep}:最大步数
 * @return {int}:成功1，失败0
 */
int EstimateBWP(int seed,char* name,int d,int N,int maxStep);

/**
 * @name: FindTheoP(char*name,int N,int d)
 * @fuction: 利用递推式找出理论概率
 * @param {name}:输出文件名
 * @param {d}:维度
 * @param {N}:最大步数
 * @return {int}:成功1，失败0
 */
int FindTheoP(char*name,int N,int d);

/**
 * @name: CalOrder(char* inName,char* outName,int m,int i)
 * @fuction: 计算阶次拟合
 * @param {inName}:输入文件名
 * @param {outName}:输出文件名
 * @param {m}:总步数的一半，向下取整
 * @param {i}:偏移步数
 * @return {int}:成功1，失败0
 */
int CalOrder(char* inName,char* outName,int m,int i);

/**
 * @name: findLinIndex(int* index,int d,int N)
 * @fuction: 把多维索引转化为线性
 * @param {index}:索引数组
 * @param {valueArray}:值数组
 * @param {d}:维度
 * @param {N}:步数
 * @return {int}:线性索引
 */
int findLinIndex(int* index,int d,int N);

/**
 * @name: findDIndex(int index,int d,int N)
 * @fuction: 把线性索引转化为多维
 * @param {index}:索引数组
 * @param {d}:维度
 * @param {N}:步数
 * @return {int*}:多维索引
 */
int* findDIndex(int index,int d ,int N);
#pragma endregion
