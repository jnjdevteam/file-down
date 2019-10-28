//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "homelib.h"

//1.현제 디렉토리 찾기
AnsiString _getexecpath()
{
    return(ExtractFilePath(ParamStr(0)));
}

//2.문자열에서 특정문자열을 찾아 바꾸기
void _replace(AnsiString& str_src, AnsiString str_find, AnsiString str_repl)
{
   int ind = str_src.Pos(str_find);

   while(ind > 0)
   {
      str_src = str_src.SubString(1, ind-1) + str_repl
                  + str_src.SubString(ind+str_find.Length(),
                             str_src.Length()-(ind-1+str_find.Length()));

      ind = str_src.Pos(str_find);
   }
}

//3. 윈도우 디렉토리 찾기
AnsiString _getwindowspath()
{
    char path[255];
    GetWindowsDirectory(path, 255);

    AnsiString str_result(path);

    return(str_result);
}

//4. 시스템디렉토리 찾기
AnsiString _getsystempath()
{
    char path[255];
    GetSystemDirectory(path, 255);

    AnsiString str_result(path);
    return(str_result);
}

//5.날짜 만들기
AnsiString _getmakedate(AnsiString str_src)
{
    AnsiString str_result = str_src.SubString(1, 4)+"년"
                            +str_src.SubString(5, 2)+"월"
                            +str_src.SubString(7, 2)+"일";
    return(str_result);
}

//6.줄넘기기
AnsiString _makebr(AnsiString str_src)
{

    char key[2];
    key[1] = 0x0D;
    key[2] = 0x0A;

    AnsiString linedown(key);

    _replace(str_src, key, "<BR>");

    return(str_src);
}

//7.파일불러와서 문자열형으로 바꾸기
AnsiString _loadfromfile(AnsiString str_filename)
{
    AnsiString str_result;

    try
    {
      TStringList* list = new TStringList();
      list->LoadFromFile(str_filename);
      str_result = list->Text;
      delete list;
    }
    catch(Exception &exception)
    {

    }

    return(str_result);
}

//8.뒤로가기 링크 문자열 반환
AnsiString _backlink()
{
   return("<a href=javascript:history.go(-1)>되돌아가기</a>");
}

//9.폰트를 빨간색으로 변형
AnsiString _makered(AnsiString str_src, AnsiString str_key)
{
   _replace(str_src, str_key, "<font color = red>" + str_key+ "</font>");

   return(str_src);
}

//10.해당문자열을 찾은다음 뒤부분 문자열을 반환 '@'자 나오기전까지나 없으면 문자열끝까지
AnsiString _nextlist(AnsiString str_list, AnsiString str_key)
{
   AnsiString str_result("");
   str_key = "@"+str_key+"@";

   int p = str_list.Pos(str_key);
   if((p==0)||(p+str_key.Length()-1 == str_list.Length())) return(str_result);

   int i=p+str_key.Length()-1;

   char* char_list;
   char_list = str_list.c_str();
   while(i<=str_list.Length())
   {
      if(char_list[i]=='@') break;
      str_result = str_result + char_list[i];
      i++;
   }

   return(str_result);
}

//11.문자열 뒤집기
void _reverse(AnsiString& str_src)
{
   AnsiString str_tmp;
   char* char_src = str_src.c_str();

   int len = str_src.Length();
   len--;

   for(int i= len; i>=0; i--)
   {
      str_tmp = str_tmp + char_src[i];
   }

   str_src = str_tmp;

}

//12. _nextlist반대 함수..(이해가 안됨 ㅠ.ㅠ);
AnsiString _prelist(AnsiString str_list, AnsiString str_key)
{
    AnsiString str_result;
    str_key = "@"+str_key+"@";
    int p = str_list.Pos(str_key)-1;
    if(p <= 0) return(str_result);

    int i = p-1;

    char* char_list;
    char_list = str_list.c_str();
    while(i>=0)
    {
       if(char_list[i]=='@') break;
       str_result = str_result + char_list[i];
       i--;
    }
    _reverse(str_result);
    return(str_result);
}

//13. nextlist를 변형한 버전..
AnsiString _2nextlist(AnsiString str_list, AnsiString str_key)
{
   AnsiString str_result("");
   int p = str_list.Pos(str_key);
   if((p==0)||(p+str_key.Length()-1 == str_list.Length())) return(str_result);

   int i=p+str_key.Length();
   str_result = str_list.SubString(i, str_list.Length()-i + 1);
   return(str_result);
}

//14. prelist를 변형한 버전
AnsiString _2prelist(AnsiString str_list, AnsiString str_key)
{
   AnsiString str_result("");
   int p = str_list.Pos(str_key);
   if(p<=1) return(str_result);

   int i= 1;
   str_result = str_list.SubString(i, p-1);
   return(str_result);
}

//15. 중간에 낀 문자 찾고, 두번째 키부터 반환
AnsiString _centerlist(AnsiString str_list, AnsiString str_key)
{
     AnsiString str_result = _2prelist(_2nextlist(str_list, str_key), str_key);
     return(str_result);
}

