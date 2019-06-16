[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "text"] `Text
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
];

module Classes = {
  type classesType =
    | Root(string)
    | Label(string)
    | Text(string)
    | TextPrimary(string)
    | TextSecondary(string)
    | Outlined(string)
    | OutlinedPrimary(string)
    | OutlinedSecondary(string)
    | Contained(string)
    | ContainedPrimary(string)
    | ContainedSecondary(string)
    | FocusVisible(string)
    | Disabled(string)
    | ColorInherit(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | FullWidth(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Label(_) => "label"
    | Text(_) => "text"
    | TextPrimary(_) => "textPrimary"
    | TextSecondary(_) => "textSecondary"
    | Outlined(_) => "outlined"
    | OutlinedPrimary(_) => "outlinedPrimary"
    | OutlinedSecondary(_) => "outlinedSecondary"
    | Contained(_) => "contained"
    | ContainedPrimary(_) => "containedPrimary"
    | ContainedSecondary(_) => "containedSecondary"
    | FocusVisible(_) => "focusVisible"
    | Disabled(_) => "disabled"
    | ColorInherit(_) => "colorInherit"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | FullWidth(_) => "fullWidth";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Label(className)
                         | Text(className)
                         | TextPrimary(className)
                         | TextSecondary(className)
                         | Outlined(className)
                         | OutlinedPrimary(className)
                         | OutlinedSecondary(className)
                         | Contained(className)
                         | ContainedPrimary(className)
                         | ContainedSecondary(className)
                         | FocusVisible(className)
                         | Disabled(className)
                         | ColorInherit(className)
                         | SizeSmall(className)
                         | SizeLarge(className)
                         | FullWidth(className) =>
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
    ~color: string=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~fullWidth: bool=?,
    ~href: string=?,
    ~size: string=?,
    ~_type: string=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Button";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~fullWidth: option(bool)=?,
      ~href: option(string)=?,
      ~size: option(size)=?,
      ~type_: option(string)=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~disabled?,
      ~disableFocusRipple?,
      ~disableRipple?,
      ~focusVisibleClassName?,
      ~fullWidth?,
      ~href?,
      ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
      ~_type=?type_,
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );