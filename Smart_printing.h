//---------------------------------------------------------------------------

#ifndef Smart_printingH
#define Smart_printingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include "Configuration.h"
#include "time_r.h"
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Registry.hpp>
#include "_TSave_configuration.h"
#include "direct_r.h"
#include "Web_browser_r.h"
#include "general_visable.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdServerIOHandler.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Graphics.hpp>
#include <memory>
#include <fstream>
#include <IdSSLOpenSSL.hpp>
#include "Preview.h"
#include <ctime>

struct remaining
{
   std::string remaining_time;
   int  pause;
   const int pause_int     = 15;
   const std::string print = "Печать";
   const int dot_begin     = -1;
   const int dot_end       = 6;
   int dot_run;
   bool pause_bool;
   bool printing;
   bool active;
   bool first;

   remaining()
   {
	this->remaining_time = "";
	this->pause          = 0;
	this->dot_run        = 0;
	this->pause_bool     = false;
	this->printing       = false;
	this->active         = false;
    this->first          = true;
   };

   void run()
   {



	 if (pause != 0)
	 {

	   this->pause--;

	   if (dot_run < this->dot_end)
	   {
		this->dot_run++;
	   }
	   else
	   {
		this->dot_run = this->dot_begin;
	   }

	 }
	 else
	 {
	  this->pause_bool = false;
	  this->pause      = this->pause_int;
	  this->dot_run    = this->dot_begin;
      this->active     = false;
	 };
   }

   std::string get_time_text()
   {
	  this->run();
	  if (this->pause_bool == false)
	  {
	   return std::string("Печать завершена...");
	  }


	  std::string temp = this->print;

	  for (int i = this->dot_begin; i < this->dot_run; i++)
	  {
	   temp = temp +std::string(".");
	  }

     return temp;
   }
};


//---------------------------------------------------------------------------
class TGeneral_F : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *Menu;
	TMenuItem *Fail_N;
	TMenuItem *Open_N;
	TMenuItem *N3;
	TMenuItem *Configuring_printer_N;
	TMenuItem *N5;
	TMenuItem *Exit_N;
	TMenuItem *Tools_N;
	TMenuItem *Power_on_N;
	TMenuItem *Power_off_N;
	TMenuItem *N10;
	TMenuItem *Config_N;
	TMenuItem *Help_N;
	TMenuItem *Help_documnet_N;
	TMenuItem *N14;
	TMenuItem *About_N;
	TPanel *Work_place;
	TLabel *Url_L;
	TBevel *Bevel_General;
	TComboBox *Url_CB;
	TBevel *Bevel_Printer;
	TComboBox *Choose_printer_CB;
	TLabel *Choose_printer_L;
	TBevel *Bevel_Report;
	TEdit *Report_E;
	TLabel *Report_First_L;
	TLabel *Report_Last_L;
	TBitBtn *Save_BB;
	TBitBtn *Choose_printer_BB;
	TStatusBar *StatusBar;
	TToolBar *ToolBar;
	TToolButton *Open_TOP;
	TToolButton *Fast_printing_TOP;
	TMenuItem *Save_as_N;
	TMenuItem *N17;
	TToolButton *Save_TOP;
	TToolButton *ToolButton2;
	TToolButton *Power_on_TOP;
	TToolButton *Power_off_TOP;
	TToolButton *ToolButton5;
	TToolButton *Config_TOP;
	TToolButton *ToolButton7;
	TToolButton *Help_TOP;
	TTimer *Run_program_timer;
	TImageList *ImageList_g;
	TMenuItem *Fast_printing_N;
	TIdHTTP *IdHTTP1;
	TLabel *Internet_status_L;
	TLabel *Site_status_L;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TMenuItem *Preview_N;
	TToolButton *Preview_TOP;
	TLabel *Internet_status_O;
	TLabel *Site_status_O;
	TButton *Check_B;
	TMenuItem *Save_N;
	TImageList *ImageList_TOP;
	TImageList *ImageList_BB;
	TTimer *Timer_back_T;
	TOpenDialog *Open_IniFile;
	TSaveDialog *Save_AS_IniFile;
	TMenuItem *Static_info_N;
	TMenuItem *N2;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Run_program_timerTimer(TObject *Sender);
	void __fastcall Config_NClick(TObject *Sender);
	void __fastcall Exit_NClick(TObject *Sender);
	void __fastcall Choose_printer_BBClick(TObject *Sender);
	void __fastcall Config_TOPClick(TObject *Sender);
	void __fastcall Save_BBClick(TObject *Sender);
	void __fastcall Preview_TOPClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Check_BClick(TObject *Sender);
	void __fastcall Preview_NClick(TObject *Sender);
	void __fastcall Power_on_TOPClick(TObject *Sender);
	void __fastcall Fast_printing_TOPClick(TObject *Sender);
	void __fastcall Url_CBExit(TObject *Sender);
	void __fastcall Url_CBChange(TObject *Sender);
	void __fastcall Timer_back_TTimer(TObject *Sender);
	void __fastcall Power_off_TOPClick(TObject *Sender);
	void __fastcall Open_TOPClick(TObject *Sender);
	void __fastcall Open_NClick(TObject *Sender);
	void __fastcall Power_on_NClick(TObject *Sender);
	void __fastcall Power_off_NClick(TObject *Sender);
	void __fastcall Fast_printing_NClick(TObject *Sender);
	void __fastcall Save_as_NClick(TObject *Sender);
	void __fastcall Choose_printer_CBChange(TObject *Sender);
	void __fastcall Save_NClick(TObject *Sender);
	void __fastcall About_NClick(TObject *Sender);
	void __fastcall Static_info_NClick(TObject *Sender);

