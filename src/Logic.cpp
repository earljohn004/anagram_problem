#include "Logic.h"
#include <algorithm>
#include <iostream>
#include <sstream>

bool Logic::isAnagram(std::string first_word, std::string second_word) {

  // Skip the checking
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
    std::vector<int> number_of_permutation;

    // Iterate over sentence
    while (std::getline(ss, word, ' ')) {
      // Check anagram count per word
      int anagram_count = 1;
      for (auto item : word_set) {
        auto checkAnagram = isAnagram(word, item);
        if (checkAnagram) {
          anagram_count++;
        }
      }
      number_of_permutation.push_back(anagram_count);
    }

    // Compute the permutations by multiplying the number of count on each index
    int total = 1;
    for (auto index : number_of_permutation) {
      total = index * total;
    }
    result.push_back(total);
  }
  return result;
}
