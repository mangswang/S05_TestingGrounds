// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolRoutes.h"

TArray<AActor*> UPatrolRoutes::GetWaypoints() const
{
	return Waypoints;
}

