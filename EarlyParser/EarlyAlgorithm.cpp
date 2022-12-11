#include "EarlyAlgorithm.hpp"

bool Early::IsGrammar(Grammar &grammar, const std::string &word) {
  Building(grammar, word);
  Position end(grammar.GetRules()[0], 1, 0);
  size_t sz = word.size();
  return rule_[sz].end() != rule_[sz].find(end);
}
void Early::Init(Grammar &grammar, size_t n) {
  rule_.clear();
  rule_.resize(n + 1);
  RuleEarly first_rule = grammar.GetRules()[0];
  rule_[0].emplace(first_rule, 0, 0);
}
void Early::Building(Grammar &grammar, const std::string &word) {
  Init(grammar, word.size());
  Predict(grammar, 0);
  Complete(0);
  for (size_t i = 0; i < word.size(); ++i) {
    Scan(word[i], i);
    Predict(grammar, i + 1);
    Complete(i+1);
  }
}
void Early::Predict(const Grammar &grammar, size_t number) {
  for (auto &state : rule_[number]) {
    char needed_start = state.GetPointSymbol();
    for (auto &rule : grammar.GetRulesStart(needed_start)) {
      rule_[number].emplace(rule, 0, number);
    }
  }
}
void Early::Scan(char symbol, size_t number) {
  for (auto &state : rule_[number]) {
    if (state.GetPointSymbol() == symbol) {
      rule_[number + 1].emplace( state.rule_, state.point_ + 1, state.begin_);
    }
  }
}
void Early::Complete(size_t number) {
  for (auto &state : rule_[number]) {
      if (state.point_ == state.rule_.GetFinishSize()){
      for (auto &maybe : rule_[state.begin_]) {
        if (state.rule_.GetStartState()==maybe.GetPointSymbol()) {
          rule_[number].emplace(maybe.rule_, maybe.point_ + 1, maybe.begin_);
        }
      }
    }
  }
}