//17. 주민등록번호 체크 함수
BOOLEAN CheckJumin( AnsiString Jumin )
{
  int posi = Jumin.Pos( "-" );
  if ( posi > 0 )  // "-"삭제루틴
  {
    Jumin = Jumin.Delete( posi, 1 );
  }
  if ( Jumin.Length() < 13 )
    return FALSE;

  AnsiString f1 = Jumin.SubString(  1,1 ),
             f2 = Jumin.SubString(  2,1 ),
             f3 = Jumin.SubString(  3,1 ),
             f4 = Jumin.SubString(  4,1 ),
             f5 = Jumin.SubString(  5,1 ),
             f6 = Jumin.SubString(  6,1 ),
             s1 = Jumin.SubString(  7,1 ),
             s2 = Jumin.SubString(  8,1 ),
             s3 = Jumin.SubString(  9,1 ),
             s4 = Jumin.SubString( 10,1 ),
             s5 = Jumin.SubString( 11,1 ),
             s6 = Jumin.SubString( 12,1 ),
             s7 = Jumin.SubString( 13,1 );
  int ff1 = StrToInt( f1 ),
      ff2 = StrToInt( f2 ),
      ff3 = StrToInt( f3 ),
      ff4 = StrToInt( f4 ),
      ff5 = StrToInt( f5 ),
      ff6 = StrToInt( f6 ),
      ss1 = StrToInt( s1 ),
      ss2 = StrToInt( s2 ),
      ss3 = StrToInt( s3 ),
      ss4 = StrToInt( s4 ),
      ss5 = StrToInt( s5 ),
      ss6 = StrToInt( s6 ),
      ss7 = StrToInt( s7 );

  int tTotal  = ff1*2 + ff2*3 + ff3*4 + ff4*5 + ff5*6 + ff6*7;
      tTotal += ss1*8 + ss2*9 + ss3*2 + ss4*3 + ss5*4 + ss6*5;

  int LastNum = 11 - (tTotal % 11);

  if ( LastNum > 9 )
  {
     AnsiString tt = IntToStr( LastNum );
     tt = tt.SubString( tt.Length(), 1 );
     LastNum = StrToInt( tt );
  }

  if ( ss7 == LastNum )
    return TRUE;
  else
    return FALSE;
}


//16. 컨텐트 필드 만들어서 반환.
AnsiString _getcontentfield(TWebRequest *Request, TStringList* contentlist, AnsiString str_uploadname)
{
    AnsiString str_null = '\0';
    AnsiString str_nameseparator2 = "\"";
    AnsiString str_nameseparator3 = "\"\r\n\r\n" ;
    AnsiString str_carragereturn = "\r\n";
    AnsiString str_nameseparator1 = str_carragereturn + "Content-Disposition: form-data; name=\"";

    AnsiString str_temp = "";
    AnsiString str_temp2 = "";
    AnsiString str_namevalue, str_name, str_value, stradd;
    AnsiString str_contenttype = Request->ContentType;
    AnsiString str_bound = _2nextlist(str_contenttype, "boundary=");
    AnsiString str_separator = "--";
    str_separator = str_separator+ str_bound;
    int totalcount = Request->ContentLength;
    AnsiString strreceived = Request->Content ;


    //자료빨아드리기
    int tmp;
    int ticks = GetTickCount();
    if(strreceived.Length() <totalcount)
    {
         while((strreceived.Length() < totalcount)&&(GetTickCount()-ticks <3000))
         {
             stradd = Request->ReadString(totalcount - strreceived.Length());
             tmp = stradd.Length();
             if(tmp > 0)
             {
                ticks = GetTickCount();
                strreceived = strreceived+ stradd;
             }
         }
    }


    //분해후 컨텐트 얻기...
    str_temp = _2nextlist(strreceived, str_separator);
    while(1)
    {
      str_namevalue = _2prelist(str_temp, str_carragereturn+str_separator);
      if(str_namevalue == "")
      {
         break;
      }

      //먼저 컨텐트 이름을 얻는다
      str_temp2 = _2nextlist(str_namevalue, str_nameseparator1);
      str_name = _2prelist(str_temp2, str_nameseparator2);

      //그다음 값을 얻는다
      if(str_name != str_uploadname)
      {
          str_value = _2nextlist(str_temp2, str_nameseparator3);
          contentlist->Values[str_name] = str_value;
      }
      else if(str_name == str_uploadname)
      {
         // 사이에 파일 업로드 루틴을 넣는다
         str_temp2 =_2nextlist(str_temp2, "filename=\"");
         str_value =_2prelist(str_temp2, str_nameseparator2);
         if(str_value != "")
         {
            str_value = ExtractFileName(str_value);
            str_temp2 =_2nextlist(str_temp2, "\r\n\r\n");
            strreceived = str_temp2;
         }
         contentlist->Values[str_name] = str_value;
      }

      str_temp = _2nextlist(str_temp, str_separator);
    }

    return(strreceived);
}



//---------------------------------------------------------------------------

#pragma package(smart_init)
