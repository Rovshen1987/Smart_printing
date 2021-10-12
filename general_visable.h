#pragma once
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>

class general_visable
{
public:
	 general_visable();
	~general_visable();

//-------------------SET--------------------------------------------------------
	void  set_Open_TOP(const bool& value);
	void  set_Save_TOP(const bool& value);
	void  set_Fast_printing_TOP(const bool& value);
	void  set_Preview_TOP(const bool& value);
	void  set_Power_on_TOP(const bool& value);
	void  set_Power_off_TOP(const bool& value);
	void  set_Config_TOP(const bool& value);

	void  set_Open_N(const bool& value);
	void  set_Save_N(const bool& value);
	void  set_Save_as_N(const bool& value);
	void  set_Fast_printing_N(const bool& value);
	void  set_Preview_N(const bool& value);
	void  set_Configuring_printer_N(const bool& value);
	void  set_Power_on_N(const bool& value);
	void  set_Power_off_N(const bool& value);
	void  set_Config_N(const bool& value);

	void  set_Save_BB(const bool& value);
	void  set_Choose_printer_BB(const bool& value);
	void  set_Url_CB(const bool& value);
	void  set_Choose_printer_CB(const bool& value);

//-------------------GET--------------------------------------------------------
	bool  get_Open_TOP();
	bool  get_Save_TOP();
	bool  get_Fast_printing_TOP();
	bool  get_Preview_TOP();
	bool  get_Power_on_TOP();
	bool  get_Power_off_TOP();
	bool  get_Config_TOP();

	bool  get_Open_N();
	bool  get_Save_N();
	bool  get_Save_as_N();
	bool  get_Fast_printing_N();
	bool  get_Preview_N();
	bool  get_Configuring_printer_N();
	bool  get_Power_on_N();
	bool  get_Power_off_N();
	bool  get_Config_N();

	bool  get_Save_BB();
	bool  get_Choose_printer_BB();
	bool  get_Url_CB();
	bool  get_Choose_printer_CB();

	void  Power_on();

	void run_e(TBitBtn* object,const bool& value);
	void run_e(TToolButton* object,const bool& value);
	void run_e(TMenuItem* object,const bool& value);
    void run_e(TComboBox* object,const bool& value);

private:

	bool  Open_TOP;
	bool  Save_TOP;
	bool  Fast_printing_TOP;
	bool  Preview_TOP;
	bool  Power_on_TOP;
	bool  Power_off_TOP;
	bool  Config_TOP;

	bool  Open_N;
	bool  Save_N;
	bool  Save_as_N;
	bool  Fast_printing_N;
	bool  Preview_N;
	bool  Configuring_printer_N;
	bool  Power_on_N;
	bool  Power_off_N;
	bool  Config_N;

	bool  Save_BB;
	bool  Choose_printer_BB;

	bool Url_CB;
	bool Choose_printer_CB;

	void standart_ok();
    bool swap_bool(bool value);



};