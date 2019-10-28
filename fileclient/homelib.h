#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <HTTPApp.hpp>

#define HomePageRoot "c:\inetpub\wwwroot\"
#define RootURL "/wwwroot/"

//1.���� ���丮 ã��
AnsiString _getexecpath();

//2.���ڿ����� Ư�����ڿ��� ã�� �ٲٱ�
void _replace(AnsiString& str_src, AnsiString str_find, AnsiString str_repl);

//3. ������ ���丮 ã��
AnsiString _getwindowspath();

//4. �ý��۵��丮 ã��
AnsiString _getsystempath();

//5.��¥ �����
AnsiString _getmakedate(AnsiString str_src);

//6.�ٳѱ��
AnsiString _makebr(AnsiString str_src);

//7.���Ϻҷ��ͼ� ���ڿ������� �ٲٱ�
AnsiString _loadfromfile(AnsiString str_filename);

//8.�ڷΰ��� ��ũ ���ڿ� ��ȯ
AnsiString _backlink();

//9.��Ʈ�� ���������� ����
AnsiString _makered(AnsiString str_src, AnsiString str_key);

//10.�ش繮�ڿ��� ã������ �ںκ� ���ڿ��� ��ȯ '@'�� �������������� ������ ���ڿ�������
//(���ذ� �� �Ȱ�-- ��� ���°���..)
AnsiString _nextlist(AnsiString str_list, AnsiString str_key);

//11.���ڿ� ������
void _reverse(AnsiString& str_src);

//12. _nextlist�ݴ� �Լ�..(���ذ� �ȵ� ��.��);
AnsiString _prelist(AnsiString str_list, AnsiString str_key);

//13. _nextlist�� ������ ����..
AnsiString _2nextlist(AnsiString str_list, AnsiString str_key);

//14. _prelist�� ������ ����
AnsiString _2prelist(AnsiString str_list, AnsiString str_key);

//15. �߰��� �� ���� ã��, �ι�° Ű���� ��ȯ
AnsiString _centerlist(AnsiString str_list, AnsiString str_key);

//16. ����Ʈ �ʵ� ���� ��ȯ.
AnsiString _getcontentfield(TWebRequest *Request, TStringList* contentlist, AnsiString str_uploadname);

//17. �ֹι�ȣüũ �Լ�
BOOLEAN CheckJumin( AnsiString Jumin );


