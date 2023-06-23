#include "BDF.h"

void BDF::parse(std::string bdf_file)
{
    _file = std::ifstream(bdf_file);
    if (!_file.is_open())
    {
        throw std::exception("Cannot open the file !");
    }

    next_line();
    if (read_string() == "STARTFONT")
    {
        _version = read_string();
    }

    next_line();
    if (read_string() == "FONT")
    {
        _font_name = read_string();
    }

    next_line();
    if (read_string() == "SIZE")
    {
        point_size = read_int();
        res_x = read_int();
        res_y = read_int();
    }

    _file.close();
}

std::string BDF::version()
{
    return _version;
}

std::string BDF::font_name()
{
    return _font_name;
}

std::string BDF::read_string()
{
    std::string value;

    while (*_it == ' ')
    {
        _it++;
    }

    if (_it == _current_line.end())
    {
        throw std::exception("No word to parse !");
    }

    while (_it != _current_line.end() && *_it != ' ')
    {
        value.push_back(*_it);
        _it++;
    }

    return value;
}

int BDF::read_int()
{
    std::string value = read_string();
    return std::stoi(value);
}

void BDF::next_line()
{
    std::getline(_file, _current_line);
    _it = _current_line.begin();
}
