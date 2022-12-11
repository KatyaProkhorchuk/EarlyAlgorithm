#include "Grammar.hpp"
#include "RuleEarly.hpp"

Grammar::Grammar(std::vector<char> &&alphabet) {
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
}

Grammar::Grammar(const std::vector<char> &alphabet) {
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
}

Grammar::Grammar(std::vector<RuleEarly> &&rules, std::vector<char> &&alphabet) {
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
  rules_.resize(rules.size());
  for (size_t i = 0; i < rules.size(); ++i) {
    rules_[i] = rules[i];
  }
}
Grammar::Grammar(const std::vector<RuleEarly> &rules,
                 const std::vector<char> &alphabet) {
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
  rules_.resize(rules.size());
  for (size_t i = 0; i < rules.size(); ++i) {
    rules_[i] = rules[i];
  }
}

Grammar::Grammar(const std::vector<RuleEarly> &rules, std::vector<char> &&alphabet) {
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
  rules_.resize(rules.size());
  for (size_t i = 0; i < rules.size(); ++i) {
    rules_[i] = rules[i];
  }
}

Grammar::Grammar(std::vector<RuleEarly> &&rules, const std::vector<char> &alphabet){
  alphabet_.resize(alphabet.size());
  for (size_t i = 0; i < alphabet.size(); ++i) {
    alphabet_[i] = alphabet[i];
  }
  rules_.resize(rules.size());
  for (size_t i = 0; i < rules.size(); ++i) {
    rules_[i] = rules[i];
  }
}

std::vector<RuleEarly> Grammar::GetRulesStart(char start) const {
  std::vector<RuleEarly> start_rule;
  for (size_t i = 0; i < rules_.size(); ++i) {
    if (rules_[i].GetStartState() == start) {
      start_rule.emplace_back(rules_[i]);
    }
  }
  return start_rule;
}

std::istream &operator>>(std::istream &in, RuleEarly &rule) {
  std::string string_rule;
  in >> string_rule;
  rule = RuleEarly(string_rule);
  return in;
}

std::ostream &operator<<(std::ostream &out, const RuleEarly &rule) {
  out << rule.GetStartState() << kRule << rule.GetFinishState();
  return out;
}

std::istream &operator>>(std::istream &in, Grammar &grammar) {
  size_t n = 0;
  in >> n;
  RuleEarly rule;
  for (size_t i = 0; i < n; ++i) {
    in >> rule;
    grammar.Add(rule);
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Grammar &grammar) {
  out << "--------------Alphabet-----------------\n";
  for (size_t i = 0; i < grammar.alphabet_.size(); ++i) {
    out << grammar.alphabet_[i] << " ";
  }
  out << std::endl;
  out << "--------------Rules---------------------\n";
  for (size_t i = 0; i < grammar.rules_.size(); ++i) {
    out << grammar.rules_[i]<< std::endl;
  }
  return out;
}