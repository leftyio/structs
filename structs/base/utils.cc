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
}  // namespace structs
