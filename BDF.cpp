#include "BDF.h"

void BDF::parse(std::string bdf_file)
{
    _file = std::ifstream(bdf_file);
    if (!_file.is_open())
    {
        throw std::exception("Cannot open the file !");
    }

    std::string line;

    std::getline(_file, line);
    if (line.substr(0, 10) == "STARTFONT ")
    {
        _version = line.substr(10, line.size() - 10);
    }

    _file.close();
}

std::string BDF::version()
{
    return _version;
}
