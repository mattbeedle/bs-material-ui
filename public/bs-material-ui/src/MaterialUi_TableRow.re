module Classes = {
  type classesType =
    | Root(string)
    | Selected(string)
    | Hover(string)
    | Head(string)
    | Footer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Selected(_) => "selected"
    | Hover(_) => "hover"
    | Head(_) => "head"
    | Footer(_) => "footer";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Selected(className)
                         | Hover(className)
                         | Head(className)
                         | Footer(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~className: string=?,
    ~hover: bool=?,
    ~selected: bool=?,
    ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "TableRow";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~hover: option(bool)=?,
      ~selected: option(bool)=?,
      ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~hover?,
      ~selected?,
      ~onDoubleClick?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );