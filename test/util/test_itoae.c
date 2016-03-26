#include "unity.h"
#include "itoae.h"


#define _BUF_LEN    20

static uint8_t _buf[ _BUF_LEN ];



void _fill_with_0xff(void)
{
    int i;
    for (i = 0; i < sizeof(_buf); i++){
        _buf[i] = 0xff;
    }
}


void setUp(void)
{
}

void tearDown(void)
{
}

void test_basic( void )
{
    _fill_with_0xff();
    itoae(_buf, 123, 0, 0, '0');
    TEST_ASSERT_EQUAL_STRING("123", _buf);

    _fill_with_0xff();
    itoae(_buf, -123, 0, 0, '0');
    TEST_ASSERT_EQUAL_STRING("-123", _buf);
}

void test_width( void )
{
    _fill_with_0xff();
    itoae(_buf, 123, 0, 5, '0');
    TEST_ASSERT_EQUAL_STRING("00123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 0, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("  123", _buf);

    _fill_with_0xff();
    itoae(_buf, -123, 0, 5, '0');
    TEST_ASSERT_EQUAL_STRING("-00123", _buf);

    _fill_with_0xff();
    itoae(_buf, -123, 0, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("-  123", _buf);
}

void test_dpp( void )
{
    _fill_with_0xff();
    itoae(_buf, 123, 1, 0, '0');
    TEST_ASSERT_EQUAL_STRING("12.3", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 2, 0, '0');
    TEST_ASSERT_EQUAL_STRING("1.23", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 3, 0, '0');
    TEST_ASSERT_EQUAL_STRING("0.123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 4, 0, '0');
    TEST_ASSERT_EQUAL_STRING("0.0123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 5, 0, '0');
    TEST_ASSERT_EQUAL_STRING("0.00123", _buf);

    _fill_with_0xff();
    itoae(_buf, -123, 5, 0, '0');
    TEST_ASSERT_EQUAL_STRING("-0.00123", _buf);
}

void test_width_and_dpp( void )
{
    _fill_with_0xff();
    itoae(_buf, 123, 0, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("  123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 1, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("  12.3", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 2, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("  1.23", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 3, 5, ' ');
    TEST_ASSERT_EQUAL_STRING(" 0.123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 4, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("0.0123", _buf);

    _fill_with_0xff();
    itoae(_buf, 123, 5, 5, ' ');
    TEST_ASSERT_EQUAL_STRING("0.00123", _buf);

}