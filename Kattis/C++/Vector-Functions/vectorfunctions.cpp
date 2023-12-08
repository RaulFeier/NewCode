#include "vectorfunctions.h"

void backwards(std::vector<int>& vec){
  std::vector<int> eep;

  for (int i = vec.size() - 1; i >= 0; i--) {
    eep.push_back(vec[i]);
  }

  vec = eep;
}

std::vector<int> everyOther(const std::vector<int>& vec){
  std::vector<int> eep;

  for (int i = 0; i < vec.size(); i += 2) {
    eep.push_back(vec[i]);
  }

  return eep;
}

int smallest(const std::vector<int>& vec){
  int sm = 1e9;
  for (auto &c : vec) {
    sm = std::min(sm, c);
  }

  return sm;
}

int sum(const std::vector<int>& vec){
  int sm = 0;
  for (auto &c : vec) {
    sm += c;
  }

  return sm;
}

int veryOdd(const std::vector<int>& suchVector){
  int sm = 0;
  for (int i = 0; i < suchVector.size(); i++) {
    if (i % 2 == 1 and suchVector[i] % 2 == 1) {
      sm++;
    }
  }

  return sm;
}
