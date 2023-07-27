<div align="center">
    <h1>Print-F Project</h1>
</div>

![Holberton School Logo](https://techcrunch.com/wp-content/uploads/2015/11/holberton-logo-horizontal.jpg?w=680)

![UBUNTU](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
## Description

This project is to recreate the printf function in C with its most important features, it was made in the software development program of [Holberton School](https://www.holbertonschool.fr/).

## Man page

The man page is a file wich explains in detail how the function works. If you want see a full explanation of this function you can run our man page this way:
```
$ man ./man_3_printf
```


## Flowchart

![Flowchart](https://github.com/Groinkb/holbertonschool-printf/blob/main/assets/Flowchart%20Template.jpeg)

## Usage

<details open>
<summary> <strong> Syntaxis </strong> </summary>

<br>

```
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
```

- - -

<details open>
<summary> <strong> Compilation </strong> </summary>

<br>


$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
 
 - - -
 
<details open>
<summary> <strong> Supported Conversion Specifiers </strong> </summary>

<br>

* %c : Prints a character.
* %s : Prints a string of characters.
* %i & %d : Prints a signed integer in base 10.
* %% : Prints a literal % character.

</details>

- - -

## Utilisation Exemple

```
#include <stdio.h>

int _printf(const char *format, ...);

int main() 
{
    char ch = 'A';
    char str[] = "Hello, World!";
    int num = 42;

    // Test of the %c specifier
    _printf("Character: %c\n", ch);

    // Test of the %s specifier
    _printf("String: %s\n", str);

    // Test of the %i specifier
    _printf("Number: %i\n", num);

    // Test of the %% specifier
    _printf("Percent sign: %%\n");

    // Test of multiple specifiers in the same string
    _printf("Character: %c, String: %s, Number: %i\n", ch, str, num);

    // Test with an empty string
    _printf("Empty string: %s\n", "");

    // Test with a null character (empty string)
    char empty_str[] = {0};
    _printf("Empty string: %s\n", empty_str);

    return (0);
}
```
Outpout :
```
Character: A
String: Hello, World!
Number: 42
Percent sign: %
Character: A, String: Hello, World!, Number: 42
Empty string:
Empty string:

```


## Authors :fist_right::fist_left:

* Hocine Bouabdallah <a href="https://github.com/HB74C21" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Benjamin Marchal <a href="https://github.com/Groinkb" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* C#21 BDX-THO <a href="https://www.youtube.com/watch?v=vev5icVBU2g" rel="nofollow"><img align="center" alt="heart" src="https://vectorwiki.com/images/a2I5f__heart.svg" height="24" /></a>

## License

This program is distributed under the terms of the Holberton license.