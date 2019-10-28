//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("fileclient.res");
USEFORM("main.cpp", frm_client);
USEUNIT("homelib.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tfrm_client), &frm_client);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
