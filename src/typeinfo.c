#include "typeinfo.h"

/*
 * Выводит информацию о элементе структуры + {unsigned char} + \n
 * binfo = byte information output
 */
void binfo(__uint8_t *cell)
{
    t_offset += sizeof(*cell);

    printf("0x%x\t", *cell);
    printf("(offset=%zx,sizeof=%zx)\t__uint8_t\tBYTE\tunsigned char\n", t_offset, sizeof(*cell));
}

/*
 * Выводит информацию о элементе структуры + {unsigned short} + \n
 * winfo = word information output
 */
void winfo(__uint16_t *cell)
{
    t_offset += sizeof(*cell);
    printf("0x%lx\t(offset=%x,sizeof=%zx)\t__uint16_t\tWORD\tunsigned short\n", *cell, t_offset, sizeof(*cell));
}

/*
 * Выводит информацию о элементе структуры {unsigned long} + \n
 * dwinfo = dword (double word) information output
 */
void dwinfo(__uint64_t* cell)
{
    t_offset += sizeof(*cell);
    printf("0x%lx\t(offset=%x,sizeof=%zx)\t__uint64_t\tDWORD\tunsigned long\n", *cell, t_offset, sizeof(*cell));
}

/*
 * Сбрасывает значение счетчика смещений спины
 * (как некомпетентный - не знаю почему изменение t_offset вне файла где он обьявлен - НЕ РАБОТАЕТ
 */
void nulloffset()
{
    t_offset = 0;
}