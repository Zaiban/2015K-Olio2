#ifndef RAKENTAJA_HH
#define RAKENTAJA_HH

/**
 *	\version $Id: pelirajapinta.hh 1795 2011-02-01 07:31:30Z salone58 $
 *  \file rakentaja.hh
 *  \brief Rakentaja-luokan esittely. ($Revision: 1795 $)
 *  \author ©2010 Eero Salonen <eero.j.salonen@tut.fi> 
 */

/**
 *	Jos k‰‰nt‰j‰ on GNUG pohjainen esim. gcc tai tutg++ k‰ytet‰‰n tr1/memory
 *	kirjastoa.
 */
#	if defined(__GNUG__)

#include <tr1/memory>
/**
 *	Muussa tapauksessa k‰ytet‰‰n memory kirjastoa ja toivotaan ett‰ k‰‰nt‰j‰st‰
 *	lˆytyy alustava tuki uudelle C++ standardille. 
 *	Toimii esim. Visual Studio 2010.
 */
#	else
#include <memory>
#	endif
#include "../../pelirajapinta.hh"
#include "../../koordinaatti.hh"
#include "../../luettelotyypit.hh"
#include "naytto.hh"
#include "Alustaja.hh"

/**
 *	\brief Labyrintti pelin alustaja luokka.
 */
class Rakentaja
{
	public:

		/**
		 *	\brief Rakentaja
		 *
		 *	\param peli Osoitin pelirajapintaan.
		 *	\param alustaja Osoitin \c Alustaja -olioon.
		 *	\param pelialueenkoko Koordinaatti joka sis‰lt‰‰ pelialueen koon.
		 *	\param naytto Osoite tulostusrajapintaan.
		 */
		Rakentaja(std::shared_ptr<Julkinen::Pelirajapinta> peli,  
			Julkinen::Koordinaatti const& pelialueenkoko, 
			std::string tiedosto,
			std::shared_ptr<Naytto> naytto);

		/**
		 *	\brief Purkaja.
		 */
		~Rakentaja();

		/**
		 *	\brief metodi alustustiedoston luontiin.
		 *
		 *	
		 */
		void lueTiedosto(); 

		/**
		 *	\brief Metodi joka lis‰‰ palat peliin.
		 *
		 *	\post Palat on lis‰tty peliin.
		 *		Poikkeusturvallisuus: Perustakuu.
		 */
		void lisaaPalat();

		/**
		 *	\brief Metodi joka lis‰‰ ensimm‰isen irtopalan peliin.
		 *
		 *	\post Irtopala on lis‰tty peliin.
		 *		Poikkeusturvallisuus: Perustakuu.
		 */
		void lisaaIrtopala();

		/**
		 *	\brief funktio joka luo pelaajat peliin, 
		 *	jos alustustiedostoa ei ole annettu.
		 *
		 *	\post Pelaajat lis‰tty peliin
		 *		Poikkeusturvallisuus: Perustakuu.
		 *
		 *	\param ihmispelaajia Ihmispelaajien m‰‰r‰.
		 *	\param tietokonepelaajia Tietokonepelaajien m‰‰r‰.
		 */
		void luoPelaajat();

		/**
		 *	\brief Metodi joka lisaa pelaajat peliin.
		 *
		 *	\post Pelaajat on lis‰tty peliin.
		 */
		void lisaaPelaajat();

		/**
		 *	\brief Metodi joka lisaa esineet peliin.
		 *
		 *	\post Esineet on lis‰tty peliin.
		 */
		void lisaaEsineet();

   void lisaaErikoispalat();
	private:

		Julkinen::PalaTyyppi maaritaPalaTyyppi(unsigned int x, unsigned int y) const;
		Julkinen::PalaTyyppi maaritaIrtoPalanTyyppi() const;
		Julkinen::PalaTyyppi 
			maaritaPalaTyyppi(Alustaja::Ruututyyppi alustustyyppi) const;
		std::string maaritaNimi();
		char int2char(int a);
		Julkinen::Koordinaatti luoSijainti();
		int str2int (std::string const & str) const;


		struct PelaajaTiedot
		{
			Julkinen::PelaajaTyyppi _tyyppi;
			std::string _nimi;
			char _merkki;
			Julkinen::Koordinaatti _sijainti;
		};

		std::shared_ptr<Julkinen::Pelirajapinta> _peli;
		std::shared_ptr<Naytto> _naytto;
		std::shared_ptr<Alustaja> _alustaja;
		Julkinen::Koordinaatti _koko;
		std::vector<PelaajaTiedot> _pelaajat;
		std::string _tiedosto;
		std::vector<std::string> _alustus;
		unsigned int _pelaajienmaara;
		int _siemenluku;
		unsigned int _pelaajialisatty;

};

#endif // RAKENTAJA_HH
