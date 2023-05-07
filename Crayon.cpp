/*
 * Copyright 2012-2023 John Scipione All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		John Scipione, jscipione@gmail.com
 */


#include "Crayon.h"

#include <Bitmap.h>
#include <Message.h>
#include <Rect.h>


const color_space kCrayonColorSpace = B_COLOR_8_BIT;
const int32 kCrayonWidth = 20;
const int32 kCrayonHeight = 45;


const unsigned char kCrayonBits[] = {
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0x00,0x00,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b
};


const unsigned char kCrayonFilledBits[] = {
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0x00,0x00,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x1b,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x1b,0x1b,0x1b,
	0x1b,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x1b,
	0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b
};


//	#pragma mark - Crayon


Crayon::Crayon()
	:
	BControl(BRect(0, 0, kCrayonWidth - 1, kCrayonHeight - 1), "Crayon", "",
		new BMessage(B_VALUE_CHANGED), B_FOLLOW_NONE, B_WILL_DRAW),
	fColor((rgb_color) { 0, 0, 0 }),
	fIcon(NULL)
{
}


Crayon::Crayon(rgb_color color)
	:
	BControl(BRect(0, 0, kCrayonWidth - 1, kCrayonHeight - 1), "Crayon", "",
		new BMessage(B_VALUE_CHANGED), B_FOLLOW_NONE, B_WILL_DRAW),
	fColor(color),
	fIcon(NULL)
{
}


Crayon::~Crayon()
{
	delete fIcon;
}


void
Crayon::AttachedToWindow()
{
	fIcon = new BBitmap(Bounds(), kCrayonColorSpace, false, false);
}


void
Crayon::Draw(BRect updateRect)
{
	BRect frame(Bounds());

	PushState();
	SetHighColor(fColor);
	SetLowColor(Parent()->ViewColor());
	FillRect(frame);

	if (fIcon != NULL) {
		bool useFilled = fColor.red + fColor.green + fColor.blue <= 42 * 3;
		fIcon->SetBits(useFilled ? kCrayonFilledBits : kCrayonBits,
			kCrayonWidth * kCrayonHeight, 0, kCrayonColorSpace);
		SetDrawingMode(B_OP_OVER);
		DrawBitmap(fIcon, frame);
	}
	PopState();
}


status_t
Crayon::Invoke(BMessage* message)
{
	if (message == NULL)
		message = Message();

	message->RemoveName("be:value");
	message->AddData("be:value", B_RGB_COLOR_TYPE, &fColor, sizeof(fColor));
	message->RemoveName("when");
	message->AddInt64("when", (int64)system_time());

	return BControl::Invoke(message);
}


void
Crayon::MouseDown(BPoint where)
{
	Invoke();
	BControl::MouseDown(where);
}


rgb_color
Crayon::Color() const
{
	return fColor;
}


void
Crayon::SetColor(rgb_color color)
{
	color.alpha = 255;
	fColor = color;
	if (Window())
		Invalidate(Bounds());
}
