object Configuration_F: TConfiguration_F
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
  ClientHeight = 704
  ClientWidth = 503
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  StyleName = 'Iceberg Classico'
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 21
  object Configuration_place_P: TPanel
    Left = 0
    Top = 0
    Width = 503
    Height = 704
    Cursor = crHandPoint
    Align = alClient
    BevelKind = bkFlat
    TabOrder = 0
    object General_setup_GB: TGroupBox
      Left = 8
      Top = 16
      Width = 481
      Height = 673
      Caption = #1054#1089#1085#1086#1074#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
      TabOrder = 0
      object Bevel1: TBevel
        Left = 16
        Top = 431
        Width = 436
        Height = 154
        Shape = bsFrame
      end
      object Bevel_Save: TBevel
        Left = 16
        Top = 341
        Width = 436
        Height = 75
        Shape = bsFrame
      end
      object Url_L_Config: TLabel
        Left = 16
        Top = 32
        Width = 23
        Height = 21
        Caption = 'Url'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Choose_printer_L_Config: TLabel
        Left = 16
        Top = 110
        Width = 141
        Height = 21
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1088#1080#1085#1090#1077#1088
      end
      object Bevel_CH: TBevel
        Left = 16
        Top = 195
        Width = 436
        Height = 139
        Shape = bsFrame
      end
      object Save_L: TLabel
        Left = 74
        Top = 355
        Width = 290
        Height = 21
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1091' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1042
      end
      object Bevel_Url: TBevel
        Left = 96
        Top = 105
        Width = 265
        Height = 9
        Shape = bsTopLine
      end
      object Bevel_timer_regularity: TBevel
        Left = 96
        Top = 180
        Width = 265
        Height = 9
        Shape = bsTopLine
      end
      object Regularity_of_printing_by_time_L: TLabel
        Left = 38
        Top = 227
        Width = 265
        Height = 21
        Caption = #1056#1077#1075#1091#1083#1103#1088#1085#1086#1089#1090#1100' '#1087#1077#1095#1072#1090#1080' '#1087#1086' '#1074#1088#1077#1084#1077#1085#1080
      end
      object Automation_Smart_Printing_program_L: TLabel
        Left = 74
        Top = 446
        Width = 332
        Height = 21
        Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1079#1072#1094#1080#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' Smart Printing'
      end
      object Starting_program_L: TLabel
        Left = 42
        Top = 501
        Width = 293
        Height = 21
        Cursor = crHandPoint
        Caption = #1085#1072#1089#1090#1088#1086#1081#1082#1072#1084' '#1087#1088#1080' '#1079#1072#1087#1091#1089#1082#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      end
      object Starting_Windows_L: TLabel
        Left = 43
        Top = 551
        Width = 144
        Height = 21
        Cursor = crHandPoint
        Caption = ' '#1079#1072#1087#1091#1089#1082#1080' Windows'
      end
      object Url_CB_Config: TComboBox
        Left = 16
        Top = 60
        Width = 433
        Height = 29
        Cursor = crHandPoint
        TabOrder = 0
        Text = 'https://moda.captain.business/p.php?api=123456789'
        OnChange = Url_CB_ConfigChange
      end
      object Choose_printer_CB_Config: TComboBox
        Tag = 1
        Left = 16
        Top = 140
        Width = 433
        Height = 29
        Cursor = crHandPoint
        TabOrder = 1
        Text = 'Choose_printer_CB_Config'
        OnChange = Choose_printer_CB_ConfigChange
      end
      object Program_run_time_CH: TCheckBox
        Tag = 4
        Left = 25
        Top = 254
        Width = 321
        Height = 25
        Cursor = crHandPoint
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1074#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        TabOrder = 3
        OnClick = Program_run_time_CHClick
      end
      object Timer_СH: TCheckBox
        Tag = 5
        Left = 24
        Top = 285
        Width = 241
        Height = 33
        Cursor = crHandPoint
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1058#1072#1081#1084#1077#1088
        TabOrder = 4
        OnClick = Timer_СHClick
      end
      object Registry_RB: TRadioButton
        Tag = 6
        Left = 43
        Top = 380
        Width = 177
        Height = 33
        Cursor = crHandPoint
        Caption = #1056#1077#1077#1089#1090#1088#1077' Windows'
        Checked = True
        TabOrder = 5
        TabStop = True
        OnClick = Registry_RBClick
      end
      object Inifile_RB: TRadioButton
        Tag = 7
        Left = 307
        Top = 380
        Width = 137
        Height = 33
        Cursor = crHandPoint
        Caption = 'Ini '#1060#1072#1081#1083
        TabOrder = 6
        OnClick = Inifile_RBClick
      end
      object Save_B: TButton
        Left = 16
        Top = 608
        Width = 209
        Height = 49
        Cursor = crHandPoint
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        TabOrder = 8
        OnClick = Save_BClick
      end
      object Close_B: TButton
        Left = 248
        Top = 608
        Width = 201
        Height = 49
        Cursor = crHandPoint
        Caption = #1047#1072#1082#1088#1099#1090#1100
        TabOrder = 10
        OnClick = Close_BClick
      end
      object Regularity_of_printing_by_time_Config_ME: TMaskEdit
        Tag = 3
        Left = 309
        Top = 225
        Width = 135
        Height = 29
        Cursor = crHandPoint
        EditMask = '!90:00:00;1;_'
        MaxLength = 8
        TabOrder = 2
        Text = '00:01:00'
        OnChange = Regularity_of_printing_by_time_Config_MEChange
        OnExit = Regularity_of_printing_by_time_Config_MEExit
      end
      object Starting_program_CH: TCheckBox
        Tag = 8
        Left = 24
        Top = 473
        Width = 425
        Height = 33
        Cursor = crHandPoint
        Caption = #1042#1082#1083#1102#1095#1072#1090#1100' '#1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1087#1086' '#1087#1086#1089#1083#1077#1076#1085#1080#1084' '
        TabOrder = 7
        OnClick = Starting_program_CHClick
      end
      object Starting_windows_CH: TCheckBox
        Tag = 9
        Left = 24
        Top = 520
        Width = 428
        Height = 33
        Cursor = crHandPoint
        Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' '#1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1087#1088#1080
        TabOrder = 9
        OnClick = Starting_windows_CHClick
      end
      object Automatics_run_CH: TCheckBox
        Tag = 2
        Left = 25
        Top = 196
        Width = 278
        Height = 25
        Cursor = crHandPoint
        Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1088#1077#1078#1080#1084' '#1087#1077#1095#1072#1090#1080
        TabOrder = 11
        OnClick = Automatics_run_CHClick
      end
      object Config_SHCut: TButton
        Left = 192
        Top = 280
        Width = 252
        Height = 38
        Cursor = crHandPoint
        Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1075#1086#1088#1103#1095#1080#1077' '#1082#1083#1072#1074#1080#1096#1072
        TabOrder = 12
        OnClick = Config_SHCutClick
      end
    end
  end
end
