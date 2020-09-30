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
#pragma endregion

#pragma region �궨����
 //����Ϊ���ೣ����������
#define M_PI 3.14159265358979323846
#define Epsilon 1.0E-6
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
 * @ param{rtol}:������
 *
 * @ ����ֵ: ������ֵ,ʧ��nan
 */
double ArcFun(double (*f)(double x), double fx,double* range, double atol);
#pragma endregion
