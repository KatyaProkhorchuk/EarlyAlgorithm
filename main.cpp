#include "EarlyParser/EarlyAlgorithm.hpp"

class SolutionMain {
 public:
  bool Solve() {
    size_t count = 0;
    std::cin >> count;
    std::vector<char> alphabet(count);
    for (auto v:alphabet) {
      std::cin >> v;
    }
    Grammar grammar;
    std::string word;
    std::cin >> grammar;
    std::cin >> word;
    Early early;
    return early.IsGrammar(grammar, word);
  }
};

int main() {
  SolutionMain solution;
  if (solution.Solve()){
    std::cout<<"YES"<<std::endl;
  } else{
    std::cout<<"NO"<<std::endl;
  }
}