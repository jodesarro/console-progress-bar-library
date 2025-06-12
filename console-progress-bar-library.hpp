#include <iostream>
#include <cmath>
#include <codecvt>

class console_progress_bar
{
private:
    std::string _filler_char = "=";
    std::string _blanker_char = " ";
    std::string _left_delimiter_char = "[";
    std::string _right_delimiter_char = "]";
    unsigned int _bar_size = 10;
    double _current_percentage = 0.;
    unsigned int _current_bar_size = 0.;
    bool _is_printed = false;
    int _last_percentage_size = 0;

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
        if (_is_printed)
        {
            erase();
        }
        std::cout << "Progress: " << _left_delimiter_char;
        for ( int i=0; i<_current_bar_size; i++)
        {
            std::cout << _filler_char;
        }
        for ( int i=_current_bar_size; i<_bar_size; i++)
        {
            std::cout << _blanker_char;
        }
        std::cout << _right_delimiter_char;
        printf(" %.2f%%", _current_percentage);
        _is_printed = true;
        if ( _current_percentage >= 100.00 )
        {
            _last_percentage_size = 6;
        }
        else if ( _current_percentage >= 10.00 )
        {
            _last_percentage_size = 5;
        }
        else
        {
            _last_percentage_size = 4;
        }
    };

    void set_bar_fillers( std::string filler_char, std::string blanker_char )
    {
        std::wstring_convert<std::codecvt_utf16<wchar_t>> converter;
        std::wstring wide_string = converter.from_bytes(filler_char);
        if ( wide_string.length() > 1 )
        {
            _filler_char = "=";
        }
        else
        {
            _filler_char = filler_char;
        }
        wide_string = converter.from_bytes(blanker_char);
        if ( wide_string.length() > 1 )
        {
            _blanker_char = " ";
        }
        else
        {
            _blanker_char = blanker_char;
        }
    };

    void set_bar_delimiters( std::string left_delimiter_char, std::string right_delimiter_char )
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wide_string = converter.from_bytes(right_delimiter_char);
        if ( wide_string.length() > 1 )
        {
            _right_delimiter_char = "[";
        }
        else
        {
            _right_delimiter_char = right_delimiter_char;
        }
        wide_string = converter.from_bytes(left_delimiter_char);
        if ( wide_string.length() > 1 )
        {
            _left_delimiter_char = "]";
        }
        else
        {
            _left_delimiter_char = left_delimiter_char;
        }
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

    void erase()
    {
        unsigned int progress_bar_total_size = 12 + _bar_size + _last_percentage_size;
        if (_left_delimiter_char != "")
        {
            progress_bar_total_size += 1;
        }
        if (_right_delimiter_char != "")
        {
            progress_bar_total_size += 1;
        }
        for (int i=0; i<progress_bar_total_size; i++)
        {
            printf("\b \b");
        }
        _is_printed = false;
        _last_percentage_size = 0;
    };
    
};