//---------------------------------------------------------------------------

#ifndef Web_browser_rH
#define Web_browser_rH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SHDocVw_OCX.h"
#include <Vcl.OleCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TWeb_browser : public TForm
{
__published:	// IDE-managed Components
	TCppWebBrowser *CppWebBrowser1;
	TEdit *Edit1;
	TPrintDialog *PrintDialog1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWeb_browser(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWeb_browser *Web_browser;
//---------------------------------------------------------------------------
#endif
