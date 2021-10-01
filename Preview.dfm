object Preview_F: TPreview_F
  Left = 0
  Top = 0
  Caption = 'Preview_F'
  ClientHeight = 623
  ClientWidth = 964
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object frxPreview1: TfrxPreview
    Left = 0
    Top = 0
    Width = 964
    Height = 623
    Align = alClient
    OutlineVisible = True
    OutlineWidth = 185
    ThumbnailVisible = False
    FindFmVisible = False
    UseReportHints = True
    OutlineTreeSortType = dtsUnsorted
    HideScrolls = False
    ExplicitLeft = 536
    ExplicitTop = 152
    ExplicitWidth = 97
    ExplicitHeight = 121
  end
  object frxReport1: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44470.466212372690000000
    ReportOptions.LastChange = 44470.466212372690000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 120
    Top = 152
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object Memo1: TfrxMemoView
        AllowVectorExport = True
        Left = 68.031540000000000000
        Top = 79.370130000000000000
        Width = 355.275820000000000000
        Height = 45.354360000000000000
        Frame.Typ = []
        Memo.UTF8W = (
          #1055#1088#1080#1085#1090)
      end
      object Memo2: TfrxMemoView
        AllowVectorExport = True
        Left = 230.551330000000000000
        Top = 177.637910000000000000
        Width = 3.779530000000000000
        Height = 15.118120000000000000
        Frame.Typ = []
      end
    end
  end
end
