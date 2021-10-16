//---------------------------------------------------------------------------

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TAbout_F : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Close_B;
	TImage *Kwork;
	TImage *Builder;
	void __fastcall Close_BClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAbout_F(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbout_F *About_F;
//---------------------------------------------------------------------------
#endif
