// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoutes.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUNDS_API UPatrolRoutes : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetWaypoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Setup")
	TArray<AActor*> Waypoints;
};
