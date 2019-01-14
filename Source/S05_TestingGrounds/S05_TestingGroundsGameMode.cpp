// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "S05_TestingGroundsGameMode.h"
#include "S05_TestingGroundsHUD.h"
#include "S05_TestingGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TestingGroundsGameMode::AS05_TestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TestingGroundsHUD::StaticClass();
}
//Blueprint'/Game/Player/Blueprints/FirstPersonCharacter.FirstPersonCharacter'