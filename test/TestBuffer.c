
#include "unity.h"
#include "Buffer.h"
#include "MK20DX256.h"
#include <stdlib.h>
#include <stdio.h>

void test_Buffer_Put_and_Get_Should_WorkTogetherToInsertAndExtractAValue(void)
{
	const uint16_t testData[] = {0, 1, 0x5A, 0x7FFF, 0xFFFF};
	uint16_t fetched;

	for (int i = 0; i < 4; i++)
	{
    	TEST_ASSERT_EQUAL(0, Buffer_Put(testData[i]));
		TEST_ASSERT_EQUAL(0, Buffer_Get(&fetched));
		TEST_ASSERT_EQUAL_HEX16(testData[i], fetched);
	}
}


void test_Buffer_Get_should_ReturnErrorIfCalledWhenEmpty(void)
{
	uint16_t fetched;
	TEST_ASSERT_EQUAL(BUFFER_ERROR_EMPTY, Buffer_Get(&fetched));
}

void test_Buffer_Put_should_ReturnErrorIfCalledWhenFull(void)
{

	int expected[BUFFER_SIZE] = {0};
	int actual[BUFFER_SIZE] = {0};


	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		expected[i] = 0;
		actual[i] = Buffer_Put(i);
	}
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, BUFFER_SIZE);
	TEST_ASSERT_NOT_EQUAL(0, Buffer_Put(1));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Buffer_Put_and_Get_Should_WorkTogetherToInsertAndExtractAValue);
    RUN_TEST(test_Buffer_Get_should_ReturnErrorIfCalledWhenEmpty);
    RUN_TEST(test_Buffer_Put_should_ReturnErrorIfCalledWhenFull);

    return UNITY_END();
}
