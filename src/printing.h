#pragma once
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
void printvxd(struct VXD_HEADER *exec);
void printlx(struct LX_HEADER *orig);

/* ����������� ��� ����������� */
#include "linearexec_definitions.h"
#include "newexec_definitions.h"

void osnefh(__uint8_t *os);
void oslxfh(__uint16_t *os);
void cpunefh(__uint16_t *cpu);
void cpulxfh(__uint16_t *cpu);
void osmode(__uint8_t *mode);