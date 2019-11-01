// This file is autogenerated by the Structs compiler, DO NOT EDIT MANUALLY

// @generated : differential looks for 'arobas generated' case sensitive.
// https://www.quora.com/Can-I-use-arc-diff-to-exclude-some-files-in-Phabricator

package io.structs.testing;

import com.datastax.driver.core.BoundStatement;
import com.datastax.driver.core.PreparedStatement;
import com.datastax.driver.core.ResultSet;
import com.datastax.driver.core.ResultSetFuture;
import com.datastax.driver.core.Row;
import com.datastax.driver.core.Session;

public final class InnerContainerStruct {
  public enum Fields {
    ID("id"),
    INNER_VALUE("inner_value"),
    INNER_VALUE_STR("inner_value_str"),
    INNER_AS_BYTES("inner_as_bytes");

    public final String fieldName;

    Fields(String fieldName) {
      this.fieldName = fieldName;
    }

    public static Iterable<Fields> all() {
      com.google.common.collect.ImmutableList.Builder<Fields> b = com.google.common.collect.ImmutableList.builder();
      b.add(ID);
      b.add(INNER_VALUE);
      b.add(INNER_VALUE_STR);
      b.add(INNER_AS_BYTES);
      return b.build();
    }
  }

  private final Session session;
  private final com.google.common.base.Supplier<PreparedStatement> selectAllStmt;
  private final com.google.common.base.Supplier<PreparedStatement> insertAllStmt;

  public InnerContainerStruct(Session session) {
    this.session = session;
    this.selectAllStmt = com.google.common.base.Suppliers.memoize(() -> {
      return createSelectAllStmt(session);
    });

    this.insertAllStmt = com.google.common.base.Suppliers.memoize(() -> {
      return createInsertAllStmt(session);
    });
  }

  private static PreparedStatement createSelectAllStmt(Session session) {
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
    ResultSetFuture rsF = session.executeAsync(bound);
    return com.google.common.util.concurrent.Futures.transform(rsF, rs -> {
      Row row = rs.one();
      if (row == null) {
        return java.util.Optional.empty();
      }

      return java.util.Optional.of(ofRowOrDie(row));
    });
  }

  private static io.structs.testing.TestingProto.InnerContainer ofRowOrDie(Row row) {
    try {
      return ofRow(row);
    } catch (com.google.protobuf.InvalidProtocolBufferException ex) {
      throw io.grpc.Status.fromThrowable(ex).asRuntimeException();
    }
  }

  private static io.structs.testing.TestingProto.InnerContainer ofRow(Row row) throws com.google.protobuf.InvalidProtocolBufferException {
    io.structs.testing.TestingProto.InnerContainer.Builder b = io.structs.testing.TestingProto.InnerContainer.newBuilder();

    {
      int idx = row.getColumnDefinitions().getIndexOf("id");
      if (!row.isNull(idx)) {
        String value = row.getString(idx);
        b.setId(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().getIndexOf("inner_value");
      if (!row.isNull(idx)) {
        int value = row.getInt(idx);
        b.getInnerBuilder().setValue(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().getIndexOf("inner_value_str");
      if (!row.isNull(idx)) {
        String value = row.getString(idx);
        b.getInnerBuilder().setValueStr(value);
      }
    }

    {
      int idx = row.getColumnDefinitions().getIndexOf("inner_as_bytes");
      if (!row.isNull(idx)) {
        java.nio.ByteBuffer value = row.getBytes(idx);
        b.getInnerAsBytesBuilder().mergeFrom(com.google.protobuf.ByteString.copyFrom(value));
      }
    }

    
    return b.build();
  }

  private static PreparedStatement createInsertAllStmt(Session session) {
    StringBuilder sb = new StringBuilder();
    sb.append("INSERT INTO inner_containers (");
    sb.append("id, inner_value, inner_value_str, inner_as_bytes) ");
    sb.append("VALUES (?, ?, ?, ?)");

    return session.prepare(sb.toString());
  }

  public void save(io.structs.testing.TestingProto.InnerContainer obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[4];

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
      if (obj.hasInnerAsBytes()) {
        o = obj.getInnerAsBytes().tobytes();
      }
      boundObjs[3] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    session.execute(bound);
  }

  public com.google.common.util.concurrent.ListenableFuture<Void> saveAsync(io.structs.testing.TestingProto.InnerContainer obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[4];

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
      if (obj.hasInnerAsBytes()) {
        o = obj.getInnerAsBytes().tobytes();
      }
      boundObjs[3] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    ResultSetFuture rsF = session.executeAsync(bound);
    return com.google.common.util.concurrent.Futures.transform(rsF, x -> null);
  }
}
