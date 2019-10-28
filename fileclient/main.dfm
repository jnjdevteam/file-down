object frm_client: Tfrm_client
  Left = 246
  Top = 190
  Width = 461
  Height = 156
  Caption = '파일다운로드 & 업로드'
  Color = clBtnFace
  Font.Charset = HANGEUL_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = '굴림체'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 208
    Top = 80
    Width = 54
    Height = 12
    AutoSize = False
    Caption = '총파일량:'
  end
  object lb_size: TLabel
    Left = 291
    Top = 80
    Width = 42
    Height = 12
    Caption = '0 KByte'
  end
  object Label3: TLabel
    Left = 207
    Top = 96
    Width = 56
    Height = 12
    AutoSize = False
    Caption = '받은파일:'
  end
  object lb_receive: TLabel
    Left = 291
    Top = 96
    Width = 42
    Height = 12
    Caption = '0 KByte'
  end
  object Label2: TLabel
    Left = 16
    Top = 24
    Width = 54
    Height = 12
    AutoSize = False
    Caption = '파일이름:'
  end
  object lb_filename: TLabel
    Left = 88
    Top = 24
    Width = 6
    Height = 12
  end
  object Label4: TLabel
    Left = 230
    Top = 112
    Width = 30
    Height = 12
    AutoSize = False
    Caption = '속도:'
  end
  object lb_fast: TLabel
    Left = 291
    Top = 112
    Width = 66
    Height = 12
    Caption = '0 KByte/sec'
  end
  object bar: TProgressBar
    Left = 16
    Top = 48
    Width = 425
    Height = 16
    Min = 0
    Max = 100
    TabOrder = 0
  end
  object socket_client: TClientSocket
    Active = True
    Address = '211.39.168.218'
    ClientType = ctNonBlocking
    Port = 12000
    OnRead = socket_clientRead
    OnError = socket_clientError
    Left = 40
    Top = 72
  end
end
