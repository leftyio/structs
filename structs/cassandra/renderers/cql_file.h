#pragma once

#include <string>

#include "structs/cassandra/message_gen.h"

namespace structs {
std::string CQLContent(const MessageGen* msg);
}  // namespace structs
