#pragma once

/*
 *			����������� ��� NEW EXECUTABLE HEADER
 *		��� � ��������� ������������ �����, � "������ ������������" ���� �����
 * ���� ���� � ������������ � ������������ ����������. 
 * ������� � ���������� ����� � ���� �����.
 */

#define __NE_NUL 0x0000 /* ����������� �� */
#define __NE_OS2 0x0001 /* IBM  OS/2 */
#define __NE_DOS 0x0002 /* MS-DOS 4x */
#define __NE_WIN 0x0003 /* MS-Windows */

#define __NE_FLAGS_386  0x0040 /* IA 80386 */ 
#define __NE_FLAGS_286  0x0020 /* IA 80286 */
#define __NE_FLAGS_8086 0x0010 /* IA 8086  */

/* ����������� ������ ��� ����������. */
#define NE_FLAGS_PROTECTED_MODE 0x0008    /* ������ ������ � ���������� ������ */

