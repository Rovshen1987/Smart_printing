
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Smart_printing.h"
#include "Preview.h"
#include "About.h"
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
//  ShowMessage(ExtractFilePath(Application->ExeName));

  this->_Robik_config = std::make_unique<_TSave_configuration>();

  if (this->_Robik_config->step_to_run_program() == true)
  {
  apple_general_config();
  }

  ImageList_BB->GetBitmap(0,Save_BB->Glyph);
  ImageList_BB->GetBitmap(0,Choose_printer_BB->Glyph);
  update_printer();

  this->run_program_Time = std::make_unique<time_r>();
  this->run_program_Time->set(std::string("0:0:0"));
  this->Run_program_timer->Enabled = true;




   this->set_remaining_time(std::string((_Robik_config->get_Regularity_of_printing_by_time()).c_str()));

  check_connect(default_host, Internet_status_O->Tag);
  check_connect(Url_CB->Text,Site_status_O->Tag);



  this->Timer_back = std::make_unique<time_r>();
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->Timer_back->set_forward(false);

  this->general_visable_general = std::make_unique<general_visable>();
  if (this->_Robik_config->get_Automatics_run() == true)
  {
   this->general_visable_general->Accept_power_on();
   this->StatusBar->Panels->Items[2]->Text = "Автоматическая работа остановлено...";
  };


  this->falg_automatics_printing = false;

  if ((this->_Robik_config->get_Automatics_run() == true) || (this->_Robik_config->get_Starting_program() == true))
  {
   this->general_visable_general->Accept_power_on();
   this->Timer_back_Trun();
  }
  else
  {
	this->general_visable_general->Accept_default();
    this->Timer_back_T->Enabled = false;
  };

   this->run_enabled();
   this->good_print_informatin       = 0;
   this->error_print_information     = 0;
   this->Report_E->Text = "Нет данных.";
   this->update_ShortCUT();
};

//------------------------------------------------------------------------------
void TGeneral_F::update()
{
  this->Url_CB->Text                           = this->_Robik_config->get_Url();
  this->Choose_printer_CB->Text                = this->_Robik_config->get_Choose_printer();
  Preview_F->frxReport->PrintOptions->Printer  = this->_Robik_config->get_Choose_printer();
	if (this->_Robik_config->get_Automatics_run() == true)
  {
   this->general_visable_general->Accept_power_on();

  }
  else
  {
   this->general_visable_general->Accept_default();
  }

  this->run_enabled();
  this->set_remaining_time(std::string((_Robik_config->get_Regularity_of_printing_by_time()).c_str()));
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->Timer_back_Trun();
  this->update_ShortCUT();
};

//------------------------------------------------------------------------------
void TGeneral_F::update(const bool& value)
{
  this->Url_CB->Text                           = this->_Robik_config->get_Url();
  this->Choose_printer_CB->Text                = this->_Robik_config->get_Choose_printer();
  Preview_F->frxReport->PrintOptions->Printer  = this->_Robik_config->get_Choose_printer();
	if (value == true)
  {
   this->general_visable_general->Accept_power_on();

  }
  else
  {
   this->general_visable_general->Accept_default();
  }

  this->run_enabled();
  this->set_remaining_time(std::string((_Robik_config->get_Regularity_of_printing_by_time()).c_str()));
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->Timer_back_Trun();
};

