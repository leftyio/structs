#pragma once

#include <string>

#include "glog/logging.h"

namespace structs {
std::string ReadFile(const std::string& filename);

// The followings are copied from helpers in the protobuf project.

std::string UnderscoresToCamelCase(const std::string& input, bool cap_next_letter);
}  // structs
