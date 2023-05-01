#include "Logic.h"
#include "common_debug.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <chrono>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

#ifdef TEST_MODE

TEST(test_case_0) {
  std::unique_ptr<Logic> logic = std::make_unique<Logic>();
  auto result = logic->checkNumberofPermutations(
      {"the", "bats", "tabs", "in", "cat", "act"},
      {"cat the bats", "in the act", "act tabs in"});
  std::vector<int> expected_result = {4, 2, 4};

  for (auto it = 0; it < result.size(); it++) {
    ASSERT_EQUAL(expected_result[it], result[it]);
  }
}

TEST(test_case_1) {
  std::unique_ptr<Logic> logic = std::make_unique<Logic>();
  auto result = logic->checkNumberofPermutations(
      {"star", "tars", "stay", "tay", "seed", "dees", "eesd", "rast", "date",
       "ate"},
      {"ate date stay", "rast tay star", "tay stay tars", "seed dees star",
       "ate seed rast"});
  std::vector<int> expected_result = {1, 9, 3, 27, 9};

  for (auto it = 0; it < result.size(); it++) {
    ASSERT_EQUAL(expected_result[it], result[it]);
  }
}

TEST_MAIN()

#endif
