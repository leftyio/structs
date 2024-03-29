// @generated: This file is autogenerated by the Structs compiler, DO NOT EDIT MANUALLY

package io.structs.testing;

import com.datastax.oss.driver.api.core.CqlSession;
import com.datastax.oss.driver.api.core.cql.AsyncResultSet;
import com.datastax.oss.driver.api.core.cql.BoundStatement;
import com.datastax.oss.driver.api.core.cql.PreparedStatement;
import com.datastax.oss.driver.api.core.cql.ResultSet;
import com.datastax.oss.driver.api.core.cql.Row;
import com.datastax.oss.driver.api.core.type.reflect.GenericType;

public final class InnerContainerStruct {
  public enum Fields {
    ID("id", "id"),
    INNER_VALUE("inner_value", "inner.value"),
    INNER_VALUE_STR("inner_value_str", "inner.value_str"),
    INNER_FIELD_STRING_VALUE("inner_field_string_value", "inner.field_string_value"),
    INNER_INNER_IN_INNER("inner_inner_in_inner", "inner.inner_in_inner"),
    INNER_AS_BYTES("inner_as_bytes", "inner_as_bytes");

    public final String fieldName;

    public final String path;

    Fields(String fieldName, String path) {
      this.fieldName = fieldName;
      this.path = path;
    }

    public static Iterable<Fields> all() {
      com.google.common.collect.ImmutableList.Builder<Fields> b = com.google.common.collect.ImmutableList.builder();
      b.add(ID);
      b.add(INNER_VALUE);
      b.add(INNER_VALUE_STR);
      b.add(INNER_FIELD_STRING_VALUE);
      b.add(INNER_INNER_IN_INNER);
      b.add(INNER_AS_BYTES);
      return b.build();
    }

    private static boolean isSelected(Fields field, com.google.protobuf.FieldMask mask) {
      for (String path: mask.getPathsList()) {
        if (path.equals(field.path) || field.path.startsWith(path + ".")) {
          return true;
        }
      }
      return false;
    }

    private static  com.google.common.collect.ImmutableList<Fields> selectFields(com.google.protobuf.FieldMask mask) {
      com.google.common.collect.ImmutableList.Builder<Fields> b = com.google.common.collect.ImmutableList.builder();

      for (Fields field : Fields.values()) {
        if (isSelected(field, mask)) {
          b.add(field);
        }
      }
      return b.build();
    }

    private Object selectIn(io.structs.testing.TestingProto.InnerContainer obj) {
      Object y = null;
      switch (this) {
        
        case ID:
          y = obj.getId();
          break;
        
        case INNER_VALUE:
          y = obj.getInner().getValue();
          break;
        
        case INNER_VALUE_STR:
          y = obj.getInner().getValueStr();
          break;
        
        case INNER_FIELD_STRING_VALUE:
          if (obj.getInner().hasFieldStringValue()) {
            y = obj.getInner().getFieldStringValue().getValue();
          }
          break;
        
        case INNER_INNER_IN_INNER:
          if (obj.getInner().hasInnerInInner()) {
            y = obj.getInner().getInnerInInner().toByteString().asReadOnlyByteBuffer();
          }
          break;
        
        case INNER_AS_BYTES:
          if (obj.hasInnerAsBytes()) {
            y = obj.getInnerAsBytes().toByteString().asReadOnlyByteBuffer();
          }
          break;
        
      }
      return y;
    }
  }

  private final CqlSession session;
  private final com.google.common.base.Supplier<PreparedStatement> selectAllStmt;
  private final com.google.common.base.Supplier<PreparedStatement> insertAllStmt;

  public InnerContainerStruct(CqlSession session) {
    this.session = session;
    this.selectAllStmt = com.google.common.base.Suppliers.memoize(() -> {
      return createSelectAllStmt(session);
    });

    this.insertAllStmt = com.google.common.base.Suppliers.memoize(() -> {
      return createInsertAllStmt(session);
    });
  }

