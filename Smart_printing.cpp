
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Smart_printing.h"
#include "Preview.h"
#include "About.h"
#include "Static_I.h"
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
  this->_Robik_config = std::make_unique<_TSave_configuration>();
  this->general_visable_general = std::make_unique<general_visable>();
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
  this->Timer_back = std::make_unique<time_r>();
  this->Timer_back->set(this->remaining_orginal.remaining_time);
  this->Timer_back->set_forward(false);


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
   this->good_print_information       = 0;
   this->error_print_information      = 0;
   this->Report_E->Text               = "Нет данных.";
   this->update_ShortCUT();
   this->Smart_time_t                 = new std::time_t;
   std::time(Smart_time_t);
   prohibit_launch();
   this->flag_print_Web_browser       = false;
   this->flag_emtysite_r              = false;
   this->flag_error_past              = false;
};

//------------------------------------------------------------------------------
void TGeneral_F::update()
{
  this->Url_E->Text                            = this->_Robik_config->get_Url();
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
  this->Url_E->Text                            = this->_Robik_config->get_Url();
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
void __fastcall TGeneral_F::FormDestroy(TObject *Sender)
{
 this->destroy_g();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Run_program_timerTimer(TObject *Sender)
{
AnsiString temp = (this->run_program_Time->get_time()).c_str();
this->StatusBar->Panels->Items[0]->Text = this->_Statusbar_Item_0 + temp;
this->past_static(temp);

jobs_printer();

	if (remaining_orginal.print_job_count > 0)
	{
	 this->StatusBar->Panels->Items[2]->Text = (this->remaining_orginal.get_time_text()).c_str();

	}
	else
	{

	};

};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Config_NClick(TObject *Sender)
{
Timer_back_T->Enabled = false;
Configuration_F->ShowModal();
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

	if (_Robik_config->get_Url() != Url_E->Text)
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
 _Robik_config->set_Url(this->Url_E->Text);
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
 this->Url_E->Text             = _Robik_config->get_Url();
 this->Choose_printer_CB->Text = _Robik_config->get_Choose_printer();
};

//------------------------------------------------------------------------------
void TGeneral_F::apple_general_program()
{
 _Robik_config->set_Url(this->Url_E->Text);
 _Robik_config->set_Choose_printer(this->Choose_printer_CB->Text);

 //----------Configuration_F-------------------------------------
 Configuration_F->Url_CB_Config->Text                            = this->Url_E->Text;
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
// void TGeneral_F::check_connect(const AnsiString& hostname, const int& Tag)
// {
//	  try
//	 {
//	  IdHTTP1->Get(hostname);
//	  this->all_error_connect(true, Tag);
//	 }
//	  catch(EIdHTTPProtocolException &es)
//	 {
//		switch(es.ErrorCode){
//		 case 200:{
//				   this->all_error_connect(false,Tag);
//				   break;
//				  }
//
//		 case 303:{
//				   this->all_error_connect(false,Tag);
//				   break;
//				  }
//
//		 case 404:{
//
//				   this->all_error_connect(false,Tag);
//
//
//
//
//
//				   break;
//				  }
//
//		 default: {
//
//				   this->all_error_connect(false,Tag);
//
//				  }
//		}
//	 }
//	  catch(EIdSocketError &se)
//	  {
//			if(se.LastError == 11001)
//			{
//			this->all_error_connect(false,Tag);
//			}
//	  };
// };

//---------------------------------------------------------------------------;

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

//---------------------------------------------------------------------------;

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
void TGeneral_F::preview_void()
{
 direct_r p;



  if (p.check_file(ExtractFilePath(Application->ExeName)+"date\\temp.bmp") == true)
  {
	Preview_F->frxReport->ShowReport();
	Preview_F->ShowModal();
  }
  else
  {
   MessageDlg("Данный момент нет информации для просмотра, сперва напечатайте чек. ", mtInformation,
   TMsgDlgButtons() << mbOK,0);
  }
};

//---------------------------------------------------------------------------
void TGeneral_F::print_void()
{
		this->remaining_orginal.empty_print = false;
		this->Timer_empty->Enabled          = false;
Preview_F->frxReport->ShowReport();
Preview_F->frxReport->PrintOptions->Printer = Choose_printer_CB->Text;
Preview_F->frxReport->PrintOptions->Copies  = 1;
Preview_F->frxReport->PrepareReport();
Preview_F->frxReport->Print();
jobs_printer();
this->remaining_orginal.print_job_count = 1;
this->good_print_information++;
show_good_print_inforamtion();
this->Report_E->Text = this->get_time()+" Состояние печати Good.";

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
        this->flag_error_past = true;
		Web_browser_F->WebBrowser->Navigate(this->_Robik_config->get_Url());
		Web_browser_F->Show();



		this->remaining_orginal.empty_print = true;
		this->Timer_empty->Enabled          = true;
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Fast_printing_TOPClick(TObject *Sender)
{

	if (remaining_orginal.print_job_count > 0)
	{
	 MessageDlg("Подождите пока напечатается которую вы отправили до этого, осталось напечатать " +IntToStr(remaining_orginal.print_job_count),
			   mtInformation,TMsgDlgButtons()<<mbOK,0);
	} else
	{
	  if ((Save_BB->Enabled == true) ||(Choose_printer_BB->Enabled == true))
	  {
	  this->Save_n_void();
	  }
	 this->print_r();
	}
}

//---------------------------------------------------------------------------;

//---------------------------------------------------------------------------
void TGeneral_F::run_enabled()
{
this->general_visable_general->run_e(Url_E,this->general_visable_general->get_Url_E());
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
	if (remaining_orginal.print_job_count > 0)
	{
	return;
	};


 if (this->remaining_orginal.pause_bool == true)
 {
	 if (this->remaining_orginal.printing == true)
	 {
		this->remaining_orginal.printing = false;
//		AnsiString temp = Url_CB->Text;
//		std::string s = temp.c_str();
//		int temp_i = s.size();

//		Web_browser_F->WebBrowser->Navigate(this->_Robik_config->get_Url());
//		Web_browser_F->Show();
		 General_F->print_r();

		this->remaining_orginal.empty_print = true;
		this->Timer_empty->Enabled          = true;


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


	Static_I_F->Successful_prints_L_g->Caption  = (std::to_string(this->good_print_information)).c_str();
	Static_I_F->Erroneous_seals_L_g->Caption    = (std::to_string(this->error_print_information)).c_str();
	Static_I_F->Result_L_g->Caption             = (std::to_string(this->error_print_information+this->good_print_information)).c_str();

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
	if (remaining_orginal.print_job_count > 0)
	{
	 MessageDlg("Подождите пока напечатается которую вы отправили до этого, осталось напечатать " +IntToStr(remaining_orginal.print_job_count),
			   mtInformation,TMsgDlgButtons()<<mbOK,0);
	} else
	{
	  if ((Save_BB->Enabled == true) ||(Choose_printer_BB->Enabled == true))
	  {
	  this->Save_n_void();
	  }
	 this->print_r();
	}
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
  this->StatusBar->Panels->Items[1]->Text = _Statusbar_Item_1+std::to_string(this->good_print_information).c_str();
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

std::string sec_s,min_s,hour_s, day_s,month_s;

sec = timeinfo->tm_sec;
min = timeinfo->tm_min;
hour = timeinfo->tm_hour;

 if (day<10)
 {
  day_s = "0"+ std::string(std::to_string(day));
 }
 else
 {
  day_s = std::to_string(day);
 }

  if (month<10)
 {
  month_s = "0"+ std::string(std::to_string(month));
 }
 else
 {
  month_s = std::to_string(month);
 }

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



std::string temp = day_s+"."+month_s+"."+std::to_string(year)+
				   " | "+hour_s+":"+min_s+":"+sec_s;

return AnsiString(temp.c_str());

};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Save_NClick(TObject *Sender)
{
	this->Save_n_void();
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
 this->Static_info_N->ShortCut          = General_F->_Robik_config->get_Static_info_SHCut();
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::About_NClick(TObject *Sender)
{
About_F->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TGeneral_F::Static_info_NClick(TObject *Sender)
{
Static_I_F->ShowModal();
}

//---------------------------------------------------------------------------
void TGeneral_F::destroy_g()
{
  DeleteFile(ExtractFilePath(Application->ExeName)+"date\\temp.bmp");
  delete this->Smart_time_t;
};

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Help_TOPClick(TObject *Sender)
{
		Web_browser_F->WebBrowser->Navigate(this->_Robik_config->get_Url());
		Web_browser_F->Show();
		Web_browser_F->Close();
}

//---------------------------------------------------------------------------
void TGeneral_F::jobs_printer()
{
int job_count = -1;

	PRINTER_INFO_2 *Pr;
	DWORD byteNeed = 0,prCount=0;
	EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,NULL,0,&byteNeed,&prCount);
	Pr = new PRINTER_INFO_2 [byteNeed];
	if(EnumPrinters(PRINTER_ENUM_CONNECTIONS|PRINTER_ENUM_LOCAL,NULL,2,(LPBYTE)Pr,byteNeed,&byteNeed,&prCount))
	{
		for(int i = 0; i < prCount; ++i)
		{
		if (AnsiString(Pr[i].pPrinterName)== Choose_printer_CB->Text)
		{
		 job_count = Pr[i].cJobs;
		}
	}
	delete Pr;
	}

	this->remaining_orginal.print_job_count = job_count;

};

//---------------------------------------------------------------------------
void TGeneral_F::prohibit_launch()//запретить запуск второй копии программы
{
//HANDLE Smart_printing_mu;
////При открытии программы пытаемся создать мютекс.
////Мютекс - такой объект, который можно увидеть из любого приложения системы
//Smart_printing_mu = General_F->Handle;
//DWORD result;
//result = WaitForSingleObject(Smart_printing_mu,0);//А теперь пытаемся его захватить себе
////Если его захватить не получается, значит мютекс уже захватил кто-то другой
//if(result!=WAIT_OBJECT_0)
//  {
//  ShowMessage("У вас уже запущена одна копия приложения");
//  Application->ShowMainForm=false;
//  Application->Terminate();
//  }
};



void TGeneral_F::Report_E_emptysite_error()
{
   this->Report_E->Text = this->get_time()+ _Statusbar_Item_error1_emptysite;
};

void __fastcall TGeneral_F::Timer_emptyTimer(TObject *Sender)
{
//	 if (General_F->check_error_connect(General_F->Empty_site->Lines->Strings[0])==true)
//	{
//		Web_browser_F->set_flag_error_connect(true);
//	}
//	else
//	{
//		Web_browser_F->set_flag_error_connect(false);
//	};

		if (General_F->check_error_connect(General_F->Empty_site->Lines->Strings[0])==true)
		{
		  if (this->flag_error_past == true)
		  {
		  this->Report_E_connect_error();;
		  this->error_print_information = error_print_information+1;
		  }
		  this->flag_error_past = false;
		return;
		}

		if ((Empty_site->Lines->Count<4)&&(Web_browser_F->get_flag_refresh() == true))
		{
          if (this->flag_error_past == true)
		  {
		  this->Report_E_emptysite_error();
		  this->error_print_information = error_print_information+1;
		  this->flag_emtysite_r = true;
		  }
		  this->flag_error_past = false;
		return;
		}

		if ((Empty_site->Lines->Count>4)&&(Web_browser_F->get_flag_refresh() == true))
		{
			Web_browser_F->Show();
			Web_browser_F->set_flag_print(true);
			Web_browser_F->screen_photo();
		}


}
//---------------------------------------------------------------------------

//void TGeneral_F::Url_CB_Load()
//{
// Url_CB->Items->Clear();
// AnsiString path = ExtractFilePath(Application->ExeName)+"date\\Url.txt";
// Url_CB->Items->LoadFromFile(path);
//};
//
//void TGeneral_F::Url_CB_delete_dub()
//{
//// AnsiString first, last;
//
//  for (int i = 0; i < Url_CB->Items->Count; i++)
//  {
//  // first = Url_CB->Items[i].GetText() ;
//
//   if (Url_CB->Items[i].GetText() == Url_CB->Items[i+1].GetText())
//   {
//	 Url_CB->Items->Delete(i);
//   };
//  };
//};
//
//void TGeneral_F::Url_CB_Save()
//{
// AnsiString path = ExtractFilePath(Application->ExeName)+"date\\Url.txt";
// Url_CB->Items->SaveToFile(path);
//};

void __fastcall TGeneral_F::Url_EChange(TObject *Sender)
{
	if (_Robik_config->get_Url() != Url_E->Text)
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

void __fastcall TGeneral_F::Preview_TOPClick(TObject *Sender)
{
 preview_void();
}

//---------------------------------------------------------------------------
void __fastcall TGeneral_F::Empty_siteChange(TObject *Sender)
{
Web_browser_F->set_flag_refresh(true);

}
//---------------------------------------------------------------------------

void TGeneral_F::Report_E_connect_error()
{
   this->Report_E->Text = this->get_time()+ _Statusbar_Item_error1_connection;
};

//---------------------------------------------------------------------------
bool TGeneral_F::check_error_connect(AnsiString date)
{
 bool resul = false;
 const std::string che    = "Переход отменен";
 const std::string er_che = "Не удается открыть эту страницу";

 std::string date_s = date.c_str();
 std::string temp  = "";
 std::string temp_2 = "";

 int date_size = std::string(date.c_str()).size();


 for (int i = 0; i < date_size; i++)
 {
   temp   = "";
   temp_2 = "";

   for (int j = i; j < (i+che.size()); j++)
   {
	temp = temp+date_s[j];
   };

	for (int j = i; j < (i+er_che.size()); j++)
   {
	temp_2 = temp_2+date_s[j];
   };

   if ((temp == che) || (temp_2 == er_che))
   {
	return resul = true;
   };

 }

 return resul;

};

//---------------------------------------------------------------------------
void TGeneral_F::past_static(const AnsiString& value)
{
Static_I_F->Working_hours_L_g->Caption     = value;
Static_I_F->Successful_prints_L_g->Caption = std::to_string(good_print_information).c_str();
Static_I_F->Erroneous_seals_L_g->Caption   = std::to_string(error_print_information).c_str();
Static_I_F->Result_L_g->Caption            = std::to_string(good_print_information+error_print_information).c_str();
};

//---------------------------------------------------------------------------
void TGeneral_F::Save_n_void()
{
	_Robik_config->set_Url(this->Url_E->Text);
	_Robik_config->set_Choose_printer(this->Choose_printer_CB->Text);
	_Robik_config->Save_shell();
	this->general_visable_general->set_Save_BB(false);
	this->general_visable_general->set_Choose_printer_BB(false);
	this->general_visable_general->set_Save_N(false);
	this->run_enabled();
};
