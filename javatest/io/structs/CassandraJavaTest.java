package io.structs;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import com.datastax.driver.core.Cluster;
import com.datastax.driver.core.HostDistance;
import com.datastax.driver.core.PoolingOptions;
import com.datastax.driver.core.RemoteEndpointAwareNettySSLOptions;
import com.datastax.driver.core.SSLOptions;
import com.datastax.driver.core.Session;
import com.datastax.driver.core.SocketOptions;

import com.google.common.collect.ImmutableList;
import com.google.protobuf.ByteString;
import io.netty.handler.ssl.SslContextBuilder;
import io.netty.handler.ssl.SslProvider;
import io.structs.testing.InnerContainerStruct;
import io.structs.testing.MostBasicStruct;
import io.structs.testing.TestingMessageStruct;
import io.structs.testing.TestingProto.InnerContainer;
import io.structs.testing.TestingProto.MostBasic;
import io.structs.testing.TestingProto.TestingEnum;
import io.structs.testing.TestingProto.TestingMessage;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import javax.net.ssl.TrustManagerFactory;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.charset.StandardCharsets;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;
import java.util.Properties;

public class CassandraJavaTest {

  private Cluster cluster;
  private Session session;

  @Before
  public void setUp() throws IOException {
    Properties props = new Properties();
    InputStream is = getClass().getResourceAsStream("/javatest/io/structs/cassandra.properties");
    try (Reader reader = new InputStreamReader(is, StandardCharsets.UTF_8)) {
      props.load(reader);
    }

    Cluster.Builder builder = Cluster.builder();

    String clusterName = props.getProperty("cluster");
    builder.withClusterName(clusterName);
    builder.withCredentials(props.getProperty("user"), props.getProperty("password"));
    builder.withSocketOptions(new SocketOptions()
        .setConnectTimeoutMillis(60000)
        .setReadTimeoutMillis(30000));

    builder.withPoolingOptions(new PoolingOptions()
        .setMaxRequestsPerConnection(HostDistance.LOCAL, 32768)
        .setMaxRequestsPerConnection(HostDistance.REMOTE, 2000)
        .setMaxQueueSize(2048));

    int port = Integer.parseInt(props.getProperty("port"));
    builder.withPort(port);
    builder.addContactPoint(props.getProperty("contact-point"));

    setupSslOrDie(props, builder);

    this.cluster = builder.build();
    this.session = cluster.connect(props.getProperty("keyspace"));

    session.execute("TRUNCATE TABLE inner_containers;");
    session.execute("TRUNCATE TABLE most_basics;");
    session.execute("TRUNCATE TABLE testing_messages;");
  }

  private void setupSslOrDie(Properties props, Cluster.Builder builder) {
    try {
      KeyStore ks = KeyStore.getInstance("JKS");

      try (InputStream trustStore = getClass().getResourceAsStream("/javatest/io/structs/cassandra.truststore")) {
        ks.load(trustStore, props.getProperty("truststore-password").toCharArray());
        TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
        tmf.init(ks);

        SslContextBuilder sslBuilder = SslContextBuilder
            .forClient()
            .sslProvider(SslProvider.OPENSSL)
            .trustManager(tmf);

        SSLOptions sslOptions = new RemoteEndpointAwareNettySSLOptions(sslBuilder.build());
        builder.withSSL(sslOptions);
      }
    } catch (IOException | KeyStoreException | NoSuchAlgorithmException | CertificateException ex) {
      throw new IllegalArgumentException("couldn't setup cassandra SSL", ex);
    }
  }

  @After
  public void tearDown() {
    session.close();
    cluster.close();

    session = null;
    cluster = null;
  }

