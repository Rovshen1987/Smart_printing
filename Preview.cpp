//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Preview.h"
#include "Web_browser_r.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma link "frxHTTPClient"
#pragma resource "*.dfm"
TPreview_F *Preview_F;
//---------------------------------------------------------------------------
__fastcall TPreview_F::TPreview_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



