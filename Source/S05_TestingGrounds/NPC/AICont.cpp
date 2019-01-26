// Fill out your copyright notice in the Description page of Project Settings.

#include "AICont.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AAICont::AAICont()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComp"));
	SightConfig = CreateDefaultSubobject< UAISenseConfig_Sight>(FName("SightConfig"));

	if (PerceptionComp && SightConfig)
	{
		PerceptionComp->ConfigureSense(*SightConfig);
		PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());

		SightConfig->SightRadius = 2000.f;
		SightConfig->LoseSightRadius = 2200.f;
		SightConfig->PeripheralVisionAngleDegrees = 70.f;

		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	}
}