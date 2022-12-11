
#pragma once

#include <iostream>
#include <string>
#include <vector>

class RuleEarly {
public:
  RuleEarly();
  RuleEarly(const std::string &rule);
  char GetStartState() const { return start_; }
  std::string GetFinishState() const { return finish_; }
  size_t GetFinishSize() const { return finish_.size();}
  bool operator<(const RuleEarly &other) const;
  bool operator==(const RuleEarly &other) const;
  RuleEarly& operator=(const RuleEarly& other){
   start_ = other.start_;
   finish_ = other.finish_;
   return *this;
  }

private:
  char start_;
  std::string finish_;
  
};