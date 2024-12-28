/*
 * Copyright 2012-2023 2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		John Scipione, jscipione@gmail.com
 */


#include "CrayonPickerApp.h"

#include <ColorPickerPanel.h>
#include <LayoutBuilder.h>
#include <PickerProtocol.h>
#include <Window.h>

#include "CrayonPicker.h"


const char* kSignature = "application/x-vnd.Haiku-CrayonPicker";


//	#pragma mark - CrayonPickerPanel


class CrayonPickerPanel : public BColorPickerPanel {
public:
					CrayonPickerPanel(CrayonPicker* view, BMessage* message);
	virtual			~CrayonPickerPanel();
};


CrayonPickerPanel::CrayonPickerPanel(CrayonPicker* view, BMessage* message)
	:
	BColorPickerPanel((BView*)view, message, BColorPickerPanel::B_CELLS_4x10,
		"Pick a color")
{
}


CrayonPickerPanel::~CrayonPickerPanel()
{
}


//	#pragma mark - CrayonPickerApp


CrayonPickerApp::CrayonPickerApp()
	:
	BApplication(kSignature),
	fPanel()
{
}


CrayonPickerApp::~CrayonPickerApp()
{
}


void
CrayonPickerApp::MessageReceived(BMessage* message)
{
	if (message->what == B_PICKER_INITIATE_CONNECTION) {
		// This is the initial open message that ModuleProxy::Invoke
		// is sending us. Pass it on to the new color picker dialog
		// where all the details will be found.
		fPanel = new CrayonPickerPanel(new CrayonPicker(), message);
	}

	BApplication::MessageReceived(message);
}


void
CrayonPickerApp::ReadyToRun()
{
	if (fPanel != NULL)
		fPanel->Show();
	else {
		// create a window if run directly
		BWindow* window = new BWindow(BRect(100, 100, 100, 100),
			"Pick a color", B_TITLED_WINDOW, B_NOT_ZOOMABLE
				| B_NOT_RESIZABLE | B_QUIT_ON_WINDOW_CLOSE
				| B_AUTO_UPDATE_SIZE_LIMITS);

		BLayoutBuilder::Group<>(window, B_VERTICAL, 0)
			.Add(new CrayonPicker())
			.End();
		window->Show();
	}
}


extern "C" BColorPickerPanel*
instantiate_color_picker(BView* view, BMessage* message,
	BColorPickerPanel::color_cell_layout layout, const char* name,
	window_look look, window_feel feel, uint32 flags, uint32 workspace)
{
	return new CrayonPickerPanel((CrayonPicker*)view, message);
}


int
main()
{
	new CrayonPickerApp();
	be_app->Run();
	delete be_app;

	return 0;
}
