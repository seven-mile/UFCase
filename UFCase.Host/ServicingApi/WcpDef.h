#pragma once

#include <Windows.h>

typedef struct _LUNICODE_STRING
{
  UINT_PTR Length;
  UINT_PTR MaximumLength;
  LPWSTR Data;
} LUNICODE_STRING;
