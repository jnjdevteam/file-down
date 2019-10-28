#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <HTTPApp.hpp>

#define HomePageRoot "c:\inetpub\wwwroot\"
#define RootURL "/wwwroot/"

//1.현제 디렉토리 찾기
AnsiString _getexecpath();

//2.문자열에서 특정문자열을 찾아 바꾸기
void _replace(AnsiString& str_src, AnsiString str_find, AnsiString str_repl);

//3. 윈도우 디렉토리 찾기
AnsiString _getwindowspath();

//4. 시스템디렉토리 찾기
AnsiString _getsystempath();

//5.날짜 만들기
AnsiString _getmakedate(AnsiString str_src);

//6.줄넘기기
AnsiString _makebr(AnsiString str_src);

//7.파일불러와서 문자열형으로 바꾸기
AnsiString _loadfromfile(AnsiString str_filename);

//8.뒤로가기 링크 문자열 반환
AnsiString _backlink();

//9.폰트를 빨간색으로 변형
AnsiString _makered(AnsiString str_src, AnsiString str_key);

//10.해당문자열을 찾은다음 뒤부분 문자열을 반환 '@'자 나오기전까지나 없으면 문자열끝까지
//(이해가 잘 안감-- 어디에 쓰는건지..)
AnsiString _nextlist(AnsiString str_list, AnsiString str_key);

//11.문자열 뒤집기
void _reverse(AnsiString& str_src);

//12. _nextlist반대 함수..(이해가 안됨 ㅠ.ㅠ);
AnsiString _prelist(AnsiString str_list, AnsiString str_key);

//13. _nextlist를 변형한 버전..
AnsiString _2nextlist(AnsiString str_list, AnsiString str_key);

//14. _prelist를 변형한 버전
AnsiString _2prelist(AnsiString str_list, AnsiString str_key);

//15. 중간에 낀 문자 찾고, 두번째 키부터 반환
AnsiString _centerlist(AnsiString str_list, AnsiString str_key);

//16. 컨텐트 필드 만들어서 반환.
AnsiString _getcontentfield(TWebRequest *Request, TStringList* contentlist, AnsiString str_uploadname);

//17. 주민번호체크 함수
BOOLEAN CheckJumin( AnsiString Jumin );


