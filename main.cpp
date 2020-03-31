#include <iostream>
#include "EarleyAlgo.h"

int main() {
  Grammar grammar;
  std::string sample;
  try {
    std::cin >> grammar;
    std::cin >> sample;
    std::cout << ((EarlyAlgo(grammar).Check(sample)) ? "YES" : "No") << '\n';
  } catch (IncorrectRule& ex) {
    std::cout << "ERROR";
  }
  return 0;
}