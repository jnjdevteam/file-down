//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class Tfrm_client : public TForm
{
__published:	// IDE-managed Components
        TClientSocket *socket_client;
        TLabel *Label1;
        TLabel *lb_size;
        TLabel *Label3;
        TLabel *lb_receive;
        TProgressBar *bar;
        TLabel *Label2;
        TLabel *lb_filename;
        TLabel *Label4;
        TLabel *lb_fast;
        void __fastcall socket_clientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall socket_clientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
        AnsiString str_buf;
        int buffersize;
        int totalsize;
        int receivesize;
        int milesecond;
        AnsiString str_filename;
        AnsiString str_savefilename;
        TFileStream* fs;
        __fastcall Tfrm_client(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_client *frm_client;
//---------------------------------------------------------------------------
#endif
