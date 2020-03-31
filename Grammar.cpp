#include "Grammar.h"

const std::vector<Grammar::Rule>& Grammar::getRules() const {
  return rules_;
}

bool Grammar::IsRuleFormatCorrect(const std::string& rule) {
  if (rule.find("->") != 1 || rule.size() < 3 || rule.find("->") == std::string::npos) {
    throw IncorrectRule();
  }
  return true;
}

bool Grammar::IsLeftOperandCorrect(const char left_operand) {
  if (!isalpha(left_operand) || !(isupper(left_operand))) {
    throw IncorrectRule();
  }
  return true;
}

Grammar::Rule Grammar::ParseEnteredRule(const std::string& rule) {
  Rule new_rule;
  if (!IsRuleFormatCorrect(rule)) {
    return bad_rule;
  } else {
    if (!IsLeftOperandCorrect(rule[0])) {
      return bad_rule;
    } else {
      new_rule.first = rule[0];
      new_rule.second = rule.substr(3, rule.size());
      for (const auto& symbol : new_rule.second) {
        if (isupper(symbol)) {
          non_terminals_.push_back(symbol);
        } else if (islower(symbol)) {
          alphabet_.push_back(symbol);
        }
      }
    }
  }
  return new_rule;
}

std::istream& operator>>(std::istream& is, Grammar& grammar) {
  int rules_number = 0;
  std::cin >> rules_number;
  grammar.rules_.emplace_back('$', "S");

  for (int i = 0; i < rules_number; ++i) {
    std::string rule;
    std::cin >> rule;
    Grammar::Rule rule_to_add = grammar.ParseEnteredRule(rule);
    if (rule_to_add == bad_rule) {
      --i;
    } else {
      grammar.rules_.push_back(rule_to_add);
    }
  }
  return is;
}

Grammar::Grammar(const std::vector<std::string>& rules) {
  rules_.emplace_back('$', "S");
  for (const auto& rule : rules) {
    rules_.push_back(ParseEnteredRule(rule));
  }
}