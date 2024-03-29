/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#ifndef OUTPUTSTREAM_H_
#define OUTPUTSTREAM_H_

#include <stdio.h>
#include <stdlib.h>

#define EXIT(code) exit(code);

// To make it bold, add 01; between the brace and the number 

#define STDERR_RED(...)         \
  fprintf(stderr, "\033[91m");  \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, "\033[0m");

#define STDOUT_GREEN(...)       \
  fprintf(stdout, "\033[92m");  \
  fprintf(stdout, __VA_ARGS__); \
  fprintf(stdout, "\033[0m");

#endif // OUTPUTSTREAM_H_
