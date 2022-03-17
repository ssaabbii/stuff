#include <stdio.h>
#include <stdlib.h>

struct Lamp
{
	int m_voltage;
};
//========================================

//========================================
struct Switcher
{
	int* m_influenceToLamps;
	int m_isWork;
};
void createSwitcher(struct Switcher* controller, char* buffer, int amountOfLamps)
{
	controller->m_influenceToLamps = (int*)(malloc(amountOfLamps * sizeof(int)));
	controller->m_isWork = 0;

	scanf_s("%s", buffer, amountOfLamps + 1);
	for (int i = 0; i < amountOfLamps; ++i)
		controller->m_influenceToLamps[i] = (buffer[i] == 'X');
}
int onSwitcher(struct Switcher* switcher, struct Lamp* lamplsArrayPointer, int amountOfLamps, int requiredVoltage, int minimumVoltage)
{
	if (switcher->m_isWork == 1)
		return 1;

	switcher->m_isWork = 1;
	for (int i = 0; i < amountOfLamps; ++i)
	{
		lamplsArrayPointer[i].m_voltage += switcher->m_influenceToLamps[i];
		if (lamplsArrayPointer[i].m_voltage > requiredVoltage || lamplsArrayPointer[i].m_voltage < minimumVoltage)
		{
			switcher->m_isWork = 0;
			for (; i >= 0; --i)
				lamplsArrayPointer[i].m_voltage -= switcher->m_influenceToLamps[i];
			return 0;
		}
	}
	return 1;
}
void offSwitcher(struct Switcher* switcher, struct Lamp* lamplsArrayPointer, int amountOfLamps)
{
	if (switcher->m_isWork == 0)
		return;

	switcher->m_isWork = 0;
	for (int i = 0; i < amountOfLamps; ++i)
		lamplsArrayPointer[i].m_voltage -= switcher->m_influenceToLamps[i];
}
//========================================




struct RemoteController
{
	struct Switcher* m_switchersArray;
	int m_amountOfSwitchers;
};
void createRemoteController(struct RemoteController* remote, char* buffer, int amountOfSwitchers, int amountOfLamps)
{
	remote->m_amountOfSwitchers = amountOfSwitchers;
	remote->m_switchersArray = (struct Switcher*)(malloc(sizeof(struct Switcher) * amountOfSwitchers));

	for (int i = 0; i < amountOfSwitchers; ++i)
		createSwitcher(&remote->m_switchersArray[i], buffer, amountOfLamps);
}




struct HighLevelGadget
{
	struct Lamp* m_lampsArray;
	int m_amountOfLampls;

	struct RemoteController* m_remotesArray;
	int m_amountOfRemotes;

	int m_requiredVoltage;
};
void createHighLevelGadget(struct HighLevelGadget* gadget)
{
	int amountSwitches;
	scanf_s("%d %d %d %d\n", &gadget->m_amountOfRemotes, &amountSwitches, &gadget->m_amountOfLampls, &gadget->m_requiredVoltage);
	gadget->m_lampsArray = (struct Lamp*)(malloc(gadget->m_amountOfLampls * sizeof(struct Lamp)));
	gadget->m_remotesArray = (struct RemoteController*)(malloc(gadget->m_amountOfRemotes * sizeof(struct RemoteController)));

	for (int i = 0; i < gadget->m_amountOfLampls; ++i)
		gadget->m_lampsArray[i].m_voltage = 0;

	char* buffer = (char*)(malloc(sizeof(char) * (gadget->m_amountOfLampls + 1)));
	for (int i = 0; i < gadget->m_amountOfRemotes; ++i)
		createRemoteController(&gadget->m_remotesArray[i], buffer, amountSwitches, gadget->m_amountOfLampls);
}
int isValidState(struct HighLevelGadget* gadget)
{
	for (int i = 0; i < gadget->m_amountOfLampls; ++i)
		if (gadget->m_lampsArray[i].m_voltage != gadget->m_requiredVoltage)
			return 0;

	return 1;
}
int recursiveFindValidState(struct HighLevelGadget* gadget, int remoteIndex)
{
	for (int index = 0; index < gadget->m_remotesArray[remoteIndex].m_amountOfSwitchers; ++index)
	{
		if (onSwitcher(&gadget->m_remotesArray[remoteIndex].m_switchersArray[index], gadget->m_lampsArray, gadget->m_amountOfLampls, gadget->m_requiredVoltage, remoteIndex - (gadget->m_amountOfRemotes - gadget->m_requiredVoltage)) == 1)
		{
			if (remoteIndex == gadget->m_amountOfRemotes - 1)
			{
				if (isValidState(gadget) == 1)
					return 1;
				else
					offSwitcher(&gadget->m_remotesArray[remoteIndex].m_switchersArray[index], gadget->m_lampsArray, gadget->m_amountOfLampls);
			}
			else
			{
				if (recursiveFindValidState(gadget, remoteIndex + 1) == 1)
					return 1;
				else
					offSwitcher(&gadget->m_remotesArray[remoteIndex].m_switchersArray[index], gadget->m_lampsArray, gadget->m_amountOfLampls);
			}
		}
	}
	return 0;
}
int findValidRemotesState(struct HighLevelGadget* gadget)
{
	return recursiveFindValidState(gadget, 0);
}
void printAnswer(struct HighLevelGadget* gadget, int state)
{
	if (state == 1)
	{
		printf("YES\n");
		for (int i = 0; i < gadget->m_amountOfRemotes; ++i)
		{
			for (int j = 0; j < gadget->m_remotesArray[i].m_amountOfSwitchers; ++j)
			{
				if (gadget->m_remotesArray[i].m_switchersArray[j].m_isWork == 1)
				{
					printf("%d\n", (j + 1));
					break;
				}
			}
		}
	}
	else
	{
		printf("NO\n");
	}
}


int main()
{
	struct HighLevelGadget gadget;
	createHighLevelGadget(&gadget);
	int result = findValidRemotesState(&gadget);
	printAnswer(&gadget, result);
	return 0;
}