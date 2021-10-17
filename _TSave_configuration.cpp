#include "_TSave_configuration.h"

//--------------------CONSTRUCTOR-----------------------------------------------
_TSave_configuration::_TSave_configuration()
{
  this->initilisation();
};

//--------------------DESTRUCTOR------------------------------------------------
_TSave_configuration::~_TSave_configuration()
{

};

//--------------------PUBLIC_SECTION--------------------------------------------
//------------------------SET---------------------------------------------------
void _TSave_configuration::set_Url(const AnsiString& value)
{
  this->Url = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Automatics_run(const bool& value)
{
   this->Automatics_run = value;
};
//------------------------------------------------------------------------------
void _TSave_configuration::set_Choose_printer(const AnsiString& value)
{
   this->Choose_printer = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Program_run_time(const bool& value)
{
   this->Program_run_time = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Timer(const bool& value)
{
   this->Timer = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Regularity_of_printing_by_time(const AnsiString& value)
{
   this->Regularity_of_printing_by_time = value;
};


//------------------------------------------------------------------------------
void _TSave_configuration::set_Registry(const bool& value)
{
   this->Registry = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Inifile(const bool& value)
{
   this->Inifile = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Starting_program(const bool& value)
{
   this->Starting_program = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Starting_windows(const bool& value)
{
   this->Starting_windows = value;
};

//-------------Short_CUT-BEGIN()-SET--------------------------------------------
void _TSave_configuration::set_Open_SHCut(const int& value)
{
	this->Open_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Save_SHCut(const int& value)
{
	this->Save_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Save_as_SHCut(const int& value)
{
	this->Save_as_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Fast_printing_SHCut(const int& value)
{
	this->Fast_printing_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Preview_SHCut(const int& value)
{
	this->Preview_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Exit_SHCut(const int& value)
{
	this->Exit_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Power_on_SHCut(const int& value)
{
	this->Power_on_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Power_off_SHCut(const int& value)
{
	 this->Power_off_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Config_SHCut(const int& value)
{
	 this->Config_SHCut = value;
};

//------------------------------------------------------------------------------
void _TSave_configuration::set_Static_info_SHCut(const int& value)
{
  this->Static_info_SHCut = value;
};

//------------------------------------------------------------------------------
//-------------Short_CUT-END()--SET----------------------------------------------

//------------------------------------------------------------------------------
//----------------------------PUBLIC_GET--------------------------------------------------
AnsiString _TSave_configuration::get_Url()
{
  return this->Url;
};

//------------------------------------------------------------------------------
AnsiString _TSave_configuration::get_Choose_printer()
{
  return this->Choose_printer;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Automatics_run()
{
   return	this->Automatics_run;
};

//------------------------------------------------------------------------------
AnsiString _TSave_configuration::get_Regularity_of_printing_by_time()
{
  return this->Regularity_of_printing_by_time;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Program_run_time()
{
  return this->Program_run_time;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Timer()
{
  return this->Timer;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Registry()
{
  return this->Registry;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Inifile()
{
  return this->Inifile;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Starting_program()
{
   return this->Starting_program;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::get_Starting_windows()
{
   return this->Starting_windows;
};

//-------------Short_CUT-BEGIN()------------------------------------------------
int _TSave_configuration::get_Open_SHCut()
{
   return this->Open_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Save_SHCut()
{
   return this->Save_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Save_as_SHCut()
{
   return this->Save_as_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Fast_printing_SHCut()
{
   return this->Fast_printing_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Preview_SHCut()
{
   return this->Preview_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Exit_SHCut()
{
   return this->Exit_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Power_on_SHCut()
{
   return this->Power_on_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Power_off_SHCut()
{
   return this->Power_off_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Config_SHCut()
{
   return this->Config_SHCut;
};

//------------------------------------------------------------------------------
int _TSave_configuration::get_Static_info_SHCut()
{
   return this->Static_info_SHCut;
};

//------------------------------------------------------------------------------
//-------------Short_CUT-END()--------------------------------------------------
//------------------------------------------------------------------------------
bool _TSave_configuration::step_to_run_program()
{
  bool result = false;

  AnsiString Quastion =  AnsiString("Свези с первом запуском программы Smart Printing\n")+
						 AnsiString("у вас на компьютере какой тип сохранение\n")+
						 AnsiString("выберите? Если ответите Yes, то будет выбрана\n")+
						 AnsiString("сохранение в реестр Windows, если ответите No,\n")+
						 AnsiString("то будет выбрана сохранение в Ini файл.\n Какой выберете? ");
  result = this->step_one();
  if (result == false)
  {
   this->default_init();

			if (MessageDlg(Quastion, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
		   this->Save_shell(true);
		}
		else
		{
		  this->Save_shell(false);
		}
  }

  this->Check_url();

  return result;
};

//------------------------------------------------------------------------------
void _TSave_configuration::Open_IniFile(const AnsiString& FileName)
{
try
 {
  TIniFile* I_nf                         = new TIniFile(FileName);
  this->Url                              = I_nf->ReadString("General","Url","");
  this->Choose_printer                   = I_nf->ReadString("General","Choose_printer","");
  this->Automatics_run                   = I_nf->ReadBool("General","Automatics_run",false);
  this->Regularity_of_printing_by_time   = I_nf->ReadString("General","Regularity_of_printing_by_time","");
  this->Program_run_time                 = I_nf->ReadBool("General","Program_run_time",false);
  this->Timer                            = I_nf->ReadBool("General","Timer",false);
  this->Registry                         = I_nf->ReadBool("General","Registry",false);
  this->Inifile                          = I_nf->ReadBool("General","Inifile",false);
  this->Starting_program                 = I_nf->ReadBool("General","Starting_program",false);
  this->Starting_windows                 = I_nf->ReadBool("General","Starting_windows",false);
  this->Open_SHCut                       = I_nf->ReadInteger("ShortCut","Open_SHCut",0);
  this->Save_SHCut                       = I_nf->ReadInteger("ShortCut","Save_SHCut",0);
  this->Save_as_SHCut                    = I_nf->ReadInteger("ShortCut","Save_as_SHCut",0);
  this->Fast_printing_SHCut              = I_nf->ReadInteger("ShortCut","Fast_printing_SHCut",0);
  this->Preview_SHCut                    = I_nf->ReadInteger("ShortCut","Preview_SHCut",0);
  this->Exit_SHCut                       = I_nf->ReadInteger("ShortCut","Exit_SHCut",0);
  this->Power_on_SHCut                   = I_nf->ReadInteger("ShortCut","Power_on_SHCut",0);
  this->Power_off_SHCut                  = I_nf->ReadInteger("ShortCut","Power_off_SHCut",0);
  this->Config_SHCut                     = I_nf->ReadInteger("ShortCut","Config_SHCut",0);
  this->Static_info_SHCut                = I_nf->ReadInteger("ShortCut","Static_info_SHCut",0);
  I_nf->Free();
  this->Save_inifile();
 }
 catch(...)
 {

 }


};

//------------------------------------------------------------------------------
void _TSave_configuration::Save_AS_IniFile(const AnsiString& FileName)
{
 TIniFile* I_nf = new TIniFile(FileName);
 I_nf->WriteString("General","Url",this->Url);
 I_nf->WriteString("General","Choose_printer",this->Choose_printer);
 I_nf->WriteBool("General","Automatics_run",this->Automatics_run);
 I_nf->WriteString("General","Regularity_of_printing_by_time",this->Regularity_of_printing_by_time);
 I_nf->WriteBool("General","Program_run_time",this->Program_run_time);
 I_nf->WriteBool("General","Timer",this->Timer);
 I_nf->WriteBool("General","Registry",this->Registry);
 I_nf->WriteBool("General","Inifile",this->Inifile);
 I_nf->WriteBool("General","Starting_program",this->Starting_program);
 I_nf->WriteBool("General","Starting_windows",this->Starting_windows);
 I_nf->WriteInteger("ShortCut","Open_SHCut",this->Open_SHCut);
 I_nf->WriteInteger("ShortCut","Save_SHCut",this->Save_SHCut);
 I_nf->WriteInteger("ShortCut","Save_as_SHCut",this->Save_as_SHCut);
 I_nf->WriteInteger("ShortCut","Fast_printing_SHCut",this->Fast_printing_SHCut);
 I_nf->WriteInteger("ShortCut","Preview_SHCut",this->Preview_SHCut);
 I_nf->WriteInteger("ShortCut","Exit_SHCut",this->Exit_SHCut);
 I_nf->WriteInteger("ShortCut","Power_on_SHCut",this->Power_on_SHCut);
 I_nf->WriteInteger("ShortCut","Power_off_SHCut",this->Power_off_SHCut);
 I_nf->WriteInteger("ShortCut","Config_SHCut",this->Config_SHCut);
 I_nf->WriteInteger("ShortCut","Static_info_SHCut",this->Static_info_SHCut);
 I_nf->Free();
};

//--------------------PRIVATE_SECTION-------------------------------------------
void _TSave_configuration::Read_shell(const bool& value)
{
   this->flag_source_save = value;

   if (value == true)
   {
	this->Read_resgistry();
   }
   else
   {
	this->Read_inifile();
   }
};

//------------------------------------------------------------------------------
void _TSave_configuration::Read_shell()
{
   if ( this->flag_source_save== true)
   {
	this->Read_resgistry();
   }
   else
   {
	this->Read_inifile();
   }
};

//------------------------------------------------------------------------------
void _TSave_configuration::Read_resgistry()
{
	if (_TSave_configuration::Check_registry() == false)
	{
	 this->default_init();
	 this->Read_shell(true);
	 return;
	};

  TRegistry* reg                       = new TRegistry;
  reg->RootKey                         = HKEY_CURRENT_USER;
  reg->OpenKey("\\Software\\Robik\\Smart_printing\\",0);
  this->Url                            = reg->ReadString("Url");
  this->Choose_printer                 = reg->ReadString("Choose_printer");
  this->Automatics_run                 = reg->ReadBool("Automatics_run");
  this->Regularity_of_printing_by_time = reg->ReadString("Regularity_of_printing_by_time");
  this->Program_run_time               = reg->ReadBool("Program_run_time");
  this->Timer                          = reg->ReadBool("Timer");
  this->Registry                       = reg->ReadBool("Registry");
  this->Inifile                        = reg->ReadBool("Inifile");
  this->Starting_program               = reg->ReadBool("Starting_program");
  this->Starting_windows               = reg->ReadBool("Starting_windows");
  this->Open_SHCut                     = reg->ReadInteger("Open_SHCut");
  this->Save_SHCut                     = reg->ReadInteger("Save_SHCut");
  this->Save_as_SHCut                  = reg->ReadInteger("Save_as_SHCut");
  this->Fast_printing_SHCut            = reg->ReadInteger("Fast_printing_SHCut");
  this->Preview_SHCut                  = reg->ReadInteger("Preview_SHCut");
  this->Exit_SHCut                     = reg->ReadInteger("Exit_SHCut");
  this->Power_on_SHCut                 = reg->ReadInteger("Power_on_SHCut");
  this->Power_off_SHCut                = reg->ReadInteger("Power_off_SHCut");
  this->Config_SHCut                   = reg->ReadInteger("Config_SHCut");
  this->Static_info_SHCut              = reg->ReadInteger("Static_info_SHCut");

  reg->CloseKey();
  delete reg;
};

//------------------------------------------------------------------------------
void _TSave_configuration::Read_inifile()
{
   if (this->Check_Ini() == false)
   {
	this->default_init();
	this->Read_shell(false);
	return;
   };

   TIniFile* I_nf                        = new TIniFile(ExtractFilePath(Application->ExeName)+"date\\config.ini");
  this->Url                              = I_nf->ReadString("General","Url","");
  this->Choose_printer                   = I_nf->ReadString("General","Choose_printer","");
  this->Automatics_run                   = I_nf->ReadBool("General","Automatics_run","");
  this->Regularity_of_printing_by_time   = I_nf->ReadString("General","Regularity_of_printing_by_time","");
  this->Program_run_time                 = I_nf->ReadBool("General","Program_run_time","");
  this->Timer                            = I_nf->ReadBool("General","Timer","");
  this->Registry                         = I_nf->ReadBool("General","Registry","");
  this->Inifile                          = I_nf->ReadBool("General","Inifile","");
  this->Starting_program                 = I_nf->ReadBool("General","Starting_program","");
  this->Starting_windows                 = I_nf->ReadBool("General","Starting_windows","");
  this->Open_SHCut                       = I_nf->ReadInteger("ShortCut","Open_SHCut",0);
  this->Save_SHCut                       = I_nf->ReadInteger("ShortCut","Save_SHCut",0);
  this->Save_as_SHCut                    = I_nf->ReadInteger("ShortCut","Save_as_SHCut",0);
  this->Fast_printing_SHCut              = I_nf->ReadInteger("ShortCut","Fast_printing_SHCut",0);
  this->Preview_SHCut                    = I_nf->ReadInteger("ShortCut","Preview_SHCut",0);
  this->Exit_SHCut                       = I_nf->ReadInteger("ShortCut","Exit_SHCut",0);
  this->Power_on_SHCut                   = I_nf->ReadInteger("ShortCut","Power_on_SHCut",0);
  this->Power_off_SHCut                  = I_nf->ReadInteger("ShortCut","Power_off_SHCut",0);
  this->Config_SHCut                     = I_nf->ReadInteger("ShortCut","Config_SHCut",0);
  this->Static_info_SHCut                = I_nf->ReadInteger("ShortCut","Static_info_SHCut",0);

   I_nf->Free();
   //delete I_nf;
};

//------------------------------------------------------------------------------
void _TSave_configuration::Save_shell(const bool& value)
{
   this->flag_source_save = value;

   if (value == true)
   {
	 Save_registry();
   }
   else
   {
	 Save_inifile();
   }
};

//------------------------------------------------------------------------------
void _TSave_configuration::Save_shell()
{
   if (this->flag_source_save == true)
   {
	 Save_registry();
   }
   else
   {
	 Save_inifile();
   }

};

//------------------------------------------------------------------------------
void _TSave_configuration::Save_registry()
{
  TRegistry* reg = new TRegistry;
  reg->RootKey  = HKEY_CURRENT_USER;
  reg->OpenKey("\\Software\\Robik\\Smart_printing\\",true);
  reg->WriteString("Url", this->Url);
  reg->WriteString("Choose_printer", this->Choose_printer);
  reg->WriteBool("Automatics_run",this->Automatics_run);
  reg->WriteString("Regularity_of_printing_by_time", this->Regularity_of_printing_by_time);
  reg->WriteBool("Program_run_time", this->Program_run_time);
  reg->WriteBool("Timer", this->Timer);
  reg->WriteBool("Registry", this->Registry);
  reg->WriteBool("Inifile", this->Inifile);
  reg->WriteBool("Starting_program", this->Starting_program);
  reg->WriteBool("Starting_windows", this->Starting_windows);
  reg->WriteInteger("Open_SHCut",this->Open_SHCut);
  reg->WriteInteger("Save_SHCut",this->Save_SHCut);
  reg->WriteInteger("Save_as_SHCut",this->Save_as_SHCut);
  reg->WriteInteger("Fast_printing_SHCut",this->Fast_printing_SHCut);
  reg->WriteInteger("Preview_SHCut",this->Preview_SHCut);
  reg->WriteInteger("Exit_SHCut",this->Exit_SHCut);
  reg->WriteInteger("Power_on_SHCut",this->Power_on_SHCut);
  reg->WriteInteger("Power_off_SHCut",this->Power_off_SHCut);
  reg->WriteInteger("Config_SHCut",this->Config_SHCut);
  reg->WriteInteger("Static_info_SHCut",this->Static_info_SHCut);
  reg->CloseKey();
  delete reg;
};

//------------------------------------------------------------------------------
void _TSave_configuration::Save_inifile()
{
 direct_r r;

	if (r.check_file(r.get_path()+"date\\") == false)
	{
	 std::string temp = "date\\";
	 r.create_folder_in_prog(temp,true);
	}

TIniFile* I_nf = new TIniFile(ExtractFilePath(Application->ExeName)+"date\\config.ini");
 I_nf->WriteString("General","Url",this->Url);
 I_nf->WriteString("General","Choose_printer",this->Choose_printer);
 I_nf->WriteBool("General","Automatics_run",this->Automatics_run);
 I_nf->WriteString("General","Regularity_of_printing_by_time",this->Regularity_of_printing_by_time);
 I_nf->WriteBool("General","Program_run_time",this->Program_run_time);
 I_nf->WriteBool("General","Timer",this->Timer);
 I_nf->WriteBool("General","Registry",this->Registry);
 I_nf->WriteBool("General","Inifile",this->Inifile);
 I_nf->WriteBool("General","Starting_program",this->Starting_program);
 I_nf->WriteBool("General","Starting_windows",this->Starting_windows);
 I_nf->WriteInteger("ShortCut","Open_SHCut",this->Open_SHCut);
 I_nf->WriteInteger("ShortCut","Save_SHCut",this->Save_SHCut);
 I_nf->WriteInteger("ShortCut","Save_as_SHCut",this->Save_as_SHCut);
 I_nf->WriteInteger("ShortCut","Fast_printing_SHCut",this->Fast_printing_SHCut);
 I_nf->WriteInteger("ShortCut","Preview_SHCut",this->Preview_SHCut);
 I_nf->WriteInteger("ShortCut","Exit_SHCut",this->Exit_SHCut);
 I_nf->WriteInteger("ShortCut","Power_on_SHCut",this->Power_on_SHCut);
 I_nf->WriteInteger("ShortCut","Power_off_SHCut",this->Power_off_SHCut);
 I_nf->WriteInteger("ShortCut","Config_SHCut",this->Config_SHCut);
 I_nf->WriteInteger("ShortCut","Static_info_SHCut",this->Static_info_SHCut);
 I_nf->Free();
};

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
bool _TSave_configuration::Check_registry_incorrect()
{
	bool result;

	TRegistry* reg = new TRegistry;
	reg->RootKey   = HKEY_CURRENT_USER;
	reg->OpenKey("\\Software\\Robik\\Smart_printing\\",0);


		if ((reg->ValueExists("Url") == false) or (reg->ValueExists("Choose_printer") == false) or (reg->ValueExists("Automatics_run") == false)
		   or (reg->ValueExists("Regularity_of_printing_by_time") == false) or (reg->ValueExists("Program_run_time") == false)
		   or (reg->ValueExists("Timer")== false) or (reg->ValueExists("Registry") == false)
		   or (reg->ValueExists("Inifile") == false) or (reg->ValueExists("Starting_program") == false)
		   or (reg->ValueExists("Starting_windows") == false))
		   {
			result = false;
		   }
		   else
		   {
			result = true;
		   }



	reg->CloseKey();
	delete reg;
	return result;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::Check_registry()
{
	bool result = false;

	if (this->Check_registry_incorrect()==false)
	{
	return result = false;
	};

  TRegistry* reg                       = new TRegistry;
  reg->RootKey                         = HKEY_CURRENT_USER;
  reg->OpenKey("\\Software\\Robik\\Smart_printing\\",0);
 try
	{
	 bool b_t = false;
	 AnsiString s_t;


	 s_t            = reg->ReadString("Url");
	 s_t            = reg->ReadString("Choose_printer");
	 b_t            = reg->ReadBool("Automatics_run");
	 s_t            = reg->ReadString("Regularity_of_printing_by_time");
	 b_t            = reg->ReadBool("Program_run_time");
	 b_t            = reg->ReadBool("Timer");
	 s_t            = reg->ReadString("Them");
	 b_t            = reg->ReadBool("Registry");
	 b_t            = reg->ReadBool("Inifile");
	 b_t            = reg->ReadBool("Starting_program");
	 b_t            = reg->ReadBool("Starting_windows");
	 result = true;
	}
	catch (std::exception& value)
	{


	 AnsiString msg = "При чтении Из реестра Windows вышло ошибка,\n программа исправила эту ошибку \n и перезаписала Ini файл!";


	 result = false;

	};

	reg->CloseKey();
	delete reg;


   return result;

};

//------------------------------------------------------------------------------
bool _TSave_configuration::Check_Ini()
{
 bool result = false;

 if (this->Check_Ini_file()==false)
 {
  return result = false;
 };

  TIniFile* I_nf = new TIniFile(ExtractFilePath(Application->ExeName)+"date\\setup.ini");
 try
	{
	 bool b_t = false;
	 AnsiString s_t;


	 s_t            = I_nf->ReadString("General","Url","");
	 s_t            = I_nf->ReadString("General","Choose_printer","");
	 b_t            = I_nf->ReadBool("General","Automatics_run","");
	 s_t            = I_nf->ReadString("General","Regularity_of_printing_by_time","");
	 b_t            = I_nf->ReadBool("General","Program_run_time","");
	 b_t            = I_nf->ReadBool("General","Timer","");
	 s_t            = I_nf->ReadString("General","Them","");
	 b_t            = I_nf->ReadBool("General","Registry","");
	 b_t            = I_nf->ReadBool("General","Inifile","");
	 b_t            = I_nf->ReadBool("General","Starting_program","");
	 b_t            = I_nf->ReadBool("General","Starting_windows","");
	 result = true;
	}
	catch (std::exception& value)
	{


	 AnsiString msg = "При чтении Ini файла вышло ошибка,\n программа исправила эту ошибку \n и перезаписала Ini файл!";


	 result = false;

	};

	 I_nf->Free();
	 //delete I_nf;


   return result;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::Check_Ini_file()
{
	bool result = false;
		 if (FileExists(ExtractFilePath(Application->ExeName)+"date\\config.ini") == true)
		 {
		  result = true;
		 }
		 else
		 {
		  result = false;
		 }
  return result;
};

//------------------------------------------------------------------------------
bool _TSave_configuration::Check_url()
{
bool result = false;

   direct_r p;
   std::string files = "date\\url.txt";


//		if (p.check_file(files) == true)
		if (FileExists(ExtractFilePath(Application->ExeName)+"date\\url.txt") == true)
		{
		 return result = true;
		}
		else
		{

		 return result = false;
		};



};

//------------------------------------------------------------------------------
void _TSave_configuration::default_init()
{
	this->Url                              = "https://moda.captain.business/p.php?api=123456789";
	this->Choose_printer                   = "Не выбран";
	this->Automatics_run                   = false;
	this->Regularity_of_printing_by_time   = "00:10:00";
	this->Program_run_time                 = true;
	this->Timer                            = true;
	this->Registry                         = false;
	this->Inifile                          = true;
	this->Starting_program                 = true;
	this->Starting_windows                 = true;
	this->initilisation();
};

//------------------------------------------------------------------------------
void _TSave_configuration::Clear_dates()
{
   if (MessageDlg("Очистить сохраненные данные приложение?", mtConfirmation,
   TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)

			{
			  this->Delete_file_(std::string("date\\config.ini"));
//			  this->Delete_file_(std::string("date\\printer.txt"));
			  this->Delete_file_(std::string("date\\url.txt"));

			  TRegistry* reg = new TRegistry;
			  reg->RootKey  = HKEY_CURRENT_USER;
			  reg->OpenKey("\\Software\\Robik\\Smart_printing\\",false);

				reg->DeleteValue("Url");
				reg->DeleteValue("Choose_printer");
                reg->DeleteValue("automatics_run");
				reg->DeleteValue("Regularity_of_printing_by_time");
				reg->DeleteValue("Program_run_time");
				reg->DeleteValue("Timer");
				reg->DeleteValue("Registry");
				reg->DeleteValue("Inifile");
				reg->DeleteValue("Starting_program");
				reg->DeleteValue("Starting_windows");
				reg->DeleteValue("Open_SHCut");
				reg->DeleteValue("Save_SHCut");
				reg->DeleteValue("Save_as_SHCut");
				reg->DeleteValue("Fast_printing_SHCut");
				reg->DeleteValue("Preview_SHCut");
				reg->DeleteValue("Exit_SHCut");
				reg->DeleteValue("Power_on_SHCut");
				reg->DeleteValue("Power_off_SHCut");
				reg->DeleteValue("Config_SHCut");
				reg->DeleteValue("Static_info_SHCut");
				reg->DeleteValue("(По умолчанию)");
				reg->DeleteKey("\\Software\\Robik\\Smart_printing");
				reg->CloseKey();

			 delete reg;
			}

};

//------------------------------------------------------------------------------
bool _TSave_configuration::Delete_file_(const std::string& FileName)
{
 direct_r p;
 bool result = false;


 if (p.check_file(std::string(FileName)) == true)
 {
   result = p.delete_this_file(FileName);
 }
 else
 {
  result = false;
 };

 return result;

};

//------------------------------------------------------------------------------
bool _TSave_configuration::step_one()// Find the source of the save
{
 bool result = false;

if (FileExists(ExtractFilePath(Application->ExeName)+AnsiString("date\\config.ini")) == true)
 {


   bool tmp = false;
   try
   {

	 TIniFile* I_nf = new TIniFile(ExtractFilePath(Application->ExeName)+"date\\config.ini");
	 tmp = I_nf->ReadBool("General","Inifile","");
		if (tmp == true)
		{
		 this->Read_shell(false);
		 I_nf->Free();
		 return true;
		}
		else
		{
		 this->Read_shell(true);
		 I_nf->Free();
		 return true;
		}

		return result = tmp;
   }
   catch(std::exception& value)
   {
	  this->Read_shell(false);
	  return result = false;

   }
 };


 TRegistry* reg = new TRegistry;
 reg->RootKey                         = HKEY_CURRENT_USER;
 reg->OpenKey("\\Software\\Robik\\Smart_printing\\",0);
   if (reg->ValueExists("Registry") == true)
   {
	  if (reg->ReadBool("Registry") == true)
		{
		 this->Read_shell(true);
		 reg->CloseKey();
		 delete reg;
		 return true;
		}
		else
		{
		 if (FileExists(ExtractFilePath(Application->ExeName)+"date\\config.ini") == true)
		 {
		 this->Read_shell(false);
		 reg->CloseKey();
		 delete reg;
		 return true;
		 }
		}

   }


   return result;
};

//------------------------------------------------------------------------------
AnsiString& _TSave_configuration::Create_inifile_path(AnsiString& path)
{
   for (int i = 0; i < path.Length(); i++)
   {
	 if (path[i] == char(92))
	 {
	  path[i] = char(47);
	 }
   }

   return path;
};

//------------------------------------------------------------------------------
void _TSave_configuration::initilisation()
{
  this->flag_source_save      = true;
  this->flag_Registry         = false;
  this->flag_program_files    = false;
  this->flag_Inifile          = false;

  this->Open_SHCut            = 0;
  this->Save_SHCut            = 0;
  this->Save_as_SHCut         = 0;
  this->Fast_printing_SHCut   = 0;
  this->Preview_SHCut         = 0;
  this->Exit_SHCut            = 0;
  this->Power_on_SHCut        = 0;
  this->Power_off_SHCut       = 0;
  this->Config_SHCut          = 0;
  this->Static_info_SHCut     = 0;
};
//------------------------------------------------------------------------------
//-------------------------------END-----------------------------------------------
