#include "unity.h"
#include "point.h"
#include "mock_display.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_make_point_should_return_a_new_point(void)
{
	struct point pt = make_point(3, 4);
	TEST_ASSERT_EQUAL_INT(3, pt.x);
	TEST_ASSERT_EQUAL_INT(4, pt.y);
}


void test_draw_point_should_draw_both_of_its_coordinates(void)
{
	struct point pt = make_point(3, 4);
	Draw_Int_Expect(3);
  	Draw_Int_Expect(4);
  	DrawPoint(pt);
}