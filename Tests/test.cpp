#include "pch.h"

#include <string>
#include "BDF.h"


class BDF_Tests : public ::testing::Test
{

protected:
	BDF parser;

	virtual void SetUp()
	{
		std::string bdf_file = "E:/Documents/Projects/BDF/Fonts/ib8x8u.bdf";
		parser.parse(bdf_file);
	}
};

TEST_F(BDF_Tests, parse_version)
{
	EXPECT_EQ(parser.version(), "2.1");
}

TEST_F(BDF_Tests, parse_font_name)
{
	EXPECT_EQ(parser.font_name(), "-IBM-BIOS-Normal-R-Normal--8-60-96-96-C-80-ISO10646-1");
}

TEST_F(BDF_Tests, parse_size)
{
	EXPECT_EQ(parser.point_size, 6);
	EXPECT_EQ(parser.res_x, 96);
	EXPECT_EQ(parser.res_y, 96);
}