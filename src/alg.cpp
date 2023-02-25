// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
if (value <= 1) return false;

if (value == 2) return true;

if ((value & 1) == 0) return false;

  for (uint64_t i = 3; i*i <= value; i += 2) {
    if (value % i == 0) return false;
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t counter = 2;
  uint64_t i = 0;

  if (n == 0) return 0;
  if (n == 1) return 2;

  for (i = 5; counter < n; i += 2) {
    if (checkPrime(i)) counter++;
  }
  return i-2;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value+1; ; i++) {
    if (checkPrime(i)) return i;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}
