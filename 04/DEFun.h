/**
 * @ �ļ���: DEFun.h
 * @ ����: ������DEFun�йصĺ����볣��
 * @ ����: YesunHuang,����Ѹ,PB18020631
 * @ ����: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ ����: 2020��9��29��
 * ���������ϴ���github,https://github.com/yesunhuang/Computational-Physics��
 * ����Ϯ�������κο��ܵ���ͬ����ҵ�ϴ�����δ����Ȩ�����ط��Ｖ��Ϊ������
 * Life is short, I want Python.
 */

#pragma once

#pragma region �궨����
 //����Ϊ���ೣ����������
#define M_PI 3.14159265358979323846 
#pragma endregion

#pragma region ͷ�ļ���
#include "Schrage16807.h"
#pragma endregion

#pragma region ��������

/**
 * @ ����: RFunToDat(int seed,char* name,int N)
 *
 * @ ����: ���������ʽ���ʺ��������������ӡ���ļ�
 *
 * @ param{seed}: ����
 *
 * @ param{name}:��ӡ�ļ���
 *
 * @ param{N}:����
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int RFunToDat(int seed,char* name,int N);

/**
 * @ ����: LFunToDat(int seed,char* name,int N)
 *
 * @ ����: ��������Lorentz���ʺ��������������ӡ���ļ�
 *
 * @ param{seed}: ����
 *
 * @ param{m}: ��������m
 *
 * @ param{name}: ��ӡ�ļ���
 *
 * @ param{N}: ����
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int LFunToDat(int seed,double m, char* name, int N);

#pragma endregion