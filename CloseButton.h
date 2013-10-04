#pragma once
#include "Elements.h"
using namespace System;
using namespace System::Drawing;

namespace MyCalendar {
	public ref class CloseButton : Element {
	protected:
		Image^ image;

	public:
		CloseButton(Point position) : image(Image::FromFile("closebtn.png")) {
			boundRect = System::Drawing::Rectangle(position, Size(15, 15));
			boundRect.Inflate(2,2);
		}

		virtual void Draw(Graphics^ g) override {
			g->DrawImage(this->image, this->boundRect);
		}
	};
}