  private static PreparedStatement createSelectAllStmt(CqlSession session) {
    Iterable<String> names = com.google.common.collect.Iterables.transform(Fields.all(), x -> x.fieldName);
    StringBuilder sb = new StringBuilder("select ");
    com.google.common.base.Joiner.on(',').appendTo(sb, names);
    sb.append(" from inner_containers where id=?");
    return session.prepare(sb.toString());
  }

  public java.util.Optional<io.structs.testing.TestingProto.InnerContainer> load(String id) {
    PreparedStatement stmt = selectAllStmt.get();
    BoundStatement bound = stmt.bind(id);
    ResultSet rs = session.execute(bound);
    Row row = rs.one();
    if (row == null) {
      return java.util.Optional.empty();
    }

    return java.util.Optional.of(ofRowOrDie(row));
  }

  public com.google.common.util.concurrent.ListenableFuture<java.util.Optional<io.structs.testing.TestingProto.InnerContainer>> loadAsync(String id) {
    PreparedStatement stmt = selectAllStmt.get();
    BoundStatement bound = stmt.bind(id);
    com.google.common.util.concurrent.ListenableFuture<AsyncResultSet> rsF = io.structs.FutureAdapters.toListenableFuture(session.executeAsync(bound));
    return com.google.common.util.concurrent.Futures.transform(rsF, rs -> {
      Row row = rs.one();
      if (row == null) {
        return java.util.Optional.empty();
      }

      return java.util.Optional.of(ofRowOrDie(row));
    }, com.google.common.util.concurrent.MoreExecutors.directExecutor());
  }

  public static io.structs.testing.TestingProto.InnerContainer ofRowOrDie(Row row) {
    try {
      return ofRow(row);
    } catch (com.google.protobuf.InvalidProtocolBufferException ex) {
      throw io.grpc.Status.fromThrowable(ex).asRuntimeException();
    }
  }

