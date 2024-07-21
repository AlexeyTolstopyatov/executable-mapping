#pragma once
#include "retyping.h"

/* 
 * � �����������
 * 
 * �������������� �������� � �������� ������� ������������ �����
 * ���� � ��������� �����, ����������� �����, 
 * ��������� ��� ������ ����������� ����� ���������� ����������� ���������.
 * �����������
 *		ARM
 *		MIPS
 *		SPARC (� ����������� �� ��)
 *		ITanium (intel)
 * ���������� �������� ���������� "����� �������"
 *		0x0000
 *		  1234
 * �������� __uint16_t (��� DWORD) ������� �������� 4 ����� (4 ���� ��� 32 ����)
 *		0x0000 -> 0x1000 -> 0x1100 -> 0x0010 -> 0x1010 -> 0x1110 -> 0x0001
 */
#define LX_SIGNATURE_ARM_SEGMENT 0x4c58 /*'L' 'X'*/
#define LE_SIGNATURE_ARM_SEGMENT 0x4c45 /*'L' 'E'*/
#define NE_SIGNATURE_ARM_SEGMENT 0x4e45 /*'N' 'E'*/
#define PE_SIGNATURE_ARM_SEGMENT 0x5045 /*'P' 'E'*/
#define MZ_SIGNATURE_ARM_SEGMENT 0x4d5a /*'M' 'Z'*/ 
/*
 * ������� �� Intel
 * 
 * ���� � ����� ���������, ������ �������� � ������ ������ (�������� __uint16_t ����)
 * ���������� ������ ������. �� ����: 
 *		0x0000 (DWORD ��� __uint16_t) �������� 4 �����. (��� 32 ����)
 *		  4321
 * ������ � ������� ����� ��� �� ��� �� �����.
 * 0x0001 -> 0x0010 -> 0x0011 -> 0x0100 -> 0x0101 -> 0x0111 -> 0x1000
 * 
 */
#define MZ_SIGNATURE_INTEL_SEGMENT 0x5a4d /*'Z' 'M'*/
#define NE_SIGNATURE_INTEL_SEGMENT 0x454e /*'E' 'N'*/ 
#define PE_SIGNATURE_INTEL_SEGMENT 0x4550 /*'E' 'P'*/
#define LE_SIGNATURE_INTEL_SEGMENT 0x454c /*'E' 'L'*/ 
#define LX_SIGNATURE_INTEL_SEGMENT 0x584c /*'X' 'L'*/

/*
 * ��������� "Portable Executable"
 *		��� ����������� (��� � �������)
 *		����������� ������ (.data .rdata .text .src .rcrs)
 *		
 *		��������� �� ������� ��������
 *		����������� ��������
 *		������ (�� �������������?) ������������� ���������
 *		��������������
 */
struct PE_HEADER
{
	__uint8_t  machine;
	__uint8_t  sections_count;
	__uint16_t time_stamp;
	__uint16_t symtable_ptr;
	__uint16_t symbols_count;
	__uint8_t  sizeof_optional_header;
	__uint8_t  characteristics;
};

/*
 * �������������� PE ���������
 *		������� (PE32 ��� PE32+)
 *		�������� (��� ��������) ������ �������� (�������) 
 *		�������� (��������������) ������ ��������
 *		������ ����
 *		������ ������������������ ����� ������
 *		������ ��_������������������ ����� ������
 *		��������� �� ����� ����� (main(...) _tmain(...) ��� ��)
 *		���		(.code)
 *		������	(.data)
 *		����� ���������
 *		������������ ������
 *		������������ ������
 *		�������� ������ ��
 *		�������������� ������ ��
 *		�������� ������ ����������
 *		�������������� ������ ����������
 *		������ ���������� (����������) Win32
 *		������ ������ (���������)
 *		������ ���������
 *		����������� �����
 *		����������
 *		�������������� DLL (����������� ��������� ����������)
 *		������ ������� �����
 *		������ ������� � ����
 *		������ ������� ����
 *		������ ������� � ����
 *		����� ����������
 *		(������ ���� ���... ������ ������ ��������� �������)
 */
