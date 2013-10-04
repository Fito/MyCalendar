#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace MyCalendar {
	public ref class Element abstract {
	protected: 
		Point position;
		Color color;
		System::Drawing::Rectangle boundRect;
		Color hoveredColor;

	public:
		Pen^ pen;
		virtual void Draw(Graphics^ g) abstract;
		Point^ GetPosition() { return position; }
		void SetPosition( Point newPosition ) { this->position = newPosition; }
		bool hovered;
		property System::Drawing::Rectangle bound {
			System::Drawing::Rectangle get() { return boundRect; }
		}

		Element() : hoveredColor(Color::LightBlue) {
			hovered = false;
		}

		bool Contains(Point p) {
			return boundRect.Contains(p);
		}
	};

	public ref class Line : Element {
	protected:
		Point end;
	public:
		Line(Color color, Point start, Point end) {
			this->color = color;
			position = start;
			this->end = end;
			boundRect = System::Drawing::Rectangle(
				Math::Min(position.X, end.X),
				Math::Min(position.Y, end.Y),
				Math::Abs(position.X - end.X),
				Math::Abs(position.Y - end.Y)
			);
			pen = gcnew Pen(color);

			if(boundRect.Width < 2) boundRect.Width = 2;
			if(boundRect.Height < 2) boundRect.Height = 2;
		}

		virtual void Draw(Graphics^ g) override{
			g->DrawLine(pen, position, end);
		}
	};

	public ref class Rectangle : Element {
	public:
		int width;
		int height;

		Rectangle(Color color, Point p1, Point p2) {
			pen = gcnew Pen(color);
			this->color = color;
			position = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y,p2.Y));
			width = Math::Abs(p1.X - p2.X);
			height = Math::Abs(p1.Y - p2.Y);
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
		}

		Rectangle(Color color, Point point, int arg_width, int arg_height) {
			Point p2 = Point(point.X + arg_width, point.Y + arg_height);
			position = Point(Math::Min(point.X, p2.X), Math::Min(point.Y,p2.Y));
			pen = gcnew Pen(color);
			this->color = color;
			width = arg_width;
			height = arg_height;
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
			boundRect.Inflate(2,2);
		}
	
		virtual void Draw(Graphics^ g) override {
			pen->Color = hovered ? hoveredColor : color;
			g->DrawRectangle(pen, position.X, position.Y, width, height);
		}
	};
}