/**
 * @ �ļ���: SciLib.h
 * @ ����: �����볣�ÿ�ѧ���뺯���йصĺ����볣�����ϲ���Schrage ��SciLib,
 * ����������֮ǰƴ��ĺ�������
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
#include "math.h"
#include "malloc.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-9
#define M_16807 2147483647 
#define A_16807 16807	
#define R_16807 2836
#define Q_16807 127773
#pragma endregion

#pragma region ��������
/**
 * @name: Factorial(int n)
 * @fuction: ��׳�
 * @param {n}: �׳�ֵ�� 
 * @return {int}: �׳�ֵ 
 */
int Factorial(int n);

/**
 * @name: Permu(int n,int k)
 * @fuction: ��������
 * @param {n}: �����
 * @param {k}: Ҫ�����и��� 
 * @return {int}: ������
 */
int Permu(int n,int k);

/**
 * @name: Combin(int n,int k)
 * @fuction: �������
 * @param {n}: �����
 * @param {k}: Ҫ����ϸ��� 
 * @return {int}: �����
 */
int Combin(int n,int k);

/**
 * @ ����: int Schrage(int seed)
 *
 * @ ����: Schrage���������
 *
 * @ param{seed}: ����
 *
 * @ ����ֵ: ��һ�������
 */
int Schrage(int seed);

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

/**
 * @ ����: ArcFun(double (*f)(double x), double fx, double* range, double rtol)
 *
 * @ ����: ���ַ����㷴����
 *
 * @ param{f}:����ָ��
 *
 * @ param{fx}:����ֵ
 *
 * @ param{range}:[start,end]�����ַ�Χ��nullΪʵ����
 *
 * @ param{atol}:�������
 *
 * @ ����ֵ: ������ֵ,ʧ��nan
 */
double ArcFun(double (*f)(double x), double fx,double* range, double atol);

/**
 * @name: BinarySearch(double* arr,double key,double len)
 * @fuction: ���ַ���ֵ
 * @param {arr}: �������� 
 * @param {key}: ����Ŀ��
 * @param {len}:���鳤��
 * @return {int}: Ŀ���ֵ 
 */
int BinarySearch(double* arr,double key,double len);

/**
 * @name: ConDirectSamToDat(double* SigmaPi,char* name,int N)
 * @fuction: ��������ֱ�ӳ���
 * @param {(*Arcf)(double xi)}:������
 * @param {name}:����ļ���
 * @param {N}:��������
 * @return {int}:�ɹ�1��ʧ��0 
 */
int ConDirectSamToDat(double (*Arcf)(double xi),char* name,int N);

/**
 * @name: ConDirectSam(double* SigmaPi,char* name,int N)
 * @fuction: ��������ֱ�ӳ���
 * @param {(*Arcf)(double xi)}:������
 * @param {N}:��������
 * @param {seed}:����
 * @return {double*}:����������double���飬��ǵ�free
 */
double* ConDirectSam(double (*Arcf)(double xi),int N,int seed);

/**
 * @name: DirectSamToDat(double* SigmaPi,char* name,int Num,int N)
 * @fuction: ����ɢ��ֱ�ӳ���
 * @param {SigmaP}:Ԥ��������ۼ�����
 * @param {name}:����ļ���
 * @param {Num}:��ɢ�����
 * @param {N}:��������
 * @return {int}:�ɹ�1��ʧ��0 
 */
int DisDirectSamToDat(double* SigmaP,char* name,int Num,int N);

/**
 * @name: DirectSamToDat(double* SigmaPi,int N)
 * @fuction: ����ɢ��ֱ�ӳ���
 * @param {SigmaP}:Ԥ��������ۼ�����
 * @param {Num}:��ɢ�����
 * @param {N}:��������
 * @return {int*}:�������������飬�ǵ�free 
 */
int* DisDirectSam(double* SigmaP,int Num,int N,int seed);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N) 
 * @fuction: �ȽϷ�����
 * @param {(*Arcf)(double xi_1)}:�ȽϺ����ķ�����ָ��
 * @param {(*IsLegal)(double x,double xi_2)}:��ѡ����
 * @param {name}:����ļ���
 * @param {N}:��������
 * @param {seed}:����
 * @return {int}:�ɹ�1��ʧ��0 
 */
int CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),int N) 
 * @fuction: �ȽϷ�����
 * @param {(*Arcf)(double xi_1)}:�ȽϺ����ķ�����ָ��
 * @param {(*IsLegal)(double x,double xi_2)}:��ѡ����
 * @param {N}:��������
 * @param {seed}:����
 * @return {double*}:��������������
 */
double* ComSam(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),int N,int seed);

/**
 * @name: MonteInt(double (*f)(double* x_vec),double** range,int Dim,int (*InArea)(double* x_vec),int N,int seed)
 * @fuction: �����ؿ���ƽ��ֵ����������ά����������Ļ���
 * @param {(*f)(double* x_vec)}: ��������
 * @param {dim}: ά��
 * @param {range}: ������
 * @param {(*InArea)(double* x_vec)}: ��������
 * @param {N}: ����Ч������
 * @param {seed}: ����
 * @return {double*}: {����ֵ,����Ч��} 
 */
double* MonteInt(double (*f)(double* x_vec),int dim,double (*range)[2],int (*InArea)(double* x_vec),int N,int seed);

/**
 * @name: double* MHMonteInt(double (*f)(double x),double (*r)(double x_0,double x),double (*arcXi)(double x_0,double xi),int N,int M,int seed);
 * @fuction: ��Metropolis���������������
 * @param {(*f)(double* x_vec)}: ��ֵ����
 * @param {r}: Accept���ʺ���
 * @param {arcXi}: �����溯��
 * @param {M}:�Ȼ�������
 * @param {N}: ����Ч������
 * @param {seed}: ����
 * @param {x_0}: ��ʼֵ
 * @return {double*}: {����ֵ,����Ч��} 
 */
double* MetroMonteInt(double (*f)(double x),
                      double (*r)(double x_0,double x),
                      double (*arcXi)(double x_0,double xi),
                      int N,int M,int seed,
                      double x0);
#pragma endregion
