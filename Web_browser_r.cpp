//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Web_browser_r.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TWeb_browser *Web_browser;
//---------------------------------------------------------------------------
__fastcall TWeb_browser::TWeb_browser(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWeb_browser::FormCreate(TObject *Sender)
{
 //CppWebBrowser1->Navigate(L"https://moda.captain.business/p.php?api=123456789");
//  CppWebBrowser1->Navigate(L"http://gtol");
}
//---------------------------------------------------------------------------
