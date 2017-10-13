#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	yazLabProject1::MainForm form;
	try {
		Application::Run(%form);
	}
	catch (...) {

	}
	

}