  @Test
  public void testBasic() throws IOException {
    assertTrue(true);

    MostBasic mostBasic1 = MostBasic.newBuilder()
        .setId("id_1")
        .build();
    MostBasic mostBasic2 = MostBasic.newBuilder()
        .setId("id_2")
        .build();

    MostBasicStruct cassandra = new MostBasicStruct(session);
    assertFalse(cassandra.load("id_1").isPresent());
    assertFalse(cassandra.load("id_2").isPresent());

    cassandra.save(mostBasic1);
    cassandra.save(mostBasic2);

    assertTrue(cassandra.load("id_1").isPresent());
    assertTrue(cassandra.load("id_2").isPresent());

    MostBasic loadedBasic1 = cassandra.load("id_1").get();
    MostBasic loadedBasic2 = cassandra.load("id_2").get();

    assertEquals("id_1", loadedBasic1.getId());
    assertEquals("id_2", loadedBasic2.getId());

    assertFalse(cassandra.load("id_3").isPresent());
  }

  @Test
  public void testPrimitiveFields() throws IOException {
    TestingMessageStruct cassandra = new TestingMessageStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    TestingMessage message = TestingMessage.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(0, message.getFieldInt32());
    assertFalse(message.getFieldBool());
    assertEquals("", message.getFieldString());
    assertArrayEquals(new byte[] {}, message.getFieldBytes().toByteArray());
    // TODO(christian) adds all.

    byte[] someBytes = new byte[] { 0, 4, 5, 8, 12, 4 };

    message = TestingMessage.newBuilder()
        .setId("id_1")
        .setFieldBool(true)
        .setFieldInt32(42)
        .setFieldFloat(0.0F)
        .setFieldBytes(ByteString.copyFrom(someBytes))
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(42, message.getFieldInt32());
    assertTrue(message.getFieldBool());
    assertEquals("", message.getFieldString());
    assertArrayEquals(someBytes, message.getFieldBytes().toByteArray());

    // TODO(christian) adds all.
  }

  @Test
  public void testPrimitiveWrappers() throws IOException {
    TestingMessageStruct cassandra = new TestingMessageStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    TestingMessage message = TestingMessage.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertFalse(message.hasFieldBoolValue());
    assertFalse(message.hasFieldDoubleValue());
    assertFalse(message.hasFieldFloatValue());
    assertFalse(message.hasFieldInt32Value());
    assertFalse(message.hasFieldInt64Value());
    
    // TODO(christian) adds all.

    TestingMessage.Builder messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");

    messageBuilder.getFieldBoolValueBuilder().setValue(false);
    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertTrue(message.hasFieldBoolValue());
    assertFalse(message.getFieldBoolValue().getValue());

    messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");

    messageBuilder.getFieldBoolValueBuilder().setValue(true);
    cassandra.save(messageBuilder.build());
    message = cassandra.load("id_1").get();
    assertTrue(message.hasFieldBoolValue());
    assertTrue(message.getFieldBoolValue().getValue());

    // Not setting it sets it back to null...
    messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");
    cassandra.save(messageBuilder.build());
    message = cassandra.load("id_1").get();
    assertFalse(message.hasFieldBoolValue());
    assertFalse(message.getFieldBoolValue().getValue());
  }

  @Test
  public void testEnum() throws IOException {
    TestingMessageStruct cassandra = new TestingMessageStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    TestingMessage message = TestingMessage.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(TestingEnum.TESTING_ENUM_UNKNOWN, message.getFieldEnum());

    message = TestingMessage.newBuilder()
        .setId("id_1")
        .setFieldEnum(TestingEnum.FIRST_VALUE)
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(TestingEnum.FIRST_VALUE, message.getFieldEnum());

    message = TestingMessage.newBuilder()
        .setId("id_1")
        .setFieldEnumValue(42)
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(TestingEnum.UNRECOGNIZED, message.getFieldEnum());
    assertEquals(42, message.getFieldEnumValue());
  }

