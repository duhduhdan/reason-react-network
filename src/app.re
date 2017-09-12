let component = ReasonReact.statelessComponent "App";

let make _children => {...component, render: fun _self => <Network />};
