/**
 * @ �ļ���: Marsaglia.h
 * @ ����: ������Sphere�йصĺ����볣��
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
 * @ ����:MRandNToDat(int seed,int N, char* name)
 *
 * @ ����:����ƽ��ͶӰ����� 
 *
 * @ param{seed}:����
 *
 * @ param{N}:����
 *
 * @ param{name}:�ļ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int MRandNToDat(int seed, int N, char* name);

#pragma endregion

