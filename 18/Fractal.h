/*
 * @Name: Fractal.h
 * @Desriptption: 声明模拟DLA与计算DLA维数相关的函数
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-12-08 20:56:48
 */

#pragma once

#pragma region 头文件区
#include "SciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define BOUND_SIZE 250
#define FOCUS_SIZE 250
#define PUMP_SIZE 300
#define OUT_SIZE 400
#define POCESS 100
#pragma endregion

#pragma region 函数声明
/**
 * @name: DLASimuToDat(char* name,int N,int seed)
 * @fuction: 模拟产生DLA图形
 * @param {name}:输出文件名
 * @param {N}:产生净粒子数
 * @param {seed}:种子
 * @return {int}:成功1，失败0
 */
int DLASimuToDat(char* name,int N,int seed);

/**
 * @name: SandboxCal(char* nameIn,char* nameOut,int* r)
 * @fuction: sanbox法计算用于拟合的维度数据
 * @param {nameIn}:输入文件名
 * @param {nameOut}:输出文件名
 * @param {N}:总读入粒子数
 * @param {r}:边长数组
 * @param {r_len}:边长数组长度
 * @return {int}:成功1，失败0
 */
int SandboxCal(char* nameIn,char* nameOut,int N,double* r,int r_len);

/**
 * @name: NRgCal(char* nameIn,char* nameOut,int* N,int N_len)
 * @fuction: 回转半径法计算用于拟合的维度数据
 * @param {nameIn}:输入文件名
 * @param {nameOut}:输出文件名
 * @param {N}:粒子数数组
 * @param {N_len}:粒子数数组长度
 * @return {int}:成功1，失败0
 */
int NRgCal(char* nameIn,char* nameOut,int* N,int N_len);
#pragma endregion