  @Test
  public void testPrimitiveLists() throws IOException {
    TestingMessageStruct cassandra = new TestingMessageStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    TestingMessage message = TestingMessage.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(0, message.getListOfBoolCount());
    assertEquals(0, message.getListOfInt32Count());
    // TODO(christian) add all.

    TestingMessage.Builder messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");
    messageBuilder.addListOfBool(false);
    messageBuilder.addListOfBool(true);
    messageBuilder.addListOfBool(false);

    messageBuilder.addListOfString("first");
    messageBuilder.addListOfString("second");

    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertEquals(ImmutableList.of(false, true, false), message.getListOfBoolList());
    assertEquals(ImmutableList.of("first", "second"), message.getListOfStringList());
    // TODO(christian) add all.

    // Check that we can clean them.
    messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");
    messageBuilder.addListOfString("first");
    messageBuilder.addListOfString("second");
    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertEquals(ImmutableList.of(), message.getListOfBoolList());
    assertEquals(ImmutableList.of("first", "second"), message.getListOfStringList());
  }

  @Test
  public void testEnumLists() throws IOException {
    TestingMessageStruct cassandra = new TestingMessageStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    TestingMessage message = TestingMessage.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();
    assertEquals(0, message.getListOfEnumCount());

    TestingMessage.Builder messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");
    messageBuilder.addListOfEnum(TestingEnum.TESTING_ENUM_UNKNOWN);
    messageBuilder.addListOfEnum(TestingEnum.SECOND_VALUE);
    messageBuilder.addListOfEnum(TestingEnum.FIRST_VALUE);
    messageBuilder.addListOfEnum(TestingEnum.THIRD_VALUE);

    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertEquals(ImmutableList.of(TestingEnum.TESTING_ENUM_UNKNOWN, TestingEnum.SECOND_VALUE, TestingEnum.FIRST_VALUE,
        TestingEnum.THIRD_VALUE), message.getListOfEnumList());

    // Check that we can clean them.
    messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");

    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertEquals(ImmutableList.of(), message.getListOfEnumList());

    // Test unknown values.
    messageBuilder = TestingMessage.newBuilder()
        .setId("id_1");
    messageBuilder.addListOfEnum(TestingEnum.TESTING_ENUM_UNKNOWN);
    messageBuilder.addListOfEnumValue(42);
    messageBuilder.addListOfEnum(TestingEnum.FIRST_VALUE);
    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();
    assertEquals(ImmutableList.of(TestingEnum.TESTING_ENUM_UNKNOWN, TestingEnum.UNRECOGNIZED, TestingEnum.FIRST_VALUE), message.getListOfEnumList());
    assertEquals(ImmutableList.of(TestingEnum.TESTING_ENUM_UNKNOWN.getNumber(), 42, TestingEnum.FIRST_VALUE.getNumber()), message.getListOfEnumValueList());
  }

  @Test
  public void testInners() throws Exception {
    InnerContainerStruct cassandra = new InnerContainerStruct(session);

    assertFalse(cassandra.load("id_1").isPresent());

    InnerContainer message = InnerContainer.newBuilder()
        .setId("id_1")
        .build();

    cassandra.save(message);

    message = cassandra.load("id_1").get();

    assertEquals(0, message.getInner().getValue());
    assertEquals("", message.getInner().getValueStr());
    assertEquals(0, message.getInnerAsBytes().getValue());
    assertEquals("", message.getInnerAsBytes().getValueStr());

    InnerContainer.Builder messageBuilder = InnerContainer.newBuilder()
        .setId("id_1");
    messageBuilder.getInnerBuilder().setValue(12);
    messageBuilder.getInnerBuilder().setValueStr("value");
    messageBuilder.getInnerAsBytesBuilder().setValue(14);
    messageBuilder.getInnerAsBytesBuilder().setValueStr("value_in_bytes");

    cassandra.save(messageBuilder.build());

    message = cassandra.load("id_1").get();

    assertEquals(12, message.getInner().getValue());
    assertEquals("value", message.getInner().getValueStr());
    assertEquals(14, message.getInnerAsBytes().getValue());
    assertEquals("value_in_bytes", message.getInnerAsBytes().getValueStr());
  }
}
