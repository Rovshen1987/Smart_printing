object Web_browser: TWeb_browser
  Left = 0
  Top = 0
  Caption = 'Web_browser'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object CppWebBrowser1: TCppWebBrowser
    Left = 0
    Top = 21
    Width = 635
    Height = 278
    Align = alClient
    TabOrder = 0
    ExplicitTop = 27
    ControlData = {
      4C000000A1410000BB1C00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object Edit1: TEdit
    Left = 0
    Top = 0
    Width = 635
    Height = 21
    Align = alTop
    TabOrder = 1
    Text = 'Edit1'
  end
  object PrintDialog1: TPrintDialog
    Left = 224
    Top = 112
  end
end