private:	// User declarations
	const AnsiString default_host = AnsiString("http://www.google.com");

	std::unique_ptr<time_r>  run_program_Time;
	std::unique_ptr<time_r>  Timer_back;



	int good_print_information;
	int error_print_information;
//	int loop_print_time;

	bool flag_Url_CB;
	bool flag_Choose_printer_CB;
	bool flag_Choose_printer_BB;
	bool flag_Save_BB;
	bool flag_Power_off_TOP;
	bool flag_Power_on_TOP;
	bool flag_Print_TOP;
	bool flag_Fast_printing_N;
	bool flag_Exit_N;
	bool flag_Power_on_N;
	bool flag_Power_off_N;

	bool flag_Internet;
	bool flag_Host;
	bool flag_program_run;

	bool falg_automatics_printing; //этот флаг для автоматически печатать нужен, когда сдесь true печать начнет автоматический


	std::unique_ptr<general_visable> general_visable_general;

const AnsiString _Statusbar_Item_0 = "Время работы программы ";
const AnsiString _Statusbar_Item_1 = "Напечатано   ";
const AnsiString _Statusbar_Item_2 = "До отправки в печать осталось ";

	remaining remaining_orginal;

//	void initialisation_to_flag();
	void check_connect(const AnsiString& hostname, const int& Tag);

	void check_label(TLabel* object, const bool& value);
	void update_printer();

	void print_r();
	void run_enabled();

	void show_good_print_inforamtion();


	void Timer_back_Trun();

    AnsiString get_time();

public:		// User declarations
    std::time_t*    Smart_time_t;
	bool get_remaining_time_bool();
	std::unique_ptr<_TSave_configuration> _Robik_config;
	void initialisation();
	void destroy_g();
	__fastcall TGeneral_F(TComponent* Owner);

	void update();
	void update(const bool& value);

	void apple_general_config();
	void apple_general_program();

	void preview_void();
	void print_void();

	std::string get_remaining_time();
	void set_remaining_time(const std::string& value);

    void update_ShortCUT();
};
//---------------------------------------------------------------------------
extern PACKAGE TGeneral_F *General_F;
//---------------------------------------------------------------------------
#endif
