[%bs.raw {|require('./network.css')|}];

open Document;

type action =
  | Offline
  | Online;

type state = {status: string};

let component = ReasonReact.reducerComponent "Network";

let offline = {js|ＯＦＦＬＩＮＥ (　´_ﾉ` )|js};

let online = {js|ＯＮＬＩＮＥ (๑꒪▿꒪)*|js};

let make _children => {
  ...component,
  initialState: fun () => {status: [%bs.raw "window.navigator.onLine"] ? online : offline},
  reducer: fun action _state =>
    switch action {
    | Offline => ReasonReact.Update {status: offline}
    | Online => ReasonReact.Update {status: online}
    },
  didMount: fun {reduce} => {
    Document.addEventListener Document.window "offline" (reduce (fun _ => Offline));
    Document.addEventListener Document.window "online" (reduce (fun _ => Online));
    ReasonReact.NoUpdate
  },
  willUnmount: fun {reduce} => {
    Document.removeEventListener Document.window "offline" (reduce (fun _ => Offline));
    Document.removeEventListener Document.window "online" (reduce (fun _ => Online));
    ()
  },
  render: fun {state: {status}} =>
    <div className="Network">
      <h1> (ReasonReact.stringToElement {js|ＹＯＵ ＡＲＥ|js}) </h1>
      <h2> (ReasonReact.stringToElement status) </h2>
    </div>
};
