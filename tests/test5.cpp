#include <tuple>
#include <gtest/gtest.h>

namespace {

struct ValueResult
{
    int a;
    int b;
    int c;
};

typedef std::tuple<const char*, ValueResult> Parameters;

class TestParamNameCombine : public testing::TestWithParam<Parameters>
{
public:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};

TEST_P(TestParamNameCombine, Add)
{
    const char* desc = std::get<0>(GetParam());
    ValueResult value = std::get<1>(GetParam());
    EXPECT_EQ(value.c, value.a + value.b );
}

const char* desc[] =
{
    "test1",
    "test2",
    "test3",
};

const ValueResult valuesAdd[] =
{
    {0, 1, 1},
    {1, 2, 3},
};

void PrintTo(const Parameters& params, std::ostream* os)
{
    const char* desc = std::get<0>(params);
    ValueResult value = std::get<1>(params);
    *os << "desc_" << desc << "_expected_" << value.c << "_value_" << value.a << "_value_" << value.b;
}


INSTANTIATE_TEST_SUITE_P(TestTestParamInstance,
                        TestParamNameCombine,
                        ::testing::Combine(
                            ::testing::ValuesIn(desc),
                            ::testing::ValuesIn(valuesAdd)
                        ),
                        ::testing::PrintToStringParamName()
                        );


} // end of namespace

