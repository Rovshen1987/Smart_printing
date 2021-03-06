#pragma once
#include <Registry.hpp>
#include <vector>
#include <IniFiles.hpp>
#include "direct_r.h"

class _TSave_configuration
{
public:
	   _TSave_configuration();
	   ~_TSave_configuration();

	   void set_Url(const AnsiString& value);
	   void set_Choose_printer(const AnsiString& value);
	   void set_Automatics_run(const bool& value);
	   void set_Regularity_of_printing_by_time(const AnsiString& value);
	   void set_Program_run_time(const bool& value);
	   void set_Timer(const bool& value);

	   void set_Registry(const bool& value);
	   void set_Inifile(const bool& value);
	   void set_Starting_program(const bool& value);
	   void set_Starting_windows(const bool& value);
//-------------Short_CUT-BEGIN()-SET---------------------------------------------
	   void set_Open_SHCut(const int& value);
	   void set_Save_SHCut(const int& value);
	   void set_Save_as_SHCut(const int& value);
	   void set_Fast_printing_SHCut(const int& value);
	   void set_Preview_SHCut(const int& value);
	   void set_Exit_SHCut(const int& value);
	   void set_Power_on_SHCut(const int& value);
	   void set_Power_off_SHCut(const int& value);
	   void set_Config_SHCut(const int& value);
	   void set_Static_info_SHCut(const int& value);
//-------------Short_CUT-END()--SET----------------------------------------------

	   bool step_to_run_program();


	   AnsiString      get_Url();
	   AnsiString      get_Choose_printer();
	   bool            get_Automatics_run();
	   AnsiString      get_Regularity_of_printing_by_time();
	   bool            get_Program_run_time();
	   bool            get_Timer();

	   bool            get_Registry();
	   bool            get_Inifile();
	   bool            get_Starting_program();
	   bool            get_Starting_windows();
//-------------Short_CUT-BEGIN()------------------------------------------------
	   int             get_Open_SHCut();
	   int             get_Save_SHCut();
	   int             get_Save_as_SHCut();
	   int             get_Fast_printing_SHCut();
	   int             get_Preview_SHCut();
	   int             get_Exit_SHCut();
	   int             get_Power_on_SHCut();
	   int             get_Power_off_SHCut();
	   int             get_Config_SHCut();
	   int             get_Static_info_SHCut();
//-------------Short_CUT-END()--------------------------------------------------

	   void            Save_shell(const bool& value);
	   void            Save_shell();
	   void            Read_shell(const bool& value);
	   void            Read_shell();
	   void            Save_registry();
	   void            Save_inifile();

	   void            Open_IniFile(const AnsiString& FileName);
       void            Save_AS_IniFile(const AnsiString& FileName);
private:
	   AnsiString      Url;  //Tag 0
	   AnsiString      Choose_printer; //Tag 1
	   bool            Automatics_run; //Tag 2
	   AnsiString      Regularity_of_printing_by_time;//Tag 3
	   bool            Program_run_time; //Tag4
	   bool            Timer; //Tag 5
	   bool            Registry; //Tag 6
	   bool            Inifile; //Tag 7
	   bool            Starting_program; //Tag 8
	   bool            Starting_windows; //Tag 9
//-------------Short_CUT-BEGIN()--Varible---------------------------------------
	   int             Open_SHCut;
	   int             Save_SHCut;
	   int             Save_as_SHCut;
	   int             Fast_printing_SHCut;
	   int             Preview_SHCut;
	   int             Exit_SHCut;
	   int             Power_on_SHCut;
	   int             Power_off_SHCut;
	   int             Config_SHCut;
	   int             Static_info_SHCut;
//-------------Short_CUT-END()--Varible---------------------------------------

	   bool            flag_Registry;
	   bool            flag_program_files;
	   bool            flag_Inifile;

//public:
	   bool            flag_source_save;


	   void            Read_resgistry();
	   void            Read_inifile();




	   bool            Check_registry();
	   bool            Check_registry_incorrect();
	   bool            Check_Ini();
	   bool            Check_Ini_file();
	   bool            Check_url();

	   void            default_init();
	   void            Clear_dates();
	   bool            Delete_file_(const std::string& FileName);

	   bool            step_one(); //Find the source of the save
	   AnsiString&     Create_inifile_path(AnsiString& path);

	   void            initilisation();

};
