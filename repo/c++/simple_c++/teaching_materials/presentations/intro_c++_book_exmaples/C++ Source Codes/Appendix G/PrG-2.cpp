// This program uses managed C++ code.
#include "stdafx.h"
#using <mscorlib.dll>
using namespace System;

int _tmain()
{
   // Create an array of integers.
   const int SIZE = 12;
   int numbers __gc[] = new int __gc[SIZE];

   // Store some values in the array.
   for (int i = 0; i < SIZE; i++)
      numbers[i] = i;

   // Display the values in the array.
   for (int i = 0; i < SIZE; i++)
      Console::WriteLine(numbers[i]);

   return 0;
} 