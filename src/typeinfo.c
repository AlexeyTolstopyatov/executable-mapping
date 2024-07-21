#include "typeinfo.h"

/*
 * Выводит таблицу с информацией о элементе + {unsigned char} + \n
 */
void binfo(__uint8_t *cell)
{
    t_offset += sizeof(*cell);

    printf("0x%x\t", *cell);
    printf("(offset=%zx,sizeof=%zx)\t__uint8_t\tBYTE\tunsigned char\n", t_offset, sizeof(*cell));
}

/*
 * Выводит таблицу с информацией о элементе + {unsigned short} + \n
 */
void winfo(__uint16_t *cell)
{
    t_offset += sizeof(*cell);
    printf("0x%lx\t(offset=%x,sizeof=%zx)\t__uint16_t\tWORD\tunsigned short\n", *cell, t_offset, sizeof(*cell));
}

/*
 * Выводит таблицу с информацией о элементе {unsigned long} + \n
 */
void dwinfo(__uint64_t* cell)
{
    t_offset += sizeof(*cell);
    printf("0x%lx\t(offset=%x,sizeof=%zx)\t__uint64_t\tDWORD\tunsigned long\n", *cell, t_offset, sizeof(*cell));
}

void nulloffset()
{
    t_offset = 0;
}