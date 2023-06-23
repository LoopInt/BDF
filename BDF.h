#pragma once

#include <string>
#include <fstream>
#include <map>

class BDF
{
public:
	void parse(std::string bdf_file);
	std::string version();
	std::string font_name();

	std::string get_property(std::string property_name);

	unsigned int point_size;
	unsigned int res_x;
	unsigned int res_y;

	unsigned bounding_box_x;
	unsigned bounding_box_y;
	unsigned bounding_box_dis_x;
	unsigned bounding_box_dis_y;
private:
	std::ifstream _file;
	std::string _current_line;
	std::string::iterator _it;

	void next_line();
	std::string read_string();
	int read_int();

	void _parse_properties();

	std::string _version;
	std::string _font_name;
	std::map<std::string, std::string> _properties;
};
