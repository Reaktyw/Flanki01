#include "MyForm1.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int Main()
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	Flanki01::MyForm1 form;
	Application::Run(% form);

    return 0;
}