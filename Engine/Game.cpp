/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Rect.h"
#include "ChiliWin.h"
#include <sstream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	link( {50, 50} )
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	Vec2 dir = {0.0f, 0.0f};
	if (wnd.kbd.KeyIsPressed( VK_RIGHT ))
	{
		dir = Directions::RIGHT;
	}
	if (wnd.kbd.KeyIsPressed( VK_LEFT ))
	{
		dir = Directions::LEFT;
	}
	if (wnd.kbd.KeyIsPressed( VK_UP ))
	{
		dir = Directions::UP;
	}
	if (wnd.kbd.KeyIsPressed( VK_DOWN ))
	{
		dir = Directions::DOWN;
	}
	link.SetDirection( dir );
	link.Update( ft.Mark() );
}

void Game::ComposeFrame()
{
	font.DrawText( "The quick brown fox!\njumped over", wnd.mouse.GetPos(), gfx );
	link.Draw( gfx );
}