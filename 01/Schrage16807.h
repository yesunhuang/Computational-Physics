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
#include "string.h"
#include "stdlib.h"
#include "math.h"
#pragma endregion

#pragma region �궨����
//����Ϊ���ೣ����������
#define M_16807 2147483647 
#define A_16807 16807	
#define R_16807 2836
#define Q_16807 127773
#define OTimes +
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
 * @ ����: double* RandN(int seed, int* range)
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
double* RandN(int seed, double* range,int N);

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
int RandNToDat(int seed, double* range, int N,char* name);

/**
 * @ ����: ReadAndCalAvg(char* name, int k)
 *
 * @ ����: ��dat�ж������ݲ�����<x^k>
 *
 * @ param{name}:�ļ���
 *
 * @ param{k}: �״�
 *
 * @ param{N}: �ܸ���
 *
 * @ ����ֵ: ����ֵ
 */
double ReadAndCalAvg(char* name, int k,int N);

/**
 * @ ����: ReadAndCalCorr(char* name,int k,int N)
 *
 * @ ����: ��dat�ж������ݲ�����C(l)
 *
 * @ param{name}:�ļ���
 *
 * @ param{l}: �״�
 *
 * @ param{N}: �ܸ���
 *
 * @ ����ֵ: ����ֵ
 */
double ReadAndCalCorr(char* name, int l, int N);

/**
 * @ ����: RecurrentIndex(int maxIndex, int rawIndex)
 *
 * @ ����: ����ѭ����������
 *
 * @ param{maxIndex}:�������
 *
 * @ param{rawIndex}:ԭʼ���� 
 *
 * @ ����ֵ: �Ϸ�������
 */
int RecurrentIndex(int length, int rawIndex);


#pragma endregion
