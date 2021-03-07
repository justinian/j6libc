#include "pdclib/_PDCLIB_internal.h"

int _PDCLIB_long_double_split( long double value, unsigned * exponent, _PDCLIB_bigint_t * significand )
{
    union
    {
        long double value;
        unsigned char byte[ sizeof( long double ) ];
    } ldbl = { value };

#if defined( _PDCLIB_LDBL_64 )

    *exponent            = ( ( (unsigned)ldbl.byte[7] & 0x7F ) <<  4 ) | ( ( (unsigned)ldbl.byte[6] & 0xF0 ) >>  4 );
#if _PDCLIB_BIGINT_DIGIT_BITS == 32
    significand->data[1] = ( ( (unsigned)ldbl.byte[6] & 0x0F ) << 16 ) |   ( (unsigned)ldbl.byte[5]          <<  8 ) |   (unsigned)ldbl.byte[4];
    significand->data[0] =   ( (unsigned)ldbl.byte[3]          << 24 ) |   ( (unsigned)ldbl.byte[2]          << 16 ) | ( (unsigned)ldbl.byte[1] << 8 ) | (unsigned)ldbl.byte[0];
    significand->size    = 2;
#else
    significand->data[3] =   (unsigned)ldbl.byte[6] & 0x0F;
    significand->data[2] = ( (unsigned)ldbl.byte[5] << 8 ) | (unsigned)ldbl.byte[4];
    significand->data[1] = ( (unsigned)ldbl.byte[3] << 8 ) | (unsigned)ldbl.byte[2];
    significand->data[0] = ( (unsigned)ldbl.byte[1] << 8 ) | (unsigned)ldbl.byte[0];
    significand->size    = 4;
#endif
    return ldbl.byte[7] >> 7;

#elif defined( _PDCLIB_LDBL_80 )

    *exponent            = ( ( (unsigned)ldbl.byte[9] & 0x7F ) <<  8 ) |   (unsigned)ldbl.byte[8];
#if _PDCLIB_BIGINT_DIGIT_BITS == 32
    significand->data[1] = ( (unsigned)ldbl.byte[7] << 24 ) | ( (unsigned)ldbl.byte[6] << 16 ) | ( (unsigned)ldbl.byte[5] << 8 ) | (unsigned)ldbl.byte[4];
    significand->data[0] = ( (unsigned)ldbl.byte[3] << 24 ) | ( (unsigned)ldbl.byte[2] << 16 ) | ( (unsigned)ldbl.byte[1] << 8 ) | (unsigned)ldbl.byte[0];
    significand->size    = 2;
#else
    significand->data[3] = ( (unsigned)ldbl.byte[7] << 8 ) | (unsigned)ldbl.byte[6];
    significand->data[2] = ( (unsigned)ldbl.byte[5] << 8 ) | (unsigned)ldbl.byte[4];
    significand->data[1] = ( (unsigned)ldbl.byte[3] << 8 ) | (unsigned)ldbl.byte[2];
    significand->data[0] = ( (unsigned)ldbl.byte[1] << 8 ) | (unsigned)ldbl.byte[0];
    significand->size    = 4;
#endif
    return ldbl.byte[9] >> 7;

#elif defined( _PDCLIB_LDBL_128 )

    *exponent            = ( ( (unsigned)ldbl.byte[15] & 0x7F ) <<  8 ) |   (unsigned)ldbl.byte[14];
#if _PDCLIB_BIGINT_DIGIT_BITS == 32
    significand->data[3] = ( (unsigned)ldbl.byte[13] <<  8 ) |   (unsigned)ldbl.byte[12];
    significand->data[2] = ( (unsigned)ldbl.byte[11] << 24 ) | ( (unsigned)ldbl.byte[10] << 16 ) | ( (unsigned)ldbl.byte[9] << 8 ) | (unsigned)ldbl.byte[8];
    significand->data[1] = ( (unsigned)ldbl.byte[ 7] << 24 ) | ( (unsigned)ldbl.byte[ 6] << 16 ) | ( (unsigned)ldbl.byte[5] << 8 ) | (unsigned)ldbl.byte[4];
    significand->data[0] = ( (unsigned)ldbl.byte[ 3] << 24 ) | ( (unsigned)ldbl.byte[ 2] << 16 ) | ( (unsigned)ldbl.byte[1] << 8 ) | (unsigned)ldbl.byte[0];
    significand->size    = 4;
#else
    significand->data[6] = ( (unsigned)ldbl.byte[13] << 8 ) | (unsigned)ldbl.byte[12];
    significand->data[5] = ( (unsigned)ldbl.byte[11] << 8 ) | (unsigned)ldbl.byte[10];
    significand->data[4] = ( (unsigned)ldbl.byte[ 9] << 8 ) | (unsigned)ldbl.byte[ 8];
    significand->data[3] = ( (unsigned)ldbl.byte[ 7] << 8 ) | (unsigned)ldbl.byte[ 6];
    significand->data[2] = ( (unsigned)ldbl.byte[ 5] << 8 ) | (unsigned)ldbl.byte[ 4];
    significand->data[1] = ( (unsigned)ldbl.byte[ 3] << 8 ) | (unsigned)ldbl.byte[ 2];
    significand->data[0] = ( (unsigned)ldbl.byte[ 1] << 8 ) | (unsigned)ldbl.byte[ 0];
    significand->size    = 7;
#endif
    return ldbl.byte[15] >> 7;

#else
#error Unsupported long double encoding.
#endif
}