//------------------------------------------------------------------------------
void TGeneral_F::destroy_()
{

};
void __fastcall TGeneral_F::FormDestroy(TObject *Sender)
{
this->destroy_();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Run_program_timerTimer(TObject *Sender)
{
this->StatusBar->Panels->Items[0]->Text = this->_Statusbar_Item_0 + (this->run_program_Time->get_time()).c_str();
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Config_NClick(TObject *Sender)
{
Timer_back_T->Enabled = false;
Configuration_F->ShowModal();
//initialisation_to_flag();
//loop_print_time = 0;
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
this->general_visable_general->set_Choose_printer_BB(false);

	if (_Robik_config->get_Url() != Url_CB->Text)
	{
	  this->general_visable_general->set_Save_BB(true);
	  this->general_visable_general->set_Save_N(true);
	}
	else
	{
	  this->general_visable_general->set_Save_BB(false);

	  if ((this->general_visable_general->get_Save_BB() == false ) &&
		   (this->general_visable_general->get_Choose_printer_BB() == false))
	  {
		this->general_visable_general->set_Save_N(false);
	  }
	};
  this->run_enabled();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Config_TOPClick(TObject *Sender)
{
Timer_back_T->Enabled = false;
Configuration_F->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Save_BBClick(TObject *Sender)
{
 _Robik_config->set_Url(this->Url_CB->Text);
 _Robik_config->Save_shell();
 this->general_visable_general->set_Save_BB(false);

	if (_Robik_config->get_Choose_printer() != Choose_printer_CB->Text)
	{
	  this->general_visable_general->set_Choose_printer_BB(true);
	  this->general_visable_general->set_Save_N(true);
	}
	else
	{
	  this->general_visable_general->set_Choose_printer_BB(false);

	  if ((this->general_visable_general->get_Save_BB() == false ) &&
		   (this->general_visable_general->get_Choose_printer_BB() == false))
	  {
		this->general_visable_general->set_Save_N(false);
	  }
	};

   this->run_enabled();
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

//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Preview_TOPClick(TObject *Sender)
{
check_connect(Url_CB->Text,Site_status_O->Tag);
if (Site_status_O->Caption != AnsiString("Есть!"))
 {
  MessageDlg("Сайт по адресу \""+Url_CB->Text+"\" не доступен, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
  return;
 }

Web_browser_F->WebBrowser->Navigate(this->_Robik_config->get_Url());
Web_browser_F->Show();
Web_browser_F->set_flag_preview(true);
Web_browser_F->set_flag_print(false);
Web_browser_F->screen_photo();

};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::FormCreate(TObject *Sender)
{
   this->initialisation();
}

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

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Check_BClick(TObject *Sender)
{

  check_connect(default_host, Internet_status_O->Tag);

  check_connect(Url_CB->Text,Site_status_O->Tag);



};

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
check_connect(Url_CB->Text,Site_status_O->Tag);
if (Site_status_O->Caption != AnsiString("Есть!"))
 {
  MessageDlg("Сайт по адресу \""+Url_CB->Text+"\" не доступен, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
  return;
 }

Web_browser_F->Show();
Web_browser_F->set_flag_preview(true);
Web_browser_F->set_flag_print(false);
Web_browser_F->screen_photo();
}

//---------------------------------------------------------------------------
void TGeneral_F::preview_void()
{
Preview_F->frxReport->ShowReport();
Preview_F->ShowModal();
};

//---------------------------------------------------------------------------
void TGeneral_F::print_void()
{
Preview_F->frxReport->ShowReport();
Preview_F->frxReport->PrintOptions->Printer = Choose_printer_CB->Text;
Preview_F->frxReport->PrintOptions->Copies  = 1;
Preview_F->frxReport->PrepareReport();
Preview_F->frxReport->Print();
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Power_on_TOPClick(TObject *Sender)
{
 this->general_visable_general->Accept_power_on();
 this->run_enabled();
 this->update(true);
 this->Timer_back_Trun();
 Timer_back_T->Enabled = true;
}

//---------------------------------------------------------------------------
void TGeneral_F::print_r()
{
check_connect(Url_CB->Text,Site_status_O->Tag);
if (Site_status_O->Caption != AnsiString("Есть!"))
 {
  this->error_print_information++;

  this->Report_E->Text = this->get_time()+" Состояние печати связи нету подключение сайту.";
  MessageDlg("Сайт по адресу \""+Url_CB->Text+"\" не доступен, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
  return;
 }

Web_browser_F->Show();
Web_browser_F->set_flag_preview(false);
Web_browser_F->set_flag_print(true);
Web_browser_F->screen_photo();
this->good_print_informatin++;
show_good_print_inforamtion();
this->Report_E->Text = this->get_time()+" Состояние печати Good.";
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Fast_printing_TOPClick(TObject *Sender)
{

print_r();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Url_CBExit(TObject *Sender)
{
check_connect(Url_CB->Text,Site_status_O->Tag);
};

//---------------------------------------------------------------------------
void TGeneral_F::run_enabled()
{
this->general_visable_general->run_e(Url_CB,this->general_visable_general->get_Url_CB());
this->general_visable_general->run_e(Choose_printer_CB,this->general_visable_general->get_Choose_printer_CB());
this->general_visable_general->run_e(Save_BB,this->general_visable_general->get_Save_BB());
this->general_visable_general->run_e(Choose_printer_BB,this->general_visable_general->get_Choose_printer_BB());

this->general_visable_general->run_e(Open_TOP,this->general_visable_general->get_Open_TOP());
this->general_visable_general->run_e(Save_TOP,this->general_visable_general->get_Save_TOP());
this->general_visable_general->run_e(Fast_printing_TOP,this->general_visable_general->get_Fast_printing_TOP());
this->general_visable_general->run_e(Preview_TOP,this->general_visable_general->get_Preview_TOP());
this->general_visable_general->run_e(Power_on_TOP,this->general_visable_general->get_Power_on_TOP());
this->general_visable_general->run_e(Power_off_TOP,this->general_visable_general->get_Power_off_TOP());
this->general_visable_general->run_e(Config_TOP,this->general_visable_general->get_Config_TOP());

this->general_visable_general->run_e(Open_N,this->general_visable_general->get_Open_N());
this->general_visable_general->run_e(Save_N,this->general_visable_general->get_Save_N());
this->general_visable_general->run_e(Save_as_N,this->general_visable_general->get_Save_as_N());
this->general_visable_general->run_e(Fast_printing_N,this->general_visable_general->get_Fast_printing_N());
this->general_visable_general->run_e(Preview_N,this->general_visable_general->get_Preview_N());
this->general_visable_general->run_e(Configuring_printer_N,this->general_visable_general->get_Configuring_printer_N());
this->general_visable_general->run_e(Power_on_N,this->general_visable_general->get_Power_on_N());
this->general_visable_general->run_e(Power_off_N,this->general_visable_general->get_Power_off_N());
this->general_visable_general->run_e(Config_N,this->general_visable_general->get_Config_N());
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Url_CBChange(TObject *Sender)
{
	if (_Robik_config->get_Url() != Url_CB->Text)
	{
	  this->general_visable_general->set_Save_BB(true);
	  this->general_visable_general->set_Save_N(true);
	}
	else
	{
	  this->general_visable_general->set_Save_BB(false);

	  if ((this->general_visable_general->get_Save_BB() == false ) &&
		   (this->general_visable_general->get_Choose_printer_BB() == false))
	  {
		this->general_visable_general->set_Save_N(false);
	  }
	};

   this->run_enabled();
}

//---------------------------------------------------------------------------
std::string TGeneral_F::get_remaining_time()
{
   return this->remaining_orginal.remaining_time;
};

//---------------------------------------------------------------------------
void TGeneral_F::set_remaining_time(const std::string& value)
{
  this->remaining_orginal.remaining_time = value;
};

//---------------------------------------------------------------------------
bool TGeneral_F::get_remaining_time_bool()
{
  int temp = 0;
  std::string ch = "123456789";
  std::string date = this->remaining_orginal.remaining_time;

  for (int i = 0; i < date.size(); i++)
  {
	for (int j = 0; j < ch.size(); j++)
	{
		if (date[i] == ch[j])
		{
		temp++;
		}
	}

  }

  if (temp>0)
  {
   return true;
  }
  else
  {
   return false;
  }
};

//------------------------------------------------------------------------------
void TGeneral_F::Timer_back_Trun()
{
	if ((get_remaining_time_bool() == true)&& (this->_Robik_config->get_Automatics_run()))
	{
	 Timer_back_T->Enabled = true;
	}
	else
	{
	 Timer_back_T->Enabled = true;
	};

};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Timer_back_TTimer(TObject *Sender)
{
 if (this->remaining_orginal.pause_bool == true)
 {
	 if (this->remaining_orginal.printing == true)
	 {
		this->remaining_orginal.printing = false;
		check_connect(Url_CB->Text,Site_status_O->Tag);
		if (Site_status_O->Caption != AnsiString("Есть!"))
		{
		MessageDlg("Сайт по адресу \""+Url_CB->Text+"\" не доступен, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
		return;
		}

		print_r();
	 };


	 this->StatusBar->Panels->Items[2]->Text = (this->remaining_orginal.get_time_text()).c_str();

	 if (this->remaining_orginal.active == false)
	 {
	  Timer_back->set(this->remaining_orginal.remaining_time);
      this->remaining_orginal.first = true;
	 }

  return;
 };

	if (this->remaining_orginal.first == true)
	{
	 this->remaining_orginal.first = false;
	 this->Timer_back->set_forward(true);
	 this->Timer_back->get_time();
     this->Timer_back->set_forward(false);
	 this->StatusBar->Panels->Items[2]->Text =  this->_Statusbar_Item_2 + (this->Timer_back->get_time()).c_str();

	 return;
	}

	  if (get_remaining_time_bool()== true)
		{
			if ((Timer_back->get_second() == 0) && (Timer_back->get_minut() == 0)&&
			(Timer_back->get_hour() == 0)&&(this->remaining_orginal.pause_bool == false))
			{
			 this->StatusBar->Panels->Items[2]->Text = "Печать начинается!";
			 this->remaining_orginal.pause_bool = true;
			 this->remaining_orginal.pause = this->remaining_orginal.pause_int;
			 this->remaining_orginal.printing = true;
			 this->remaining_orginal.active   = true;
			}
			else
			{
			   if (this->remaining_orginal.pause_bool == false)
			   {
				this->StatusBar->Panels->Items[2]->Text =  this->_Statusbar_Item_2 + (this->Timer_back->get_time()).c_str();
			   }

			}

		}
		else
		{
		   this->StatusBar->Panels->Items[2]->Text = "Автоматическая работа выключена";
		   Timer_back_T->Enabled = false;
		}



};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Power_off_TOPClick(TObject *Sender)
{
  this->general_visable_general->Accept_default();
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->run_enabled();
  this->update(false);
   this->StatusBar->Panels->Items[2]->Text = "Автоматическая работа остановлено...";
   Timer_back_T->Enabled = false;
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Open_TOPClick(TObject *Sender)
{
	if (Open_IniFile->Execute())
	{
	 MessageDlg("Текучая конфигурация заменится новым, который даны момент открывайте! ", mtInformation,TMsgDlgButtons()<<mbOK ,0 );;
	 this->_Robik_config->Open_IniFile(Open_IniFile->FileName);
	 this->update();
	};
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Open_NClick(TObject *Sender)
{
	if (Open_IniFile->Execute())
	{
	 MessageDlg("Текучая конфигурация заменится новым, который даны момент открывайте! ", mtInformation,TMsgDlgButtons()<<mbOK ,0 );;
	 this->_Robik_config->Open_IniFile(Open_IniFile->FileName);
	 this->update();
	};
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Power_on_NClick(TObject *Sender)
{
 this->general_visable_general->Accept_power_on();
 this->run_enabled();
 this->update(true);
 this->Timer_back_Trun();
 Timer_back_T->Enabled = true;
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Power_off_NClick(TObject *Sender)
{
  this->general_visable_general->Accept_default();
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->run_enabled();
  this->update(false);
   this->StatusBar->Panels->Items[2]->Text = "Автоматическая работа остановлено...";
   Timer_back_T->Enabled = false;
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Fast_printing_NClick(TObject *Sender)
{
check_connect(Url_CB->Text,Site_status_O->Tag);
if (Site_status_O->Caption != AnsiString("Есть!"))
 {
  MessageDlg("Сайт по адресу \""+Url_CB->Text+"\" не доступен, исправьте пожалуйста!",
			 mtInformation,TMsgDlgButtons()<<mbOK ,0 );
  return;
 }

print_r();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Save_as_NClick(TObject *Sender)
{

	if (Save_AS_IniFile->Execute())
	{
	 this->_Robik_config->Save_AS_IniFile(Save_AS_IniFile->FileName);
	};
}
//---------------------------------------------------------------------------

void TGeneral_F::show_good_print_inforamtion()
{
  this->StatusBar->Panels->Items[1]->Text = _Statusbar_Item_1+std::to_string(this->good_print_informatin).c_str();
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Choose_printer_CBChange(TObject *Sender)
{
	if (_Robik_config->get_Choose_printer() != Choose_printer_CB->Text)
	{
	  this->general_visable_general->set_Choose_printer_BB(true);
	  this->general_visable_general->set_Save_N(true);
	}
	else
	{
	  this->general_visable_general->set_Choose_printer_BB(false);

	  if ((this->general_visable_general->get_Save_BB() == false ) &&
		   (this->general_visable_general->get_Choose_printer_BB() == false))
	  {
		this->general_visable_general->set_Save_N(false);
	  }
	};

   this->run_enabled();
}

//---------------------------------------------------------------------------
AnsiString TGeneral_F::get_time()
{
time_t seconds = time(NULL);
tm* timeinfo = localtime(&seconds);

int day,month, year, sec,min, hour;
day = timeinfo->tm_mday;
month = timeinfo->tm_mon;
month++;
year = timeinfo->tm_year;
year = year+1900;

std::string sec_s,min_s,hour_s;

sec = timeinfo->tm_sec;
min = timeinfo->tm_min;
hour = timeinfo->tm_hour;

 if (sec<10)
 {
  sec_s = "0"+ std::string(std::to_string(sec));
 }
 else
 {
  sec_s = std::to_string(sec);
 }

 if (min<10)
 {
  min_s = "0"+std::string(std::to_string(min));
 }
 else
 {
  min_s = std::to_string(min);
 }

 if (hour<10)
 {
  hour_s ="0"+ std::string(std::to_string(hour));
 }
 else
 {
  hour_s = std::to_string(hour);
 }



std::string temp = std::to_string(day)+"."+std::to_string(month)+"."+std::to_string(year)+
				   " | "+hour_s+":"+min_s+":"+sec_s;

return AnsiString(temp.c_str());

};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Save_NClick(TObject *Sender)
{
	_Robik_config->set_Url(this->Url_CB->Text);
	_Robik_config->set_Choose_printer(this->Choose_printer_CB->Text);
	_Robik_config->Save_shell();
	this->general_visable_general->set_Save_BB(false);
	this->general_visable_general->set_Choose_printer_BB(false);
	this->general_visable_general->set_Save_N(false);
    this->run_enabled();
};

//---------------------------------------------------------------------------
void TGeneral_F::update_ShortCUT()
{
 this->Open_N->ShortCut                 = General_F->_Robik_config->get_Open_SHCut();
 this->Save_N->ShortCut                 = General_F->_Robik_config->get_Save_SHCut();
 this->Save_as_N->ShortCut              = General_F->_Robik_config->get_Save_as_SHCut();
 this->Fast_printing_N->ShortCut        = General_F->_Robik_config->get_Fast_printing_SHCut();
 this->Preview_N->ShortCut              = General_F->_Robik_config->get_Preview_SHCut();
 this->Exit_N->ShortCut                 = General_F->_Robik_config->get_Exit_SHCut();
 this->Power_on_N->ShortCut             = General_F->_Robik_config->get_Power_on_SHCut();
 this->Power_off_N->ShortCut            = General_F->_Robik_config->get_Power_off_SHCut();
 this->Config_N->ShortCut               = General_F->_Robik_config->get_Config_SHCut();
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::About_NClick(TObject *Sender)
{
About_F->ShowModal();
}
//---------------------------------------------------------------------------

