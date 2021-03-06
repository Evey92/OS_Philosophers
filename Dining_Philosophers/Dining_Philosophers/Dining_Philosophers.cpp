#include "pch.h"
#include "Table.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <mutex>
#include <chrono>
#include <condition_variable>


std::vector<Philosopher> m_philVec;
std::vector<Philosopher>::iterator m_iterator;

void fillPhilVec(Table table)
{    
    Philosopher Plato("Plato", table.fork1, table.fork2, true);
    m_philVec.push_back(Plato);
    
    Philosopher Aristotle("Aristotle", table.fork2, table.fork3, true);
    m_philVec.push_back(Aristotle);
    
    Philosopher Socrates("Socrates", table.fork3, table.fork4, true);
    m_philVec.push_back(Socrates);
    
    Philosopher Descartes("Descartes", table.fork4, table.fork5, true);
    m_philVec.push_back(Descartes);
    
    Philosopher Kant("Kant", table.fork5, table.fork1, true);
    m_philVec.push_back(Kant);
}

void startDinner() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Dinner started!" << std::endl;
  {
    Table table;
    //fillPhilVec(table);
    std::array<Philosopher, 5> philosophers{
      {
        {"Plato", table.fork1, table.fork2, true},
        {"Aristotle", table.fork2, table.fork3, true},
        {"Socrates", table.fork3, table.fork4, true},
        {"Descartes", table.fork4, table.fork5, true},
        {"Kant", table.fork5, table.fork1, true},
      }
    };

    std::this_thread::sleep_for(std::chrono::seconds(5));
    for (m_iterator = m_philVec.begin(); m_iterator != m_philVec.end(); m_iterator++)
    {
      std::cout << "Deactivating Philosopher: " << m_iterator->m_name << std::endl;
      m_iterator->m_dinnerReady = false;
    }
  }
  std::cout << "Dinner is over B\n";
  
}


int main()
{
  startDinner();
}

