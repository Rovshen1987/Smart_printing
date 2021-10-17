object Static_I_F: TStatic_I_F
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
  ClientHeight = 292
  ClientWidth = 448
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 21
  object Panel_g: TPanel
    Left = 0
    Top = 0
    Width = 448
    Height = 292
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 0
    object Program_operation_GB: TGroupBox
      Left = 16
      Top = 16
      Width = 425
      Height = 97
      Caption = #1069#1082#1089#1087#1083#1091#1072#1090#1072#1094#1080#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      TabOrder = 0
      object Launched_L: TLabel
        Left = 16
        Top = 32
        Width = 69
        Height = 21
        Caption = #1047#1072#1087#1091#1097#1077#1085
      end
      object Working_hours_L: TLabel
        Left = 16
        Top = 59
        Width = 115
        Height = 21
        Caption = #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099
      end
      object Launched_L_g: TLabel
        Left = 216
        Top = 32
        Width = 113
        Height = 21
        Caption = 'Launched_L_g'
      end
      object Working_hours_L_g: TLabel
        Left = 216
        Top = 56
        Width = 155
        Height = 21
        Caption = 'Working_hours_L_g'
      end
      object Bevel2: TBevel
        Left = 192
        Top = 23
        Width = 9
        Height = 57
        Shape = bsLeftLine
      end
    end
    object Print_statistics_GB: TGroupBox
      Left = 16
      Top = 128
      Width = 425
      Height = 113
      Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1087#1077#1095#1072#1090#1080
      TabOrder = 1
      object Successful_prints_L: TLabel
        Left = 16
        Top = 24
        Width = 142
        Height = 21
        Caption = #1059#1089#1087#1077#1096#1085#1099#1077' '#1087#1077#1095#1072#1090#1080
      end
      object Erroneous_seals_L: TLabel
        Left = 16
        Top = 48
        Width = 158
        Height = 21
        Caption = #1054#1096#1080#1073#1086#1095#1085#1099#1077' '#1087#1077#1095#1072#1090#1080
      end
      object Bevel1: TBevel
        Left = 16
        Top = 75
        Width = 393
        Height = 6
        Shape = bsTopLine
      end
      object Result_L: TLabel
        Left = 16
        Top = 80
        Width = 39
        Height = 21
        Caption = #1048#1090#1086#1075
      end
      object Successful_prints_L_g: TLabel
        Left = 216
        Top = 24
        Width = 173
        Height = 21
        Caption = 'Successful_prints_L_g'
      end
      object Erroneous_seals_L_g: TLabel
        Left = 216
        Top = 51
        Width = 163
        Height = 21
        Caption = 'Erroneous_seals_L_g'
      end
      object Result_L_g: TLabel
        Left = 216
        Top = 80
        Width = 87
        Height = 21
        Caption = 'Result_L_g'
      end
      object Bevel3: TBevel
        Left = 192
        Top = 12
        Width = 9
        Height = 57
        Shape = bsLeftLine
      end
    end
    object Save_reports_B: TButton
      Left = 16
      Top = 247
      Width = 166
      Height = 42
      Cursor = crHandPoint
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1054#1090#1095#1077#1090
      TabOrder = 2
      OnClick = Save_reports_BClick
    end
    object Exit_B: TButton
      Left = 272
      Top = 247
      Width = 169
      Height = 41
      Cursor = crHandPoint
      Caption = #1042#1099#1081#1090#1080
      TabOrder = 3
      OnClick = Exit_BClick
    end
  end
  object SaveDialog: TSaveDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1086#1081' '#1092#1072#1081#1083' (*txt)|*.txt;'
    Left = 232
    Top = 112
  end
end
