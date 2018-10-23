#pragma once
#include "Fork.h"
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <random>
#include <iomanip>


class Table;

class Philosopher
{

 public:
   Philosopher(std::string name, Fork& L, Fork& R, bool isReady) :m_name(name), m_pLeftFork(L), m_pRightFork(R), m_dinnerReady(isReady), m_lifeSpan(&Philosopher::dine, this) {}
  ~Philosopher();

  Philosopher(const Philosopher& other): m_name(other.m_name), m_pLeftFork(other.m_pLeftFork), m_pRightFork(other.m_pRightFork), m_dinnerReady(other.m_dinnerReady) {}

  void eating();
  void thinking();
  void dine();

  //Table& table;
  int m_philID;
  int waitTime = 4000;
  int eatTime = 5000;
  int timeToStarve = 3000;
  bool m_dinnerReady;
  std::string m_name;
  Fork& m_pLeftFork;
  Fork& m_pRightFork;
  std::thread m_lifeSpan; 
  std::mt19937      rng{ std::random_device{}() };
};

