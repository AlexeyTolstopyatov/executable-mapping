#pragma once
#include <iostream>
#include "typeinfo.h"
#include "mapping.h"

/*		(�) ����������� �������
 * ���������� "Printing.h" -- �������, ��������� ���������� � ��������.
 * ������������ ��� ������������ ������� ���������
 * 
 */

void printsig(__uint16_t header);
void printmz(struct MZ_HEADER *exec);
void printpe(struct NT_HEADER *exec);
void printope(struct OPTIONAL_PE_HEADER *ope);
void printne(struct NE_HEADER *exec);
void printle(struct LE_HEADER *exec);