struct OPTIONAL_PE_HEADER
{
	__uint8_t  signature;
	__uint8_t  maj_linkv;
	__uint8_t  min_linkv;
	__uint16_t sizeof_code;
	__uint16_t sizeof_init;
	__uint16_t sizeof_uninit;
	__uint16_t entry_point_address;
	__uint16_t code;
	__uint16_t data;
	__uint16_t image;
	__uint16_t sect_alignment;
	__uint16_t file_alignment;
	__uint8_t  maj_os_version;
	__uint8_t  min_os_version;
	__uint8_t  maj_subenv_version;
	__uint8_t  min_subenv_version;
	__uint16_t win32_version;
	__uint16_t sizeof_image;
	__uint16_t sizeof_headers;
	__uint16_t checksum;
	__uint8_t  sub_environment;
	__uint8_t  dll_characteristics;
	__uint16_t sizeof_stack_reserve;
	__uint16_t sizeof_stack_commit;
	__uint16_t sizeof_heap_reserve;
	__uint16_t sizeof_heap_commit;
	__uint16_t loader_flags;
	/* .data catalog struct */
};


/*
 * DOS-��������� ��� MZ ���������
 * MZ ��� Mark Zbikowski (������� Microsoft), ������������ ������
 * ���������.
 *		������� MZ (��� ZM)
 *		������ ���������� �����
 *		����� �����
 *		����������� �����������
 *		������
 *		����������� ���������� �������
 *		������������ ���������� �������
 *		����� ������������� �������� ��� �������� SS
 *		����������� �������� �������� ��� SP
 *		����������� ����� (������ �� �����������, ����� ���� 0)
 *		����������� �������� ��� IP
 *		��������� �� ������� ��� CS ��������
 *		������� �����������
 *		����� ���������� (������ ���������� ���������� �������������� ������, ��� ��� ���)
 *		���������������� ��� 0x1C (8 ���� ��� QWORD ��� __uint64_t)
 *		OEM ������������� (OEM -- ������������ ������������� ������������)
 *		���������� � �������������
 *		����������������� ��� 0x28
 *		����� ���������� ��������� (��� E_LFANEW)
 */
struct MZ_HEADER 
{
	__uint16_t mz_signature;
	__uint16_t last_block_size;
	__uint16_t file_blocks;
	__uint16_t relocations_count;
	__uint16_t paragraphs;
	__uint16_t min_extra_paragraphs;
	__uint16_t max_extra_paragraphs;
	__uint16_t ss;
	__uint16_t sp;
	__uint16_t checksum;
	__uint16_t ip;
	__uint16_t cs;
	__uint16_t reloc_table_offset;
	__uint16_t overlay_number;
	__uint16_t secured_0x1c[4];
	__uint16_t oem_id;
	__uint16_t oem_info;
	__uint16_t secured_0x28[10];
	__uint16_t next_signature; /* e_lfanew (���������������� "long file address of New Executable"... �� ������ long???) */
};


struct NT_HEADER /*�� ��...*/
{
	__uint16_t pe_signature;
	PE_HEADER header;
	OPTIONAL_PE_HEADER optional_header;
};

/* 
 * New Executable ���������
 * ����� ��� ��������� ������ ��� ����������� ������
 * ������������� � .EXE ������ ��������� ��� MS-DOS � MS-Windows 3x
 *		�������
 *		������
 *		�������
 *		�������� �� ������� ���������
 *		����������� �����
 *		������������� ����������� ������� (��...)
 *		����������� ������������� ����
 *		����������� ������������� �����
 *		����������� �������� � CS:IP
 *		����������� �������� � SS:SP
 *		���������� ���������
 *		"Module Reference Table" �������� ��������-��������� �������
 *		������ ������� ���� (�� ����������?)
 *		�������� ������� ���������
 *		�������� ������� ��������
 *		�������� ������� ���� ����������
 *		�������� ��������-��������� �������
 * ��� �������� ������� ��������
 *		������������
 *		���������� ��������� ��������
 *		������������ ������� (��������, ��� ������� ��� ��� ������� ���������� ����������)
 *		������ ����� ��� ����������
 *		������ ������������ ��������
 *		�������� �� ������������ ��������
 *		����������� ������ �������� ����
 *		��������� ������ ������������ �������
 */
