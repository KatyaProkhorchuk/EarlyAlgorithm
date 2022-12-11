#pragma once
#include "Grammar.hpp"
#include "RuleEarly.hpp"
#include <iostream>
#include <set>
class Early {
public:
  Early() = default;
  bool IsGrammar(Grammar &grammar, const std::string &word);

private:
  struct Position {
  public:
    Position(RuleEarly rule, size_t point, size_t begin) {
      rule_ = rule;
      point_ = point;
      begin_ = begin;
    }

    char GetPointSymbol() const { return rule_.GetFinishState()[point_]; }

    bool operator<(const Position &other) const {
      if (rule_ == other.rule_) {
        if (point_ == other.point_) {
          return begin_ < other.begin_;
        }
        return point_ < other.point_;
      }
      return rule_ < other.rule_;
    }
    RuleEarly rule_;
    size_t point_;
    size_t begin_;
  };
  std::vector<std::set<Position>> rule_;
  void Init(Grammar &grammar, size_t n);
  void Building(Grammar &grammar, const std::string &word);
  void Predict(const Grammar &grammar, size_t number);
  void Scan(char symbol, size_t number);
  void Complete(size_t number);
};
