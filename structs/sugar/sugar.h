// This header is included EVERYWHERE.

#pragma once

#include <string>
#include <vector>

// potentially any file can want to log.
#include "glog/logging.h"

namespace structs {
// things that we like to access without the std::
using std::size_t;
using std::string;
using std::vector;
}  // structs
