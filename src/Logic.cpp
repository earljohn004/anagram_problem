#include "Logic.h"
#include <algorithm>
#include <iostream>
#include <sstream>

bool Logic::isAnagram(std::string first_word, std::string second_word) {

  // Skip the checking if word is the same
  if (first_word == second_word)
    return false;

  // Check the length and skip if not the same
  if (first_word.length() != second_word.length())
    return false;

  // Check if anagram
  std::sort(first_word.begin(), first_word.end());
  std::sort(second_word.begin(), second_word.end());

  return first_word == second_word;
}

std::vector<int>
Logic::checkNumberofPermutations(std::vector<std::string> word_set,
                                 std::vector<std::string> sentences) {
  std::vector<int> result{};

  for (auto sentence : sentences) {

    std::stringstream ss{sentence};
    std::string word;
    int total_perm = 1;

    // Iterate over sentence
    while (std::getline(ss, word, ' ')) {
      // Check anagram count per word
      int anagram_count = 1;
      for (auto item : word_set) {
        if (isAnagram(word, item)) {
          anagram_count++;
        }
      }
      total_perm = total_perm * anagram_count;
    }
    result.push_back(total_perm);
  }
  return result;
}
