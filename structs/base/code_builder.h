#pragma once

#include <sstream>

namespace structs {
class CodeBuilder {
 public:
  CodeBuilder();
  ~CodeBuilder();
 
  CodeBuilder& Indent();
  CodeBuilder& Newline();
  CodeBuilder& BreakLine();
  CodeBuilder& PureBreakLine();
  CodeBuilder& Outdent();

  CodeBuilder& operator<<(const std::string& in);

  std::string ToString() { return out_.str(); }

 private:
  int indent_{ 0 };
  std::ostringstream out_;
};
}  // structs
