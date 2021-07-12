# FT_PRINTF 42SP

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-orange)
## My own printf. Because putnbr and putstr aren’t enough

### Description
This is a project from 42 School. Where I recoded the printf, using the following rules:

* The prototype of ft_printf should be `int ft_printf(const char *, ...)`;
* You have to recode the libc’s printf function;
* It must not do the buffer management like the realprintf;
* It will manage the following conversions:cspdiuxX%;
* It will manage any combination of the following flags: ’-0.*’ and minimum fieldwidth with all conversions;

### Download
Feel free to download the project:
```
git clone https://github.com/wblech/ft_printf
```

### Using The Program
Compile the program:
```
make
```
To ```compile``` with your main in local folder:
```
gcc -Wall -Wextra -Werror -L. -lftprintf  main.c -o main
```
### Example of Usage
```
#include "libftprintf.h"

int main(void)
{
	ft_printf("teste\n");
	ft_printf("%i, %d, %x, %X\n", 10, 20, 8783478674, 8783478674);
	ft_printf("%5.10i\n", 4567);
	return (0);
}
```

#### Author
Wincenty Bertoni Lech - [GitHub](https://github.com/wblech/)
