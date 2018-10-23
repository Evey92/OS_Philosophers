#pragma once
#include "Philosopher.h"
#include "Fork.h"
#include <vector>


class Table
{
 
 public:

  Table() = default;
  Table(const Table& other) {}
  ~Table() {}

  bool tableSet;
  Fork fork1;
  Fork fork2;
  Fork fork3;
  Fork fork4;
  Fork fork5;


};


