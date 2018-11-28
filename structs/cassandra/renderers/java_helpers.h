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

void SetListFromJavaStmt(const FieldGen& field,
                         const std::string& builder,
                         const std::string& value_name,
                         CodeBuilder& cb);

void GetFromJavaObj(const FieldGen& field,
                    const std::string& obj_name,
                    const std::string& getted_name,
                    CodeBuilder& cb);

void GetterFromCassandraRow(const FieldGen& field,
                            const std::string& row_name,
                            const std::string& idx_name,
                            CodeBuilder& cb);

std::string TokenName(const std::string& java_type);
}  // structs
