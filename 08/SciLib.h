/**
 * @ �ļ���: SciLib.h
 * @ ����: �����볣�ÿ�ѧ���뺯���йصĺ����볣��
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
#include "Schrage16807.h"
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-9
#pragma endregion

#pragma region ��������
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
 * @name: DirectSamToDat(double* SigmaPi,char* name,int N)
 * @fuction: ����ɢ��ֱ�ӳ���
 * @param {SigmaP}:Ԥ��������ۼ�����
 * @param {name}:����ļ���
 * @param {N}:��������
 * @param {M}:��ɢ�����
 * @return {int}:�ɹ�1��ʧ��0 
 */
int DisDirectSamToDat(double* SigmaP,char* name,int Num,int N);

/**
 * @name: CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N) 
 * @fuction: �ȽϷ�����
 * @param {(*Arcf)(double xi_1)}:�ȽϺ����ķ�����ָ��
 * @param {(*IsLegal)(double x,double xi_2)}:��ѡ����
 * @param {name}:����ļ���
 * @param {N}:��������
 * @return {type} 
 */
int CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N);

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

#pragma endregion
