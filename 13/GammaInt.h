/*
 * @Name: GammaInt.h
 * @Desriptption: ��Ӧ��GammaInt.c�ָ��ֶ����Ķ���ͷ�ļ�
 * @Email: yesunhuang@mail.ustc.edu.cn
 * @OpenSource: https://github.com/yesunhuang
 * @Msg: ���������ϴ���github,https://github.com/yesunhuang/Computational-Physics��
 * ����Ϯ�������κο��ܵ���ͬ����ҵ�ϴ�����δ����Ȩ�����ط��Ｖ��Ϊ������
 * Life is short, I want Python.
 * @Author: YesunHuang
 * @Date: 2020-11-17 16:57:13
 */

#pragma once

#pragma region ͷ�ļ���
#include "SciLib.h"
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define alpha 2
#define Gamma_alpha 1
#define beta 10
#pragma endregion

#pragma region ��������
/**
 * @name: Gammaf(double x)
 * @fuction:��ֵ���� 
 * @param {x}: �Ա���
 * @return {double}: ��Ӧ����ֵ
 */
double Gammaf(double x);

/**
 * @name: r(double x0, double x)
 * @fuction: Metropolis�����accept����
 * @param {x0}: ��ǰֵ
 * @param {x}: �ݻ�ֵ
 * @return {double}: ��Ӧ����
 */
double Gammar(double x0, double x);

/**
 * @name: arcXi(double x0, double x)
 * @fuction: ת�ƺ���������
 * @param {x0}: ��ǰֵ
 * @param {xi}: �����
 * @return {double}: �ݻ�ֵ
 */
double GammaarcXi(double x0, double xi);

/**
 * @name: Montef(double* x)
 * @fuction: Ϊ���ؿ��巽�����õĺ���
 * @param {x}:�Ա���
 * @return {double}:����ֵ
 */
double Montef(double* x);

/**
 * @name: InArea(double* x_vec)
 * @fuction: Ϊ���ؿ��巽�����õĺ���
 * @param {x}:�Ա���
 * @return {double}:�Ƿ���������
 */
int GammaInArea(double* x_vec);
#pragma endregion