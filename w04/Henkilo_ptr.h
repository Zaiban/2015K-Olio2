#pragma once
#include "stdafx.h"
#include "Henkilo.h"
using std::string;

namespace myNs{

	class Henkilo_ptr
	{
	public:
		Henkilo_ptr();
		Henkilo_ptr(string firstName, string lastName, string personalIndentityCode);
		~Henkilo_ptr();
		Henkilo* getS() const;
		Henkilo& operator*() const;
		Henkilo* operator->() const;
	private:
		string mFirstName;
		string mLastName;
		string mPersonalIndentityCode;
		mutable Henkilo *mS;

		void Load() const;
	};

}