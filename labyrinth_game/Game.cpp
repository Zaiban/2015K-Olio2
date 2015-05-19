#include "Game.h"
#include "debug.hh"
#include "vaittama.hh"

Game::Game() :
mInitialization(true), mScreen(nullptr), mAreaSize(0), mActivePlayer(0), mHasPushed(false)
{}


Game::~Game()
{
	DEBUG_OUTPUT("Game destructor" << std::endl);
	if (debug_output)
		system("PAUSE");
}
bool Game::onkoAlustustilassa() const{
	return mInitialization;
}
void Game::lisaaNaytto(Julkinen::Nayttorajapinta* naytto){
	DEBUG_OUTPUT("lisaaNaytto()" << std::endl);
	mScreen = dynamic_cast<Naytto*>(naytto);
	mScreen->komentoAloitaRakennus();
}
void Game::maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko){
	mAreaSize = koko.haeXkoordinaatti();
}
void Game::lisaaPelaaja(Julkinen::PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti){
	DEBUG_OUTPUT("lisaaPelaaja()" << std::endl);

	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeXkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeYkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");

	mPlayers.push_back(Player(tyyppi, nimi, lyhenne, sijainti));
}
void Game::lisaaPala(Julkinen::PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti){
	DEBUG_OUTPUT("lisaaPala()" << std::endl);
	// TO-DO: ehdot
	mPieces.push_back(Piece(sijainti, pala, rotaatio));
}
void Game::lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja){
	DEBUG_OUTPUT("lisaaEsine()" << std::endl);

	for (int i = 0; i < mPieces.size(); i++){
		if (mPieces.at(i).getLocation() == sijainti)
			mPieces.at(i).setItem(merkki);
	}
	for (int i = 0; i < mPlayers.size(); i++){
		if (mPlayers.at(i).getName() == pelaaja){
			mPlayers.at(i).addTargetItem(merkki);
		}
	}
}
void Game::asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde){
	DEBUG_OUTPUT("asetaPalanTyyppi()" << std::endl);

	std::vector<Piece>::iterator currentPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
		return piece.getLocation() == sijainti;
	});
	currentPiece->setSpecialType(tyyppi);
	currentPiece->setTarget(kohde);
}
void Game::alustusLopeta(){
	DEBUG_OUTPUT("alustusLopeta()" << std::endl);

	updateScreen();
	mScreen->komentoLopetaRakennus();
	mInitialization = false;
	mScreen->ilmoitusVuorossa(mPlayers.at(mActivePlayer).getName());
}
bool Game::onkoPelitilassa() const{
	return !mInitialization;
}
void Game::komentoTyonna(Julkinen::Reuna reuna, unsigned int paikka, unsigned int rotaatio){
	DEBUG_OUTPUT("komentoTyonna()" << std::endl);

	// Perform checks
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 59, "vaihdaVuoro");

	if (mHasPushed){
		Julkinen::Toimintovirhe(Julkinen::Toimintovirhe::VIRHE_IRTOPALAA_ON_JO_TYONNETTY).tulosta(std::cout);
		std::cout << std::endl;
		mScreen->ilmoitusVuorossa(mPlayers.at(mActivePlayer).getName());
		return;
	}

	// Begin construction mode
	mScreen->komentoAloitaRakennus();
	mInitialization = true;

	// Get iterator to the piece of the opposite edge
	int x, y;
	switch (reuna){
	case Julkinen::ALA:
		y = 1;
		x = paikka;
		break;
	case Julkinen::YLA:
		y = mAreaSize;
		x = paikka;
		break;
	case Julkinen::OIKEA:
		x = 1;
		y = paikka;
		break;
	case Julkinen::VASEN:
		x = mAreaSize;
		y = paikka;
		break;
	}
	std::vector<Piece>::iterator detachPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
		return piece.getLocation() == Julkinen::Koordinaatti(x, y);
	});

	// Move pieces
	std::vector<Piece>::iterator movePiece;
	switch (reuna){
	case Julkinen::ALA:
		for (y += 1; y < (int)mAreaSize + 1; y++){
			movePiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			movePiece->setLocation(Julkinen::Koordinaatti(x, y - 1));
		}
		y--;
		break;
	case Julkinen::YLA:
		for (y -= 1; y > 0; y--){
			movePiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			movePiece->setLocation(Julkinen::Koordinaatti(x, y + 1));
		}
		y++;
		break;
	case Julkinen::OIKEA:
		for (x += 1; x < (int)mAreaSize + 1; x++){
			movePiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			movePiece->setLocation(Julkinen::Koordinaatti(x - 1, y));
		}
		x--;
		break;
	case Julkinen::VASEN:
		for (x -= 1; x > 0; x--){
			movePiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			movePiece->setLocation(Julkinen::Koordinaatti(x + 1, y));
		}
		x++;
		break;
	}

	// Move the current detached piece to empty slot
	std::vector<Piece>::iterator attachPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
		return piece.getLocation() == Julkinen::Koordinaatti();
	});
	attachPiece->setLocation(Julkinen::Koordinaatti(x, y));
	attachPiece->setRotation(rotaatio);

	// Set the original piece of opposite edge as the new detached piece
	detachPiece->setLocation(Julkinen::Koordinaatti());

	mHasPushed = true;

	updateScreen();

	mScreen->komentoLopetaRakennus();
	mScreen->ilmoitusVuorossa(mPlayers.at(mActivePlayer).getName());
	mInitialization = false;
}
void Game::komentoLiiku(Julkinen::Suunta suunta, unsigned int maara){
	DEBUG_OUTPUT("komentoLiiku()" << std::endl);
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 67, "vaihdaVuoro");

	// Perform checks

	if (suunta == Julkinen::AUTOMAATTI){
		handleCPU();
		return;
	}
	if (!mHasPushed){
		Julkinen::Toimintovirhe(Julkinen::Toimintovirhe::VIRHE_IRTOPALAA_EI_OLE_TYONNETTY).tulosta(std::cout);
		std::cout << std::endl;
		return;
	}
	if (maara > ULONG_MAX / 2){
		Julkinen::Komentovirhe(Julkinen::Komentovirhe::VIRHE_TUNNISTAMATON_PARAMETRI).tulosta(std::cout);
		std::cout << std::endl;
		return;
	}
	if (maara == 0 && suunta != Julkinen::Suunta::PAIKALLAAN){
		Julkinen::Komentovirhe(Julkinen::Komentovirhe::VIRHE_TUNNISTAMATON_PARAMETRI).tulosta(std::cout);
		std::cout << std::endl;
		return;
	}
	if (isWallCollision(suunta, maara)){
		Julkinen::Toimintovirhe(Julkinen::Toimintovirhe::VIRHE_EI_VOITU_LIIKKUA_ANNETTUA_MAARAA).tulosta(std::cout);
		return;
	}

	// Get players current coordinates
	int x = mPlayers.at(mActivePlayer).getLocation().haeXkoordinaatti();
	int y = mPlayers.at(mActivePlayer).getLocation().haeYkoordinaatti();
	switch (suunta){
	case Julkinen::ALAS:
		// Loop all the pieces in players path to collect items
		for (int limit = y + maara; y < limit + 1; y++){
			// Get iterator to the piece under the player
			std::vector<Piece>::iterator atPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			// If piece has item that matches players next target, collect it
			if (atPiece->getItem() == mPlayers.at(mActivePlayer).nextItem()){
				mPlayers.at(mActivePlayer).collectItem();
				atPiece->removeItem();
			}
		}
		y--;
		// Move the player
		mPlayers.at(mActivePlayer).setLocation(Julkinen::Koordinaatti(x, y));
		break;
	case Julkinen::YLOS:
		// Loop all the pieces in players path to collect items
		for (int limit = y - maara; y >= limit; y--){
			// Get iterator to the piece under the player
			std::vector<Piece>::iterator atPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			// If piece has item that matches players next target, collect it
			if (atPiece->getItem() == mPlayers.at(mActivePlayer).nextItem()){
				mPlayers.at(mActivePlayer).collectItem();
				mScreen->ilmoitusEsinePoimittu(atPiece->getItem(), mPlayers.at(mActivePlayer).getName());
				atPiece->removeItem();
			}
		}
		y++;
		// Move the player
		mPlayers.at(mActivePlayer).setLocation(Julkinen::Koordinaatti(x, y));
		break;
	case Julkinen::OIKEALLE:
		// Loop all the pieces in players path to collect items
		for (int limit = x + maara; x < limit + 1; x++){
			// Get iterator to the piece under the player
			std::vector<Piece>::iterator atPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			// If piece has item that matches players next target, collect it
			if (atPiece->getItem() == mPlayers.at(mActivePlayer).nextItem()){
				mPlayers.at(mActivePlayer).collectItem();
				atPiece->removeItem();
			}
		}
		x--;
		// Move the player
		mPlayers.at(mActivePlayer).setLocation(Julkinen::Koordinaatti(x, y));
		break;
	case Julkinen::VASEMMALLE:
		// Loop all the pieces in players path to collect items
		for (int limit = x - maara; x >= limit; x--){
			// Get iterator to the piece under the player
			std::vector<Piece>::iterator atPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});
			// If piece has item that matches players next target, collect it
			if (atPiece->getItem() == mPlayers.at(mActivePlayer).nextItem()){
				mPlayers.at(mActivePlayer).collectItem();
				atPiece->removeItem();
			}
		}
		x++;
		// Move the player
		mPlayers.at(mActivePlayer).setLocation(Julkinen::Koordinaatti(x, y));
		break;
	}


	if (suunta == Julkinen::PAIKALLAAN)
		mPlayers.at(mActivePlayer).setLastCommand(std::string("paikallaan"));
	else if (suunta != Julkinen::AUTOMAATTI){
		mPlayers.at(mActivePlayer).setLastCommand(std::string("liiku " + directionChar(suunta) + " " + std::to_string(maara)));
	}
}
bool Game::vaihdaVuoro(){
	DEBUG_OUTPUT("vaihdaVuoro()" << std::endl);

	// Perform checks
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 70, "vaihdaVuoro");

	// Check if someone won the game
	std::for_each(mPlayers.begin(), mPlayers.end(), [&](Player player){
		if (player.isWinner())
		{
			return false;
		}	
	});

	// Do things
	mHasPushed = false;
	mScreen->komentoAloitaRakennus();
	mInitialization = true;

	updateScreen();

	mScreen->komentoLopetaRakennus();
	mInitialization = false;

	if (mActivePlayer == mPlayers.size() - 1)
		mActivePlayer = 0;
	else
		mActivePlayer++;
	DEBUG_OUTPUT("Active Player:" << mActivePlayer << std::endl);

	mScreen->ilmoitusVuorossa(mPlayers.at(mActivePlayer).getName());
	return true;
}
Julkinen::PelaajaTyyppi Game::haeVuorossa(){
	return mPlayers.at(mActivePlayer).getType();
}

