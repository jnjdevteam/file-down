//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define SENDSIZE 1

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

  int idx = lbox_client->ItemIndex;
  if(idx == -1) return;

  TCustomWinSocket* Socket;
  Socket = (TCustomWinSocket*)lst_client->Items[idx];


  TOpenDialog* dlg = new TOpenDialog(this);
  TFileStream* fs;
  AnsiString fstr;
  dlg->InitialDir = "d:\\";
  dlg->DefaultExt = "*.*";
  if(dlg->Execute() == TRUE)
  {

     AnsiString fstr;
     fs = new TFileStream(dlg->FileName, fmOpenRead|fmShareCompat);
     AnsiString str = "#FILEDOWNSTART#" + IntToStr(fs->Size)+"#"+ dlg->FileName + "#";
     Socket->SendText(str);
     delete fs;

  }
  delete dlg;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    lst_client = new TList();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete lst_client;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sock_serverClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    lst_client->Add(Socket);
    lbox_client->Items->AddObject(Socket->RemoteAddress, Socket);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sock_serverClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        int idx = lbox_client->Items->IndexOfObject(Socket);

        if(idx == -1) return;
        lbox_client->Items->Delete(idx);
        lst_client->Remove(Socket);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sock_serverClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{


        AnsiString str_data="";

        AnsiString cls_str="";
        cls_str = Socket->ReceiveText();

        int idx = cls_str.Pos("#FILEDOWNLOADED#");
        if(idx <= 0) return;

        cls_str.Delete(idx, 16);
        idx = cls_str.Pos("#");
        AnsiString str_filename = cls_str.SubString(1, idx-1);
        cls_str.Delete(1, idx);
        idx = cls_str.Pos("#");
        AnsiString str_downloadedsize = cls_str.SubString(1, idx-1);
        int downloadedsize = StrToInt(str_downloadedsize);

        TFileStream* fs = new TFileStream(str_filename, fmOpenRead|fmShareCompat);
        int totalsize = fs->Size;
        fs->Position = downloadedsize;
        if((totalsize-downloadedsize) > (SENDSIZE*1024))
        {

           str_data.SetLength(SENDSIZE*1024);
           fs->Read(str_data.c_str(), SENDSIZE*1024);

        }
        else
        {
           str_data.SetLength(totalsize-downloadedsize);
           fs->Read(str_data.c_str(), totalsize-downloadedsize);
        }
        delete fs;



        AnsiString str= "#FILEDOWNLOADING#"+ IntToStr(str_data.Length()) + "#";
        str = str + str_data;
        Socket->SendText(str);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::sock_serverClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{

      int idx = lbox_client->Items->IndexOfObject(Socket);

      if(idx == -1) return;
      lbox_client->Items->Delete(idx);
      lst_client->Remove(Socket);
      Socket->Close();

      ErrorCode = 0;
}
//---------------------------------------------------------------------------

