object Form1: TForm1
  Left = 271
  Top = 149
  Width = 378
  Height = 302
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 248
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object lbox_client: TListBox
    Left = 16
    Top = 16
    Width = 225
    Height = 241
    ImeName = '한국어(한글) (MS-IME98)'
    ItemHeight = 13
    TabOrder = 1
  end
  object sock_server: TServerSocket
    Active = True
    Port = 12000
    ServerType = stNonBlocking
    OnClientConnect = sock_serverClientConnect
    OnClientDisconnect = sock_serverClientDisconnect
    OnClientRead = sock_serverClientRead
    OnClientError = sock_serverClientError
    Left = 336
    Top = 16
  end
end