void Game::updateScreen(){

	std::for_each(mPieces.begin(), mPieces.end(), [&](Piece piece){
		mScreen->palaLaudalle(piece.getType(), Julkinen::ErikoispalaTyyppi(), piece.getRotation(), piece.getLocation(), Julkinen::Koordinaatti());
		// Check that there is an item on the piece
		if (piece.getItem() != 'x')
			mScreen->esineLaudalle(piece.getItem(), piece.getLocation());
	});
	std::for_each(mPlayers.begin(), mPlayers.end(), [&](Player player){
		mScreen->pelaajaLaudalle(player.getAbbr(), player.getLocation());
	});
	std::for_each(mPlayers.begin(), mPlayers.end(), [&](Player player){
		mScreen->tulostaPelaajantiedot(player.getName(), player.getCollectedItems(), player.getTargetItems(), player.getLastCommand());
	});
}
bool Game::isWallCollision(Julkinen::Suunta direction, unsigned int amount){
	int x = mPlayers.at(mActivePlayer).getLocation().haeXkoordinaatti();
	int y = mPlayers.at(mActivePlayer).getLocation().haeYkoordinaatti();

	switch (direction){
	case Julkinen::ALAS:
		// check if out of game area
		if ((y + amount) > mAreaSize) return true;
		// check for collision
		for (unsigned i = 0; i < amount; i++){

			std::vector<Piece>::iterator currentPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});

			Julkinen::PalaTyyppi startType = currentPiece->getType();
			unsigned int startRotation = currentPiece->getRotation();

			if ((startType == Julkinen::IPALA && startRotation == 2)
				|| (startType == Julkinen::IPALA && startRotation == 4)
				|| (startType == Julkinen::LPALA && startRotation == 1)
				|| (startType == Julkinen::LPALA && startRotation == 4)
				|| (startType == Julkinen::TPALA && startRotation == 3)
				) return true;

			std::vector<Piece>::iterator nextPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y + 1);
			});

			Julkinen::PalaTyyppi destType = nextPiece->getType();
			unsigned int destRotation = nextPiece->getRotation();

			if ((destType == Julkinen::IPALA && destRotation == 2)
				|| (destType == Julkinen::IPALA && destRotation == 4)
				|| (destType == Julkinen::LPALA && destRotation == 2)
				|| (destType == Julkinen::LPALA && destRotation == 3)
				|| (destType == Julkinen::TPALA && destRotation == 1)
				) return true;
			y++;
		}
		break;
	case Julkinen::YLOS:
		// check if out of game area
		if ((y - amount) < 1) return true;
		// check for collision
		for (unsigned i = 0; i < amount; i++){

			std::vector<Piece>::iterator currentPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});

			Julkinen::PalaTyyppi startType = currentPiece->getType();
			unsigned int startRotation = currentPiece->getRotation();

			if ((startType == Julkinen::IPALA && startRotation == 2)
				|| (startType == Julkinen::IPALA && startRotation == 4)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::TPALA && startRotation == 1)
				) return true;

			std::vector<Piece>::iterator nextPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y - 1);
			});

			Julkinen::PalaTyyppi destType = nextPiece->getType();
			unsigned int destRotation = nextPiece->getRotation();

			if ((destType == Julkinen::IPALA && destRotation == 2)
				|| (destType == Julkinen::IPALA && destRotation == 4)
				|| (destType == Julkinen::LPALA && destRotation == 1)
				|| (destType == Julkinen::LPALA && destRotation == 4)
				|| (destType == Julkinen::TPALA && destRotation == 3)
				) return true;
			y--;
		}
		break;
	case Julkinen::OIKEALLE:
		// check if out of game area
		if ((x + amount) > mAreaSize) return true;
		// check for collision
		for (unsigned i = 0; i < amount; i++){

			std::vector<Piece>::iterator currentPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});

			Julkinen::PalaTyyppi startType = currentPiece->getType();
			unsigned int startRotation = currentPiece->getRotation();

			if ((startType == Julkinen::IPALA && startRotation == 1)
				|| (startType == Julkinen::IPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 4)
				|| (startType == Julkinen::TPALA && startRotation == 2)
				) return true;

			std::vector<Piece>::iterator nextPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x + 1, y);
			});

			Julkinen::PalaTyyppi destType = nextPiece->getType();
			unsigned int destRotation = nextPiece->getRotation();

			if ((destType == Julkinen::IPALA && destRotation == 1)
				|| (destType == Julkinen::IPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 1)
				|| (destType == Julkinen::LPALA && destRotation == 2)
				|| (destType == Julkinen::TPALA && destRotation == 4)
				) return true;
			x++;
		}
		break;
	case Julkinen::VASEMMALLE:
		// check if out of game area
		if ((x - amount) < 1) return true;
		// check for collision
		for (unsigned i = 0; i < amount; i++){

			std::vector<Piece>::iterator currentPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x, y);
			});

			Julkinen::PalaTyyppi startType = currentPiece->getType();
			unsigned int startRotation = currentPiece->getRotation();

			if ((startType == Julkinen::IPALA && startRotation == 1)
				|| (startType == Julkinen::IPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 1)
				|| (startType == Julkinen::LPALA && startRotation == 2)
				|| (startType == Julkinen::TPALA && startRotation == 4)
				) return true;

			std::vector<Piece>::iterator nextPiece = std::find_if(mPieces.begin(), mPieces.end(), [&](Piece piece){
				return piece.getLocation() == Julkinen::Koordinaatti(x - 1, y);
			});

			Julkinen::PalaTyyppi destType = nextPiece->getType();
			unsigned int destRotation = nextPiece->getRotation();

			if ((destType == Julkinen::IPALA && destRotation == 1)
				|| (destType == Julkinen::IPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 4)
				|| (destType == Julkinen::TPALA && destRotation == 2)
				) return true;
			x--;
		}
		break;
	}
	// If got to this point, no collisions detected
	return false;
}
void Game::handleCPU(){
	// Get CPU target coordinates
	Julkinen::Koordinaatti targetCoords;
	std::for_each(mPieces.begin(), mPieces.end(), [&](Piece piece){
		if (piece.getItem() == mPlayers.at(mActivePlayer).nextItem())
			targetCoords = piece.getLocation();
	});
	if (!targetCoords.onkoIrtopala())
	DEBUG_OUTPUT("CPU Target coords: " << targetCoords.haeXkoordinaatti() << " " << targetCoords.haeYkoordinaatti() << std::endl);

}
std::string Game::directionChar(Julkinen::Suunta direction){
	if (direction == Julkinen::ALAS)
		return std::string("a");
	else if (direction == Julkinen::YLOS)
		return std::string("y");
	else if (direction == Julkinen::VASEMMALLE)
		return std::string("v");
	else if (direction == Julkinen::OIKEALLE)
		return std::string("o");

	return std::string("");
}