#include "EarlyParser/EarlyAlgorithm.cpp"
#include <gtest/gtest.h>
TEST(PALINDROM, FORMALKILOVE) {
  std::vector<RuleEarly> rules;
  std::vector<char> alphabet;
  std::string word = "I love formalki! !iklamrof evol I";
  for (char letter = 'a'; letter <= 'z'; ++letter) {
    alphabet.emplace_back(letter);
  }
  for (char letter = 'A'; letter <= 'Z'; ++letter) {
    alphabet.emplace_back(letter);
  }
  alphabet.emplace_back(' ');
  alphabet.emplace_back('!');
  rules.emplace_back("U->S");
  std::string start_state = "S->";
  rules.emplace_back(start_state);
  for (size_t i = 0; i < alphabet.size(); ++i) {
    std::string end_state = std::string(1, alphabet[i]);
    rules.emplace_back(start_state + end_state);
    end_state += "S" + std::string(1, alphabet[i]);
    rules.emplace_back(start_state + end_state);
  }
  Grammar grammar(rules, alphabet);
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}

TEST(PALINDROM, OSLIK) {
  std::vector<RuleEarly> rules;
  std::vector<char> alphabet;
  std::string word = "iaiaiaiaaiaiaiai";
  for (char letter = 'a'; letter <= 'z'; ++letter) {
    alphabet.emplace_back(letter);
  }
  alphabet.emplace_back(' ');
  alphabet.emplace_back('!');
  rules.emplace_back("U->S");
  std::string start_state = "S->";
  rules.emplace_back(start_state);
  for (size_t i = 0; i < alphabet.size(); ++i) {
    std::string end_state = std::string(1, alphabet[i]);
    rules.emplace_back(start_state + end_state);
    end_state += "S" + std::string(1, alphabet[i]);
    rules.emplace_back(start_state + end_state);
  }
  Grammar grammar(rules, alphabet);
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}
TEST(PALINDROM, STRESSSPACES) {
  std::vector<char> alphabet;
  alphabet.emplace_back(' ');
  std::string start_state = "S->";
  std::vector<RuleEarly> rules;
  rules.emplace_back("U->S");
  rules.emplace_back(start_state);
  for (const auto &letter : alphabet) {
    std::string end_state = std::string(1, letter);
    rules.emplace_back(start_state + end_state);
    end_state += "S" + std::string(1, letter);
    rules.emplace_back(start_state + end_state);
  }
  Grammar grammar(rules, alphabet);
  std::string word;
  const size_t n = 100;
  for(size_t i = 0; i < n; ++i){
    word += " ";
  }
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}
TEST(PALINDROM, DOTANDSPASE) {
  std::vector<char> alphabet;
  alphabet.emplace_back(' ');
  alphabet.emplace_back('.');
  std::string start_state = "S->";
  std::vector<RuleEarly> rules;
  rules.emplace_back("U->S");
  rules.emplace_back(start_state);
  for (const auto &letter : alphabet) {
    std::string end_state = std::string(1, letter);
    rules.emplace_back(start_state + end_state);
    end_state += "S" + std::string(1, letter);
    rules.emplace_back(start_state + end_state);
  }
  Grammar grammar(rules, alphabet);
  std::string word;
  const size_t n = 100;
  for(size_t i = 0; i < n; ++i){
    word += " .";
  }
  for(size_t i = 0; i < n; ++i){
    word += ". ";
  }
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}
TEST(CORRECT_BRACKET_SEQUENCE, CORRECT) {
  std::vector<char> alphabet = {'(', ')'};
  std::vector<RuleEarly> rule = {RuleEarly("U->S"), RuleEarly("S->(S)S"), RuleEarly("S->S(S)"),
                             RuleEarly("S->")};
  Grammar grammar(rule, alphabet);
  Early parser;
  std::string word = "(()((()()()())))()";
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}

TEST(CORRECT_BRACKET_SEQUENCE, INCORRECT) {
  std::vector<char> alphabet = {'(', ')'};
  std::vector<RuleEarly> rules = {RuleEarly("U->S"), RuleEarly("S->(S)S"), RuleEarly("S->S(S)"),
                             RuleEarly("S->")};
  Grammar grammar(rules, alphabet);
  std::string word = "((())(((((";
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), false);
}
TEST(CORRECT_BRACKET_SEQUENCE, CORRECT_STRESS) {
  std::vector<char> alphabet = {'(', ')'};
  std::vector<RuleEarly> rules = {RuleEarly("U->S"), RuleEarly("S->(S)S"), RuleEarly("S->S(S)"),
                             RuleEarly("S->")};
  Grammar grammar(rules, alphabet);
  std::string word;
  const size_t n = 10000;
  for (size_t i = 0; i < n; ++i) {
    word += "(";
  }
  for (size_t i = 0; i < n; ++i) {
    word += ")";
  }
  Early parser;
  EXPECT_EQ(parser.IsGrammar(grammar, word), true);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
