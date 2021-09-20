package io.structs;

import com.google.common.util.concurrent.ListenableFuture;

import java.util.concurrent.CompletionStage;

public final class FutureAdapters {

  public static <T> ListenableFuture<T> toListenableFuture(CompletionStage<T> stage) {
    return new CompletableToListenableFutureWrapper<>(stage.toCompletableFuture());
  }
}
