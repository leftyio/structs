#pragma once

#include <string>

#include "structs/cassandra/message_gen.h"
#include "structs/sugar/sugar.h"

namespace structs {
string JavaContent(const MessageGen* msg);
}  // namespace structs
