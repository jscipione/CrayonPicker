/*
 * Copyright 2012-2021 2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef CRAYON_PICKER_APP_H
#define CRAYON_PICKER_APP_H


#include <Application.h>


extern const char* kSignature;


class CrayonPickerPanel;

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
