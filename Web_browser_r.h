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
private:	// User declarations


//    const int A4_height = 1000;
    int timer_count     = 0;
    AnsiString path_r;
	void initilisation();


	bool  flag_refresh;

	bool  flag_print;
	bool  flag_preview;

	void refresh_site();

public:		// User declarations
	__fastcall TWeb_browser_F(TComponent* Owner);
	void screen_photo();

	void set_flag_preview(const bool& value);
	bool get_flag_preview();
	void set_flag_print(const bool& value);
	bool get_flag_print();
	const int A4_width  = 620;
	const int A4_height = 877;

};
//---------------------------------------------------------------------------
extern PACKAGE TWeb_browser_F *Web_browser_F;
//---------------------------------------------------------------------------
#endif
