#ifndef MACROS_H
#define MACROS_H	

/* MACROS */

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

#endif /*MACROS_H*/ 
