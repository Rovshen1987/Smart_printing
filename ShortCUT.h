//---------------------------------------------------------------------------

#ifndef ShortCUTH
#define ShortCUTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
struct ShortCut_struct
{


	int Open_SHCut;
	int Save_SHCut;
	int Save_as_SHCut;
	int Fast_printing_SHCut;
	int Preview_SHCut;
	int Exit_SHCut;
	int Power_on_SHCut;
	int Power_off_SHCut;
	int Config_SHCut;

	 ShortCut_struct()
	 {
	  this->Open_SHCut           = 0;
	  this->Save_SHCut           = 0;
	  this->Save_as_SHCut        = 0;
	  this->Fast_printing_SHCut  = 0;
	  this->Preview_SHCut        = 0;
	  this->Exit_SHCut           = 0;
	  this->Power_on_SHCut       = 0;
	  this->Power_off_SHCut      = 0;
	  this->Config_SHCut         = 0;
	 }
};

class TShortCUT_F : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Open_SHCut_L;
	TLabel *Save_SHCut_L;
	TLabel *Save_as_SHCut_L;
	TLabel *Fast_printing_SHCut_L;
	TLabel *Preview_SHCut_L;
	TLabel *Exit_SHCut_L;
	TLabel *Power_on_SHCut_L;
	TLabel *Power_off_SHCut_L;
	TLabel *Config_SHCut_L;
	TBitBtn *Open_SHCut_BB;
	TBitBtn *Save_SHCut_BB;
	TBitBtn *Save_as_SHCut_BB;
	TBitBtn *Fast_printing_SHCut_BB;
	TBitBtn *Preview_SHCut_BB;
	TBitBtn *Exit_SHCut_BB;
	TBitBtn *Power_on_SHCut_BB;
	TBitBtn *Power_off_SHCut_BB;
	TBitBtn *Config_SHCut_BB;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TButton *Save_B;
	TPanel *Panel2;
	THotKey *Open_SHCut_E;
	THotKey *Save_SHCut_E;
	THotKey *Save_as_SHCut_E;
	THotKey *Fast_printing_SHCut_E;
	THotKey *Preview_SHCut_E;
	THotKey *Exit_SHCut_E;
	THotKey *Power_on_SHCut_E;
	THotKey *Power_off_SHCut_E;
	THotKey *Config_SHCut_E;
	TBevel *Bevel4;
	TButton *Exit_B;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Open_SHCut_EChange(TObject *Sender);
	void __fastcall Save_SHCut_EChange(TObject *Sender);
	void __fastcall Save_as_SHCut_EChange(TObject *Sender);
	void __fastcall Fast_printing_SHCut_EChange(TObject *Sender);
	void __fastcall Preview_SHCut_EChange(TObject *Sender);
	void __fastcall Exit_SHCut_EChange(TObject *Sender);
	void __fastcall Power_on_SHCut_EChange(TObject *Sender);
	void __fastcall Power_off_SHCut_EChange(TObject *Sender);
	void __fastcall Config_SHCut_EChange(TObject *Sender);
	void __fastcall Save_BClick(TObject *Sender);
	void __fastcall Exit_BClick(TObject *Sender);


private:	// User declarations
	void initilisation();
	ShortCut_struct base;

	void config_to_date();
	void date_to_config();

	void program_to_date();
	void date_to_program();


	void Save();
	void Exit();
	bool check_equality();


public:		// User declarations
	__fastcall TShortCUT_F(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TShortCUT_F *ShortCUT_F;
//---------------------------------------------------------------------------
#endif


