#include "pch.h"

#include <string>
#include "BDF.h"

TEST(TestCaseName, TestName)
{
	std::string bdf_file = "E:/Documents/Projects/BDF/Fonts/ib8x8u.bdf";
	BDF parser;
	parser.parse(bdf_file);
	EXPECT_EQ(parser.version(), "2.1");
}