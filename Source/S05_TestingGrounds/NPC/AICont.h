// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICont.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AAICont : public AAIController
{
	GENERATED_BODY()
	
public:

	AAICont();

	UPROPERTY(VisibleAnywhere, Category = "Perception")
	class UAIPerceptionComponent* PerceptionComp;

	UPROPERTY(EditDefaultsOnly, Category = "Perception")
	class UAISenseConfig_Sight* SightConfig;

};
