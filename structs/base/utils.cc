#include "structs/base/utils.h"

#include<fstream>
#include<iostream>
#include<string>
#include <vector>

namespace structs {
std::size_t FileRead(std::istream& is, std::vector<char>* buff) {
  is.read(&(*buff)[0], buff->size());
  return is.gcount();
}

std::string ReadFile(const std::string& filename) {
  std::filebuf fb;
  CHECK(fb.open (filename, std::ios::in));
  std::istream ifs(&fb);

  constexpr std::size_t kBufSize = 64 * 1024;
  std::vector<char> buffer(kBufSize);

  std::string s;
  while(std::size_t n = FileRead(ifs, &buffer)) {
    s.append(&buffer[0], n);
  }

  fb.close();
  return s;
}

std::string UnderscoresToCamelCase(const std::string& input, bool cap_next_letter) {
  std::string result;
  // Note:  I distrust ctype.h due to locales.
  for (int i = 0; i < input.size(); i++) {
    if ('a' <= input[i] && input[i] <= 'z') {
      if (cap_next_letter) {
        result += input[i] + ('A' - 'a');
      } else {
        result += input[i];
      }
      cap_next_letter = false;
    } else if ('A' <= input[i] && input[i] <= 'Z') {
      if (i == 0 && !cap_next_letter) {
        // Force first letter to lower-case unless explicitly told to
        // capitalize it.
        result += input[i] + ('a' - 'A');
      } else {
        // Capital letters after the first are left as-is.
        result += input[i];
      }
      cap_next_letter = false;
    } else if ('0' <= input[i] && input[i] <= '9') {
      result += input[i];
      cap_next_letter = true;
    } else {
      cap_next_letter = true;
    }
  }
  // Add a trailing "_" if the name should be altered.
  if (input[input.size() - 1] == '#') {
    result += '_';
  }
  
  return result;
}
}  // namespace structs