struct NE_HEADER 
{
	__uint16_t signature;
	__uint8_t  version;
	__uint8_t  revision;
	__uint16_t entry_table_offset;
	__uint16_t sizeof_entry_table;
	__uint64_t checksum;
	__uint16_t flag;
	__uint16_t auto_data_segment;
	__uint16_t heap;
	__uint16_t stack;
	__uint64_t csip; /*Code Segment:IP*/
	__uint64_t sssp; /*Source Segment?:Source Page*/
	__uint16_t segments_count;
	__uint16_t module_reft_entries;
	__uint16_t sizeof_name_table;
	__uint16_t segment_table_offset;
	__uint16_t resources_table_offset;
	__uint16_t resident_name_table_offset;
	__uint16_t module_reference_table_offset;
	__uint16_t imports_table_offset;
	__uint64_t nonresident_name_table_offset;
	__uint16_t mov_entries_count;
	__uint16_t align;
	__uint16_t resource_segments_count;
	__uint8_t  os; /*target*/
	__uint8_t  oflag; /*another flags*/
	__uint16_t ret_entries_count;
	__uint16_t refbytes_segment_offset; /*???*/ 
	__uint16_t sizeof_codearea;
	__uint16_t expected_os;
};

/*
 *		����?
 * �� ������� ����������� �������� ��� Windows 3x/9x
 * ���������� LE ���������, ����� ���������� � �������� ����
 * ����� � LE ���������.
 * 
 */
struct LE_HEADER 
{
	LX_HEADER os2_header;
	VXD_HEADER driver_header;
};
/*
 * LX ��������� ��� �������� ������ ��� Microsoft Windows 95
 * � ������������� ������ ��� IBM OS/2.
 * 
 *		���� � ����� �����, ��������� ���������� OS/2 � VXD (��� .386 ��������)
 * ����������. �� ���????
 *		�� ����, ���� ���������� � LE/LX ���������� ��������� �� Windows 98,
 * (��� � DOS), �� Windows 9x ������������ ���������� � OS/2 ����������, ������ ���...
 * ������ API ��� OS/2 ���������� ����� �� OS/2. ������� ���� __uint8_t ������� ��� ����������� ��.
 */
struct LX_HEADER
{
	__uint16_t signature;
	__uint8_t  byte_order;
	__uint8_t  word_order;
	/*--------------------*/
	__uint64_t format;
	__uint16_t cpu;
	__uint16_t os;
	__uint64_t module_version;
	__uint64_t module_flags;
	__uint64_t module_pages;
	__uint64_t eip_object_num;
	__uint64_t eip;
	__uint64_t esp_object_num;
	__uint64_t esp;
	__uint64_t sizeof_page;
	__uint64_t sizeof_last_page;
	__uint64_t sizeof_fix_section;
	__uint64_t sizeof_fix_section_check;
	__uint64_t sizeof_loader_section;
	__uint64_t sizeof_loader_section_check;
	__uint64_t object_table_offset;
	__uint64_t object_table_entries;
	__uint64_t object_page_map_offset;
	__uint64_t object_iterdata_offset;
	__uint64_t rsrc_table_offset;
	__uint64_t rsrc_table_entries;
	__uint64_t resident_names_table_offset;
	__uint64_t entry_table_offset;
	__uint64_t module_direct_offset;
	__uint64_t module_direct_entries;
	__uint64_t fix_page_offset;
	__uint64_t fix_records_offset;
	__uint64_t imported_names_table_offset;
	__uint64_t imports_count;
	__uint64_t import_procs_offset;
	__uint64_t perpage_check_offset;
	__uint64_t data_pages_offset;
	__uint64_t preload_pages_count;
	__uint64_t nonresident_names_table_offset;
	__uint64_t nonresident_names_check;
	__uint64_t automatic_data_object;
	__uint64_t dbg_information_offset;
	__uint64_t dbg_information_len;
	__uint64_t preload_instance_pages_count;
	__uint64_t demand_instance_pages_count;
	__uint64_t heap;
	__uint64_t stack;
	__uint8_t  reserved[8];
};

struct VXD_HEADER 
{
	__uint64_t win_resoff;
	__uint64_t win_reslen;
	__uint16_t dev_id;
	__uint16_t ddk_version;
};