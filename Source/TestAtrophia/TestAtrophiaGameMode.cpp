// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestAtrophiaGameMode.h"
#include "TestAtrophiaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestAtrophiaGameMode::ATestAtrophiaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
