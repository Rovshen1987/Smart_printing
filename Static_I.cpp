//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Static_I.h"
#include "Smart_printing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatic_I_F *Static_I_F;
//---------------------------------------------------------------------------
__fastcall TStatic_I_F::TStatic_I_F(TComponent* Owner)
	: TForm(Owner)
{
};

//---------------------------------------------------------------------------
void __fastcall TStatic_I_F::Exit_BClick(TObject *Sender)
{
 Static_I_F->Close();
};

//---------------------------------------------------------------------------
void TStatic_I_F::initilisation()
{
	this->Launched_L_g->Caption           = this->run_program(General_F->Smart_time_t);
	this->Working_hours_L_g->Caption      = "00:00:00";
	this->Successful_prints_L_g->Caption  = "0";
	this->Erroneous_seals_L_g->Caption    = "0";
	this->Result_L_g->Caption             = "0";
};

//---------------------------------------------------------------------------
void __fastcall TStatic_I_F::FormCreate(TObject *Sender)
{
 this->initilisation();
}

//---------------------------------------------------------------------------
AnsiString TStatic_I_F::run_program(std::time_t* value)
{
 struct std::tm* time = std::localtime(value);

 int day, month, year, hour, min, second;
 day      = 0;
 month    = 0;
 year     = 0;
 hour     = 0;
 min      = 0;
 second   = 0;

 day      = time->tm_mday;
 month    = time->tm_mon+1;
 year     = time->tm_year+1900;

 hour     = time->tm_hour;
 min      = time->tm_min;
 second   = time->tm_sec;

 std::string day_s, month_s, year_s, hour_s, min_s, second_s, result;

 day_s    = this->paste_null(day);
 month_s  = this->paste_null(month);
 year_s   = std::to_string(year);
 hour_s   = this->paste_null(hour);
 min_s    = this->paste_null(min);
 second_s = this->paste_null(second);

 result = day_s+"."+month_s+"."+year_s+"г.  ||  "+ hour_s+":"+min_s+":"+second_s;

 delete time;
 return result.c_str();
};

std::string TStatic_I_F::paste_null(const int& value)
{
  std::string result;

   if (value<10)
   {
	result = "0"+std::to_string(value);
   }
   else
   {
	result = std::to_string(value);
   };

   return result;
};

//-----------------------------------------------------------------------------
void __fastcall TStatic_I_F::Save_reports_BClick(TObject *Sender)
{
	if (SaveDialog->Execute())
	{
		TMemo* LN= new TMemo(Static_I_F);
		LN->Name = "Label_Nod";
		LN->Parent = Static_I_F;

		LN->Left = 15;
		LN->Top  = 15;
		LN->Enabled = true;
		LN->Visible = false;
		LN->Font->Style = TFontStyles() << fsBold;
		LN->Font->Size = 9;
		LN->Color = clHighlightText;

		LN->Width = 325;
		LN->Height = 325;

		LN->Lines->Clear();
		LN->ScrollBars = ssBoth;

        this->paste_information(LN);
		LN->Lines->SaveToFile(SaveDialog->FileName+".txt");

		LN->DestroyComponents();
		delete LN;
	}
};

//---------------------------------------------------------------------------
TMemo* TStatic_I_F::paste_information(TMemo* object)
{
  for (int i = 0; i < 1; i++)
  {
   object->Lines->Add("");
  };

  AnsiString Line = "----------------------------------------------------------";
  AnsiString Line_s = "********************************************************";

  object->Lines->Add("**************"+General_F->Caption+"**************");
  object->Lines->Add(Line);
  object->Lines->Add("    "+this->Launched_L->Caption+"    "+this->Launched_L_g->Caption+";");
  object->Lines->Add(Line);
  object->Lines->Add("");
  object->Lines->Add(Line);
  object->Lines->Add("    "+this->Working_hours_L->Caption+"    "+this->Working_hours_L_g->Caption+";");
  object->Lines->Add(Line);
  object->Lines->Add("");
  object->Lines->Add("-------------------Статистика печати------------------------");
  object->Lines->Add(Line);
  object->Lines->Add("    "+this->Successful_prints_L->Caption+"    "+this->Successful_prints_L_g->Caption+";");
  object->Lines->Add(Line);
  object->Lines->Add("");
  object->Lines->Add(Line);
  object->Lines->Add("    "+this->Erroneous_seals_L->Caption+"    "+this->Erroneous_seals_L_g->Caption+";");
  object->Lines->Add(Line);
  object->Lines->Add("");
  object->Lines->Add(Line);
  object->Lines->Add("    "+this->Result_L->Caption+"    "+this->Result_L_g->Caption+";");
  object->Lines->Add(Line);
  object->Lines->Add(Line_s);
  object->Lines->Add(Line_s);

  std::time_t* time_paste                 = new std::time_t;
  std::time(time_paste);

  object->Lines->Add("Время создание отчета   "+this->run_program(time_paste));
  delete time_paste;

  return object;
};
