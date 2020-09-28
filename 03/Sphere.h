/**
 * @ �ļ���: Sphere.h
 * @ ����: ������Sphere�йصĺ����볣��
 * @ ����: YesunHuang,����Ѹ,PB18020631
 * @ ����: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ ����: 2020��9��28��
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
 * @ ����:SRandNToDat(int seed, double rho, double N, char* name)
 *
 * @ ����:������������� 
 *
 * @ param{seed}:��������,[seed1,seed2]
 *
 * @ param{rho}:�뾶
 *
 * @ param{N}:����
 *
 * @ param{name}:�ļ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int SRandNToDat(int seed, double rho, int N, char* name);

/**
 * @ ����:NSRandNToDat(int* seed, double rho, double N, char* name)
 *
 * @ ����:��һ�ֱȽϴ��ķ����������������
 *
 * @ param{seed}:��������[seed1,seed2,seed3]
 *
 * @ param{rho}:�뾶
 *
 * @ param{N}:����
 *
 * @ param{name}:�ļ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int NSRandNToDat(int seed, double rho, int N, char* name);

#pragma endregion

