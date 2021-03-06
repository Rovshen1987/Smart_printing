//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Configuration.h"
#include "ShortCUT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "time_r.h"
TConfiguration_F *Configuration_F;
//---------------------------------------------------------------------------
__fastcall TConfiguration_F::TConfiguration_F(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString TConfiguration_F::correct_time(const AnsiString& value)
{
AnsiString temp;
time_r* p = new time_r();
p->set_Paralysis(true);
p->set(std::string(value.c_str()));
temp = (p->get_time()).c_str();

delete p;
return temp;
};

void __fastcall TConfiguration_F::Regularity_of_printing_by_time_Config_MEExit(TObject *Sender)

{
 Regularity_of_printing_by_time_Config_ME->Text = this->correct_time(Regularity_of_printing_by_time_Config_ME->Text);
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Close_BClick(TObject *Sender)
{
	 if (what_flag_checked() == true)
	 {
		this->initialisation();
		this->Button_enabled();
	 }
	 else
	 {
		  if (General_F->get_remaining_time_bool()== true)
		  {
		   if (General_F->Power_off_TOP->Enabled == true)
		   {
			General_F->Timer_back_T->Enabled = true;
		   }
		   else
		   {
			General_F->Timer_back_T->Enabled = false;
		   }

		  }
		  else
		  {
		   General_F->StatusBar->Panels->Items[2]->Text = "?????????????? ?????? ?????????";
		   General_F->Timer_back_T->Enabled = false;
		  }
	  Configuration_F->Close();
	 }

}
//---------------------------------------------------------------------------

bool TConfiguration_F::check_saving(const int& Tag, const bool& value)
{
bool result  = false;

	switch (Tag)
	{
	case 2: {
			 result = General_F->_Robik_config->get_Automatics_run();
			 break;
			};
	case 4: {
			 result = General_F->_Robik_config->get_Program_run_time();
			 break;
			};

	case 5: {
			 result = General_F->_Robik_config->get_Timer();
			break;
			};

	case 6: {
			 result = General_F->_Robik_config->get_Registry();
			break;
			};

	case 7: {
			 result = General_F->_Robik_config->get_Inifile();
			break;
			};

	case 8: {
			 result = General_F->_Robik_config->get_Starting_program();
			break;
			};

	case 9: {
			 result = General_F->_Robik_config->get_Starting_windows();
			break;
			};

	};


		if (value == result)
		{

		return true;
		}
		else
		{
		return false;
		}


};



bool TConfiguration_F::check_saving(const int& Tag, const AnsiString& value)
{
AnsiString result = false;

	switch (Tag)
	{
	case 0: {
			 result = General_F->_Robik_config->get_Url();
			 break;
			};

	case 1: {
			 result = General_F->_Robik_config->get_Choose_printer();
			 break;
			};

	case 3: {
			 result = General_F->_Robik_config->get_Regularity_of_printing_by_time();
			 break;
			};
	};

	if (value == result)
	{

	 return true;
	}
	else
	{
	 return false;
	}
};

void TConfiguration_F::initialisation()
{
this->Url_CB_Config->Text                               = General_F->_Robik_config->get_Url();
this->Choose_printer_CB_Config->Text                    = General_F->_Robik_config->get_Choose_printer();
this->Automatics_run_CH->Checked                        = General_F->_Robik_config->get_Automatics_run();
this->Regularity_of_printing_by_time_Config_ME->Text    = General_F->_Robik_config->get_Regularity_of_printing_by_time();
this->Program_run_time_CH->Checked                      = General_F->_Robik_config->get_Program_run_time();
this->Timer_?H->Checked                                 = General_F->_Robik_config->get_Timer();
this->Registry_RB->Checked                              = General_F->_Robik_config->get_Registry();
this->Inifile_RB->Checked                               = General_F->_Robik_config->get_Inifile();
this->Starting_program_CH->Checked                      = General_F->_Robik_config->get_Starting_program();
this->Starting_windows_CH->Checked                      = General_F->_Robik_config->get_Starting_windows();

this->flag_unchecking();
update_printer();
};

void TConfiguration_F::flag_unchecking()
{
this->flag_Url                            = false;
this->flag_Choose_printer                 = false;
this->flag_Automatics_run                 = false;
this->flag_Regularity_of_printing_by_time = false;
this->flag_Program_run_time               = false;
this->flag_Timer                          = false;
this->flag_Registry                       = false;
this->flag_Inifile                        = false;
this->flag_Starting_program               = false;
this->flag_Starting_windows               = false;

this->Button_enabled();
};

bool TConfiguration_F::what_flag_checked()
{
bool result = false;


std::vector<bool> v;
v.push_back(this->flag_Url);
v.push_back(this->flag_Choose_printer);
v.push_back(this->flag_Automatics_run);
v.push_back(this->flag_Regularity_of_printing_by_time);
v.push_back(this->flag_Program_run_time);
v.push_back(this->flag_Timer);
v.push_back(this->flag_Registry);
v.push_back(this->flag_Inifile);
v.push_back(this->flag_Starting_program);
v.push_back(this->flag_Starting_windows);

	for (auto p = v.begin(); p !=v.end(); p++)
	{
	  if ((*p)==true)
	  {
	  //b = *p;
	  return result = true;

	  }
	};

	v.clear();

 return result = false;

};

void TConfiguration_F::Button_enabled()
{
	  if (this->what_flag_checked() == true)
	  {
	   this->Save_B->Enabled = true;
	   this->Close_B->Caption = "????????";
	  }
	  else
	  {
	   this->Save_B->Enabled = false;
	   this->Close_B->Caption = "???????";
	  };

};
void __fastcall TConfiguration_F::Url_CB_ConfigChange(TObject *Sender)
{

  if(this->check_saving(this->Url_CB_Config->Tag, Url_CB_Config->Text) == true)
  {
  this->flag_Url = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Url = true;
  this->Button_enabled();
  };
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::FormCreate(TObject *Sender)
{
this->initialisation();
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Choose_printer_CB_ConfigChange(TObject *Sender)

{
  if(this->check_saving(this->Choose_printer_CB_Config->Tag, Choose_printer_CB_Config->Text) == true)
  {
  this->flag_Choose_printer = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Choose_printer = true;
  this->Button_enabled();
  };
}

//---------------------------------------------------------------------------
void __fastcall TConfiguration_F::Automatics_run_CHClick(TObject *Sender)
{
  if(this->check_saving(this->Automatics_run_CH->Tag, this->Automatics_run_CH->Checked) == true)
  {
  this->flag_Automatics_run = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Automatics_run = true;
  this->Button_enabled();
  };

	  if (this->Automatics_run_CH->Checked == true)
	  {
	  this->Regularity_of_printing_by_time_Config_ME->Enabled = true;
	  }
	  else
	  {
	  this->Regularity_of_printing_by_time_Config_ME->Enabled = false;
	  }
}

//---------------------------------------------------------------------------
void __fastcall TConfiguration_F::Regularity_of_printing_by_time_Config_MEChange(TObject *Sender)

{
  if(this->check_saving(this->Regularity_of_printing_by_time_Config_ME->Tag, Regularity_of_printing_by_time_Config_ME->Text) == true)
  {
  this->flag_Regularity_of_printing_by_time = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Regularity_of_printing_by_time = true;
  this->Button_enabled();
  };


}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Program_run_time_CHClick(TObject *Sender)
{
  if(this->check_saving(this->Program_run_time_CH->Tag, this->Program_run_time_CH->Checked) == true)
  {
  this->flag_Program_run_time = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Program_run_time = true;
  this->Button_enabled();
  };
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Timer_?HClick(TObject *Sender)
{
  if(this->check_saving(this->Timer_?H->Tag, this->Timer_?H->Checked) == true)
  {
  this->flag_Timer = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Timer = true;
  this->Button_enabled();
  };
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Registry_RBClick(TObject *Sender)
{

	if(this->check_saving(this->Registry_RB->Tag, this->Registry_RB->Checked) == true)
  {
  this->flag_Registry = false;

		if(this->check_saving(this->Inifile_RB->Tag, this->Inifile_RB->Checked) == true)
		{
		this->flag_Inifile = false;
		}
  this->Button_enabled();
  }
  else
  {
  this->flag_Registry = true;
  this->Button_enabled();
  };
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Inifile_RBClick(TObject *Sender)
{
	if(this->check_saving(this->Inifile_RB->Tag, this->Inifile_RB->Checked) == true)
  {
  this->flag_Inifile = false;

		if(this->check_saving(this->Registry_RB->Tag, this->Registry_RB->Checked) == true)
		{
		this->flag_Registry = false;
		}
  this->Button_enabled();
  }
  else
  {
  this->flag_Registry = true;
  this->Button_enabled();
  };
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Starting_program_CHClick(TObject *Sender)
{
  if(this->check_saving(this->Starting_program_CH->Tag, this->Starting_program_CH->Checked) == true)
  {
  this->flag_Starting_program = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Starting_program = true;
  this->Button_enabled();
  };

}

//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Starting_windows_CHClick(TObject *Sender)
{
  if(this->check_saving(this->Starting_windows_CH->Tag, this->Starting_windows_CH->Checked) == true)
  {
  this->flag_Starting_windows = false;
  this->Button_enabled();
  }
  else
  {
  this->flag_Starting_windows = true;
  this->Button_enabled();
  };


	TRegistry *reg = new TRegistry();
	reg->RootKey=HKEY_CURRENT_USER;
	reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run",true);
	if (Starting_windows_CH->Checked == true)
	{
		reg->WriteString("Smart Printing v.1.0",Application->ExeName);
		reg->CloseKey();
	}
	else
	{
		reg->DeleteValue("Smart Printing v.1.0");

	}
		reg->CloseKey();
}
//---------------------------------------------------------------------------

void __fastcall TConfiguration_F::Save_BClick(TObject *Sender)
{
//Save to Modul
General_F->_Robik_config->set_Url(this->Url_CB_Config->Text);
General_F->_Robik_config->set_Choose_printer(this->Choose_printer_CB_Config->Text);
General_F->_Robik_config->set_Automatics_run(this->Automatics_run_CH->Checked);
General_F->_Robik_config->set_Regularity_of_printing_by_time(this->Regularity_of_printing_by_time_Config_ME->Text);
General_F->_Robik_config->set_Program_run_time(this->Program_run_time_CH->Checked);
General_F->_Robik_config->set_Timer(this->Timer_?H->Checked);
General_F->_Robik_config->set_Registry(this->Registry_RB->Checked);
General_F->_Robik_config->set_Inifile(this->Inifile_RB->Checked);
General_F->_Robik_config->set_Starting_program(this->Starting_program_CH->Checked);
General_F->_Robik_config->set_Starting_windows(this->Starting_windows_CH->Checked);

	if (this->Registry_RB->Checked == true)
	{
	 General_F->_Robik_config->Save_shell(true);
	 General_F->_Robik_config->Save_inifile();
	}
	{
	 General_F->_Robik_config->Save_shell(false);
	 General_F->_Robik_config->Save_registry();
	}

 this->flag_unchecking();
 this->Button_enabled();
 General_F->update();

}
//---------------------------------------------------------------------------
  void TConfiguration_F::update_printer()
 {
	PRINTER_INFO_2 *Pr;
	DWORD byteNeed = 0,prCount=0;
	EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,NULL,0,&byteNeed,&prCount);
	Pr = new PRINTER_INFO_2 [byteNeed];
	if(EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,(LPBYTE)Pr,byteNeed,&byteNeed,&prCount))
	{
		for(int i = 0; i < prCount; ++i)
		{
		Choose_printer_CB_Config->Items->Add(AnsiString(Pr[i].pPrinterName));
		}
	}
	delete Pr;
 };


//---------------------------------------------------------------------------



void __fastcall TConfiguration_F::Config_SHCutClick(TObject *Sender)
{
ShortCUT_F->ShowModal();
}
//---------------------------------------------------------------------------

