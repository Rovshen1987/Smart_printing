object Web_browser_F: TWeb_browser_F
  Left = 0
  Top = 0
  VertScrollBar.ParentColor = False
  VertScrollBar.Visible = False
  AlphaBlend = True
  AlphaBlendValue = 0
  Caption = 'Web_browser_F'
  ClientHeight = 440
  ClientWidth = 845
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
  object Image: TImage
    Left = 0
    Top = 0
    Width = 845
    Height = 440
    Align = alClient
    ExplicitLeft = 200
    ExplicitTop = 88
    ExplicitWidth = 169
    ExplicitHeight = 169
  end
  object WebBrowser: TWebBrowser
    Left = 0
    Top = 0
    Width = 845
    Height = 440
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 200
    ExplicitTop = 144
    ExplicitWidth = 300
    ExplicitHeight = 150
    ControlData = {
      4C000000555700007A2D00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object Timer: TTimer
    Enabled = False
    OnTimer = TimerTimer
    Left = 472
    Top = 192
  end
end
