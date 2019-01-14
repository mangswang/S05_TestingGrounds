// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoutes.h"
#include "AIController.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//get waypoints
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolPointsComp = ControlledPawn->FindComponentByClass<UPatrolRoutes>();
	if (!ensure(PatrolPointsComp)) { return EBTNodeResult::Failed; }
	auto Waypoints = PatrolPointsComp->GetWaypoints();
	if (Waypoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Waypoints for %s"), *ControlledPawn->GetName())
			return EBTNodeResult::Failed;
	}
	//set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoints[Index]);

	//iterate index
	auto NextIndex = (Index + 1) % Waypoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	return EBTNodeResult::Succeeded;
}
