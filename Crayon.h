/*
 * Copyright 2012-2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef CRAYON_H
#define CRAYON_H


#include <Control.h>


class BBitmap;
class BMessage;
class BPoint;
class BRect;


class Crayon : public BControl {
public:
								Crayon();
								Crayon(rgb_color color);
	virtual						~Crayon();

	virtual	void				AttachedToWindow();
	virtual	void				Draw(BRect updateRect);
	virtual status_t			Invoke(BMessage* message = NULL);
	virtual	void				MouseDown(BPoint where);
	virtual	void				MouseUp(BPoint where);

			rgb_color			Color() const;
			void				SetColor(rgb_color color);

protected:
			rgb_color			fColor;
			BBitmap*			fIcon;

private:
			BMessage*			fMouseDownMessage;
};


#endif	// CRAYON_H
