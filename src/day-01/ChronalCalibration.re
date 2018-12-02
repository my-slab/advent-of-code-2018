let calibrate = List.fold_left((+), 0);

let findRepeat = frequencies => {
  module IntSet =
    Set.Make({
      type t = int;
      let compare = Pervasives.compare;
    });

  let rec reduce = (input, acc, set) =>
    switch (input) {
    | [] => reduce(frequencies, acc, set)
    | [head, ...rest] =>
      let newAcc = acc + head;

      IntSet.mem(newAcc, set) ?
        newAcc : reduce(rest, newAcc, IntSet.add(newAcc, set));
    };

  let initialSet = IntSet.empty |> IntSet.add(0);
  reduce(frequencies, 0, initialSet);
};

calibrate(Input.frequencies |> Array.to_list) |> Js.log;
findRepeat(Input.frequencies |> Array.to_list) |> Js.log;