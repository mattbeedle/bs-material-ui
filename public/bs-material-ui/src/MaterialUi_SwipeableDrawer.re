[@bs.deriving jsConverter]
type anchor = [
  | [@bs.as "left"] `Left
  | [@bs.as "top"] `Top
  | [@bs.as "right"] `Right
  | [@bs.as "bottom"] `Bottom
];

module BackdropProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    component: React.element,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      switch (obj->componentGet) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "component",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      Some(unwrappedMap);
    | None => None
    };
  };
};

module ModalProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "BackdropProps"]
    _BackdropProps: BackdropProps.t,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      switch (BackdropProps.unwrap(obj->_BackdropPropsGet)) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "BackdropProps",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      Some(unwrappedMap);
    | None => None
    };
  };
};

module PaperProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    component: React.element,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      switch (obj->componentGet) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "component",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      Some(unwrappedMap);
    | None => None
    };
  };
};

module TransitionDuration_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    enter: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    exit: [ | `Int(int) | `Float(float)],
  };
  let make = t;

  let unwrap = (obj: t) => {
    let unwrappedMap = Js.Dict.empty();

    switch (
      obj->enterGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("enter", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    switch (
      obj->exitGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("exit", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    unwrappedMap;
  };
};

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "permanent"] `Permanent
  | [@bs.as "persistent"] `Persistent
  | [@bs.as "temporary"] `Temporary
];
[@bs.obj]
external makePropsMui:
  (
    ~anchor: string=?,
    ~disableBackdropTransition: bool=?,
    ~disableDiscovery: bool=?,
    ~disableSwipeToOpen: bool=?,
    ~hideBackdrop: bool=?,
    ~hysteresis: 'number_n=?,
    ~minFlingVelocity: 'number_5=?,
    ~_ModalProps: 'any_rcmu=?,
    ~onClose: 'any_r4aj,
    ~onOpen: 'any_r71r,
    ~_open: bool,
    ~_PaperProps: 'any_rxl3=?,
    ~_SwipeAreaProps: Js.t({..})=?,
    ~swipeAreaWidth: 'number_d=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r8xf=?,
    ~variant: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "SwipeableDrawer";

[@react.component]
let make =
    (
      ~anchor: option(anchor)=?,
      ~disableBackdropTransition: option(bool)=?,
      ~disableDiscovery: option(bool)=?,
      ~disableSwipeToOpen: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~hysteresis: option([ | `Int(int) | `Float(float)])=?,
      ~minFlingVelocity: option([ | `Int(int) | `Float(float)])=?,
      ~_ModalProps: option(ModalProps.t)=?,
      ~onClose: ReactEvent.Synthetic.t => unit,
      ~onOpen: ReactEvent.Synthetic.t => unit,
      ~open_: bool,
      ~_PaperProps: option(PaperProps.t)=?,
      ~_SwipeAreaProps: option(Js.t({..}))=?,
      ~swipeAreaWidth: option([ | `Int(int) | `Float(float)])=?,
      ~theme: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~variant: option(variant)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~anchor=?anchor->(Belt.Option.map(v => anchorToJs(v))),
      ~disableBackdropTransition?,
      ~disableDiscovery?,
      ~disableSwipeToOpen?,
      ~hideBackdrop?,
      ~hysteresis=?
        hysteresis->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~minFlingVelocity=?
        minFlingVelocity->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
      ~_ModalProps=?ModalProps.unwrap(_ModalProps),
      ~onClose,
      ~onOpen,
      ~_open=open_,
      ~_PaperProps=?PaperProps.unwrap(_PaperProps),
      ~_SwipeAreaProps?,
      ~swipeAreaWidth=?
        swipeAreaWidth->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
      ~theme?,
      ~transitionDuration=?
        transitionDuration->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      (),
    ),
  );