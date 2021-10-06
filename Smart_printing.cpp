//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Smart_printing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGeneral_F *General_F;
//---------------------------------------------------------------------------
__fastcall TGeneral_F::TGeneral_F(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void TGeneral_F::initialisation()
{

  this->run_program_Time = new time_r();
  this->run_program_Time->set<std::string>("0:0:0");
  this->_Robik_config = std::make_unique<_TSave_configuration>();
//  check_connect(default_host, Internet_status_BT->Tag);
//  check_connect(Url_CB->Text,Site_status_BT->Tag);
  if (this->_Robik_config->step_to_run_program() == true)
  {
  apple_general_config();
  }

  check_connect(default_host, Internet_status_O->Tag);
  check_connect(Url_CB->Text,Site_status_O->Tag);

  ImageList->GetBitmap(1,Save_BB->Glyph);
  ImageList->GetBitmap(1,Choose_printer_BB->Glyph);
  update_printer();
};

//------------------------------------------------------------------------------
void TGeneral_F::update()
{
  this->Url_CB->Text = this->_Robik_config->get_Url();
  this->Choose_printer_CB->Text = this->_Robik_config->get_Choose_printer();
};

//------------------------------------------------------------------------------
void TGeneral_F::destroy_()
{
  delete this->run_program_Time;
};
void __fastcall TGeneral_F::FormDestroy(TObject *Sender)
{
this->destroy_();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::TimerTimer(TObject *Sender)
{
this->StatusBar->Panels->Items[0]->Text = this->_Statusbar_Item_0 + (this->run_program_Time->get_time()).c_str();

}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Config_NClick(TObject *Sender)
{
Configuration_F->ShowModal();
initialisation_to_flag();
loop_print_time = 0;
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Exit_NClick(TObject *Sender)
{
General_F->Close();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Choose_printer_BBClick(TObject *Sender)
{

 _Robik_config->set_Choose_printer(this->Choose_printer_CB->Text);
 _Robik_config->Save_shell();
/*
_TSave_configuration r;

r.set_Url("http:\\Serik");
r.set_Choose_printer("Samsung");
r.set_Regularity_of_printing_by_time("01:01:01");
r.set_Program_run_time(true);
r.set_Timer(true);
r.set_Registry(true);
r.set_Inifile(true);
r.set_Starting_program(true);
r.set_Starting_windows(true);
//r.Save_registry();  */

// if (r.Check_program() == true)
// {
//  General_F->Caption = "bar";
// }
// else
// {
// General_F->Caption = "yok";
// }
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Config_TOPClick(TObject *Sender)
{
Configuration_F->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Save_BBClick(TObject *Sender)
{

 _Robik_config->set_Url(this->Url_CB->Text);
 _Robik_config->Save_shell();

}

//---------------------------------------------------------------------------
void TGeneral_F::apple_general_config()
{
 this->Url_CB->Text            = _Robik_config->get_Url();
 this->Choose_printer_CB->Text = _Robik_config->get_Choose_printer();

 //----------Configuration_F-------------------------------------
// Configuration_F->Url_CB_Config->Text                            = _Robik_config->get_Url();
// Configuration_F->Choose_printer_CB_Config->Text                 = _Robik_config->get_Choose_printer();
// Configuration_F->Regularity_of_printing_by_time_Config_ME->Text = _Robik_config->get_Regularity_of_printing_by_time();
// Configuration_F->Program_run_time_CH->Checked                   = _Robik_config->get_Program_run_time();
// Configuration_F->Timer_СH->Checked                              = _Robik_config->get_Timer();
// Configuration_F->Registry_RB->Checked                           = _Robik_config->get_Registry();
// Configuration_F->Inifile_RB->Checked                            = _Robik_config->get_Inifile();
// Configuration_F->Starting_program_CH->Checked                   = _Robik_config->get_Starting_program();
// Configuration_F->Starting_windows_CH->Checked                   = _Robik_config->get_Starting_windows();
};

//------------------------------------------------------------------------------
void TGeneral_F::apple_general_program()
{
 _Robik_config->set_Url(this->Url_CB->Text);
 _Robik_config->set_Choose_printer(this->Choose_printer_CB->Text);

 //----------Configuration_F-------------------------------------
 Configuration_F->Url_CB_Config->Text                            = this->Url_CB->Text;
 Configuration_F->Choose_printer_CB_Config->Text                 = this->Choose_printer_CB->Text;

 _Robik_config->set_Regularity_of_printing_by_time(Configuration_F->Regularity_of_printing_by_time_Config_ME->Text);
 _Robik_config->set_Program_run_time(Configuration_F->Program_run_time_CH->Checked);
 _Robik_config->set_Timer(Configuration_F->Timer_СH->Checked);
 _Robik_config->set_Registry(Configuration_F->Registry_RB->Checked);
 _Robik_config->set_Inifile(Configuration_F->Inifile_RB->Checked  );
 _Robik_config->set_Starting_program(Configuration_F->Starting_program_CH->Checked);
 _Robik_config->set_Starting_windows(Configuration_F->Starting_windows_CH->Checked);
};

//------------------------------------------------------------------------------
void TGeneral_F::initialisation_to_flag()
{
this->flag_Url_CB             = true;
this->flag_Choose_printer_CB  = true;
this->flag_Choose_printer_BB  = true;
this->flag_Save_BB            = true;
this->flag_Power_off_TOP      = true;
this->flag_Power_on_TOP       = true;
this->flag_Print_TOP          = true;
this->flag_Fast_printing_N    = true;
this->flag_Exit_N             = true;
this->flag_Power_on_N         = true;
this->flag_Power_off_N        = true;

this->flag_Internet           = true;
this->flag_Host               = true;
this->flag_program_run        = true;
};
//------------------------------------------------------------------------------



 void TGeneral_F::check_connect(const AnsiString& hostname, const int& Tag)
 {
	  try
	 {
	  IdHTTP1->Get(hostname);
	  if (Tag == 1)
	  {

	   check_label(Internet_status_O, true);
	  };

	   if (Tag == 2)
	   {

		check_label(Site_status_O, true);
	   }

	 }
	  catch(EIdHTTPProtocolException &se)
	 {
		switch(se.ErrorCode){
		 case 200:
		   break;
		 case 303:
		   break;
		 case 404:
		   break;
		 default: {
					  if (Tag == 1)
					{

					  check_label(Internet_status_O, false);
					};

					if (Tag == 2)
					{

					  check_label(Site_status_O, false);

					}
				   break;
				  }
		}
	 }
	  catch(EIdSocketError &se)
	  {
	  if(se.LastError == 11001)
	   {
			  if (Tag == 1)
			{

				check_label(Internet_status_O, false);
			};

			if (Tag == 2)
			{

				check_label(Site_status_O, false);

			}

	   }


	  };


 };






void __fastcall TGeneral_F::ToolButton1Click(TObject *Sender)
{
Web_browser_F->Show();
Web_browser_F->set_flag_preview(true);
Web_browser_F->set_flag_print(false);
Web_browser_F->screen_photo();

}
//---------------------------------------------------------------------------

void __fastcall TGeneral_F::FormCreate(TObject *Sender)
{
   this->initialisation();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TGeneral_F::check_label(TLabel* object, const bool& value)
{
   if (value == true)
   {
	object->Caption = "Есть!";
	object->Font->Color = clGreen;
   }
   else
   {
	object->Caption = "Нет!";
	object->Font->Color = clRed;
   }

};

void __fastcall TGeneral_F::Check_BClick(TObject *Sender)
{

  check_connect(default_host, Internet_status_O->Tag);

  check_connect(Url_CB->Text,Site_status_O->Tag);


}
//---------------------------------------------------------------------------
 void TGeneral_F::update_printer()
 {
	PRINTER_INFO_2 *Pr;
	DWORD byteNeed = 0,prCount=0;
	EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,NULL,0,&byteNeed,&prCount);
	Pr = new PRINTER_INFO_2 [byteNeed];
	if(EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,(LPBYTE)Pr,byteNeed,&byteNeed,&prCount))
	{
		for(int i = 0; i < prCount; ++i)
		{
		Choose_printer_CB->Items->Add(AnsiString(Pr[i].pPrinterName));
		}
	}
	delete Pr;
 };
void __fastcall TGeneral_F::Preview_NClick(TObject *Sender)
{
Preview_F->ShowModal();
}
//---------------------------------------------------------------------------



void TGeneral_F::preview_void()
{
Preview_F->frxReport1->ShowReport();
Preview_F->ShowModal();
};

void TGeneral_F::print_void()
{

};
