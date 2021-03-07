#include "pdclib/_PDCLIB_internal.h"

int _PDCLIB_double_split( double value, unsigned * exponent, _PDCLIB_bigint_t * significand )
{
    union
    {
        double value;
        unsigned char byte[ sizeof( double ) ];
    } dbl = { value };

    *exponent            = ( ( (unsigned)dbl.byte[7] & 0x7F ) <<  4 ) | ( ( (unsigned)dbl.byte[6] & 0xF0 ) >>  4 );

#if _PDCLIB_BIGINT_DIGIT_BITS == 32
    significand->data[1] = ( ( (unsigned)dbl.byte[6] & 0x0F ) << 16 ) |   ( (unsigned)dbl.byte[5]          <<  8 ) |   (unsigned)dbl.byte[4];
    significand->data[0] =   ( (unsigned)dbl.byte[3]          << 24 ) |   ( (unsigned)dbl.byte[2]          << 16 ) | ( (unsigned)dbl.byte[1] << 8 ) | (unsigned)dbl.byte[0];
    significand->size    = 2;
#else
    significand->data[3] =   (unsigned)dbl.byte[6] & 0x0F;
    significand->data[2] = ( (unsigned)dbl.byte[5] << 8 ) | (unsigned)dbl.byte[4];
    significand->data[1] = ( (unsigned)dbl.byte[3] << 8 ) | (unsigned)dbl.byte[2];
    significand->data[0] = ( (unsigned)dbl.byte[1] << 8 ) | (unsigned)dbl.byte[0];
    significand->size    = 4;
#endif

    return dbl.byte[7] >> 7;
}
