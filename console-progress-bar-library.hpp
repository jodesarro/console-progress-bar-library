#include <iostream>
#include <cmath>

namespace progress_bar
{

namespace _internal
{
std::string _fill_char = "=";
std::string _empty_char = " ";
std::string _left_delimiter_char = "[";
std::string _right_delimiter_char = "]";
unsigned int _bar_size = 10;
}

double current_percentage = 0.;

void print(const unsigned int &current_position, const unsigned int &max_position)
{
    unsigned int current_bar_size;
    if ( current_position < max_position )
    {
       current_bar_size = int(floor(double(_internal::_bar_size)*double(current_position)/double(max_position)));
       current_percentage = 100.*double(current_position)/double(max_position);
    }
    else
    {
        current_bar_size = _internal::_bar_size;
        current_percentage = 100.0;
    }
    std::cout << "\r" << "Progress: " << _internal::_left_delimiter_char;
    for ( int i=0; i<current_bar_size; i++)
    {
        std::cout << _internal::_fill_char;
    }
    for ( int i=current_bar_size; i<_internal::_bar_size; i++)
    {
        std::cout << _internal::_empty_char;
    }
    std::cout << _internal::_right_delimiter_char;
    printf(" %.1f%%", current_percentage);
}

void style ( std::string fill_char, std::string empty_char = " ", std::string left_delimiter_char = "[", std::string right_delimiter_char = "]", unsigned int bar_size = 10 )
{
    _internal::_fill_char = fill_char;
    _internal::_empty_char = empty_char;
    _internal::_right_delimiter_char = right_delimiter_char;
    _internal::_left_delimiter_char = left_delimiter_char;
    _internal::_bar_size = bar_size = 10;
}

void fill()
{
    print(0, 0);
}

void empty()
{
    print(0, 1);
}

void clear()
{
    int left_delimiter_char_size;
    _internal::_left_delimiter_char = "" ? left_delimiter_char_size=0 : left_delimiter_char_size=1;
    int right_delimiter_char_size;
    _internal::_right_delimiter_char = "" ? right_delimiter_char_size=0 : right_delimiter_char_size=1;
    for (int i=0; i<10 + left_delimiter_char_size + _internal::_bar_size + right_delimiter_char_size + 1 + 6; i++)
    {
        std::cout << "\b";
    }
}

}
