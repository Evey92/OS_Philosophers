#include "pch.h"
#include "Philosopher.h"
#include "Table.h"




Philosopher::~Philosopher()
{
  m_lifeSpan.join();
}

void Philosopher::eating() {
  
  std::lock(m_pLeftFork.mutex, m_pRightFork.mutex);
  std::lock_guard<std::mutex> leftForkLock(m_pLeftFork.mutex, std::adopt_lock);
  std::lock_guard<std::mutex> RightForkLock(m_pRightFork.mutex, std::adopt_lock);   
      
    //Philosopher's got both forks. Start eating for a time, then set both forks on the table.
      std::cout << m_name << " is eating with \n";

      static thread_local std::uniform_int_distribution<> dist(1, 6);
      std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 50));

      std::cout << m_name << " finished eating.\n";
}

void Philosopher::thinking() {
  /**
  *Philosopher will think for a while, then he'll try to grab both forks.
  *If after some time he can't get any forks, he'll die of starvation.
  */

  
  static thread_local std::uniform_int_distribution<> wait(1, 6);
  std::this_thread::sleep_for(std::chrono::milliseconds(wait(rng) * 150));
  std::cout << m_name << " is thinking.\n";

  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

  std::chrono::duration<double, std::milli> elapsed = std::chrono::high_resolution_clock::now() - start;

  if (elapsed >= std::chrono::milliseconds(5000))
  {
    std::cout << m_name << " is starving to death. Sad.\n";
  }

}

void Philosopher::dine() {
    
    while (!m_dinnerReady);

    do
    {
      thinking();
      eating();
    } while (m_dinnerReady);
    
}
