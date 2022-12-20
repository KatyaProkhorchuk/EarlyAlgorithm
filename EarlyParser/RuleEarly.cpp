#include "RuleEarly.hpp"
const std::string kRule = "->";
const std::vector<char> kAlphabet = {'a', 'b'};
RuleEarly::RuleEarly() : start_{' '}, finish_{' '} {};

RuleEarly::RuleEarly(const std::string &rule) {
  size_t delimiter = rule.find(kRule);
  if (delimiter == -1) {
    std::cout<<"Incorrect rules";
    return;
  }
  std::string start = rule.substr(0, delimiter);
  start_ = start[0];
  finish_ = &rule[delimiter + kRule.size()];
}

bool RuleEarly::operator<(const RuleEarly &rule) const {
  return start_ == rule.start_ ? finish_ < rule.finish_: start_<rule.start_;
}
bool RuleEarly::operator==(const RuleEarly &rule) const {
  if (start_ == rule.start_) {
    return finish_ == rule.finish_;
  }
  return false;
}
