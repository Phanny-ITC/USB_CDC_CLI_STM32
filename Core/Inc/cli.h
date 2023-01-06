/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Anh Vo Tuan <votuananhs@gmail.com>
 *
 * Copyright (c) 2020 Sovichea Tep <sovichea.tep@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __CLI_H__
#define __CLI_H__

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "main.h"
//#define FREERTOS_ENABLED
#ifdef FREERTOS_ENABLED
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#endif


#ifndef USE_COLOR
#define USE_COLOR 1
#endif

#define DELIMITER_CHARACTERS    " "
#define LEN_INPUT_BUFFER        100

#define PROMPT  ">>"

#define ESC          	"\033"
#define RESET        	ESC "[0m"
#define CLEAR_SCREEN 	ESC "c" ESC "[3J"

#if (USE_COLOR)
/* ANSI Color using Escape Sequences */
/* Dark colors*/
#define DB    ESC "[30m"    // Dark Black.
#define DR    ESC "[31m"    // Dark Red.
#define DG    ESC "[32m"    // Dark Green.
#define DY    ESC "[33m"    // Dark Yellow.
#define DS    ESC "[34m"    // Dark Sky. (Dark blue)
#define DP    ESC "[35m"    // Dark Pink.
#define DC    ESC "[36m"    // Dark Cyan.
#define DW    ESC "[37m"    // Dark white. (Light Gray)

/* Bold light colors */
#define BB    ESC "[30;1m"  // Light Black.
#define BR    ESC "[31;1m"  // Light Red.
#define BG    ESC "[32;1m"  // Light Green.
#define BY    ESC "[33;1m"  // Light Yellow.
#define BS    ESC "[34;1m"  // Light Sky. (Light blue)
#define BP    ESC "[35;1m"  // Light Pink.
#define BC    ESC "[36;1m"  // Light Cyan.
#define BW    ESC "[37;1m"  // Light white.
#else
  /* Dark colors*/
  #define DB    ""    // Dark Black.
  #define DR    ""    // Dark Red.
  #define DG    ""    // Dark Green.
  #define DY    ""    // Dark Yellow.
  #define DS    ""    // Dark Sky. (Dark blue)
  #define DP    ""    // Dark Pink.
  #define DC    ""    // Dark Cyan.
  #define DW    ""    // Dark white. (Light Gray)

  /* Bold light colors */
  #define BB    ""  // Light Black.
  #define BR    ""  // Light Red.
  #define BG    ""  // Light Green.
  #define BY    ""  // Light Yellow.
  #define BS    ""  // Light Sky. (Light blue)
  #define BP    ""  // Light Pink.
  #define BC    ""  // Light Cyan.
  #define BW    ""  // Light white.
#endif

/* ============================== Type ============================= */
typedef struct _cli_t_
{
  const char *command;
  const void (*entry_function)(uint8_t argc, uint8_t **argv);
  int8_t num_param;
  const char *description;
  struct _cli_t_ *next_command;
} cli_t;

/* ============================== Global Variable ================== */

/* ============================== API ============================== */
void CLI_Init(void);
int8_t CLI_AddCommand(cli_t *new_command, uint8_t num_command);
void CLI_ParseCommand(const char *str_command, const uint8_t len_command);
uint8_t CLI_GetChar(const uint8_t character);
void CLI_ClearBuffer(void);
void CLI_WriteString(const char *s);
void CLI_Process(void);
void CLI_Printf(const char *format, ...);

/* end file */
#endif /* __CLI_H__ */
