//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Web_browser_r.h"
#include "Smart_printing.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TWeb_browser_F *Web_browser_F;
//---------------------------------------------------------------------------
__fastcall TWeb_browser_F::TWeb_browser_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWeb_browser_F::FormCreate(TObject *Sender)
{
 WebBrowser->Navigate(L"https://moda.captain.business/p.php?api=123456789");
//  CppWebBrowser1->Navigate(L"http://gtol");

initilisation();
}
//---------------------------------------------------------------------------
void TWeb_browser_F::initilisation()
{
direct_r temp;
Web_browser_F->Width  = A4_width;
Web_browser_F->Height = A4_height;
path_r = (temp.get_path()).c_str();

flag_print   = false;
flag_preview = false;
};

void TWeb_browser_F::refresh_site()
{
WebBrowser->Refresh();
flag_refresh = false;
};


void TWeb_browser_F::screen_photo()
{
 refresh_site();
// flag_refresh   = true;
 Timer->Enabled = true;
 timer_count    = 0;
};


void __fastcall TWeb_browser_F::TimerTimer(TObject *Sender)
{
  if ((flag_refresh == true) and (timer_count >= 1))
  {
	Image->Picture->Bitmap->SetSize(Image->ClientRect.Width()-17,
									 Image->ClientRect.Height());
	Image->Picture->Bitmap->Canvas->Brush->Color= clBlack;
	Image->Picture->Bitmap->Canvas->FillRect(Image->ClientRect);

	HWND Window = WebBrowser->Handle;
	if(!Window)
		return;

	TRect SrcRect;
	GetWindowRect(Window,&SrcRect);
	SrcRect.SetLocation(0,0);

	HDC Context =  GetWindowDC(Window);
	std::auto_ptr<TControlCanvas> ControlCanvas(new TControlCanvas);
	ControlCanvas->Handle= Context;

	TRect DestRect= Image->ClientRect;
	InflateRect(DestRect,0,0);
	Image->Canvas->CopyRect(
		DestRect,
		ControlCanvas.get(),
		SrcRect);

	ReleaseDC(Window,Context);

	Image->Picture->SaveToFile(path_r+"date\\temp.bmp");
	flag_refresh   = false;
	timer_count    = 0;
	Timer->Enabled = false;


	if (flag_preview == true)
	{

	 General_F->preview_void();

	 flag_preview = false;
	}

	 if (flag_print == true)
	{
	 General_F->print_void();
     flag_print = false;
	}
	Web_browser_F->Close();
  }
  timer_count++;
}

//---------------------------------------------------------------------------
void TWeb_browser_F::set_flag_preview(const bool& value)
{
  this->flag_preview = value;
};

//---------------------------------------------------------------------------
bool TWeb_browser_F::get_flag_preview()
{
   return this->flag_preview;
};

//---------------------------------------------------------------------------
void TWeb_browser_F::set_flag_print(const bool& value)
{
   this->flag_print = value;
};

//---------------------------------------------------------------------------
bool TWeb_browser_F::get_flag_print()
{
  return this->flag_print;
};



void __fastcall TWeb_browser_F::WebBrowserDownloadComplete(TObject *Sender)
{
flag_refresh = true;
}
//---------------------------------------------------------------------------



void __fastcall TWeb_browser_F::FormShow(TObject *Sender)
{
Web_browser_F->Left = 0;
Web_browser_F->Top  = 0;
}
//---------------------------------------------------------------------------

