/**
 * @ �ļ���: Schrage16807.h
 * @ ����: ������Schrage�йصĺ����볣��
 * @ ����: YesunHuang,����Ѹ,PB18020631
 * @ ����: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ ����: 2020��9��22��
 * ���������ϴ���github,https://github.com/yesunhuang/Computational-Physics��
 * ����Ϯ�������κο��ܵ���ͬ����ҵ�ϴ�����δ����Ȩ�����ط��Ｖ��Ϊ������
 * Life is short, I want Python.
 */

#pragma once

#pragma region ͷ�ļ���
#include "malloc.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#pragma endregion

#pragma region �궨����
//����Ϊ���ೣ��
#define M_16807 2147483647 
#define A_16807 16807	
#define R_16807 2836
#define Q_16807 127773
#pragma endregion

#pragma region ��������
/**
 * @ ����: int Shrage(int seed)
 *
 * @ ����: Shrage���������
 *
 * @ param{seed}: ����
 *
 * @ ����ֵ: ��һ�������
 */
int Shrage(int seed);

/**
 * @ ����: int* RandN(int seed, int* range)
 *
 * @ ����: ������������
 *
 * @ param{seed}: ����
 *
 * @ param{range}: ��Χ
 *
 * @ param{N}: �ܸ���
 *
 * @ ����ֵ: ������������������,���Լǵ�free��
 */
int* RandN(int seed, int* range,int N);

/**
 * @ ����: int Seed()
 *
 * @ ����: �������ڲ�������
 *
 * @ ����ֵ: ����
 */
int Seed();

/**
 * @ ����: RandNToDat(int seed, int* range, int N)
 *
 * @ ����: ������������,��print���ļ���
 *
 * @ param{seed}: ����
 *
 * @ param{range}: ��Χ
 *
 * @ param{N}: �ܸ���
 *
 * @ param{name}: ����ļ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int RandNToDat(int seed, int* range, int N,char* name);
#pragma endregion
