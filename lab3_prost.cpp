#include "lab3_prost.h"

#include <list>
#include "iostream"
TwoNumber::TwoNumber()
{
}

bool * TwoNumber::rechEratosfena(int numberTwo)
{
  bool * array = new bool[numberTwo + 1];
  for(int i = 2; i < numberTwo + 1; i++)
  {
    array[i] = 1;
  }
  for(int p = 2; p < numberTwo + 1; p++)
  {
    if(array[p] != 0)
      for(int64_t j = (int64_t)p * p; j <  numberTwo ; j += p)
      {
        array[j] = 0;
      }
  }
  return array;
}

std::vector<int> TwoNumber::getList(int numberOne, int numberTwo)
{
  // проверка что a положительное число
  if(numberOne <= 0)
  {
    throw std::out_of_range("a must be positive");
  }
  // Проверка что b положительное число
  if(numberTwo <= 0)
  {
    throw std::out_of_range("b must be positive");
  }
  // проверка что a > b
  if(numberOne >= numberTwo)
  {
    throw std::out_of_range("b must be more than a");
  }
  bool * array = rechEratosfena(numberTwo);
  std::vector<int> lstSimpl;
  if(numberOne > 1)
  {
    for(int p =  numberOne; p < numberTwo; p++)
      if(array[p] != 0)
      {
        lstSimpl.push_back(p);
      }
  }
  else
  {
    for(int p =  2; p < numberTwo + 1; p++)
      if(array[p] != 0)
      {
        lstSimpl.push_back(p);
      }
  }
  delete[] array;
  return lstSimpl;
}