  public static io.structs.testing.TestingProto.InnerContainer ofRow(Row row) throws com.google.protobuf.InvalidProtocolBufferException {
    io.structs.testing.TestingProto.InnerContainer.Builder b = io.structs.testing.TestingProto.InnerContainer.newBuilder();

    {
      int idx = row.getColumnDefinitions().firstIndexOf("id");
      if (idx != -1 && !row.isNull(idx)) {
        String value = row.getString(idx);
        b.setId(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().firstIndexOf("inner_value");
      if (idx != -1 && !row.isNull(idx)) {
        int value = row.getInt(idx);
        b.getInnerBuilder().setValue(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().firstIndexOf("inner_value_str");
      if (idx != -1 && !row.isNull(idx)) {
        String value = row.getString(idx);
        b.getInnerBuilder().setValueStr(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().firstIndexOf("inner_field_string_value");
      if (idx != -1 && !row.isNull(idx)) {
        String value = row.getString(idx);
        b.getInnerBuilder().getFieldStringValueBuilder().setValue(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().firstIndexOf("inner_inner_in_inner");
      if (idx != -1 && !row.isNull(idx)) {
        java.nio.ByteBuffer value = row.getByteBuffer(idx);
        b.getInnerBuilder().getInnerInInnerBuilder().mergeFrom(com.google.protobuf.ByteString.copyFrom(value));
      }
    }

    {
      int idx = row.getColumnDefinitions().firstIndexOf("inner_as_bytes");
      if (idx != -1 && !row.isNull(idx)) {
        java.nio.ByteBuffer value = row.getByteBuffer(idx);
        b.getInnerAsBytesBuilder().mergeFrom(com.google.protobuf.ByteString.copyFrom(value));
      }
    }

    
    return b.build();
  }

  private static PreparedStatement createInsertAllStmt(CqlSession session) {
    StringBuilder sb = new StringBuilder();
    sb.append("INSERT INTO inner_containers (");
    sb.append("id, inner_value, inner_value_str, inner_field_string_value, inner_inner_in_inner, inner_as_bytes) ");
    sb.append("VALUES (?, ?, ?, ?, ?, ?)");

    return session.prepare(sb.toString());
  }

  public void save(io.structs.testing.TestingProto.InnerContainer obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[6];

    {
      Object o = null;
      o = obj.getId();
      boundObjs[0] = o;
    }

    {
      Object o = null;
      o = obj.getInner().getValue();
      boundObjs[1] = o;
    }

    {
      Object o = null;
      o = obj.getInner().getValueStr();
      boundObjs[2] = o;
    }

    {
      Object o = null;
      if (obj.getInner().hasFieldStringValue()) {
        o = obj.getInner().getFieldStringValue().getValue();
      }
      boundObjs[3] = o;
    }

    {
      Object o = null;
      if (obj.getInner().hasInnerInInner()) {
        o = obj.getInner().getInnerInInner().toByteString().asReadOnlyByteBuffer();
      }
      boundObjs[4] = o;
    }

    {
      Object o = null;
      if (obj.hasInnerAsBytes()) {
        o = obj.getInnerAsBytes().toByteString().asReadOnlyByteBuffer();
      }
      boundObjs[5] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    session.execute(bound);
  }

  public com.google.common.util.concurrent.ListenableFuture<Void> saveAsync(io.structs.testing.TestingProto.InnerContainer obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[6];

    {
      Object o = null;
      o = obj.getId();
      boundObjs[0] = o;
    }

    {
      Object o = null;
      o = obj.getInner().getValue();
      boundObjs[1] = o;
    }

    {
      Object o = null;
      o = obj.getInner().getValueStr();
      boundObjs[2] = o;
    }

    {
      Object o = null;
      if (obj.getInner().hasFieldStringValue()) {
        o = obj.getInner().getFieldStringValue().getValue();
      }
      boundObjs[3] = o;
    }

    {
      Object o = null;
      if (obj.getInner().hasInnerInInner()) {
        o = obj.getInner().getInnerInInner().toByteString().asReadOnlyByteBuffer();
      }
      boundObjs[4] = o;
    }

    {
      Object o = null;
      if (obj.hasInnerAsBytes()) {
        o = obj.getInnerAsBytes().toByteString().asReadOnlyByteBuffer();
      }
      boundObjs[5] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    com.google.common.util.concurrent.ListenableFuture<AsyncResultSet> rsF = io.structs.FutureAdapters.toListenableFuture(session.executeAsync(bound));
    return com.google.common.util.concurrent.Futures.transform(rsF, x -> null, com.google.common.util.concurrent.MoreExecutors.directExecutor());
  }

  public void update(io.structs.testing.TestingProto.InnerContainer obj, com.google.protobuf.FieldMask mask) {
    mask = com.google.protobuf.util.FieldMaskUtil.normalize(mask);
    if (!com.google.protobuf.util.FieldMaskUtil.isValid(io.structs.testing.TestingProto.InnerContainer.getDescriptor(), mask)) {
      throw new IllegalArgumentException("illegal mask: " + mask);
    }

    StringBuilder sb = new StringBuilder();
    sb.append("UPDATE inner_containers SET ");
    java.util.List<Fields> fields = Fields.selectFields(mask);
    for (int i = 0; i < fields.size(); ++i) {
      Fields field = fields.get(i);
      sb.append(field.fieldName).append("=?");
      if (i < fields.size() - 1) {
        sb.append(", ");
      }
    }

    sb.append("  where id=?");

    String stmtStr = sb.toString();
    System.out.println(stmtStr);
    PreparedStatement stmt = session.prepare(stmtStr);
    Object[] boundObjs = new Object[fields.size() + 1];
    int i = 0;
    while (i < fields.size()) {
      Fields field = fields.get(i);
      boundObjs[i] = field.selectIn(obj);
      ++i;
    }

    
    boundObjs[i++] = Fields.ID.selectIn(obj);
    ++i;

    BoundStatement bound = stmt.bind(boundObjs);
    session.execute(bound);
  }
}
