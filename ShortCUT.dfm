object ShortCUT_F: TShortCUT_F
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1075#1086#1088#1103#1095#1080#1077' '#1082#1083#1072#1074#1080#1096#1072
  ClientHeight = 595
  ClientWidth = 611
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Times New Roman'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 19
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 611
    Height = 595
    Cursor = crHandPoint
    Align = alClient
    BevelKind = bkSoft
    TabOrder = 0
    object Open_SHCut_L: TLabel
      Left = 80
      Top = 20
      Width = 71
      Height = 21
      Caption = #1054#1090#1082#1088#1099#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Save_SHCut_L: TLabel
      Left = 80
      Top = 70
      Width = 87
      Height = 21
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Save_as_SHCut_L: TLabel
      Left = 80
      Top = 120
      Width = 218
      Height = 21
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' ('#1085#1072#1089#1090#1088#1086#1081#1082#1091')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Fast_printing_SHCut_L: TLabel
      Left = 80
      Top = 170
      Width = 126
      Height = 21
      Caption = #1041#1099#1089#1090#1088#1072#1103' '#1087#1077#1095#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Preview_SHCut_L: TLabel
      Left = 80
      Top = 220
      Width = 229
      Height = 21
      Caption = #1055#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1099#1081' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Exit_SHCut_L: TLabel
      Left = 80
      Top = 270
      Width = 52
      Height = 21
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Power_on_SHCut_L: TLabel
      Left = 80
      Top = 320
      Width = 80
      Height = 21
      Caption = #1042#1082#1083#1102#1095#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Power_off_SHCut_L: TLabel
      Left = 80
      Top = 370
      Width = 90
      Height = 21
      Caption = #1054#1090#1082#1083#1102#1095#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Config_SHCut_L: TLabel
      Left = 80
      Top = 420
      Width = 85
      Height = 21
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Bevel1: TBevel
      Left = 70
      Top = 10
      Width = 9
      Height = 463
      Shape = bsLeftLine
    end
    object Bevel2: TBevel
      Left = 337
      Top = 23
      Width = 9
      Height = 450
      Shape = bsLeftLine
    end
    object Bevel3: TBevel
      Left = 8
      Top = 496
      Width = 585
      Height = 9
      Shape = bsTopLine
    end
    object Bevel4: TBevel
      Left = 8
      Top = 504
      Width = 585
      Height = 73
      Shape = bsFrame
      Style = bsRaised
    end
    object Open_SHCut_BB: TBitBtn
      Left = 8
      Top = 10
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 0
      Images = General_F.ImageList_g
      TabOrder = 0
    end
    object Save_SHCut_BB: TBitBtn
      Left = 8
      Top = 60
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 1
      Images = General_F.ImageList_g
      TabOrder = 1
    end
    object Save_as_SHCut_BB: TBitBtn
      Left = 8
      Top = 110
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 2
      Images = General_F.ImageList_g
      TabOrder = 2
    end
    object Fast_printing_SHCut_BB: TBitBtn
      Left = 8
      Top = 160
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 3
      Images = General_F.ImageList_g
      TabOrder = 3
    end
    object Preview_SHCut_BB: TBitBtn
      Left = 8
      Top = 210
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 5
      Images = General_F.ImageList_g
      TabOrder = 4
    end
    object Exit_SHCut_BB: TBitBtn
      Left = 8
      Top = 260
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 10
      Images = General_F.ImageList_g
      TabOrder = 5
    end
    object Power_on_SHCut_BB: TBitBtn
      Left = 8
      Top = 310
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 6
      Images = General_F.ImageList_g
      TabOrder = 6
    end
    object Power_off_SHCut_BB: TBitBtn
      Left = 8
      Top = 360
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 7
      Images = General_F.ImageList_g
      TabOrder = 7
    end
    object Config_SHCut_BB: TBitBtn
      Left = 8
      Top = 410
      Width = 50
      Height = 40
      Cursor = crHandPoint
      ImageIndex = 8
      Images = General_F.ImageList_g
      TabOrder = 8
    end
    object Save_B: TButton
      Left = 80
      Top = 520
      Width = 200
      Height = 50
      Cursor = crHandPoint
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 9
      OnClick = Save_BClick
    end
    object Panel2: TPanel
      Left = 352
      Top = 13
      Width = 241
      Height = 460
      TabOrder = 10
      object Open_SHCut_E: THotKey
        Left = 10
        Top = 5
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 0
        OnChange = Open_SHCut_EChange
      end
      object Save_SHCut_E: THotKey
        Left = 10
        Top = 55
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 1
        OnChange = Save_SHCut_EChange
      end
      object Save_as_SHCut_E: THotKey
        Left = 10
        Top = 105
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 2
        OnChange = Save_as_SHCut_EChange
      end
      object Fast_printing_SHCut_E: THotKey
        Left = 10
        Top = 155
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 3
        OnChange = Fast_printing_SHCut_EChange
      end
      object Preview_SHCut_E: THotKey
        Left = 10
        Top = 205
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 4
        OnChange = Preview_SHCut_EChange
      end
      object Exit_SHCut_E: THotKey
        Left = 10
        Top = 255
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 5
        OnChange = Exit_SHCut_EChange
      end
      object Power_on_SHCut_E: THotKey
        Left = 10
        Top = 305
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 6
        OnChange = Power_on_SHCut_EChange
      end
      object Power_off_SHCut_E: THotKey
        Left = 10
        Top = 355
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 7
        OnChange = Power_off_SHCut_EChange
      end
      object Config_SHCut_E: THotKey
        Left = 10
        Top = 405
        Width = 217
        Height = 33
        Cursor = crHandPoint
        HotKey = 0
        Modifiers = []
        TabOrder = 8
        OnChange = Config_SHCut_EChange
      end
    end
    object Exit_B: TButton
      Left = 352
      Top = 520
      Width = 200
      Height = 50
      Cursor = crHandPoint
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      TabOrder = 11
      OnClick = Exit_BClick
    end
  end
end
