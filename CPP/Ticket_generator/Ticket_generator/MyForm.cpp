#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Reflection;

[assembly:AssemblyVersionAttribute("4.3.2.1")];
namespace DesignLibrary {}

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Ticketgenerator::MyForm form;
	Application::Run(%form);
}