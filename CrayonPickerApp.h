/*
 * Copyright 2012-2021 2025 John Scipione. All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef CRAYON_PICKER_APP_H
#define CRAYON_PICKER_APP_H


#include <Application.h>
#include <ColorPickerPanel.h>


extern const char* kSignature;


using BPrivate::BColorPickerPanel;


class CrayonPicker;

class CrayonPickerPanel : public BColorPickerPanel {
public:
					CrayonPickerPanel(CrayonPicker* view, BMessage* message);
	virtual			~CrayonPickerPanel();
};

class CrayonPickerApp : public BApplication {
public:
								CrayonPickerApp();
	virtual						~CrayonPickerApp();

	virtual	void				MessageReceived(BMessage* message);
	virtual	void				ReadyToRun();

private:
			CrayonPickerPanel*	fPanel;
};


#endif	// CRAYON_PICKER_APP_H
