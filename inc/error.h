#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
    no_error,
    enull,
    eduplicated,
    esorted_or_invalid_int,
    enotdigit,
    emaxint
} t_error;

#endif