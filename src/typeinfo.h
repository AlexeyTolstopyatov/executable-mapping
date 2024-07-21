#pragma once
#include <iostream>

#include "retyping.h"
/*
 *		(�) ����������� ������� �. 
 * ���������� "Typeinfo.h" -- ������� ��� �������� � ������ 
 * ���������� � ��������� � ����������. 
 * 
 * �� ������, ����� �� ��������� �������� ������� ��� ������� ����
 * ������������ �����, ��� ����� �������� ������������� ������ ��� ������������ �������
 * 
 * ������� ������ ��� �������� ��������, ������� ��������� �� ��������� ��������� ����� MZ.
 * �� ����, ����� �������� ����������� ���� (*.exe), �� ������� �� �������� ��� ������� 0x3C, 
 * ��� ��������� �������� �������� (�� 0) �� ���������� ��������� (NE/LE/PE)
 *	(���� � ������� ��� ��������� �������.....)
 */


 /* �������� ��������� ��� �������� ����� �����. */
static __uint64_t t_offset = 0;
static __uint64_t h_result = 0x00;

/*������� ������� � ����� ����� ������ Windows � ����� ��������� �����������...*/

void winfo(__uint16_t *cell);
void binfo(__uint8_t *cell);
void dwinfo(__uint64_t *cell);
void nulloffset();