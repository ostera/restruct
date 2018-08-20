open Bench_Utils;
open ReStruct;

module Helpers = {
  let make_batched_queue = x => {
    let e = BatchedQueue.empty;
    let rec f =
      fun
      | (q, 0) => q
      | (q, x) => f((BatchedQueue.push(q, 0), x - 1));
    f((e, x));
  };

  let rec consume_batched_queue = q =>
    switch (BatchedQueue.tail(q)) {
    | None => None
    | Some(q') => consume_batched_queue(q')
    };

  let make_bankers_queue = x => {
    let e = BankersQueue.empty;
    let rec f =
      fun
      | (q, 0) => q
      | (q, x) => f((BankersQueue.push(q, 0), x - 1));
    f((e, x));
  };

  let rec consume_bankers_queue = q =>
    switch (BankersQueue.tail(q)) {
    | None => None
    | Some(q') => consume_bankers_queue(q')
    };

  let make_realtime_queue = x => {
    let e = Lazy.RealTimeQueue.empty;
    let rec f =
      fun
      | (q, 0) => q
      | (q, x) => f((Lazy.RealTimeQueue.push(q, 0), x - 1));
    f((e, x));
  };

  let rec consume_realtime_queue = q =>
    switch (Lazy.RealTimeQueue.tail(q)) {
    | None => None
    | Some(q') => consume_realtime_queue(q')
    };
};

module Push = {
  let push_batched_queue = (x, ()) => {
    let _ = Helpers.make_batched_queue(x);
    ();
  };

  let push_bankers_queue = (x, ()) => {
    let _ = Helpers.make_bankers_queue(x);
    ();
  };

  let push_realtime_queue = (x, ()) => {
    let _ = Helpers.make_realtime_queue(x);
    ();
  };

  let run = size =>
    ReBench.(
      make()
      |> add("ReStruct.BatchedQueue.push", push_batched_queue(size))
      |> add("ReStruct.BankersQueue.push", push_bankers_queue(size))
      |> add("ReStruct.Lazy.RealTimeQueue.push", push_realtime_queue(size))
      |> on(Start, default_announcer(~size, ~name="Queue.Push"))
      |> on(Cycle, default_printer)
      |> on(Complete, _e => Js.log(""))
      |> run(run_opts(~async=false))
    );
};

module Tail = {
  let tail_batched_queue = x => {
    let q = Helpers.make_batched_queue(x);
    () => {
      let _ = BatchedQueue.tail(q);
      ();
    };
  };

  let tail_bankers_queue = x => {
    let q = Helpers.make_bankers_queue(x);
    () => {
      let _ = BankersQueue.tail(q);
      ();
    };
  };

  let tail_realtime_queue = x => {
    let q = Helpers.make_realtime_queue(x);
    () => {
      let _ = Lazy.RealTimeQueue.tail(q);
      ();
    };
  };

  let run = size =>
    ReBench.(
      make()
      |> add("ReStruct.BatchedQueue.tail", tail_batched_queue(size))
      |> add("ReStruct.BankersQueue.tail", tail_bankers_queue(size))
      |> add("ReStruct.Lazy.RealTimeQueue.tail", tail_realtime_queue(size))
      |> on(Start, default_announcer(~size, ~name="Queue.Tail"))
      |> on(Cycle, default_printer)
      |> on(Complete, _e => Js.log(""))
      |> run(run_opts(~async=false))
    );
};
