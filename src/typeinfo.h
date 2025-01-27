#pragma once

#include "retyping.h"
#include <stdio.h>

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

/*������� ������� � ����� ����� ������ Windows � ����� ��������� �����������...*/

void winfo(__uint16_t *cell);
void binfo(__uint8_t *cell);
void dwinfo(__uint64_t *cell);
void nulloffset();
