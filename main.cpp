// Example program
#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
#include <queue>



int main()
{
  std::string name;
  srand(time(0));
  std::cout << "What is your name? " << INT_MAX << " " << rand();
  
  std::priority_queue<int> q;
 
  const auto data = {1,8,5,6,3,4,0,9,7,2};
    
  std::priority_queue<int, std::vector<int>, std::greater<int>> q2(data.begin(), data.end());
  q2.pop(); 
  std::cout << "What is your name? " << INT_MAX << " " << rand() <<  " " << q2.top(); 
  return 0;
}
