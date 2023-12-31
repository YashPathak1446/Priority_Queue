#include <gtest/gtest.h>

#include <fstream>
#include <vector>

#include "../include/ver.hpp"
#include "MyPriorityQueue.hpp"
#include "convert.hpp"

namespace {

// As always, this is a STARTING POINT of test cases
// and is not an exhaustive set of test cases.
// You should be sure to test EVERY function of
// your priority queue as well as the Lewis Carroll puzzle.

TEST(Required, SimplePQCreation) {
  MyPriorityQueue<int> mpq;
  mpq.insert(3);
  EXPECT_EQ(mpq.min(), 3);
}

TEST(Required, SimpleTestOfMin) {
  MyPriorityQueue<int> mpq;
  mpq.insert(3);
  mpq.insert(5);
  EXPECT_EQ(mpq.min(), 3);
}

TEST(Required, SimpleTestOfMinUpdating) {
  MyPriorityQueue<int> mpq;
  mpq.insert(3);
  mpq.insert(2);
  EXPECT_EQ(mpq.min(), 2);
}

// self tests

TEST(Optional, classExampleInsert7426) {
  MyPriorityQueue<int> pq;
  pq.insert(3);
  pq.insert(8);
  pq.insert(5);
  pq.insert(13);
  pq.insert(9);
  pq.insert(19);
  pq.insert(20);
  pq.insert(18);
  pq.insert(25);
  pq.insert(7);
  pq.insert(4);
  pq.insert(2);
  pq.insert(6);
  pq.print();
  EXPECT_EQ(pq.min(), 2);
}

TEST(Optional2, extactMin) {
  MyPriorityQueue<int> pq;
  pq.insert(3);
  pq.insert(8);
  pq.insert(5);
  pq.insert(13);
  pq.insert(9);
  pq.insert(19);
  pq.insert(20);
  pq.insert(18);
  pq.insert(25);
  pq.extractMin();
  pq.extractMin();
  pq.extractMin();
  pq.print();
}
// part2 tests

TEST(RequiredPart2, AntToEat) {
  std::string WORD_ONE = "ant";
  std::string WORD_TWO = "eat";
  auto CORRECT_LENGTH = 5;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

TEST(SampleTests, PuttersToHampers) {
  std::string WORD_ONE = "putters";
  std::string WORD_TWO = "hampers";
  auto CORRECT_LENGTH = 14;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

TEST(SampleTests, BankingToBrewing) {
  std::string WORD_ONE = "banking";
  std::string WORD_TWO = "brewing";
  auto CORRECT_LENGTH = 15;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

TEST(SampleTests, ChangesToGlasses) {
  std::string WORD_ONE = "changes";
  std::string WORD_TWO = "glasses";
  auto CORRECT_LENGTH = 48;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

TEST(SampleTests, ChangesToSmashed) {
  std::string WORD_ONE = "changes";
  std::string WORD_TWO = "smashed";
  auto CORRECT_LENGTH = 48;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

TEST(SampleTests, BoostedToClasses) {
  std::string WORD_ONE = "boosted";
  std::string WORD_TWO = "classes";
  auto CORRECT_LENGTH = 44;

  std::unordered_set<std::string> words;
  std::ifstream in("words.txt");
  loadWordsIntoTable(words, in);

  std::vector<std::string> r = convert(WORD_ONE, WORD_TWO, words);

  std::ifstream in2("words.txt");

  EXPECT_EQ(r.size(), CORRECT_LENGTH);
  EXPECT_TRUE(validConversion(r, WORD_ONE, WORD_TWO, in2));
}

}  // namespace