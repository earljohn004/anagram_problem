#ifndef _SRC_LOGIC_H
#define _SRC_LOGIC_H

#include <iostream>
#include <vector>

class Logic {
public:
  Logic() = default;
  std::vector<int>
  check_number_of_permutations(std::vector<std::string> word_set,
                            std::vector<std::string> sentence_set);
  bool is_anagram(std::string first_word, std::string second_word);
};

#endif // _SRC_LOGIC_H
