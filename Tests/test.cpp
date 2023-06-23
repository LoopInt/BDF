#include "pch.h"

#include <string>
#include "BDF.h"

TEST(BDF, parse_version)
{
	std::string bdf_file = "E:/Documents/Projects/BDF/Fonts/ib8x8u.bdf";
	BDF parser;
	parser.parse(bdf_file);
	EXPECT_EQ(parser.version(), "2.1");
}

TEST(BDF, parse_font_name)
{
	std::string bdf_file = "E:/Documents/Projects/BDF/Fonts/ib8x8u.bdf";
	BDF parser;
	parser.parse(bdf_file);
	EXPECT_EQ(parser.font_name(), "-IBM-BIOS-Normal-R-Normal--8-60-96-96-C-80-ISO10646-1");
}