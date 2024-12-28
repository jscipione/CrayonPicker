/*
 * Copyright 1999, Be Incorporated. All rights reserved.
 * Copyright 2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 * This file may be used under the terms of the Be Sample Code License.
 */
#ifndef CRAYON_PICKER_H
#define CRAYON_PICKER_H


#include <View.h>


const int32 kMaxCrayonCount = 48;


class BBitmap;
class Crayon;
class SelectedCrayon;


class CrayonPicker : public BView {
public:
								CrayonPicker(rgb_color color);
	virtual						~CrayonPicker();

	virtual	void				AttachedToWindow();
	virtual	void				MessageReceived(BMessage* message);

			rgb_color			Color() const { return fColor; };
			void				SetColor(rgb_color color);

private:
			rgb_color			fColor;
			SelectedCrayon*		fSelectedColor;
			Crayon*				fCrayonList[kMaxCrayonCount];
			int32				fCrayonCount;
};


#endif	// CRAYON_PICKER_H
