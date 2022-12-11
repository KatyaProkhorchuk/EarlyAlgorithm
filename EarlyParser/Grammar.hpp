
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "RuleEarly.hpp"

const std::string kRule = "->";
const std::vector<char> kAlphabet = {'a', 'b'};
class Grammar {
 public:
  Grammar(std::vector<char>&& alphabet);
  Grammar(const std::vector<RuleEarly>& rules, std::vector<char>&& alphabet);
  Grammar(std::vector<RuleEarly>&& rules,
                   const std::vector<char>& alphabet = kAlphabet);
  size_t GetRulesCount(){ return rules_.size(); } 
  Grammar(const std::vector<char>& alphabet = kAlphabet);
  Grammar(std::vector<RuleEarly>&& rules, std::vector<char>&& alphabet);
  Grammar(const std::vector<RuleEarly>& rules, const std::vector<char>& alphabet = kAlphabet);
  std::vector<RuleEarly> GetRules() const{ return rules_; }
  std::vector<RuleEarly> GetRulesStart(char start) const;
  std::vector<char> GetAlphabet() const { return alphabet_; }
  void Add(RuleEarly rule){rules_.emplace_back(rule);}
  friend std::istream& operator>>(std::istream& in, Grammar& grammar);
  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);

 private:
  std::vector<char> alphabet_;
  std::vector<RuleEarly> rules_;
  
};

