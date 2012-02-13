
#include "3dsFileFormat.h"
#include "3dsFileLoader.h"
#include "AppFrame.h"

#include "Window.h"
#include "ViewControl.h"

void main()
{
	CViewControl Control("Manager");
	CAppFrame Finestra2("Demo", 10, 10, 400, 400);
	Control.AppendWindow(&Finestra2);
	Control.Start();
}
