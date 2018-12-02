open Jest;

describe("Chronal Calibration #1", () => {
  open Expect;
  open ChronalCalibration;

  test("+1, -2, +3, +1", () =>
    expect(calibrate([1, (-2), 3, 1])) |> toBe(3)
  );

  test("+1, +1, +1", () =>
    expect(calibrate([1, 1, 1])) |> toBe(3)
  );

  test("+1, +1, -2", () =>
    expect(calibrate([1, 1, (-2)])) |> toBe(0)
  );

  test("-1, -2, -3", () =>
    expect(calibrate([(-1), (-2), (-3)])) |> toBe(-6)
  );
});

describe("Chronal Calibration #2", () => {
  open Expect;
  open ChronalCalibration;

  test("+1, -1", () =>
    expect(findRepeat([1, (-1)])) |> toBe(0)
  );

  test("+3, +3, +4, -2, -4", () =>
    expect(findRepeat([3, 3, 4, (-2), (-4)])) |> toBe(10)
  );

  test("-6, +3, +8, +5, -6", () =>
    expect(findRepeat([(-6), 3, 8, 5, (-6)])) |> toBe(5)
  );

  test("+7, +7, -2, -7, -4", () =>
    expect(findRepeat([7, 7, (-2), (-7), (-4)])) |> toBe(14)
  );
});