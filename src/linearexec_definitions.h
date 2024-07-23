#pragma once

/*			����������� LINEAR EXECUTABLE ��������������� ���������
 *		������ LE/LX ��������� ��������� ���������� � ����������� � ���������,
 * ����������� �� ������.
 * 
 * ������������ �������, ��������� �����������, ...?
 */
#define __LE_NUL 0x00 /* ����������� (�����) �� */
#define __LE_WIN 0x02 /* MS-Windows */
#define __LE_OS2 0x01 /* IBM OS/2 */
#define __LE_DOS 0x03 /* MS-DOS 4x */
#define __LE_386 0x04 /* MS-Windows � ���������� ���������� 386 */

/*			����������� ����������� ��
 * �� ���� ����� ��������� � ����� ��� �� � �����, �� ���� �������� ������ ����������
 * ����������� ���������� ������� � �����:
 */
#define __LE_CPU_286 0x01 /* IA 80286 (i286) */
#define __LE_CPU_386 0x02 /* IA 80386 (i386) */
#define __LE_CPU_486 0x03 /* IA 80486 (i486) */
#define __LE_CPU_586 0x04 /* IA 80586 (i586) */
#define __LE_CPU_R20 0x40 /* MIPS R2000 �������������� */
#define __LE_CPU_R60 0x41 /* MIPS R6000 */
#define __LE_CPU_R40 0x42 /* MIPS R4000 */

