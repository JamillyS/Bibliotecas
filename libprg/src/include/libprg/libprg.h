#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif


