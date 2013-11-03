#pragma once
#include "Elements.h"
#include "CloseButton.h"
using namespace System;
using namespace System::Drawing;

namespace MyCalendar {
	public ref class EventText : Element {
	protected:
		CloseButton^ closeButton;
		String^ title;
		String^ description;
		SolidBrush^ brush;
		Font^ font;
		FontFamily^ fontFamily;
		int textHeight;
		int textWidth;
		bool expanded;

	public:
		Rectangle^ border;
		EventText(Point p, String^ title, String^ description) : expanded(false) {
			this->fontFamily = gcnew FontFamily(L"Arial");
			this->font = gcnew System::Drawing::Font(fontFamily, 10, FontStyle::Regular, GraphicsUnit::Point);
			this->color = Color::Black;
			brush = gcnew SolidBrush(color);
			position = p;
			this->title = title;
			this->description = description;
			this->font = font;
			textHeight = font->Height;
			textWidth = static_cast<int>(font-> Size * title-> Length);
			border = gcnew Rectangle(Color::Gray, position, 255, textHeight + 15);
			boundRect = System::Drawing::Rectangle(position, Size(textWidth, textHeight));
			boundRect.Inflate(2,2);
		}
		
		void SetPosition(Point p) {
			Element::SetPosition(p);
			border->SetPosition(p);
			boundRect.Location = p;
		}

		void toggleFrame() {
			expanded ? resetFrame() : expandFrame();
		}

		void expandFrame() {
			border->height = font->Height + 60;
			expanded = true;
		}

		void resetFrame() {
			border->height = font->Height + 15;
			expanded = false;
		}

		bool isExpanded() {
			return expanded;
		}

		void drawDescription(Graphics^ g) {
			g->DrawString(description, font, brush, Point(15, (textHeight + 20)));
		}

		void drawTitle(Graphics^ g) {
			g->DrawString(title, font, brush, Point(15, (textHeight/2)));
		}

		virtual void Draw(Graphics^ g) override {
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			drawTitle(g);
			if (expanded) { drawDescription(g); }
			g->ResetTransform();
			closeButton = gcnew CloseButton(Point(position.X + 230, position.Y + 8));
			border->Draw(g);
			closeButton->Draw(g);
		}

		bool CloseClicked(Point clickedSpot) {
			return closeButton->Contains(clickedSpot);
		}

		bool FrameClicked(Point clickedSpot) {
			return (border->Contains(clickedSpot) && !CloseClicked(clickedSpot));
		}
	};
}
