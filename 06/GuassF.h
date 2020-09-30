/**
 * @ �ļ���: GuassF.h
 * @ ����: ������GuassFunction�йصĺ����볣��
 * @ ����: YesunHuang,����Ѹ,PB18020631
 * @ ����: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ ����: 2020��9��30��
 * ���������ϴ���github,https://github.com/yesunhuang/Computational-Physics��
 * ����Ϯ�������κο��ܵ���ͬ����ҵ�ϴ�����δ����Ȩ�����ط��Ｖ��Ϊ������
 * Life is short, I want Python.
 */

#pragma once

#pragma region ͷ�ļ���
#include "Schrage16807.h"
#include "SciLib.h"
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define G_Atol 1E-5
#pragma endregion

#pragma region ��������

/**
 * @ ����: GRandNToDat(int seed, int* range, int N)
 *
 * @ ����: �������Guass�����,��print���ļ���
 *
 * @ param{seed}: ����
 *
 * @ param{N}: �ܸ���
 *
 * @ param{name}: ����ļ���
 *
 * @ ����ֵ: �ɹ�Ϊ�ܳ�������ʧ��Ϊ0
 */
int GRandNToDat(int seed,  int N, char* name);

/**
 * @ ����: LorentzF(double x)
 *
 * @ ����: ��������F��ֱ�ӳ����ۻ�
 *
 * @ param{x}: �Ա���
 *
 * @ ����ֵ: ����ֵ
 */
double LorentzF(double x);

#pragma endregion


