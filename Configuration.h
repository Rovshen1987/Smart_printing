//---------------------------------------------------------------------------

#ifndef ConfigurationH
#define ConfigurationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "Smart_printing.h"
//---------------------------------------------------------------------------
class TConfiguration_F : public TForm
{
__published:	// IDE-managed Components
	TPanel *Configuration_place_P;
	TGroupBox *General_setup_GB;
	TLabel *Url_L_Config;
	TComboBox *Url_CB_Config;
	TLabel *Choose_printer_L_Config;
	TComboBox *Choose_printer_CB_Config;
	TCheckBox *Program_run_time_CH;
	TCheckBox *Timer_ÑH;
	TBevel *Bevel_CH;
	TLabel *Save_L;
	TRadioButton *Registry_RB;
	TRadioButton *Inifile_RB;
	TBevel *Bevel_Url;
	TBevel *Bevel_Save;
	TButton *Save_B;
	TButton *Close_B;
	TBevel *Bevel_timer_regularity;
	TLabel *Regularity_of_printing_by_time_L;
	TMaskEdit *Regularity_of_printing_by_time_Config_ME;
	TLabel *Automation_Smart_Printing_program_L;
	TCheckBox *Starting_program_CH;
	TCheckBox *Starting_windows_CH;
	TLabel *Starting_program_L;
	TLabel *Starting_Windows_L;
	TBevel *Bevel1;
	void __fastcall Regularity_of_printing_by_time_Config_MEExit(TObject *Sender);
	void __fastcall Close_BClick(TObject *Sender);
	void __fastcall Url_CB_ConfigChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Choose_printer_CB_ConfigChange(TObject *Sender);
	void __fastcall Regularity_of_printing_by_time_Config_MEChange(TObject *Sender);
	void __fastcall Program_run_time_CHClick(TObject *Sender);
	void __fastcall Timer_ÑHClick(TObject *Sender);
	void __fastcall Registry_RBClick(TObject *Sender);
	void __fastcall Inifile_RBClick(TObject *Sender);
	void __fastcall Starting_program_CHClick(TObject *Sender);
	void __fastcall Starting_windows_CHClick(TObject *Sender);
	void __fastcall Save_BClick(TObject *Sender);



private:	// User declarations
	AnsiString correct_time(const AnsiString& value);
	bool check_saving(const int& Tag, const bool& value);
//	bool check_saving_inside(const int& Tag, const bool& value, bool& result);
	bool check_saving(const int& Tag, const AnsiString& value);

	void initialisation();

	bool flag_Url;
	bool flag_Choose_printer;
	bool flag_Regularity_of_printing_by_time;
	bool flag_Program_run_time;
	bool flag_Timer;
	bool flag_Registry;
	bool flag_Inifile;
	bool flag_Starting_program;
	bool flag_Starting_windows;

	void flag_unchecking();
	bool what_flag_checked();
	void Button_enabled();
public:		// User declarations
	__fastcall TConfiguration_F(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfiguration_F *Configuration_F;
//---------------------------------------------------------------------------
#endif
