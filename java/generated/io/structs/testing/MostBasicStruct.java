// @generated: This file is autogenerated by the Structs compiler, DO NOT EDIT MANUALLY

package io.structs.testing;

import com.datastax.oss.driver.api.core.CqlSession;
import com.datastax.oss.driver.api.core.cql.AsyncResultSet;
import com.datastax.oss.driver.api.core.cql.BoundStatement;
import com.datastax.oss.driver.api.core.cql.PreparedStatement;
import com.datastax.oss.driver.api.core.cql.ResultSet;
import com.datastax.oss.driver.api.core.cql.Row;
import com.datastax.oss.driver.api.core.type.reflect.GenericType;

public final class MostBasicStruct {
  public enum Fields {
    ID("id", "id");

    public final String fieldName;

    public final String path;

    Fields(String fieldName, String path) {
      this.fieldName = fieldName;
      this.path = path;
    }

    public static Iterable<Fields> all() {
      com.google.common.collect.ImmutableList.Builder<Fields> b = com.google.common.collect.ImmutableList.builder();
      b.add(ID);
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

    private Object selectIn(io.structs.testing.TestingProto.MostBasic obj) {
      Object y = null;
      switch (this) {
        
        case ID:
          y = obj.getId();
          break;
        
      }
      return y;
    }
  }

  private final CqlSession session;
  private final com.google.common.base.Supplier<PreparedStatement> selectAllStmt;
  private final com.google.common.base.Supplier<PreparedStatement> insertAllStmt;

  public MostBasicStruct(CqlSession session) {
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
    sb.append(" from most_basics where id=?");
    return session.prepare(sb.toString());
  }

  public java.util.Optional<io.structs.testing.TestingProto.MostBasic> load(String id) {
    PreparedStatement stmt = selectAllStmt.get();
    BoundStatement bound = stmt.bind(id);
    ResultSet rs = session.execute(bound);
    Row row = rs.one();
    if (row == null) {
      return java.util.Optional.empty();
    }

    return java.util.Optional.of(ofRowOrDie(row));
  }

  public com.google.common.util.concurrent.ListenableFuture<java.util.Optional<io.structs.testing.TestingProto.MostBasic>> loadAsync(String id) {
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

  public static io.structs.testing.TestingProto.MostBasic ofRowOrDie(Row row) {
    try {
      return ofRow(row);
    } catch (com.google.protobuf.InvalidProtocolBufferException ex) {
      throw io.grpc.Status.fromThrowable(ex).asRuntimeException();
    }
  }

  public static io.structs.testing.TestingProto.MostBasic ofRow(Row row) throws com.google.protobuf.InvalidProtocolBufferException {
    io.structs.testing.TestingProto.MostBasic.Builder b = io.structs.testing.TestingProto.MostBasic.newBuilder();

    {
      int idx = row.getColumnDefinitions().firstIndexOf("id");
      if (idx != -1 && !row.isNull(idx)) {
        String value = row.getString(idx);
        b.setId(value);
      }
    }

    
    return b.build();
  }

  private static PreparedStatement createInsertAllStmt(CqlSession session) {
    StringBuilder sb = new StringBuilder();
    sb.append("INSERT INTO most_basics (");
    sb.append("id) ");
    sb.append("VALUES (?)");

    return session.prepare(sb.toString());
  }

  public void save(io.structs.testing.TestingProto.MostBasic obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[1];

    {
      Object o = null;
      o = obj.getId();
      boundObjs[0] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    session.execute(bound);
  }

  public com.google.common.util.concurrent.ListenableFuture<Void> saveAsync(io.structs.testing.TestingProto.MostBasic obj) {
    PreparedStatement stmt = insertAllStmt.get();
    Object[] boundObjs = new Object[1];

    {
      Object o = null;
      o = obj.getId();
      boundObjs[0] = o;
    }

    BoundStatement bound = stmt.bind(boundObjs);
    com.google.common.util.concurrent.ListenableFuture<AsyncResultSet> rsF = io.structs.FutureAdapters.toListenableFuture(session.executeAsync(bound));
    return com.google.common.util.concurrent.Futures.transform(rsF, x -> null, com.google.common.util.concurrent.MoreExecutors.directExecutor());
  }

  public void update(io.structs.testing.TestingProto.MostBasic obj, com.google.protobuf.FieldMask mask) {
    mask = com.google.protobuf.util.FieldMaskUtil.normalize(mask);
    if (!com.google.protobuf.util.FieldMaskUtil.isValid(io.structs.testing.TestingProto.MostBasic.getDescriptor(), mask)) {
      throw new IllegalArgumentException("illegal mask: " + mask);
    }

    StringBuilder sb = new StringBuilder();
    sb.append("UPDATE most_basics SET ");
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
