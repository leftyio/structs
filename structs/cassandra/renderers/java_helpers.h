// This file defines helpers to render java classes and statements.

#pragma once

#include <string>

#include "glog/logging.h"

#include "structs/base/code_builder.h"
#include "structs/cassandra/field_gen.h"
#include "structs/sugar/sugar.h"

namespace structs {
void SetFromJavaStmt(const FieldGen& field,
                     const string& value_name,
                     CodeBuilder& cb);

void SetListFromJavaStmt(const FieldGen& field,
                         const string& builder,
                         const string& value_name,
                         CodeBuilder& cb);

void GetFromJavaObj(const FieldGen& field,
                    const string& obj_name,
                    const string& getted_name,
                    CodeBuilder& cb);

void GetterFromCassandraRow(const FieldGen& field,
                            const string& row_name,
                            const string& idx_name,
                            CodeBuilder& cb);

string TokenName(const string& java_type);
string WrapperTypeOf(const string& java_type);
}  // structs
