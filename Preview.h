//---------------------------------------------------------------------------

#ifndef PreviewH
#define PreviewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include "frxPreview.hpp"
//---------------------------------------------------------------------------
class TPreview_F : public TForm
{
__published:	// IDE-managed Components
	TfrxReport *frxReport1;
	TfrxPreview *frxPreview1;
private:	// User declarations
public:		// User declarations
	__fastcall TPreview_F(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPreview_F *Preview_F;
//---------------------------------------------------------------------------
#endif
