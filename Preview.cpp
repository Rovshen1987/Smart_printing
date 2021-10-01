//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Preview.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma resource "*.dfm"
TPreview_F *Preview_F;
//---------------------------------------------------------------------------
__fastcall TPreview_F::TPreview_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
