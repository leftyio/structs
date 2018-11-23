#include "structs/base/code_builder.h"

namespace structs {
CodeBuilder::CodeBuilder() {
}

CodeBuilder::~CodeBuilder() {
}
 
CodeBuilder& CodeBuilder::Indent() {
  out_ << '\n';
  indent_ += 2;
  
  for (int i = 0; i < indent_; ++i) {
    out_ << ' ';
  }

  return *this;
}

CodeBuilder& CodeBuilder::Newline() {
  out_ << '\n';
  
  for (int i = 0; i < indent_; ++i) {
    out_ << ' ';
  }

  return *this;
}

CodeBuilder& CodeBuilder::BreakLine() {
  out_ << '\n';
  out_ << '\n';
  return *this;
}

CodeBuilder& CodeBuilder::Outdent() {
  out_ << '\n';
  indent_ -= 2;
  
  for (int i = 0; i < indent_; ++i) {
    out_ << ' ';
  }

  return *this;
}

CodeBuilder& CodeBuilder::operator<<(const std::string& in) {
  out_ << in;

  return *this;
}
}  // namespace structs