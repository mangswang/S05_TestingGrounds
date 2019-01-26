// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05_TestingGroundsGameMode.h"
#include "InfiniteTerrainGroundsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGroundsGameMode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	AInfiniteTerrainGroundsGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nav Mesh Bounds Volume Pool")
	class UActorPool* NavMeshBoundsVolumePool;


private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
};
