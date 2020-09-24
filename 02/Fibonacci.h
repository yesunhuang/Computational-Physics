/**
 * @ �ļ���: Fibonacci.h
 * @ ����: ������Fibonaccii�йصĺ����볣��
 * @ ����: YesunHuang,����Ѹ,PB18020631
 * @ ����: yesunhuang@mail.ustc.edu.cn
 * @ https://github.com/yesunhuang
 * @ ����: 2020��9��24��
 * ���������ϴ���github,https://github.com/yesunhuang/Computational-Physics��
 * ����Ϯ�������κο��ܵ���ͬ����ҵ�ϴ�����δ����Ȩ�����ط��Ｖ��Ϊ������
 * Life is short, I want Python.
 */

#pragma once

#pragma region ͷ�ļ���
#include "Schrage16807.h"
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define OTimes +
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#pragma endregion

#pragma region ��������

//����Ϊ���ֺ�������
/**
 * @ ����: int Fibonacci(int* cache, int q, int p)
 *
 * @ ����: ����Fibonacci���е���һ����
 *
 * @ param{cache}:����������һ�����Ļ�������
 *
 * @ param{n}:��ǰ���
 *
 * @ param{q}:�ӳ���
 *
 * @ param{p}:�ӳ���
 *
 * @ ����ֵ: ��һ����
 */
int Fibonacci(int* cache, int n, int q, int p);

/**
 * @ ����: int FibRandNToDat(int seed, double* range, int N, char* name,int p,int q)
 *
 * @ ����: ����һ������Fibonacciα������в���ӡ��dat��
 *
 * @ param{seed}: ����
 *
 * @ param{range}: ��Χ
 *
 * @ param{N}: �ܸ���
 *
 * @ param{name}: ����ļ���
 *
 * @ param{p}: �ӳ���
 *
 * @ param{q}: �ӳ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
int FibRandNToDat(int seed, double* range, int N, char* name,int p,int q);

/**
 * @ ����: ReadAndCalScale(char* name, int N)
 *
 * @ ����: ��dat��������x<y<z�����ı�����
 *
 * @ param{N}: �ܸ���
 *
 * @ param{name}: �����ļ���
 *
 * @ ����ֵ: �ɹ�1��ʧ��0
 */
double ReadAndCalScale(char* name, int N);
#pragma endregion
