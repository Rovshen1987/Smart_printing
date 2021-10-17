//---------------------------------------------------------------------------

#ifndef Static_IH
#define Static_IH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <string>
//---------------------------------------------------------------------------
class TStatic_I_F : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel_g;
	TGroupBox *Program_operation_GB;
	TLabel *Launched_L;
	TLabel *Working_hours_L;
	TGroupBox *Print_statistics_GB;
	TLabel *Successful_prints_L;
	TLabel *Erroneous_seals_L;
	TBevel *Bevel1;
	TLabel *Result_L;
	TLabel *Launched_L_g;
	TLabel *Working_hours_L_g;
	TLabel *Successful_prints_L_g;
	TLabel *Erroneous_seals_L_g;
	TLabel *Result_L_g;
	TButton *Save_reports_B;
	TButton *Exit_B;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TSaveDialog *SaveDialog;
	void __fastcall Exit_BClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Save_reports_BClick(TObject *Sender);
private:	// User declarations
	void initilisation();
	AnsiString run_program(std::time_t* value);
	std::string paste_null(const int& value);

	TMemo* paste_information(TMemo* object);
public:		// User declarations
	__fastcall TStatic_I_F(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStatic_I_F *Static_I_F;
//---------------------------------------------------------------------------
#endif
