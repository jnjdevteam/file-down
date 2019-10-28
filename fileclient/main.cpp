//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "homelib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_client *frm_client;
//---------------------------------------------------------------------------
__fastcall Tfrm_client::Tfrm_client(TComponent* Owner)
        : TForm(Owner)
{

   fs = NULL;
   str_filename = "";
   str_savefilename = "";
   totalsize = 0;
   receivesize = 0;
   buffersize =0;

}
//---------------------------------------------------------------------------

void __fastcall Tfrm_client::socket_clientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{

   AnsiString str = Socket->ReceiveText();


   int idx = str.Pos("#FILEDOWNSTART#");
   if(idx>0)
   {

      lb_size->Caption = "0 KByte";
      lb_receive->Caption = "0 KByte";


     if(str_filename != "") return;

     str.Delete(idx, 15);
     idx = str.Pos("#");
     AnsiString str_count = str.SubString(1, idx-1);
     totalsize = StrToInt(str_count);

     str.Delete(1, idx);
     idx = str.Pos("#");
     str_filename = str.SubString(1, idx-1);

     if(MessageDlg("언넘이 파일을 보내는디 이거 바이러스 일수도 있으니께\r\n받든지 말던지 니입맞데로 하게", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
     {

        TSaveDialog* dlg = new TSaveDialog(this);
        dlg->InitialDir = "";
        dlg->FileName = ExtractFileName(str_filename);
        dlg->DefaultExt = ExtractFileExt(str_filename);
        if(dlg->Execute() == TRUE)
        {
           str_savefilename = dlg->FileName;
           AnsiString str_require = "#FILEDOWNLOADED#" + str_filename + "#0#";
           Socket->SendText(str_require);
           receivesize = 0;
           fs = new TFileStream(str_savefilename, fmCreate|fmShareCompat);
           lb_filename->Caption = ExtractFileName(str_filename);
           int byte_totalsize = totalsize/1024;
           lb_size->Caption = IntToStr(byte_totalsize) + " KByte";
           lb_receive->Caption = "0 KByte";
           bar->Max = totalsize;
           bar->Min = 0;
           bar->Position = 0;
           milesecond = GetTickCount();
           lb_fast->Caption = "0 Kbyte/sec";
        }
        else
        {
            fs = NULL;
            str_buf = "";
            str_filename = "";
            str_savefilename = "";
            totalsize = 0;
            receivesize = 0;
            buffersize =0;

            lb_filename->Caption = "";
            lb_receive->Caption = "0 KByte";
            lb_size->Caption = "0 KByte";
            bar->Position = 0;
            lb_fast->Caption = "0 Kbyte/sec";

        }
     }
     else
     {
            fs = NULL;
            str_buf = "";
            str_filename = "";
            str_savefilename = "";
            totalsize = 0;
            receivesize = 0;
            buffersize =0;

            lb_filename->Caption = "";
            lb_receive->Caption = "0 KByte";
            lb_size->Caption = "0 KByte";
            bar->Position = 0;
            lb_fast->Caption = "0 Kbyte/sec";
     }


   }
   else
   {
      idx = str.Pos("#FILEDOWNLOADING#");
      if(idx >0)
      {
         str.Delete(idx, 17);
         idx = str.Pos("#");
         AnsiString str_buffersize = str.SubString(1, idx-1);
         buffersize = StrToInt(str_buffersize);
         str.Delete(1, idx);
         str_buf = "";
         str_buf = str;
         receivesize = receivesize + str.Length();
         int byte_receivesize = receivesize/1024;
         lb_receive->Caption = IntToStr(byte_receivesize) + " KByte";
         int fast = GetTickCount();
         fast = fast-milesecond;
         fast = (byte_receivesize*1000)/ fast;
         lb_fast->Caption = IntToStr(fast) + " KByte/sec";
         bar->Position = receivesize;

         if(receivesize == totalsize)
         {
            fs->Write(str_buf.c_str(), str_buf.Length());

            delete fs;
            fs = NULL;
            str_buf = "";
            str_filename = "";
            str_savefilename = "";
            totalsize = 0;
            receivesize = 0;
            buffersize =0;

            lb_filename->Caption = "";
            lb_receive->Caption = "0 KByte";
            lb_size->Caption = "0 KByte";
            bar->Position = 0;
            lb_fast->Caption = "0 Kbyte/sec";

            ShowMessage("다운로드 완료");


         }
         else if(str_buf.Length() >= buffersize)
         {
            fs->Write(str_buf.c_str(), str_buf.Length());
            AnsiString str_require = "#FILEDOWNLOADED#" + str_filename + "#" + IntToStr(receivesize)+ "#";
            Socket->SendText(str_require);

         }
      }
      else
      {
         if(fs == NULL) return;
         str_buf = str_buf + str;
         receivesize = receivesize + str.Length();
         int byte_receivesize = receivesize/1024;
         lb_receive->Caption = IntToStr(byte_receivesize) + " KByte";
         int fast = GetTickCount();
         fast = fast-milesecond;
         fast = (byte_receivesize*1000)/ fast;
         lb_fast->Caption = IntToStr(fast) + " KByte/sec";

         bar->Position = receivesize;

         if(receivesize == totalsize)
         {
            fs->Write(str_buf.c_str(), str_buf.Length());
            delete fs;
            str_buf = "";
            fs == NULL;
            str_filename = "";
            str_savefilename = "";
            totalsize = 0;
            receivesize = 0;
            buffersize = 0;

            lb_filename->Caption = "";
            lb_receive->Caption = "0 KByte";
            lb_size->Caption = "0 KByte";
            bar->Position = 0;
            lb_fast->Caption = "0 Kbyte/sec";

             ShowMessage("다운로드 완료");


         }
         else if(str_buf.Length() >= buffersize)
         {
            fs->Write(str_buf.c_str(), str_buf.Length());
            AnsiString str_require = "#FILEDOWNLOADED#" + str_filename + "#" + IntToStr(receivesize) +"#";
            Socket->SendText(str_require);
         }

      }
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_client::FormClose(TObject *Sender, TCloseAction &Action)
{
   socket_client->Active = FALSE;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_client::socket_clientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
   ErrorCode = 0;
   ShowMessage("서버와의 연결이 끊어졌읍니다");
}
//---------------------------------------------------------------------------


