#pragma once

/*		(C) Толстопятов Алексей А.
 * Работая с Windows API иногда хочется 
 * не работать. 
 * Наверное лучше определить свою типизацию данных
 * В структурах будет слишком много элементов
 * 
 * Чтобы детальнее определять исполняемый файл, прийдется вводить замены и определения 
 * для некоторых 16разрядных значений
 * 
 * #define _OS2_ 0x02
 * #define _DOS_ 0x03
 * #define _WIN386_ 0x04
 * 
 */

typedef unsigned long	 __uint64_t;	/* DWORD */
typedef unsigned char	 __uint8_t;		/* BYTE */
typedef unsigned short	 __uint16_t;	/* WORD */
typedef unsigned int	 __uint32_t;	/* DWORD32 */