/*
 * main.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 *
 */

/*! \mainpage Project for Advanced Programming at University of Antwerp
 *
 * \section intro_sec Introduction
 *
 * The goal was to make a game similar to space invaders.
 *
 * \section install_sec Installation
 *
 * To install this program, some requirements are needed.
 * I.e. : SFML-2.1 & CMake 2.6 or higher
 *
 * Installation :
 * \li 1) Open up terminal & navigate to this folder (i.e. "/WhateverPathYouChose/Space-Invaders")
 * \li 2) Make a new directory, usually named "build" (i.e. "mkdir build")
 * \li 3) Change to the new directory (i.e. "cd <name-of-new-folder>")
 * \li 4) Type "cmake .." followed by "make install"
 * \li 5) Switch to the bin folder & run the program (i.e. "cd ../bin" followed by "./Space-Invaders")
 *	remark : the program MUST be ran from the 'bin' folder,
 *		otherwise problems are caused with the font
 *
 * Uninstall procedure :
 * \li 1) Open up terminal & navigate to this folder (i.e. "/WhateverPathYouChose/Space-Invaders")
 * \li 2) Remove <name-of-new-folder> which was created upon installation
 * \li 3) Remove the executable in the 'bin' folder & leave default.tff intact.
 *
 */

#include "Model/SpaceInvaders.h"
#include "View/GWSI.h"
#include "Controller/GISI.h"

/**
 *  \file main.cpp
 *  \brief Everything starts in this file.
 *
 *  This file contains the 'main' function & a delay function to make sure the game doesn't
 *  immediately start if you pressed enter too long, i.e. while executing the program in
 *  a terminal.
 */


/**
 *  \namespace AR
 *  \brief A namespace to bundle the work.
 */
using namespace AR;

void Delay() //half second delay
{
	std::chrono::time_point<std::chrono::system_clock> t1;
	t1 = std::chrono::system_clock::now();
	while(true)
	{
		std::chrono::duration<double> diff = std::chrono::system_clock::now() - t1;
		if( diff.count() > 0.5 ) return;
	}
}

/**
 *  \fn main
 *  \brief The entry point of the program.
 *
 *  The main function is responsible for the game-loop. Besides that, 'main' will deal
 *  with any exceptions that may be thrown outside the 'Update' function from the 'Model'
 *  (or classes derived from 'Model').
 */
int main(int argc, char* argv[])
{
	try
	{
		GameState* M = new SpaceInvaders;
		GameWindow* V = new GWSI;
		GameInput* C = new GISI;
		Delay(); //so that the game doesn't get started immediately if you push enter too long
		while( V->Open() )
		{
			//inputs
			if( C->CloseGame(V->getWindow()) ) { V->Close(); break; }
			else if( C->StartGame() and !M->Started() ) { M->StartGame(); }
			else if( C->PauseGame() and !M->Paused() ) { M->PauseGame(); }
			else if( C->ResumeGame() and M->Paused() ) { M->ResumeGame(); }
			else if ( C->ResumeGame() and M->GameOver() ) { M->Reset(); }

			//update model
			//may want to add a timeout so that the game's speed stays locked
			//thus, resulting into uniform game speed on different machines
			if( M->Started() and !M->Paused() and !M->GameOver() )
			{
				try
				{
					//still need to know which player in case of multiplayer...
					if( C->Fire() and M->NoBullets() ) { M->PlayerFires(); }
					if( C->MoveLeft() ) { M->MovePlayerLeft(); }
					if( C->MoveRight() ) { M->MovePlayerRight(); }
					M->Update();
				} catch (GameException& ge) {
					//should never be the case though
					std::cout << "Fatal Error! Terminating with ErrorCode "
							<< ge.ErrorCode() << std::endl;
					if( M != 0 ) delete M;
					if( V != 0 ) delete V;
					if( C != 0 ) delete C;
					return 0;
				} catch (std::exception& e) { std::cout << e.what() << std::endl;
				} catch (...) { std::cout << "Unknown exception occurred." << std::endl; }
			}
			//output
			V->Update(M->Started(), M->Paused(), M->GameOver(),
					M->GetObjects(), M->GetLevel());
		}
		delete M;
		delete V;
		delete C;
	} catch (std::exception& e) { std::cout << e.what() << std::endl;
	} catch (...) { std::cout << "Unknown exception occurred." << std::endl; }
	return 0;
}

// TODO: Doxygen comments

//feedback : MVC-> ok
//			Observer pattern-> nok -> do if time left
//			Abstract factory-> used in View to create shapes
//				Keeping AddObject instead of using a factory for the sake of time
//					reasoning: any game derived from GameState has to implement this
//					therefor, every game will have it's own internal factory
//			SFML outside model-> should be ok now
//
//feedback2 : everything seems ok, besides observer

