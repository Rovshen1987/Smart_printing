//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAbout_F *About_F;
//---------------------------------------------------------------------------
__fastcall TAbout_F::TAbout_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAbout_F::Close_BClick(TObject *Sender)
{
About_F->Close();
}
//---------------------------------------------------------------------------
