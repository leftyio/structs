#pragma once

#include <string>

#include "structs/cassandra/message_gen.h"

namespace structs {
std::string SparkJavaContent(const MessageGen* msg);
}  // namespace structs
