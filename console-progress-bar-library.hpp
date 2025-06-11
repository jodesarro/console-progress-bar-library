#include <iostream>
#include <cmath>

class console_progress_bar
{
private:
    std::string _fill_char = "=";
    std::string _blank_char = " ";
    std::string _left_delimiter_char = "[";
    std::string _right_delimiter_char = "]";
    unsigned int _bar_size = 10;
    double _current_percentage = 0.;
    unsigned int _current_bar_size = 0.;

public:
    void print( const unsigned int &current_position, const unsigned int &max_position )
    {
        if ( current_position < max_position )
        {
            _current_bar_size = int(floor(double(_bar_size)*double(current_position)/double(max_position)));
            _current_percentage = 100.*double(current_position)/double(max_position);
        }
        else
        {
            _current_bar_size = _bar_size;
            _current_percentage = 100.;
        }
        clear();
        std::cout << "Progress: " << _left_delimiter_char;
        for ( int i=0; i<_current_bar_size; i++)
        {
            std::cout << _fill_char;
        }
        for ( int i=_current_bar_size; i<_bar_size; i++)
        {
            std::cout << _blank_char;
        }
        std::cout << _right_delimiter_char;
        printf(" %.2f%%", _current_percentage);
    };

    void set_bar_fillers( std::string fill_char, std::string blank_char )
    {
        _fill_char = fill_char;
        _blank_char = blank_char;
    };

    void set_bar_delimiters( std::string left_delimiter_char, std::string right_delimiter_char )
    {
        _right_delimiter_char = right_delimiter_char;
        _left_delimiter_char = left_delimiter_char;
    };

    void set_bar_size( unsigned int bar_size )
    {
        _bar_size = bar_size;
    };

    double get_current_percentage()
    {
        return _current_percentage;
    };

    void print_full()
    {
        print(0, 0);
    };

    void print_empty()
    {
        print(0, 1);
    };

    void clear()
    {
        int left_delimiter_char_size;
        _left_delimiter_char == "" ? left_delimiter_char_size=0 : left_delimiter_char_size=1;
        int right_delimiter_char_size;
        _right_delimiter_char == "" ? right_delimiter_char_size=0 : right_delimiter_char_size=1;
        int percentage_size;
        if ( _current_percentage >= 100. )
        {
            percentage_size = 6;
        }
        else if ( _current_percentage >= 10. )
        {
            percentage_size = 5;
        }
        else
        {
            percentage_size = 4;
        }
        for (int i=0; i<10 + left_delimiter_char_size + _bar_size + right_delimiter_char_size + 1 + percentage_size + 1; i++)
        {
            std::cout << "\b \b";
        }
    };
    
};