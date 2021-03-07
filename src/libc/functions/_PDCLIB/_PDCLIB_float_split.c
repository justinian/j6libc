#include "pdclib/_PDCLIB_internal.h"

int _PDCLIB_float_split( float value, unsigned * exponent, _PDCLIB_bigint_t * significand )
{
    union
    {
        float value;
        unsigned char byte[ sizeof( float ) ];
    } flt = { value };

    *exponent            = ( ( (unsigned)flt.byte[3] & 0x7F ) <<  1 ) | ( (unsigned)flt.byte[2] >> 7 );

#if _PDCLIB_BIGINT_DIGIT_BITS == 32
    significand->data[0] = ( ( (unsigned)flt.byte[2] & 0x7F ) << 16 ) | ( (unsigned)flt.byte[1] << 8 ) | (unsigned)flt.byte[0];
    significand->size    = 1;
#else
    significand->data[1] =   (unsigned)flt.byte[2] & 0x7F;
    significand->data[0] = ( (unsigned)flt.byte[1] << 8 ) | (unsigned)flt.byte[0];
    significand->size    = 2;
#endif

    return flt.byte[3] >> 7;
}
