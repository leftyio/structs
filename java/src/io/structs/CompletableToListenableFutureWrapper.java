// Forked from:
//
// https://github.com/spotify/futures-extra

package io.structs;

import com.google.common.util.concurrent.AbstractFuture;
import com.google.common.util.concurrent.ListenableFuture;

import java.util.concurrent.CancellationException;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.CompletionException;
import java.util.concurrent.CompletionStage;
import java.util.function.BiConsumer;

class CompletableToListenableFutureWrapper<V>
    extends AbstractFuture<V>
    implements ListenableFuture<V>, BiConsumer<V, Throwable> {

  private final CompletionStage<V> future;

  CompletableToListenableFutureWrapper(final CompletionStage<V> future) {
    this.future = future;
    future.whenComplete(this);
  }

  public CompletableFuture<V> unwrap() {
    return future.toCompletableFuture();
  }

  @Override
  public boolean cancel(final boolean mayInterruptIfRunning) {
    future.toCompletableFuture().cancel(mayInterruptIfRunning);
    return super.cancel(mayInterruptIfRunning);
  }

  @Override
  public void accept(final V v, final Throwable throwable) {
    if (throwable != null) {
      if (throwable instanceof CancellationException) {
        cancel(false);
      } else {
        setException(unwrapThrowable(throwable));
      }
    } else {
      set(v);
    }
  }

  static Throwable unwrapThrowable(Throwable throwable) {
    // Don't go too deep in case there is recursive exceptions
    for (int i = 0; i < 100; i++) {
      if (throwable instanceof CompletionException) {
        throwable = throwable.getCause();
      } else {
        break;
      }
    }
    return throwable;
  }
}
