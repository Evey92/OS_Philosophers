#pragma once
#include <mutex>
#include <thread>

class Fork
{
 public:
  Fork() = default;
  Fork(const Fork& other) : m_id(other.m_id) {}
  std::mutex mutex;
  int m_id;
};

