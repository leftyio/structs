// This file defines helpers to render java classes and statements.

#pragma once

#include <string>

#include "glog/logging.h"

#include "structs/base/code_builder.h"
#include "structs/cassandra/field_gen.h"

namespace structs {
void SetFromJavaStmt(const FieldGen& field,
                     const std::string& value_name,
                     CodeBuilder& cb);

void GetFromJavaObj(const FieldGen& field,
                    const std::string& obj_name,
                    const std::string& getted_name,
                    CodeBuilder& cb);
}  // structs
