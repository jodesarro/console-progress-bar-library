# Console Progress Bar library: A C++ library for printing the progress of numeric iterations on the console

<p align="center" width="100%">
    <img src="https://github.com/jodesarro/console-progress-bar-library/blob/main/illustration.gif?raw=true">
</p>

## Available functions

### Printing the progress
```
void print(const unsigned int &current_position, const unsigned int &max_position)
```

### Printing a progress of 100%
```
void print_full()
```

### Printing a progress of 0%
```
void print_empty()
```

### Get the percentage of the current progress
```
double get_current_percentage()
```

### Erasing the progress bar out of the console
```
void erase()
```

### Styling

The implementation of the progress bar has a default style of the type `Progress: [=======   ] 70.00%`.
The default style may be changed as desired through the functions listed below.

#### Setting the bar size
```
void set_bar_size(unsigned int bar_size)
```

#### Setting the bar delimiters
```
void set_bar_delimiters(std::string left_delimiter_char, std::string right_delimiter_char)
```

#### Setting the bar fillers
```
void set_bar_fillers(std::string filler_char, std::string blanker_char)
```

#### Note

Notice that although `filler_char`, `blanker_char`, `left_delimiter_char` and `right_delimiter_char` are declared as `std::string`, each one must be a single character that occupies a single space on the console, otherwise they will be restored to the default style. In particular, `left_delimiter_char` and `right_delimiter_char` may be an empty string (`""`). 

## How to use

The library is in a header-only library style, i.e., there is nothing to build, you only have to include the <a href="console-progress-bar-library.hpp">*console-progress-bar-library.hpp*</a> file into your project.

## A simple example

### Input

```
#include <iostream>
#include <unistd.h> // Required for 'sleep()'
#include "console-progress-bar-library.hpp"

int main()
{
  // Creating the object my_progress
  console_progress_bar my_progress;

  // Styling the progress bar
  my_progress.set_bar_size(10);
  my_progress.set_bar_fillers("█", "░");
  my_progress.set_bar_delimiters("", "");

  // Required for printing Unicode chars such as █ and ░ on Windows cmd
  system("chcp 65001 > nul");

  // Printing a progress of 0%
  my_progress.print_empty();

  // Loop for printing the progress after each iteration
  for (int i=0; i<=98; i++)
  {
      sleep(1); // Waiting one second, simulating a slow process
      my_progress.print(i,17); // Printing the progress
  }

  // Printing a progress of 100%
  my_progress.print_full();

  // Erasing the progress bar out of the console
  my_progress.erase();

}
```

### Output

![Illustration](https://github.com/jodesarro/console-progress-bar-library/blob/main/example.gif?raw=true)

### Some interesting Unicode characters for progress bars
█, ░, ⚫, ⚪, ■, ▰, ▱, ...

## Authorship

The codes and routines were developed and are updated by <a href="https://www.researchgate.net/profile/Jhonas-de-Sarro">Jhonas O. de Sarro</a> ([@jodesarro]( https://github.com/jodesarro )).

## Licensing

This project is protected under <a href="LICENSE">MIT License</a>.
