// Copyright Epic Games, Inc. All Rights Reserved.

#include "Image2PoseGameMode.h"
#include "Image2PoseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AImage2PoseGameMode::AImage2PoseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
