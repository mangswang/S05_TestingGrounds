// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGroundsGameMode.h"
#include "NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrainGroundsGameMode::AInfiniteTerrainGroundsGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void AInfiniteTerrainGroundsGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);

		++VolumeIterator;
	}
}

void AInfiniteTerrainGroundsGameMode::AddToPool(ANavMeshBoundsVolume * VolumeToAdd)
{
	NavMeshBoundsVolumePool->AddActor(VolumeToAdd);
}
