module Document = {
  type element;
  let window: element = [%bs.raw "window"];
  external addEventListener : element => string => (unit => unit) => unit =
    "addEventListener" [@@bs.send];
  external removeEventListener : element => string => (unit => unit) => unit =
    "removeEventListener" [@@bs.send];
};
