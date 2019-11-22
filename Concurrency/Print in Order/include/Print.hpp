#pragma once

#include <iostream>
#include <string>

void Print(std::string &&msg) { std::cout << msg; }

void PrintFirst() { Print("first"); }

void PrintSecond() { Print("second"); }

void PrintThird() { Print("third"); }