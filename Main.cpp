#include <iostream>


#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <math.h>
using namespace std;

struct Vec2
{
	float x;
	float y;
};


class DrawPolygon : public olc::PixelGameEngine
{
public:
	DrawPolygon()
	{
		sAppName = "DrawPolygon demo";
	}
private:
	float r = 10.0f;
	Vec2 coords;

	void DrawHexagon(Vec2 coords, float radius)
	{
		float inr = radius * (sqrt(3) / 2);
		Vec2 corners[] = {
			{0.0f + coords.x, radius + coords.y},
			{inr + coords.x, (radius * 0.5f) + coords.y},
			{inr + coords.x, (radius * -0.5f) + coords.y},
			{0.0f + coords.x, -radius + coords.y},
			{-inr + coords.x, (radius * -0.5f) + coords.y},
			{-inr + coords.x, (radius * 0.5f) + coords.y}
		};
		for (int n = 0; n < 5; n++)
		{
			DrawLine(corners[n].x, corners[n].y, corners[n+1].x, corners[n+1].y, olc::WHITE);
		}
		DrawLine(corners[5].x, corners[5].y, corners[0].x, corners[0].y, olc::WHITE);
	}
	void DrawRPoplygon(Vec2 coords, float radius, int N, float rot)
	{
		float rotRad = rot * 3.14159265359/180;
		Vec2* corners = new Vec2[N];


		for (int n = 0; n < N; n++)
		{
			corners[n].x = radius * cos(2 * 3.14159265359 * n / N + rotRad) + coords.x;
			corners[n].y = radius * sin(2 * 3.14159265359 * n / N + rotRad) + coords.y;
		}
		for (int n = 0; n < N-1; n++)
		{
			DrawLine(corners[n].x, corners[n].y, corners[n + 1].x, corners[n +1].y, olc::WHITE);
		}
		DrawLine(corners[N-1].x, corners[N-1].y, corners[0].x, corners[0].y, olc::WHITE);
	}
public:
	bool OnUserCreate() override
	{
		coords.x = ScreenWidth() / 2;
		coords.y = ScreenHeight() / 2;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLUE);

		/*if (GetKey(olc::Key::W).bHeld)
		{
			coords.y -= 100 * fElapsedTime;
		}
		if (GetKey(olc::Key::S).bHeld)
		{
			coords.y += 100 * fElapsedTime;
		}
		if (GetKey(olc::Key::A).bHeld)
		{
			coords.x -= 100 * fElapsedTime;
		}
		if (GetKey(olc::Key::D).bHeld)
		{
			coords.x += 100 * fElapsedTime;
		}*/

		DrawRPoplygon(coords, 100, 6, 45);


		return true;
	}
};

int main()
{
	DrawPolygon demo;
	if (demo.Construct(400, 400, 2, 2, false, true))
	{
		demo.Start();
	}

    return true;
}

