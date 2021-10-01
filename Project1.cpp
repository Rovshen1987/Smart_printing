//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Web_browser_r.cpp", Web_browser);
USEFORM("Smart_printing.cpp", General_F);
USEFORM("Configuration.cpp", Configuration_F);
USEFORM("Preview.cpp", Preview_F);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TGeneral_F), &General_F);
		Application->CreateForm(__classid(TConfiguration_F), &Configuration_F);
		Application->CreateForm(__classid(TWeb_browser), &Web_browser);
		Application->CreateForm(__classid(TPreview_F), &Preview_F);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
