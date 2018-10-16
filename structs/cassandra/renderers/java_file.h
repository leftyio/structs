#pragma once

#include <string>

#include "structs/cassandra/message_gen.h"

namespace structs {
std::string JavaContent(const MessageGen* msg);
}  // namespace structs
