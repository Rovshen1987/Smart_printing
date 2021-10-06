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
#include <memory>
#include <fstream>
#include <IdSSLOpenSSL.hpp>
#include "Preview.h"

//---------------------------------------------------------------------------
class TGeneral_F : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *Menu;
	TMenuItem *Fail_N;
	TMenuItem *Open_config_N;
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
	TToolButton *Print_TOP;
	TMenuItem *Save_config_N;
	TMenuItem *N17;
	TToolButton *Save_TOP;
	TToolButton *ToolButton2;
	TToolButton *Power_on_TOP;
	TToolButton *Power_off_TOP;
	TToolButton *ToolButton5;
	TToolButton *Config_TOP;
	TToolButton *ToolButton7;
	TToolButton *Help_TOP;
	TTimer *Timer;
	TImageList *ImageList;
	TMenuItem *Fast_printing_N;
	TIdHTTP *IdHTTP1;
	TLabel *Internet_status_L;
	TLabel *Site_status_L;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TMenuItem *Preview_N;
	TToolButton *ToolButton1;
	TLabel *Internet_status_O;
	TLabel *Site_status_O;
	TButton *Check_B;
	TPrintDialog *PrintDialog1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall Config_NClick(TObject *Sender);
	void __fastcall Exit_NClick(TObject *Sender);
	void __fastcall Choose_printer_BBClick(TObject *Sender);
	void __fastcall Config_TOPClick(TObject *Sender);
	void __fastcall Save_BBClick(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Check_BClick(TObject *Sender);
	void __fastcall Preview_NClick(TObject *Sender);
private:	// User declarations
	const AnsiString default_host = AnsiString("http://www.google.com");

	time_r*  run_program_Time;

	int loop_print_time;

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

	void initialisation_to_flag();
	void check_connect(const AnsiString& hostname, const int& Tag);

	void check_label(TLabel* object, const bool& value);
    void update_printer();


const AnsiString _Statusbar_Item_0 = "Время работы программы ";
const AnsiString _Statusbar_Item_1 = "Напечатано ";
const AnsiString _Statusbar_Item_2 = "Состояние соединения ";

public:		// User declarations
	std::unique_ptr<_TSave_configuration> _Robik_config;
	void initialisation();
    void destroy_();
	__fastcall TGeneral_F(TComponent* Owner);

    void update();

	void apple_general_config();
	void apple_general_program();

	void preview_void();
	void print_void();
};
//---------------------------------------------------------------------------
extern PACKAGE TGeneral_F *General_F;
//---------------------------------------------------------------------------
#endif
