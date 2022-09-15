/*
 Custom flag: Fifty Fifty (+FF)
 Each kill has a fifty fifty chance of earning 20 points or losing 20 points.
 
 Copyright 2022 Quinn Carmack
 May be redistributed under either the LGPL or MIT licenses.
 
 ./configure --enable-custom-plugins=fiftyFiftyFlag
*/
 
#include "bzfsAPI.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class FiftyFiftyFlag : public bz_Plugin
{
	virtual const char* Name()
	{
		return "Fifty Fifty Flag";
	}
	virtual void Init(const char*);
	virtual void Event(bz_EventData*);
	~FiftyFiftyFlag();

	virtual void Cleanup(void)
	{
		Flush();
	}
};

BZ_PLUGIN(FiftyFiftyFlag)

void FiftyFiftyFlag::Init(const char*)
{
	bz_RegisterCustomFlag("FF", "Fifty Fifty", "Each kill has a 50/50 chance of 20 or -20 points.", 0, eGoodFlag);
	Register(bz_ePlayerDieEvent);
}

FiftyFiftyFlag::~FiftyFiftyFlag() {}

void FiftyFiftyFlag::Event(bz_EventData *eventData)
{
	if (eventData->eventType == bz_ePlayerDieEvent)
	{
		bz_PlayerDieEventData_V1 *data = (bz_PlayerDieEventData_V1*) eventData;
		
		if (data->flagKilledWith == "FF")
		{
			if (data->killerID != data->playerID)
			{
				std::srand(std::time(nullptr));
				int r = std::rand() % 2;
				
				if (r == 0)
				{
					bz_sendTextMessagef(BZ_SERVER, data->killerID, "Lucky you! +20 points!");
					bz_incrementPlayerWins(data->killerID, 19);
				}
				else
				{
					bz_sendTextMessagef(BZ_SERVER, data->killerID, "May the odds be ever in your favor... next time; -20 points.");
					bz_incrementPlayerWins(data->killerID, -1);
					bz_incrementPlayerLosses(data->killerID, 20);
				}
			}
		}
	}
}
