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
	   void set_Regularity_of_printing_by_time(const AnsiString& value);
	   void set_Program_run_time(const bool& value);
	   void set_Timer(const bool& value);

	   void set_Registry(const bool& value);
	   void set_Inifile(const bool& value);
	   void set_Starting_program(const bool& value);
	   void set_Starting_windows(const bool& value);

	   bool step_to_run_program();


	   AnsiString get_Url();
	   AnsiString get_Choose_printer();
	   AnsiString get_Regularity_of_printing_by_time();
	   bool       get_Program_run_time();
	   bool       get_Timer();

	   bool       get_Registry();
	   bool       get_Inifile();
	   bool       get_Starting_program();
	   bool       get_Starting_windows();

	   void            Save_shell(const bool& value);
	   void            Save_shell();
	   void            Read_shell(const bool& value);
	   void            Read_shell();
	   void            Save_registry();
	   void            Save_inifile();
private:
	   AnsiString      Url;  //Tag 0
	   AnsiString      Choose_printer; //Tag 1
	   AnsiString      Regularity_of_printing_by_time;//Tag 2
	   bool            Program_run_time; //Tag3
	   bool            Timer; //Tag 4
	   bool            Registry; //Tag 5
	   bool            Inifile; //Tag 6
	   bool            Starting_program; //Tag 7
	   bool            Starting_windows; //Tag 8

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
	   AnsiString&      Create_inifile_path(AnsiString& path);

};
