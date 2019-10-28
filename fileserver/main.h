//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TServerSocket *sock_server;
        TButton *Button1;
        TListBox *lbox_client;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall sock_serverClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall sock_serverClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall sock_serverClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall sock_serverClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
        TList* lst_client;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
