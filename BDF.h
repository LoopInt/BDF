#pragma once

#include <string>
#include <fstream>

class BDF
{
public:
	void parse(std::string bdf_file);
	std::string version();
private:
	std::ifstream _file;
	std::string _version;
};

