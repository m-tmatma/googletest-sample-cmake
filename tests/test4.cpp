#include <gtest/gtest.h>

namespace {

struct ValueResult
{
    int a;
    int b;
    int c;
};

class TestParamName : public testing::TestWithParam<ValueResult>
{
public:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};

TEST_P(TestParamName, Add)
{
    ValueResult value = GetParam();
    EXPECT_EQ(value.c, value.a + value.b );
}

const ValueResult valuesAdd[] =
{
    {0, 1, 1},
    {1, 2, 3},
};

void PrintTo(const ValueResult& value, std::ostream* os)
{
    *os << "expected_" << value.c << "_value_" << value.a << "_value_" << value.b;
}


INSTANTIATE_TEST_SUITE_P(TestTestParamInstance,
                        TestParamName,
                        ::testing::ValuesIn(valuesAdd),
                        ::testing::PrintToStringParamName()
                        );


} // end of namespace

