# Console Progress Bar library: A C++ library for printing the progress of numeric iterations on the console


<p align="center" width="100%">
    <img src="https://github.com/jodesarro/console-progress-bar-library/blob/main/illustration.gif">
</p>

## Available functions

### Printing the progress
```
void progress_bar::print(const unsigned int &current_position, const unsigned int &max_position)
```

### Printing a progress of 100%
```
void progress_bar::fill()
```

### Printing a progress of 0%
```
void progress_bar::empty()
```

### Getting (or setting without any effect) the percentage of the current progress
```
double progress_bar::current_percentage;
```

### Styling the progress bar
```
void progress_bar::style( std::string fill_char, std::string empty_char = " ", std::string left_delimiter_char = "[", std::string right_delimiter_char = "]", unsigned int bar_size = 10 )
```
Notice that although `fill_char`, `empty_char`, `left_delimiter_char` and `right_delimiter_char` are declared as `std::string`, each one must be a single character that occupies a single space on the console. Also, the `left_delimiter_char` and `right_delimiter_char` may be empty (`""`) if it is desired.


### Clearing the progress bar out of the console
```
void progress_bar::clear()
```

## How to use

The library is in a header-only library style, i.e., there is nothing to build, you only have to include the <a href="mtxdat-library.hpp">*mtxdat-library.hpp*</a> file into your project.

## A simple example

### Input

```
#include <iostream>
#include <unistd.h> // Required for 'sleep()'
#include "console-progress-bar.hpp"

int main()
{
  // Styling progress bar
  progress_bar::style( "█", "░", "", "", 10 );
  
  // Required for printing Unicode chars on Windows cmd
  system("chcp 65001 > nul");

  // Printing a progress of 0%
  progress_bar::empty();

  // Loop printing the progress after each iteration
  for (int i=0; i<=98; i++)
  {
      sleep(1); // Waiting one second, simulating a slow process
      progress_bar::print(i,17); // Printing the progress
  }

  // Printing a progress of 100%
  progress_bar::fill();

  // Clearing the progress bar out of the console
  progress_bar::clear();
}
```

### Output

![Illustration](https://github.com/jodesarro/console-progress-bar-library/blob/main/example.gif)

### Some interesting Unicode characters for progress bars
█, ░, ⚫, ⚪, ■, ▰, ▱, ...

## Authorship

The codes and routines were developed and are updated by <a href="https://www.researchgate.net/profile/Jhonas-de-Sarro">Jhonas O. de Sarro</a> ([@jodesarro]( https://github.com/jodesarro )).

## Licensing

This project is protected under <a href="LICENSE">MIT License</a>.
