#include "general_visable.h"

//--------------------CONSTRUCTOR-----------------------------------------------
general_visable::general_visable()
{
   this->Accept_default();
  // this->Power_on();
};

//--------------------DESSTRUCTOR-----------------------------------------------
general_visable::~general_visable()
{

};

//---------------------PUBLIC_SECTION-------------------------------------------

//-------------------SET--------------------------------------------------------
void general_visable::set_Open_TOP(const bool& value)
{
   this->Open_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Save_TOP(const bool& value)
{
   this->Save_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Fast_printing_TOP(const bool& value)
{
   this->Fast_printing_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Preview_TOP(const bool& value)
{
   this->Preview_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Power_on_TOP(const bool& value)
{
   this->Power_on_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Power_off_TOP(const bool& value)
{
   this->Power_off_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Config_TOP(const bool& value)
{
   this->Config_TOP = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Open_N(const bool& value)
{
   this->Open_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Save_N(const bool& value)
{
   this->Save_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Save_as_N(const bool& value)
{
   this->Save_as_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Fast_printing_N(const bool& value)
{
   this->Fast_printing_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Preview_N(const bool& value)
{
   this->Preview_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Configuring_printer_N(const bool& value)
{
   this->Configuring_printer_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Power_on_N(const bool& value)
{
   this->Power_on_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Power_off_N(const bool& value)
{
   this->Power_off_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Config_N(const bool& value)
{
   this->Config_N = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Save_BB(const bool& value)
{
   this->Save_BB = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Choose_printer_BB(const bool& value)
{
   this->Choose_printer_BB = value;
};


//------------------------------------------------------------------------------
void general_visable::set_Url_E(const bool& value)
{
   this->Url_E = value;
};

//------------------------------------------------------------------------------
void general_visable::set_Choose_printer_CB(const bool& value)
{
   this->Choose_printer_CB = value;
};

//------------------------------------------------------------------------------
void general_visable::run_e(TBitBtn* object, const bool& value)
{
  if (object->Enabled != value)
  {  if (value == true)
	 {
	  object->Enabled = true;
	 }
	 else
	 {
	  object->Enabled = false;
	 }

  };
};

//------------------------------------------------------------------------------
void general_visable::run_e(TToolButton* object,const bool& value)
{
  if (object->Enabled != value)
  {
   object->Enabled = value;
  };
};

//------------------------------------------------------------------------------
void general_visable::run_e(TMenuItem* object,const bool& value)
{
  if (object->Enabled != value)
  {
   object->Enabled = value;
  };
};

//------------------------------------------------------------------------------
void general_visable::run_e(TComboBox* object,const bool& value)
{
  if (object->Enabled != value)
  {
   object->Enabled = value;
  };
};

void general_visable::run_e(TEdit* object,const bool& value)
{
   if (object->Enabled != value)
  {
   object->Enabled = value;
  };
};

//------------------------------------------------------------------------------
//-------------------GET--------------------------------------------------------
bool general_visable::get_Open_TOP()
{
   return this->Open_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Save_TOP()
{
	return this->Save_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Fast_printing_TOP()
{
   return this->Fast_printing_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Preview_TOP()
{
   return this->Preview_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Power_on_TOP()
{
   return this->Power_on_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Power_off_TOP()
{
   return this->Power_off_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Config_TOP()
{
   return this->Config_TOP;
};

//------------------------------------------------------------------------------
bool general_visable::get_Open_N()
{
   return this->Open_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Save_N()
{
   return this->Save_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Save_as_N()
{
   return this->Save_as_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Fast_printing_N()
{
   return this->Fast_printing_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Preview_N()
{
   return this->Preview_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Configuring_printer_N()
{
   return this->Configuring_printer_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Power_on_N()
{
   return this->Power_on_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Power_off_N()
{
   return this->Power_off_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Config_N()
{
   return this->Config_N;
};

//------------------------------------------------------------------------------
bool general_visable::get_Save_BB()
{
   return this->Save_BB;
};

//------------------------------------------------------------------------------
bool general_visable::get_Choose_printer_BB()
{
   return this->Choose_printer_BB;
};

//------------------------------------------------------------------------------
bool general_visable::get_Url_E()
{
   return this->Url_E;
};

//------------------------------------------------------------------------------
bool general_visable::get_Choose_printer_CB()
{
   return this->Choose_printer_CB;
};

//------------------------------------------------------------------------------
//---------Configuration_LIST_begin()-------------------------------------------
void general_visable::Accept_power_on()
{
	this->Open_TOP               = false;
	this->Save_TOP               = false;
	this->Fast_printing_TOP      = true;
	this->Preview_TOP            = false;
	this->Power_on_TOP           = false;
	this->Power_off_TOP          = true;
	this->Config_TOP             = false;

	this->Open_N                 = false;
	this->Save_N                 = false;
	this->Save_as_N              = false;
	this->Fast_printing_N        = false;
	this->Preview_N              = false;
	this->Configuring_printer_N  = false;
	this->Power_on_N             = false;
	this->Power_off_N            = true;
	this->Config_N               = false;

	this->Url_E                  = false;
	this->Choose_printer_CB      = false;
	this->Save_BB                = false;
	this->Choose_printer_BB      = false;
};

void general_visable::Accept_default()
{
	this->Open_TOP               = true;
	this->Save_TOP               = true;
	this->Fast_printing_TOP      = true;
	this->Preview_TOP            = true;
	this->Power_on_TOP           = true;
	this->Power_off_TOP          = false;
	this->Config_TOP             = true;

	this->Open_N                 = true;
	this->Save_N                 = false;
	this->Save_as_N              = true;
	this->Fast_printing_N        = true;
	this->Preview_N              = true;
	this->Configuring_printer_N  = true;
	this->Power_on_N             = true;
	this->Power_off_N            = false;
	this->Config_N               = true;

	this->Url_E                 = true;
	this->Choose_printer_CB      = true;
	this->Save_BB                = false;
	this->Choose_printer_BB      = false;

};

//---------Configuration_LIST_end()-------------------------------------------

//---------------------PRIVATE_SECTION------------------------------------------

//------------------------------------------------------------------------------
bool general_visable::swap_bool(bool value)
{
  bool result;

  if (value == true)
  {
   result = false;
  }
  else
  {
   result = true;
  }

  return result;
};
