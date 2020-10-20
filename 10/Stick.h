/*
 * @Name: Stick.h
 * @Desriptption: 包含stick.c需要的预编译指令与各种声明
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: 本程序已上传至github,https://github.com/yesunhuang/Computational-Physics，
 * 请勿抄袭本程序，任何可能的雷同的作业上传都是未经授权的严重犯罪级行为！！！
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-10-20 21:15:04
 */

#pragma once

#pragma region 头文件区
#include "sciLib.h"
#pragma endregion

#pragma region 宏定义区
 //以下为各类常数及操作符
#define P_THETA 0.5
#define DELTA_THETA 0.001
#pragma endregion

#pragma region 函数声明
/**
 * @name: RWThetaToDat(int seed,char* name,int tn)
 * @fuction: 计算单个粒子的RW转动投影
 * @param {seed}:计算种子
 * @param {name}:输出文件名
 * @param {tn}:时间步数
 * @return {int}:成功1，失败0
 */
int RWThetaToDat(int seed,char* name,int tn);

/**
 * @name: CalAvg(int seed,char* name,int N,int tn)
 * @fuction: 计算多个个粒子的RW值投影矩
 * @param {seed}:计算种子
 * @param {name}:输出文件名
 * @param {N}:取样个数
 * @param {tn}:时间步数
 * @param {l}:矩阶
 * @return {int}:成功1，失败0
 */
int CalAvg(int seed,char* name,int N,int tn,int l);

/**
 * @name: CalAvg(int seed,char* name,int N,int tn)
 * @fuction: 计算多个个粒子的RW关联
 * @param {seed}:计算种子
 * @param {name}:输出文件名
 * @param {N}:取样个数
 * @param {tn}:时间步数
 * @param {tau}:取样零点
 * @return {int}:成功1，失败0
 */
int CalCor(int seed,char* name,int N,int tn,int tau);
#pragma endregion
