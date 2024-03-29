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
	env()
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
	/*
	if (wnd.kbd.KeyIsPressed( VK_UP ))
	{
		square.testLinearMotion( {0.0f, -10.0f }, 1 );
	}
	if (wnd.kbd.KeyIsPressed( VK_LEFT ))
	{
		square.testLinearMotion( { -10.0f, 0.0f }, 1 );
	}
	if (wnd.kbd.KeyIsPressed( VK_DOWN ))
	{
		square.testLinearMotion( { 0.0f, 10.0f }, 1 );
	}
	if (wnd.kbd.KeyIsPressed( VK_RIGHT ))
	{
		square.testLinearMotion( { 10.0f, 0.0f }, 1 );
	}

	if (wnd.kbd.KeyIsPressed( VK_SPACE ))
	{
		square.Reset();
	}

	if (wnd.mouse.LeftIsPressed())
	{
		square.applyForce( { -5.0f, 5.0f }, Vec2( wnd.mouse.GetPos() ), 1 );
	}
	*/

	env.Update();
}

void Game::ComposeFrame()
{
	env.Draw( gfx );
}