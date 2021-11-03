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
#include <SHDocVw.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "direct_r.h"
//---------------------------------------------------------------------------
class TWeb_browser_F : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser;
	TImage *Image;
	TTimer *Timer;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall WebBrowserNavigateComplete2(TObject *ASender, IDispatch * const pDisp,
          const OleVariant &URL);
	void __fastcall WebBrowserNavigateError(TObject *ASender, IDispatch * const pDisp,
          const OleVariant &URL, const OleVariant &Frame, const OleVariant &StatusCode,
          WordBool &Cancel);
	void __fastcall WebBrowserDocumentComplete(TObject *ASender, IDispatch * const pDisp,
          const OleVariant &URL);
private:	// User declarations
	const int A4_width  = 620;
	const int A4_height = 877;
	int timer_count     = 0;

	AnsiString path_r;

	bool       flag_print;
	bool       flag_refresh;
	bool       flag_error_connect;

	void initilisation();






public:		// User declarations
	__fastcall TWeb_browser_F(TComponent* Owner);

	void screen_photo();

	void set_flag_print(const bool& value);
	bool get_flag_print();
	void set_flag_refresh(const bool& value);
	bool get_flag_refresh();
	void set_flag_error_connect(const bool& value);
	bool get_flag_error_connect();


};
//---------------------------------------------------------------------------
extern PACKAGE TWeb_browser_F *Web_browser_F;
//---------------------------------------------------------------------------
#endif
