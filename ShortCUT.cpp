//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ShortCUT.h"
#include "Smart_printing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShortCUT_F *ShortCUT_F;
//---------------------------------------------------------------------------
__fastcall TShortCUT_F::TShortCUT_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TShortCUT_F::initilisation()
{
 General_F->ImageList_g->GetBitmap(0,Open_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(1,Save_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(2,Save_as_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(3,Fast_printing_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(5,Preview_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(10,Exit_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(6,Power_on_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(7,Power_off_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(8,Config_SHCut_BB->Glyph);
 General_F->ImageList_g->GetBitmap(12,Static_info_SHCut_BB->Glyph);
 this->config_to_date();
 this->date_to_program();
 this->Save_B->Enabled = false;
};
void __fastcall TShortCUT_F::FormCreate(TObject *Sender)
{
this->initilisation();
}
//---------------------------------------------------------------------------
void TShortCUT_F::config_to_date()
{
 this->base.Open_SHCut                 = General_F->_Robik_config->get_Open_SHCut();
 this->base.Save_SHCut                 = General_F->_Robik_config->get_Save_SHCut();
 this->base.Save_as_SHCut              = General_F->_Robik_config->get_Save_as_SHCut();
 this->base.Fast_printing_SHCut        = General_F->_Robik_config->get_Fast_printing_SHCut();
 this->base.Preview_SHCut              = General_F->_Robik_config->get_Preview_SHCut();
 this->base.Exit_SHCut                 = General_F->_Robik_config->get_Exit_SHCut();
 this->base.Power_on_SHCut             = General_F->_Robik_config->get_Power_on_SHCut();
 this->base.Power_off_SHCut            = General_F->_Robik_config->get_Power_off_SHCut();
 this->base.Config_SHCut               = General_F->_Robik_config->get_Config_SHCut();
 this->base.Static_info_SHCut          = General_F->_Robik_config->get_Static_info_SHCut();
};

//---------------------------------------------------------------------------
void TShortCUT_F::date_to_config()
{
 General_F->_Robik_config->set_Open_SHCut(this->base.Open_SHCut);
 General_F->_Robik_config->set_Save_SHCut(this->base.Save_SHCut);
 General_F->_Robik_config->set_Save_as_SHCut(this->base.Save_as_SHCut);
 General_F->_Robik_config->set_Fast_printing_SHCut(this->base.Fast_printing_SHCut);
 General_F->_Robik_config->set_Preview_SHCut(this->base.Preview_SHCut);
 General_F->_Robik_config->set_Exit_SHCut(this->base.Exit_SHCut);
 General_F->_Robik_config->set_Power_on_SHCut(this->base.Power_on_SHCut);
 General_F->_Robik_config->set_Power_off_SHCut(this->base.Power_off_SHCut);
 General_F->_Robik_config->set_Config_SHCut(this->base.Config_SHCut);
 General_F->_Robik_config->set_Static_info_SHCut(this->base.Static_info_SHCut);
 General_F->_Robik_config->Save_shell();
 General_F->update_ShortCUT();
};

//---------------------------------------------------------------------------
void TShortCUT_F::program_to_date()
{
 this->base.Open_SHCut                 = this->Open_SHCut_E->HotKey;
 this->base.Save_SHCut                 = this->Save_SHCut_E->HotKey;
 this->base.Save_as_SHCut              = this->Save_as_SHCut_E->HotKey;
 this->base.Fast_printing_SHCut        = this->Fast_printing_SHCut_E->HotKey;
 this->base.Preview_SHCut              = this->Preview_SHCut_E->HotKey;
 this->base.Exit_SHCut                 = this->Exit_SHCut_E->HotKey;
 this->base.Power_on_SHCut             = this->Power_on_SHCut_E->HotKey;
 this->base.Power_off_SHCut            = this->Power_off_SHCut_E->HotKey;
 this->base.Config_SHCut               = this->Config_SHCut_E->HotKey;
 this->base.Static_info_SHCut          = this->Static_info_SHCut_E->HotKey;
};

//---------------------------------------------------------------------------
void TShortCUT_F::date_to_program()
{
 this->Open_SHCut_E->HotKey            = this->base.Open_SHCut;
 this->Save_SHCut_E->HotKey            = this->base.Save_SHCut;
 this->Save_as_SHCut_E->HotKey         = this->base.Save_as_SHCut;
 this->Fast_printing_SHCut_E->HotKey   = this->base.Fast_printing_SHCut;
 this->Preview_SHCut_E->HotKey         = this->base.Preview_SHCut;
 this->Exit_SHCut_E->HotKey            = this->base.Exit_SHCut ;
 this->Power_on_SHCut_E->HotKey        = this->base.Power_on_SHCut;
 this->Power_off_SHCut_E->HotKey       = this->base.Power_off_SHCut;
 this->Config_SHCut_E->HotKey          = this->base.Config_SHCut;
 this->Static_info_SHCut_E->HotKey     = this->base.Static_info_SHCut;
};

//---------------------------------------------------------------------------
void TShortCUT_F::Save()
{
 this->program_to_date();
 this->date_to_config();
 this->Save_B->Enabled = false;
};

//---------------------------------------------------------------------------
void TShortCUT_F::Exit()
{
 this->config_to_date();
 this->date_to_program();
 ShortCUT_F->Close();
};

//---------------------------------------------------------------------------
bool TShortCUT_F::check_equality()
{

 bool result = true;
  std::vector<int> vec;
  vec.push_back(this->Open_SHCut_E->HotKey);
  vec.push_back(this->Save_SHCut_E->HotKey);
  vec.push_back(this->Save_as_SHCut_E->HotKey);
  vec.push_back(this->Fast_printing_SHCut_E->HotKey);
  vec.push_back(this->Preview_SHCut_E->HotKey);
  vec.push_back(this->Exit_SHCut_E->HotKey);
  vec.push_back(this->Power_on_SHCut_E->HotKey);
  vec.push_back(this->Power_off_SHCut_E->HotKey);
  vec.push_back(this->Config_SHCut_E->HotKey);
  vec.push_back(this->Static_info_SHCut_E->HotKey);

  for (int i = 0; i < vec.size(); i++)
  {
	 for (int j = (i+1); j < (vec.size()-1); j++)
	 {
	   if ((vec[i] == vec[j])&&(vec[j]!=0))
	   {
		return result;
	   };
	 };
  };

  vec.clear();
  result = false;
  return result;
};
void __fastcall TShortCUT_F::Open_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Save_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Save_as_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Fast_printing_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Preview_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Exit_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Power_on_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Power_off_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Config_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Save_BClick(TObject *Sender)
{
 if (check_equality() == true)
 {
	MessageDlg("Вы назначили одинаковые клавиша для разных команд, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
			 return;
 };

 this->Save();
};
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Exit_BClick(TObject *Sender)
{
 this->Exit();
}
//---------------------------------------------------------------------------

void __fastcall TShortCUT_F::Static_info_SHCut_EChange(TObject *Sender)
{
this->Save_B->Enabled = true;
}
//---------------------------------------------------------------------------

