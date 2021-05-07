// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "IgnitionRushGameMode.h"
#include "IgnitionRushCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIgnitionRushGameMode::AIgnitionRushGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
