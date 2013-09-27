#pragma once
#include "Elements.h"
using namespace System;
using namespace System::Drawing;

namespace MyCalendar {
	public ref class EventText : Element {
	protected: 
		String^ text;
		SolidBrush^ brush;
		Font^ font;
		Rectangle^ border;
		int textHeight;
		int textWidth;

	public:
		EventText(Color color, Point p, String^ text, Font^ font) {
			this->color = color;
			brush = gcnew SolidBrush(color);
			position = p;
			this->text = text;
			this->font = font;
			textHeight = font->Height;
			textWidth = static_cast<int>(font-> Size * text-> Length);
			border = gcnew Rectangle(Color::LightBlue, position, 240, textHeight + 20);
			boundRect = System::Drawing::Rectangle(position, Size(textWidth, textHeight));
			boundRect.Inflate(2,2);
		}

		virtual void Draw(Graphics^ g) override {
			brush->Color = color;
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			g->DrawString(text, font, brush, Point(10, (textHeight/2 - 4)));
			g->ResetTransform();
			border->Draw(g);
		}
	};
}
