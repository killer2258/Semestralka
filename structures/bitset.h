/*****************************************************************************
* bitset.h
* Martin Zaťovič
* 20.2.2020
* Hlavičkový súbor obsahujúci makrá a inline funkcie pre prácu s bitovým poľom 
*
* Riešenie úlohy DU1 IJC a)
* Preložené: gcc 7.5.0
******************************************************************************/

#include "error.h"
#include <string.h>
#include <limits.h>
#include <assert.h>

#ifndef _BITSET_H_

#define _BITSET_H_

//macro for number of bits in unsigned long int
#define UNSIGNED_BITS (sizeof(unsigned long) * CHAR_BIT)

//macro for rounding up if the remainder of division is greater than 0
#define DIV_ROUND_UP(a, b) (((a) + (b) - 1)/(b))

	
	typedef unsigned long* bitset_t;
	typedef unsigned long bitset_index_t;

//macro for creating a static bitset
#define bitset_create(jmeno_pole,velikost) \
        unsigned long jmeno_pole[DIV_ROUND_UP(velikost, UNSIGNED_BITS) + 1] = {velikost, 0}; \
        static_assert(velikost > 0, "Zaporna alebo nulova velkost pola ");


//macro for creating a dynamic bitset
#define bitset_alloc(jmeno_pole,velikost) \
	unsigned long* jmeno_pole; \
	assert(velikost > 0); \
	if(!(jmeno_pole = malloc(sizeof(unsigned long) * (DIV_ROUND_UP(velikost, UNSIGNED_BITS) + 1)))) \
	{ \
		fprintf(stderr, "bitset_alloc: Chyba alokace paměti."); \
	}\
	memset(jmeno_pole, 0, (sizeof(unsigned long) * (DIV_ROUND_UP(velikost, UNSIGNED_BITS) + 1))); \
	jmeno_pole[0] = velikost;


//macro for freeing a bitset
#define bitset_free(jmeno_pole) \
	free(jmeno_pole);



#ifdef USE_INLINE
	//inline function that returns size of an array in bits
	static inline unsigned long bitset_size(bitset_t jmeno_pole) {
		return (unsigned long)jmeno_pole[0];
	}

#else

//macro for size of bitset in bits
#define bitset_size(jmeno_pole) \
	(unsigned long)jmeno_pole[0]
		
#endif



#ifdef USE_INLINE
	//inline function for setting a bit to specified value
	static inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz) {
		if(index >= bitset_size(jmeno_pole)) {
			printf("Index %lu je neplatny. Platne indexy su v intervale 0 do %lu.", (bitset_index_t)index, bitset_size(jmeno_pole));
		}
		if(vyraz == 1)
		{
			jmeno_pole[(index / UNSIGNED_BITS) + 1] |= (1LU << (index % UNSIGNED_BITS));
		}
		if(vyraz == 0)
		{
			jmeno_pole[(index / UNSIGNED_BITS) + 1] &= ~(1LU << (index % UNSIGNED_BITS));
		}
	}

#else

//macro for setting a bit to specified value
#define bitset_setbit(jmeno_pole,index,vyraz) \
	do { \
		if(index >= bitset_size(jmeno_pole)) { \
			printf("Index %lu je neplatny. Platne indexy su v intervale 0 do %lu.", (bitset_index_t)index, bitset_size(jmeno_pole)); \
		} \
		if(vyraz == 1) \
		{ \
			jmeno_pole[(index / UNSIGNED_BITS) + 1] |= (1UL << (index % UNSIGNED_BITS)); \
		} \
		if(vyraz == 0) \
		{ \
			jmeno_pole[(index / UNSIGNED_BITS) + 1] &= ~(1UL << (index % UNSIGNED_BITS)); \
		} \
	} \
	while (0)
#endif



#ifdef USE_INLINE
	//inline function that returns a value of bit on specified index
	static inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
		unsigned long flag;
		unsigned long help;
		if(index >= jmeno_pole[0])
		{
			error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu.", (unsigned long)index, bitset_size(jmeno_pole));
			return -1;
		}
		flag = 1;
		flag <<= index % UNSIGNED_BITS;
		help = jmeno_pole[(index / UNSIGNED_BITS) + 1];
		help &= flag;
		if(help != 0)
		{
			return 1;
		}
		else 
			return 0;
	}
#else

//macro for returning a value of bit on specified index
#define bitset_getbit(jmeno_pole,index) \
        ((index >= bitset_size(jmeno_pole)) \
        ? \
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu.", (bitset_index_t)index, bitset_size(jmeno_pole)),0 \
        : \
	((jmeno_pole[(index/UNSIGNED_BITS) + 1] & (1LU << (index % UNSIGNED_BITS))) != 0))

#endif
#endif
