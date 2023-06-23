#pragma once

#include <string>
#include <fstream>

class BDF
{
public:
	void parse(std::string bdf_file);
	std::string version();
	std::string font_name();
	unsigned int point_size;
	unsigned int res_x;
	unsigned int res_y;
private:
	std::ifstream _file;
	std::string _current_line;
	std::string::iterator _it;

	void next_line();
	std::string read_string();
	int read_int();

	std::string _version;
	std::string _font_name;
	
};



