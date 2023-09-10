#pragma once

#include <Windows.h>

typedef struct _LUNICODE_STRING
{
  UINT64 Length;
  UINT64 MaximumLength;
  LPWSTR Data;
} LUNICODE_STRING;
