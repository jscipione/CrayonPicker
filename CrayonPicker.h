/*
 * Copyright 2012-2025 John Scipione. All rights reserved.
 * Copyright 1999, Be Incorporated. All rights reserved.
 *
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
								CrayonPicker();
	virtual						~CrayonPicker();

	virtual	void				AttachedToWindow();
	virtual	void				MessageReceived(BMessage* message);
	virtual	void				MouseDown(BPoint where);
	virtual	void				MouseMoved(BPoint where, uint32 code,
									const BMessage* dragMessage);
	virtual	void				MouseUp(BPoint where);

			rgb_color			Color() const { return fColor; };
			void				SetColor(rgb_color color);

private:
			rgb_color			fColor;
			SelectedCrayon*		fSelectedColor;
			int32				fCrayonCount;
			Crayon*				fCrayonList[kMaxCrayonCount];
			BPoint				fMouseOffset;
			bool				fMouseDown : 1;
};


#endif	// CRAYON_PICKER_H
