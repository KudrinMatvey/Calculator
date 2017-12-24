#include "stdafx.h"
#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ConsoleApplication1::MyForm()); 
	return 0;

}