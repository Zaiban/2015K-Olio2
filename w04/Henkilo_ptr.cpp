#include "stdafx.h"
#include "Henkilo_ptr.h"

namespace myNs{

	Henkilo_ptr::Henkilo_ptr()
	{  }
	Henkilo_ptr::Henkilo_ptr(string firstName, string lastName, string personalIndentityCode)
		:mFirstName(firstName), mLastName(lastName), mPersonalIndentityCode(personalIndentityCode), mS(nullptr)
	{
	}
	Henkilo_ptr::~Henkilo_ptr()
	{
		if (!mS) // Varmistetaan resurssin vapauttaminen
			delete mS;
	}
	Henkilo* Henkilo_ptr::getS() const
	{
		return mS;
	}
	void Henkilo_ptr::Load() const
	{
		if (mS == nullptr)
			mS = new Henkilo(mFirstName, mLastName, mPersonalIndentityCode);
	}
	Henkilo &Henkilo_ptr::operator*() const
	{
		Load(); // Testataan aina onko osoitin validi
		return *mS;
	}
	Henkilo *Henkilo_ptr::operator->() const
	{
		Load(); // Testataan aina onko osoitin validi
		return mS;
	}

}